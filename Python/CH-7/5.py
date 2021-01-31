import re
# 用花括号匹配特定次数

haRegx = re.compile(r'(Ha){3}')
mo1 = haRegx.search('HaHaHa')
print(mo1.group())

mo2 = haRegx.search('Ha')
print(mo2 == None)
