import os

path = 'D:\\Coding\\Python\\CH-8\\hello.txt'

#读取文件
helloFile = open(path)
helloContent = helloFile.read()
print(helloContent)

#写入文件
#w 覆盖原内容写入 a 在原内容中添加
baconFile = open('D:\\Coding\\Python\\CH-8\\bacon.txt', 'w')
baconFile.write('Hello World!\n')

baconFile.close()
baconFile = open('D:\\Coding\\Python\\CH-8\\bacon.txt', 'a')
baconFile.write('Bacon is not a vegetable1111\n')

baconFile.close()
baconFile = open('D:\\Coding\\Python\\CH-8\\bacon.txt')
content = baconFile.read()
baconFile.close()
print(content)
