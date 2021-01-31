import re
#贪心和非贪心匹配

greedyHaRegx = re.compile(r'(Ha){3, 5}')
mo1 = greedyHaRegx.search('HaHaHaHaHa')
print(mo1.group())

# mo2 = greedyRegx.search('')