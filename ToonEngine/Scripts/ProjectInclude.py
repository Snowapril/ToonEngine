import inspect
import os
from shutil import copyfile
from Utils import get_all_files

def main():
    current_path = os.path.dirname(os.path.abspath(
        inspect.getfile(inspect.currentframe())))
    root_path = os.path.join(current_path, "..")
    imgui_path = os.path.join(root_path, "Libraries/imgui")
    target_path = os.path.join(root_path, "ToonEditor/imgui")
	
	# Check resource dir exists, if doesnt exists create one.
    if not os.path.exists(target_path) : os.makedirs(target_path)

    files = get_all_files(imgui_path, ["h", "cpp"])
    
    for file in files:
        src = os.path.join(imgui_path, file)
        dst = os.path.join(target_path, file)
        copyfile(src, dst)

        with open(dst, "r+") as f:
            content = f.read()
            f.seek(0, 0)
            f.write('#include "stdafx.h"' + '\n' + content)

    print("Including imgui sources to project Complete!")

if __name__ == "__main__" :
    main()
