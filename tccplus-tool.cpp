#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <unistd.h>
#include <curl/curl.h>
#include <CoreFoundation/CoreFoundation.h> // 添加CoreFoundation头文件
#include <sys/stat.h>

// 下载文件
bool downloadFile(const std::string& url) {
    CURL* curl = curl_easy_init();
    if (curl) {
        FILE* file = fopen("./tccplus", "wb");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);
        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(file);
        if (res == CURLE_OK) {
            std::cout << "File download successful" << std::endl;
            return true;
        } else {
            std::cerr << "Download failed: Unable to connect to the specified URL" << std::endl;
            return false;
        }
    }
    return false;
}

// 检查并下载tccplus文件
bool checkAndDownloadTccplus() {
    if (access("./tccplus", F_OK) != -1) {
        std::cout << "'tccplus' Check completed" << std::endl;
        return true;
    } else {
        std::vector<std::string> urls;
        urls.push_back("https://raw.githubusercontent.com/Gloridust/tccplus-tool/main/src/tccplus");
        urls.push_back("https://raw.staticdn.net/Gloridust/tccplus-tool/main/src/tccplus");
        urls.push_back("https://raw.fastgit.org/Gloridust/tccplus-tool/main/src/tccplus");
        for (const auto& url : urls) {
            std::cout << "Download 'tccplus' from " << url << " ..." << std::endl;
            if (downloadFile(url)) {
                chmod("./tccplus", S_IRWXU | S_IRWXG | S_IRWXO);
                return true;
            }
        }
        std::cerr << "None of the sources can be downloaded" << std::endl;
        return false;
    }
}

// 获取应用程序路径
std::string getAppPath() {
    std::string appPath;
    std::cout << "Drop or input app_path here:";
    std::getline(std::cin, appPath);

    if (!appPath.empty() && (appPath.front() == '\'' || appPath.front() == '"') && appPath.front() == appPath.back()) {
        appPath = appPath.substr(1, appPath.size() - 2);
    }

    std::cout << "Your app path is: " << appPath << std::endl;
    return appPath;
}

// 选择操作
std::string chooseAction() {
    std::cout << "Please select an action:" << std::endl;
    std::cout << "1. add" << std::endl;
    std::cout << "2. reset" << std::endl;
    std::string choice;
    std::getline(std::cin, choice);

    if (choice == "1") {
        std::cout << "You selected 'add'" << std::endl;
        return "add";
    } else if (choice == "2") {
        std::cout << "You selected 'reset'" << std::endl;
        return "reset";
    } else {
        std::cerr << "Invalid option" << std::endl;
        return "";
    }
}

// 选择服务
std::string chooseService() {
    std::cout << "Choose service:" << std::endl;
    std::vector<std::string> services = {
        "All", "Accessibility", "AddressBook", "AppleEvents", "Calendar", "Camera", "ContactsFull", "ContactsLimited",
        "DeveloperTool", "Facebook", "LinkedIn", "ListenEvent", "Liverpool", "Location", "MediaLibrary", "Microphone",
        "Motion", "Photos", "PhotosAdd", "PostEvent", "Reminders", "ScreenCapture", "ShareKit", "SinaWeibo", "Siri",
        "SpeechRecognition", "SystemPolicyAllFiles", "SystemPolicyDesktopFolder", "SystemPolicyDeveloperFiles",
        "SystemPolicyDocumentsFolder", "SystemPolicyDownloadsFolder", "SystemPolicyNetworkVolumes",
        "SystemPolicyRemovableVolumes", "SystemPolicySysAdminFiles", "TencentWeibo", "Twitter", "Ubiquity", "Willow"
    };
    for (size_t i = 0; i < services.size(); ++i) {
        std::cout << i + 1 << ". " << services[i] << std::endl;
    }

    std::string choice;
    std::getline(std::cin, choice);

    size_t index;
    try {
        index = std::stoi(choice);
    } catch (const std::exception& e) {
        std::cerr << "Invalid option" << std::endl;
        return "";
    }

    if (index >= 1 && index <= services.size()) {
        std::cout << "You Chose '" << services[index - 1] << "' service" << std::endl;
        return services[index - 1];
    } else {
        std::cerr << "Invalid option" << std::endl;
        return "";
    }
}

// 获取Bundle标识符
std::string getBundleIdentifier(const std::string& appPath) {
    try {
        std::ifstream file(appPath + "/Contents/Info.plist", std::ios::binary);
        if (file) {
            file.seekg(0, std::ios::end);
            std::streamsize size = file.tellg();
            file.seekg(0, std::ios::beg);

            std::vector<char> buffer(size);
            if (file.read(buffer.data(), size)) {
                CFDataRef data = CFDataCreateWithBytesNoCopy(nullptr, reinterpret_cast<const UInt8*>(buffer.data()), buffer.size(), kCFAllocatorNull);
                CFPropertyListRef plist = CFPropertyListCreateWithData(nullptr, data, kCFPropertyListImmutable, nullptr, nullptr);
                if (plist) {
                    CFDictionaryRef dict = static_cast
                    CFDictionaryRef>(plist);
                    CFStringRef bundleIdent = static_cast
                    CFStringRef>(CFDictionaryGetValue(dict, CFSTR("CFBundleIdentifier")));
                    if (bundleIdent) {
                        char identifier[1024];
                        CFStringGetCString(bundleIdent, identifier, sizeof(identifier), kCFStringEncodingUTF8);
                        std::string identifierStr(identifier);
                        std::cout << "Bundle Identifier: " << identifierStr << std::endl;
                        return identifierStr;
                    } else {
                        std::cerr << "Bundle Identifier not found" << std::endl;
                    }
                } else {
                    std::cerr << "Invalid Info.plist file" << std::endl;
                }
            }
        } else {
            std::cerr << "File not found" << std::endl;
        }
    } catch (...) {
        std::cerr << "Error occurred while reading Info.plist" << std::endl;
    }
    return "";
}

// 运行tccplus
void runTccplus(const std::string& action, const std::string& service, const std::string& bundleIdent) {
    std::string command = "./tccplus " + action + " " + service + " " + bundleIdent;
    int result = system(command.c_str());
    if (result != 0) {
        std::cerr << "Command execution failed" << std::endl;
    }
}

int main() {
    if (checkAndDownloadTccplus()) {
        std::string appPath = getAppPath();
        std::string action = chooseAction();
        std::string service = chooseService();
        std::string bundleIdent = getBundleIdentifier(appPath);
        runTccplus(action, service, bundleIdent);
        std::cout << "Press any key to continue...";
        std::cin.ignore();
    } else {
        std::cerr << "No 'tccplus' file found" << std::endl;
    }
    return 0;
}
