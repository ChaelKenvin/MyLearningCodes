import re
# 用加号匹配一次或多次

batRegx = re.compile(r'Bat(wo)+man')
mo1 = batRegx.search('The Adventures of Batman')  # 0
print(mo1 == None)

mo2 = batRegx.search('The Adventures of Batwoman')  # 1
print(mo2.group())

mo3 = batRegx.search('The Adventures of Batwowowowowowoman')  # many
print(mo3.group())
