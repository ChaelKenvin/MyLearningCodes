import re

phoneNumRegex = re.compile(r'\d\d\d-\d\d\d-\d\d\d\d')
mo1 = phoneNumRegex.search('My number is 415-555-4242')
print('Phone number found: ' + mo1.group())  # 415-555-4242

phoneNumRegex = re.compile(r'(\d\d\d)-(\d\d\d)-(\d\d\d\d)')
mo2 = phoneNumRegex.search('My number is 415-555-4242')
print('Phone number found: ' + mo2.group(1))
print('Phone number found: ' + mo2.group(2))
print('Phone number found: ' + mo2.group(3))
print('Phone number found: ' + mo2.group(0))
print('Phone number found: ' + mo2.group())
print(mo2.groups())

phoneNumRegex = re.compile(r'(\d\d\d)-(\d\d\d-\d\d\d\d)')
mo3 = phoneNumRegex.search('My number is 415-555-4242')
areaCode, mainNumber = mo3.groups()
print("areaCode: " + areaCode)
print("mainNumber: " + mainNumber)

phoneNumRegex = re.compile(r'(\(\d\d\d\)) (\d\d\d-\d\d\d\d)')
mo3 = phoneNumRegex.search('My number is (415) 555-4242')
print(mo3.group(1))
print(mo3.group(2))
