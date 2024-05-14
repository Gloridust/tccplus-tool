#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

#define MAX_URL_LENGTH 1000

int download_file(const char *url)
{
    char command[MAX_URL_LENGTH + 30];
    snprintf(command, sizeof(command), "wget -O ./tccplus %s", url);
    if (system(command) == 0)
    {
        printf("File download successful\n");
        return 1;
    }
    else
    {
        printf("Download failed: Unable to connect to the specified URL\n");
        return 0;
    }
}

int check_and_download_tccplus()
{
    if (access("./tccplus", F_OK) != -1)
    {
        printf("'tccplus' Check completed\n");
        return 1;
    }
    else
    {
        const char *urls[] = {
            "https://raw.githubusercontent.com/Gloridust/tccplus-tool/main/src/tccplus",
            "https://raw.staticdn.net/Gloridust/tccplus-tool/main/src/tccplus",
            "https://raw.fastgit.org/Gloridust/tccplus-tool/main/src/tccplus"};
        for (int i = 0; i < sizeof(urls) / sizeof(urls[0]); ++i)
        {
            printf("Download 'tccplus' from %s ...\n", urls[i]);
            if (download_file(urls[i]))
            {
                system("chmod 755 ./tccplus");
                return 1;
            }
        }
        printf("None of the sources can be downloaded\n");
        return 0;
    }
}

char *get_app_path()
{
    char *app_path = (char *)malloc(MAX_URL_LENGTH * sizeof(char));
    if (app_path == NULL)
    {
        perror("Unable to allocate memory for app_path");
        exit(EXIT_FAILURE);
    }
    printf("Drop or input app_path here: ");
    if (fgets(app_path, MAX_URL_LENGTH, stdin) != NULL)
    {
        size_t len = strlen(app_path);
        if (len > 0 && app_path[len - 1] == '\n')
        {
            app_path[len - 1] = '\0'; // remove newline character
        }
        return app_path;
    }
    else
    {
        perror("Error reading app_path");
        free(app_path);
        exit(EXIT_FAILURE);
    }
}

char *choose_action()
{
    printf("Please select an action:\n");
    printf("1. add\n");
    printf("2. reset\n");
    printf("Please enter the serial number to select an action: ");
    char choice[3];
    if (fgets(choice, sizeof(choice), stdin) != NULL)
    {
        if (strcmp(choice, "1\n") == 0 || strcmp(choice, "1") == 0)
        {
            printf("You selected 'add'\n");
            return "add";
        }
        else if (strcmp(choice, "2\n") == 0 || strcmp(choice, "2") == 0)
        {
            printf("You selected 'reset'\n");
            return "reset";
        }
        else
        {
            printf("Invalid option\n");
            return NULL;
        }
    }
    else
    {
        perror("Error reading choice");
        return NULL;
    }
}

