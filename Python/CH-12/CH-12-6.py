import openpyxl

import os

# 图表

os.chdir("D:\\Coding\\Python\\CH-12")

wb = openpyxl.Workbook()
sheet = wb[wb.sheetnames[0]]

for i in range(1, 11):
    sheet['A' + str(i)].value = i

# refObj = openpyxl.chart.Reference(sheet, (1, 1), (10, 1))
refObj = openpyxl.chart.Reference(sheet, min_row = 1, min_col = 1, max_row = 10, max_col = 1)

seriesObj = openpyxl.chart.Series(refObj, title='First Series')

charObj = openpyxl.chart.BarChart()
charObj.title = 'MyChart'
charObj.append(seriesObj)
# charObj.drawing.top = 50  # set position
# charObj.drawing.left = 100
# charObj.drawing.right = 300  # set the size
# charObj.drawing.height = 200

sheet.add_chart(charObj, 'C5')
wb.save('chart.xlsx')
