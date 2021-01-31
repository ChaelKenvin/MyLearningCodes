import shutil, os, send2trash
#复制文件和文件夹

#Change the current working directory to the specified path.
# os.chdir('D:\\Coding\\Python')

#复制文件 copy(​src, dst​)
# shutil.copy('D:\\Coding\\Python\\test1.py', 'D:\\Coding')
# shutil.copy('D:\\Coding\\Python\\CH-9\\CH-9-1.py', 'D:\\Coding\\test1.py')

#移动文件 move(​src, dst​)
# shutil.move('D:\\Coding\\test1.py', 'D:\\Coding\\Python')

#永久删除文件和文件夹
#os.unlink(path)删除path处的文件
#os.rmdir(path)删除path处的空文件夹
#shutil.rmtree(path)删除path处的文件夹，包含其中的所有文件和文件夹

#删除文件和文件夹到回收站 send2trash模块
baconFile = open('D:\\Coding\\bacon.txt', 'a')
baconFile.write('Hello world\n')
baconFile.close()
send2trash.send2trash('D:\\Coding\\bacon.txt')

