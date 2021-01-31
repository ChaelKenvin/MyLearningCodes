import os
import zipfile

# zipfile处理压缩文件

os.chdir('D:\\Coding')

# 获取zip文件
examplezip = zipfile.ZipFile('testzip.zip')

# 打印zip文件的内容
print(examplezip.namelist())

# 获取其中一个文件的大小
spamInfo = examplezip.getinfo('mydata.dat')
print(spamInfo.file_size)

# 计算压缩的效率
print('Compressed file is %sx smaller!' % (round(spamInfo.file_size / spamInfo.compress_size, 2)))

examplezip.close()

# 解压缩
examplezip2 = zipfile.ZipFile('testzip.zip')
# examplezip2.extractall()#原地解压，不创建文件夹
# examplezip2.extractall('textzip')#原地解压到文件夹中
examplezip2.extractall('Python\\textzip')  # 解压到其他路径
examplezip2.extractall('D:\\textzip')  # 解压到其他路径

examplezip2.close()

# 创建压缩包
newZip = zipfile.ZipFile('new.zip', 'w')#压缩包名
newZip.write('VSproject', compress_type=zipfile.ZIP_DEFLATED)#压缩包路径
newZip.close()