char *choose_service()
{
    printf("Choose service:\n");
    printf("1. All\n");
    printf("2. Accessibility\n");
    printf("3. AddressBook\n");
    printf("4. AppleEvents\n");
    printf("5. Calendar\n");
    printf("6. Camera\n");
    printf("7. ContactsFull\n");
    printf("8. ContactsLimited\n");
    printf("9. DeveloperTool\n");
    printf("10. Facebook\n");
    printf("11. LinkedIn\n");
    printf("12. ListenEvent\n");
    printf("13. Liverpool\n");
    printf("14. Location\n");
    printf("15. MediaLibrary\n");
    printf("16. Microphone\n");
    printf("17. Motion\n");
    printf("18. Photos\n");
    printf("19. PhotosAdd\n");
    printf("20. PostEvent\n");
    printf("21. Reminders\n");
    printf("22. ScreenCapture\n");
    printf("23. ShareKit\n");
    printf("24. SinaWeibo\n");
    printf("25. Siri\n");
    printf("26. SpeechRecognition\n");
    printf("27. SystemPolicyAllFiles\n");
    printf("28. SystemPolicyDesktopFolder\n");
    printf("29. SystemPolicyDeveloperFiles\n");
    printf("30. SystemPolicyDocumentsFolder\n");
    printf("31. SystemPolicyDownloadsFolder\n");
    printf("32. SystemPolicyNetworkVolumes\n");
    printf("33. SystemPolicyRemovableVolumes\n");
    printf("34. SystemPolicySysAdminFiles\n");
    printf("35. TencentWeibo\n");
    printf("36. Twitter\n");
    printf("37. Ubiquity\n");
    printf("38. Willow\n");
    printf("Please enter the service serial number to select service: ");
    char choice[3];
    if (fgets(choice, sizeof(choice), stdin) != NULL)
    {
        if (strcmp(choice, "1\n") == 0)
        {
            printf("You Chose 'All' service\n");
            return "All";
        }
        else if (strcmp(choice, "2\n") == 0)
        {
            printf("You Chose 'Accessibility' service\n");
            return "Accessibility";
        }
        else if (strcmp(choice, "3\n") == 0)
        {
            printf("You Chose 'AddressBook' service\n");
            return "AddressBook";
        }
        else if (strcmp(choice, "4\n") == 0)
        {
            printf("You Chose 'AppleEvents' service\n");
            return "AppleEvents";
        }
        else if (strcmp(choice, "5\n") == 0)
        {
            printf("You Chose 'Calendar' service\n");
            return "Calendar";
        }
        else if (strcmp(choice, "6\n") == 0)
        {
            printf("You Chose 'Camera' service\n");
            return "Camera";
        }
        else if (strcmp(choice, "7\n") == 0)
        {
            printf("You Chose 'ContactsFull' service\n");
            return "ContactsFull";
        }
        else if (strcmp(choice, "8\n") == 0)
        {
            printf("You Chose 'ContactsLimited' service\n");
            return "ContactsLimited";
        }
        else if (strcmp(choice, "9\n") == 0)
        {
            printf("You Chose 'DeveloperTool' service\n");
            return "DeveloperTool";
        }
        else if (strcmp(choice, "10\n") == 0)
        {
            printf("You Chose 'Facebook' service\n");
            return "Facebook";
        }
        else if (strcmp(choice, "11\n") == 0)
        {
            printf("You Chose 'LinkedIn' service\n");
            return "LinkedIn";
        }
        else if (strcmp(choice, "12\n") == 0)
        {
            printf("You Chose 'ListenEvent' service\n");
            return "ListenEvent";
        }
        else if (strcmp(choice, "13\n") == 0)
        {
            printf("You Chose 'Liverpool' service\n");
            return "Liverpool";
        }
        else if (strcmp(choice, "14\n") == 0)
        {
            printf("You Chose 'Location' service\n");
            return "Location";
        }
        else if (strcmp(choice, "15\n") == 0)
        {
            printf("You Chose 'MediaLibrary' service\n");
            return "MediaLibrary";
        }
        else if (strcmp(choice, "16\n") == 0)
        {
            printf("You Chose 'Microphone' service\n");
            return "Microphone";
        }
        else if (strcmp(choice, "17\n") == 0)
        {
            printf("You Chose 'Motion' service\n");
            return "Motion";
        }
        else if (strcmp(choice, "18\n") == 0)
        {
            printf("You Chose 'Photos' service\n");
            return "Photos";
        }
        else if (strcmp(choice, "19\n") == 0)
        {
            printf("You Chose 'PhotosAdd' service\n");
            return "PhotosAdd";
        }
        else if (strcmp(choice, "20\n") == 0)
        {
            printf("You Chose 'PostEvent' service\n");
            return "PostEvent";
        }
        else if (strcmp(choice, "21\n") == 0)
        {
            printf("You Chose 'Reminders' service\n");
            return "Reminders";
        }
        else if (strcmp(choice, "22\n") == 0)
        {
            printf("You Chose 'ScreenCapture' service\n");
            return "ScreenCapture";
        }
        else if (strcmp(choice, "23\n") == 0)
        {
            printf("You Chose 'ShareKit' service\n");
            return "ShareKit";
        }
        else if (strcmp(choice, "24\n") == 0)
        {
            printf("You Chose 'SinaWeibo' service\n");
            return "SinaWeibo";
        }
        else if (strcmp(choice, "25\n") == 0)
        {
            printf("You Chose 'Siri' service\n");
            return "Siri";
        }
        else if (strcmp(choice, "26\n") == 0)
        {
            printf("You Chose 'SpeechRecognition' service\n");
            return "SpeechRecognition";
        }
        else if (strcmp(choice, "27\n") == 0)
        {
            printf("You Chose 'SystemPolicyAllFiles' service\n");
            return "SystemPolicyAllFiles";
        }
        else if (strcmp(choice, "28\n") == 0)
        {
            printf("You Chose 'SystemPolicyDesktopFolder' service\n");
            return "SystemPolicyDesktopFolder";
        }
        else if (strcmp(choice, "29\n") == 0)
        {
            printf("You Chose 'SystemPolicyDeveloperFiles' service\n");
            return "SystemPolicyDeveloperFiles";
        }
        else if (strcmp(choice, "30\n") == 0)
        {
            printf("You Chose 'SystemPolicyDocumentsFolder' service\n");
            return "SystemPolicyDocumentsFolder";
        }
        else if (strcmp(choice, "31\n") == 0)
        {
            printf("You Chose 'SystemPolicyDownloadsFolder' service\n");
            return "SystemPolicyDownloadsFolder";
        }
        else if (strcmp(choice, "32\n") == 0)
        {
            printf("You Chose 'SystemPolicyNetworkVolumes' service\n");
            return "SystemPolicyNetworkVolumes";
        }
        else if (strcmp(choice, "33\n") == 0)
        {
            printf("You Chose 'SystemPolicyRemovableVolumes' service\n");
            return "SystemPolicyRemovableVolumes";
        }
        else if (strcmp(choice, "34\n") == 0)
        {
            printf("You Chose 'SystemPolicySysAdminFiles' service\n");
            return "SystemPolicySysAdminFiles";
        }
        else if (strcmp(choice, "35\n") == 0)
        {
            printf("You Chose 'TencentWeibo' service\n");
            return "TencentWeibo";
        }
        else if (strcmp(choice, "36\n") == 0)
        {
            printf("You Chose 'Twitter' service\n");
            return "Twitter";
        }
        else if (strcmp(choice, "37\n") == 0)
        {
            printf("You Chose 'Ubiquity' service\n");
            return "Ubiquity";
        }
        else if (strcmp(choice, "38\n") == 0)
        {
            printf("You Chose 'Willow' service\n");
            return "Willow";
        }
        else
        {
            printf("Invalid option\n");
            return NULL;
        }
    }

    char *get_bundle_identifier(const char *app_path)
    {
        xmlDoc *document = NULL;
        xmlNode *root, *first_child, *node;
        char info_plist_path[MAX_URL_LENGTH + 20];
        snprintf(info_plist_path, sizeof(info_plist_path), "%s/Contents/Info.plist", app_path);

        document = xmlReadFile(info_plist_path, NULL, 0);
        if (document == NULL)
        {
            printf("File not found or unable to read Info.plist\n");
            return NULL;
        }

        root = xmlDocGetRootElement(document);
        for (node = root->children; node; node = node->next)
        {
            if (node->type == XML_ELEMENT_NODE && xmlStrcmp(node->name, (const xmlChar *)"key") == 0)
            {
                if (xmlStrcmp(xmlNodeGetContent(node), (const xmlChar *)"CFBundleIdentifier") == 0)
                {
                    first_child = node->next;
                    while (first_child && first_child->type != XML_ELEMENT_NODE)
                    {
                        first_child = first_child->next;
                    }
                    if (first_child && xmlStrcmp(first_child->name, (const xmlChar *)"string") == 0)
                    {
                        char *bundle_identifier = (char *)xmlNodeGetContent(first_child);
                        printf("Bundle Identifier: %s\n", bundle_identifier);
                        xmlFreeDoc(document);
                        return bundle_identifier;
                    }
                }
            }
        }
        xmlFreeDoc(document);
        printf("Bundle Identifier not found\n");
        return NULL;
    }

    void run_tccplus(const char *action, const char *service, const char *bundle_identifier)
    {
        char command[MAX_URL_LENGTH + 50];
        snprintf(command, sizeof(command), "./tccplus %s %s %s", action, service, bundle_identifier);
        if (system(command) != 0)
        {
            printf("Command execution failed\n");
        }
    }

    int main()
    {
        if (check_and_download_tccplus() == 1)
        {
            char *app_path = get_app_path();
            char *action = choose_action();
            char *service = choose_service();
            char *bundle_identifier = get_bundle_identifier(app_path);
            if (bundle_identifier != NULL)
            {
                run_tccplus(action, service, bundle_identifier);
            }
            free(app_path);
            free(bundle_identifier);
            printf("Press any key to continue...");
            getchar();
        }
        else
        {
            printf("No 'tccplus' file found\n");
        }
        return 0;
    }
}
