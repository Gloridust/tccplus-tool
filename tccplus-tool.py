import plistlib
import subprocess
import os
import requests
import queue

def download_file(url):
    try:
        response = requests.get(url, timeout=3)
        if response.status_code == 200:
            with open("./tccplus", 'wb') as f:
                f.write(response.content)
            print(f"File download successful")
            return True
        else:
            print("Download failed: Unable to connect to the specified URL")
            return False
    except Exception as e:
        print("Download failed:", e)
        return False

def check_and_download_tccplus():
    if os.path.exists("./tccplus"):
        print(f"'tccplus' Check completed")
        return True
    else:
        urls = [
            "https://raw.githubusercontent.com/Gloridust/tccplus-tool/main/src/tccplus",
            "https://raw.staticdn.net/Gloridust/tccplus-tool/main/src/tccplus",
            "https://raw.fastgit.org/Gloridust/tccplus-tool/main/src/tccplus",
        ]
        for url in urls:
            print(f"Download 'tccplus' from {url} ...")
            if download_file(url):
                os.chmod("./tccplus", 0o755)
                return True
        else:
            print("None of the sources can be downloaded")
            return False

def get_app_path():
    app_path = input("Drop or input app_path here:")

    if app_path.startswith("'") and user_input.endswith("'"):
        # 去掉开头和结尾的单引号
        app_path = app_path[1:-1]
    elif app_path.startswith('"') and user_input.endswith('"'):
        # 去掉开头和结尾的双引号
        user_input = user_input[1:-1]

    print("Your app path is:：", app_path)
    return app_path

def choose_action():
    print("Please select an action:")
    print("1. add")
    print("2. reset")
    choice = input("Please enter the serial number to select an action:")

    if choice:
        if choice == "1":
            print("You selected 'add'")
            action = "add"
        elif choice == "2":
            print("You selected 'reset'")
            action = "reset"
        else:
            print("Invalid option")
    else:
        action = "add"
    
    return action

