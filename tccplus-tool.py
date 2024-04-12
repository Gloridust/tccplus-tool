import plistlib
import tkinter as tk
from tkinter import filedialog
import subprocess

def get_app_path():
    root = tk.Tk()
    root.withdraw()  # Hide windows
    app_path = filedialog.askopenfilename()  # Select app
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
        elif action == "2":
            print("You selected 'reset'")
            action = "reset"
        else:
            print("Invalid option")
    else:
        action = "add"
    
    return action

def choose_service():
    print("请选择服务:")
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

    choice = input("请输入服务的序号以选择服务:")

    if choice:
        if choice == "1":
            print("您选择了 'All' 服务")
            service = "All"
        elif choice == "2":
            print("您选择了 'Accessibility' 服务")
            service = "Accessibility"
        elif choice == "3":
            print("您选择了 'AddressBook' 服务")
            service = "AddressBook"
        elif choice == "4":
            print("您选择了 'AppleEvents' 服务")
            service = "AppleEvents"
        elif choice == "5":
            print("您选择了 'Calendar' 服务")
            service = "Calendar"
        elif choice == "6":
            print("您选择了 'Camera' 服务")
            service = "Camera"
        elif choice == "7":
            print("您选择了 'ContactsFull' 服务")
            service = "ContactsFull"
        elif choice == "8":
            print("您选择了 'ContactsLimited' 服务")
            service = "ContactsLimited"
        elif choice == "9":
            print("您选择了 'DeveloperTool' 服务")
            service = "DeveloperTool"
        elif choice == "10":
            print("您选择了 'Facebook' 服务")
            service = "Facebook"
        elif choice == "11":
            print("您选择了 'LinkedIn' 服务")
            service = "LinkedIn"
        elif choice == "12":
            print("您选择了 'ListenEvent' 服务")
            service = "ListenEvent"
        elif choice == "13":
            print("您选择了 'Liverpool' 服务")
            service = "Liverpool"
        elif choice == "14":
            print("您选择了 'Location' 服务")
            service = "Location"
        elif choice == "15":
            print("您选择了 'MediaLibrary' 服务")
            service = "MediaLibrary"
        elif choice == "16":
            print("您选择了 'Microphone' 服务")
            service = "Microphone"
        elif choice == "17":
            print("您选择了 'Motion' 服务")
            service = "Motion"
        elif choice == "18":
            print("您选择了 'Photos' 服务")
            service = "Photos"
        elif choice == "19":
            print("您选择了 'PhotosAdd' 服务")
            service = "PhotosAdd"
        elif choice == "20":
            print("您选择了 'PostEvent' 服务")
            service = "PostEvent"
        elif choice == "21":
            print("您选择了 'Reminders' 服务")
            service = "Reminders"
        elif choice == "22":
            print("您选择了 'ScreenCapture' 服务")
            service = "ScreenCapture"
        elif choice == "23":
            print("您选择了 'ShareKit' 服务")
            service = "ShareKit"
        elif choice == "24":
            print("您选择了 'SinaWeibo' 服务")
            service = "SinaWeibo"
        elif choice == "25":
            print("您选择了 'Siri' 服务")
            service = "Siri"
        elif choice == "26":
            print("您选择了 'SpeechRecognition' 服务")
            service = "SpeechRecognition"
        elif choice == "27":
            print("您选择了 'SystemPolicyAllFiles' 服务")
            service = "SystemPolicyAllFiles"
        elif choice == "28":
            print("您选择了 'SystemPolicyDesktopFolder' 服务")
            service = "SystemPolicyDesktopFolder"
        elif choice == "29":
            print("您选择了 'SystemPolicyDeveloperFiles' 服务")
            service = "SystemPolicyDeveloperFiles"
        elif choice == "30":
            print("您选择了 'SystemPolicyDocumentsFolder' 服务")
            service = "SystemPolicyDocumentsFolder"
        elif choice == "31":
            print("您选择了 'SystemPolicyDownloadsFolder' 服务")
            service = "SystemPolicyDownloadsFolder"
        elif choice == "32":
            print("您选择了 'SystemPolicyNetworkVolumes' 服务")
            service = "SystemPolicyNetworkVolumes"
        elif choice == "33":
            print("您选择了 'SystemPolicyRemovableVolumes' 服务")
            service = "SystemPolicyRemovableVolumes"
        elif choice == "34":
            print("您选择了 'SystemPolicySysAdminFiles' 服务")
            service = "SystemPolicySysAdminFiles"
        elif choice == "35":
            print("您选择了 'TencentWeibo' 服务")
            service = "TencentWeibo"
        elif choice == "36":
            print("您选择了 'Twitter' 服务")
            service = "Twitter"
        elif choice == "37":
            print("您选择了 'Ubiquity' 服务")
            service = "Ubiquity"
        elif choice == "38":
            print("您选择了 'Willow' 服务")
            service = "Willow"
        else:
            print("无效的选项")
            service = None
    else:
        print("未选择服务，默认选择 'All'")
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
    app_path = get_app_path()
    action = choose_action()
    service = choose_service()
    bundle_ident = get_bundle_identifier(app_path)
    run_tccplus(action,service,bundle_ident)

if __name__ == "__main__":
    main()