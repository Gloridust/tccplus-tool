# import os
import subprocess

app_path = input("input your app path:")

def get_bundle_identifier(app_path):
    command = ["grep", "BundleIdent", "-A", "1", f"{app_path}/Contents/Info.plist"]
    try:
        result = subprocess.run(command, capture_output=True, text=True, check=True)
        # 输出结果
        print(result.stdout)
    except subprocess.CalledProcessError as e:
        print("命令执行失败:", e)


get_bundle_identifier(app_path)
