import re
# 用问号实现可选匹配

batRegx = re.compile(r'Bat(wo)?man')  # wo是可选的分组,匹配?之前的分组零次或一次
mo1 = batRegx.search('The Adventures of Batman')
print(mo1.group())

mo2 = batRegx.search('The Adventures of Batwoman')
print(mo2.group())

phoneRegx = re.compile(r'(\d\d\d-)?\d\d\d-\d\d\d\d')
mo3 = phoneRegx.search('My number is 415-555-4242')
print(mo3.group())

mo4 = phoneRegx.search('My number is 555-4242')
print(mo4.group())
