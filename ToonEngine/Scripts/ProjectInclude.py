import inspect
import os
import sys
from shutil import copyfile
from Utils import get_all_files, pickout_list_with_keyword

def main(target_project_name, keyword):
    current_path = os.path.dirname(os.path.abspath(
        inspect.getfile(inspect.currentframe())))
    root_path = os.path.join(current_path, "..")
    imgui_path = os.path.join(root_path, "Libraries/imgui")
    imgui_impl_path = os.path.join(imgui_path, "examples")
    target_path = os.path.join(root_path, target_project_name + "/imgui")
	
	# Check resource dir exists, if doesnt exists create one.
    if not os.path.exists(target_path) : os.makedirs(target_path)

    common_files = get_all_files(imgui_path, ["h", "cpp"])
    impl_files = get_all_files(imgui_impl_path, ["h", "cpp"])
    impl_files = pickout_list_with_keyword(impl_files, keyword)

    for file in common_files:
        src = os.path.join(imgui_path, file)
        dst = os.path.join(target_path, file)
        copyfile(src, dst)

        with open(dst, "r+") as f:
            content = f.read()
            f.seek(0, 0)
            f.write('#include "stdafx.h"' + '\n' + content)

    for file in impl_files:
        src = os.path.join(imgui_impl_path, file)
        dst = os.path.join(target_path, file)
        copyfile(src, dst)

        with open(dst, "r+") as f:
            content = f.read()
            f.seek(0, 0)
            f.write('#include "stdafx.h"' + '\n' + content)

    print("Including imgui sources to project Complete!")

if __name__ == "__main__" :
    if len(sys.argv) != 3:
        print("Usage: python ProjectInclude.py [target project name] [keyword related to graphics library]")
    else:
        main(sys.argv[1], sys.argv[2])