def choose_service():
    print("choose service:")
    print("1. All")
    print("2. Accessibility")
    print("3. AddressBook")
    print("4. AppleEvents")
    print("5. Calendar")
    print("6. Camera")
    print("7. ContactsFull")
    print("8. ContactsLimited")
    print("9. DeveloperTool")
    print("10. Facebook")
    print("11. LinkedIn")
    print("12. ListenEvent")
    print("13. Liverpool")
    print("14. Location")
    print("15. MediaLibrary")
    print("16. Microphone")
    print("17. Motion")
    print("18. Photos")
    print("19. PhotosAdd")
    print("20. PostEvent")
    print("21. Reminders")
    print("22. ScreenCapture")
    print("23. ShareKit")
    print("24. SinaWeibo")
    print("25. Siri")
    print("26. SpeechRecognition")
    print("27. SystemPolicyAllFiles")
    print("28. SystemPolicyDesktopFolder")
    print("29. SystemPolicyDeveloperFiles")
    print("30. SystemPolicyDocumentsFolder")
    print("31. SystemPolicyDownloadsFolder")
    print("32. SystemPolicyNetworkVolumes")
    print("33. SystemPolicyRemovableVolumes")
    print("34. SystemPolicySysAdminFiles")
    print("35. TencentWeibo")
    print("36. Twitter")
    print("37. Ubiquity")
    print("38. Willow")

    choice = input("Please enter the service serial number to select service:")

    if choice:
        if choice == "1":
            print("You Chose 'All' service")
            service = "All"
        elif choice == "2":
            print("You Chose 'Accessibility' service")
            service = "Accessibility"
        elif choice == "3":
            print("You Chose 'AddressBook' service")
            service = "AddressBook"
        elif choice == "4":
            print("You Chose 'AppleEvents' service")
            service = "AppleEvents"
        elif choice == "5":
            print("You Chose 'Calendar' service")
            service = "Calendar"
        elif choice == "6":
            print("You Chose 'Camera' service")
            service = "Camera"
        elif choice == "7":
            print("You Chose 'ContactsFull' service")
            service = "ContactsFull"
        elif choice == "8":
            print("You Chose 'ContactsLimited' service")
            service = "ContactsLimited"
        elif choice == "9":
            print("You Chose 'DeveloperTool' service")
            service = "DeveloperTool"
        elif choice == "10":
            print("You Chose 'Facebook' service")
            service = "Facebook"
        elif choice == "11":
            print("You Chose 'LinkedIn' service")
            service = "LinkedIn"
        elif choice == "12":
            print("You Chose 'ListenEvent' service")
            service = "ListenEvent"
        elif choice == "13":
            print("You Chose 'Liverpool' service")
            service = "Liverpool"
        elif choice == "14":
            print("You Chose 'Location' service")
            service = "Location"
        elif choice == "15":
            print("You Chose 'MediaLibrary' service")
            service = "MediaLibrary"
        elif choice == "16":
            print("You Chose 'Microphone' service")
            service = "Microphone"
        elif choice == "17":
            print("You Chose 'Motion' service")
            service = "Motion"
        elif choice == "18":
            print("You Chose 'Photos' service")
            service = "Photos"
        elif choice == "19":
            print("You Chose 'PhotosAdd' service")
            service = "PhotosAdd"
        elif choice == "20":
            print("You Chose 'PostEvent' service")
            service = "PostEvent"
        elif choice == "21":
            print("You Chose 'Reminders' service")
            service = "Reminders"
        elif choice == "22":
            print("You Chose 'ScreenCapture' service")
            service = "ScreenCapture"
        elif choice == "23":
            print("You Chose 'ShareKit' service")
            service = "ShareKit"
        elif choice == "24":
            print("You Chose 'SinaWeibo' service")
            service = "SinaWeibo"
        elif choice == "25":
            print("You Chose 'Siri' service")
            service = "Siri"
        elif choice == "26":
            print("You Chose 'SpeechRecognition' service")
            service = "SpeechRecognition"
        elif choice == "27":
            print("You Chose 'SystemPolicyAllFiles' service")
            service = "SystemPolicyAllFiles"
        elif choice == "28":
            print("You Chose 'SystemPolicyDesktopFolder' service")
            service = "SystemPolicyDesktopFolder"
        elif choice == "29":
            print("You Chose 'SystemPolicyDeveloperFiles' service")
            service = "SystemPolicyDeveloperFiles"
        elif choice == "30":
            print("You Chose 'SystemPolicyDocumentsFolder' service")
            service = "SystemPolicyDocumentsFolder"
        elif choice == "31":
            print("You Chose 'SystemPolicyDownloadsFolder' service")
            service = "SystemPolicyDownloadsFolder"
        elif choice == "32":
            print("You Chose 'SystemPolicyNetworkVolumes' service")
            service = "SystemPolicyNetworkVolumes"
        elif choice == "33":
            print("You Chose 'SystemPolicyRemovableVolumes' service")
            service = "SystemPolicyRemovableVolumes"
        elif choice == "34":
            print("You Chose 'SystemPolicySysAdminFiles' service")
            service = "SystemPolicySysAdminFiles"
        elif choice == "35":
            print("You Chose 'TencentWeibo' service")
            service = "TencentWeibo"
        elif choice == "36":
            print("You Chose 'Twitter' service")
            service = "Twitter"
        elif choice == "37":
            print("You Chose 'Ubiquity' service")
            service = "Ubiquity"
        elif choice == "38":
            print("You Chose 'Willow' service")
            service = "Willow"
        else:
            print("Invalid option")
            service = None
    else:
        print("No service is selected, 'All' is selected by default")
        service = "All"
    
    return service


def get_bundle_identifier(app_path):
    try:
        with open(f"{app_path}/Contents/Info.plist", "rb") as f:
            plist_data = plistlib.load(f)
            bundle_ident = plist_data.get("CFBundleIdentifier")
            if bundle_ident:
                print("Bundle Identifier:", bundle_ident)
                return bundle_ident
            else:
                print("Bundle Identifier not found")
    except FileNotFoundError:
        print("File not found")
    except plistlib.InvalidFileException:
        print("Invalid Info.plist file")

def run_tccplus(action,service,bundle_ident):
    command = ["./tccplus", action, service, bundle_ident]
    try:   
        result = subprocess.run(command, capture_output=True, text=True, check=True)
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print("Command execution failed:", e)



def main():
    have_tccplus_file = check_and_download_tccplus()
    if have_tccplus_file == True:
        app_path = get_app_path()
        action = choose_action()
        service = choose_service()
        bundle_ident = get_bundle_identifier(app_path)
        run_tccplus(action,service,bundle_ident)
        input("Press any key to continue...")
    else:
        print("No 'tccplus' file found")

if __name__ == "__main__":
    main()