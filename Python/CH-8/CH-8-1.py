import os

#用反斜杠连接，创建文件名称的字符串
print(os.path.join('usr', 'bin', 'spam'))

myFiles = ['accounts.txt', 'details.txt', 'invite.txt']
for filename in myFiles:
    print(os.path.join('C:\\users\\aswergart', filename))

#os.makedirs()创建新文件夹
# os.makedirs('D:\\Coding2\\filename2')#没有同名文件夹才会创建

#返回参数的绝对路径的字符串
print(os.path.abspath('.'))

#是绝对路径返回True
print(os.path.isabs('.\\CH-8-1.py'))
print(os.path.isabs('D:\\Coding\\Python\\CH-8\\CH-8-1.py'))

#返回从start到path的相对路径的字符串
#如果没有start，就使用当前工作目录作为开始路径
print(os.path.relpath('C:\\Windows', 'C:\\'))
print(os.path.relpath('D:\\Coding', 'D:\\Coding\\Python\\CH-8\\CH-8-1.py'))

print(os.getcwd())

#dirname(path)返回path最后一个斜杠之前的所有内容
#basename(path)返回path最后一个斜杠之后的所有内容
path = 'D:\\Coding\\Python\\CH-8\\CH-8-1.py'
print(os.path.dirname(path))
print(os.path.basename(path))

#split(path)分离一个路径的目录名称和基本名称
print(os.path.split(path))
print(os.path.dirname(path), os.path.basename(path))

#getsize返回路径中文件的字节数
print(os.path.getsize(path))

#listdir返回文件名字符串的列表
# print(os.listdir('C:\\Windows\\System32'))
print(os.listdir('D:\\Coding\\Python'))

#exits检测路径的文件或文件夹是否存在
print(os.path.exists('C:\\Windows\\System32'))
print(os.path.exists('C:\\Windows\\Systemm32'))

#isfile检测路径是否是一个文件
print(os.path.isfile('C:\\Windows\System32'))
print(os.path.isfile(path))

#isdir检测路径是否是一个文件夹
print(os.path.isdir('C:\\Windows\System32'))
print(os.path.isdir(path))