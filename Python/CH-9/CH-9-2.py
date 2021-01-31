import os

#walk遍历目录树

for foldername, subfolders, filenames in os.walk('D:\\Coding\\Python'):
    print('The current folder is: ' + foldername)

    for subfolder in subfolders:
        print('SUBFOLDER OF ' + foldername + ': ' + subfolder)
    for filename in filenames:
        print('FILE INSIDE ' + foldername + ': ' + filename)