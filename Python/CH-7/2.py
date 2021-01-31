import re
# 用管道匹配多个分组
# 匹配多个表达式中的一个

heroRegx = re.compile(r'Batman|Tina Fey')  # 匹配batman或Tina Fey
mo1 = heroRegx.search('Batman and Tina Fey.')
print(mo1.group())

mo2 = heroRegx.search('Tina Fey and Batman')
print(mo2.group())

# 匹配Batman, Batmobile, Batcopter, Batbat中任意一个
batRegx = re.compile(r'Bat(man|mobile|copter|bat)')
mo3 = batRegx.search('Batmobile lost a copter')
print(mo3.group())
print(mo3.group(1))
