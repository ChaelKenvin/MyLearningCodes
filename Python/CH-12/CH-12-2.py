import openpyxl
import os

os.chdir("D:\\Coding\\Python\\CH-12")
wb = openpyxl.load_workbook('example.xlsx')
sheet = wb['Shet1']

#获取行和列
print(tuple(sheet['A1' : 'F3']))

for rowofCellObjects in sheet['A1' : 'F3']:
    for cellobj in rowofCellObjects:
        print(cellobj.coordinate, cellobj.value)
    print('---end of row---')

print(list(sheet.columns)[0])
print(list(sheet.rows)[0])
for obj in list(sheet.columns)[0]:
    print(obj.value)
for obj in list(sheet.rows)[0]:
    print(obj.value)
