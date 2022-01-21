import os, shutil

path = "F:\\My SJTU\\20_暑期\\ACM\\洛谷"

copy_path = "C:\\Users\\14475\\Desktop\\leetcode\\洛谷"
files = os.listdir(path=path)

for file in files:
    file_path = os.path.join(path, file)
    if os.path.isdir(file_path):
        for cpp in os.listdir(path=file_path):
            if os.path.splitext(cpp)[1] == ".cpp":
                new_name = str(file)
                new_name = new_name[:new_name.find(' ')] + ".cpp"
                new_name = os.path.join(copy_path, new_name)
                shutil.copyfile(os.path.join(file_path, cpp), new_name)
                print(new_name)      
print("FINISH")