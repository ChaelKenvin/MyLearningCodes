import openpyxl
from openpyxl .styles import Font

import os

# 调整行和列

os.chdir("D:\\Coding\\Python\\CH-12")

wb = openpyxl.Workbook()
sheet = wb[wb.sheetnames[0]]

sheet['A1'] = 'Tail row'
sheet['B2'] = 'Wide column'

sheet.row_dimensions[1].height = 70
sheet.column_dimensions['B'].width = 20

wb.save('dimensions.xlsx')