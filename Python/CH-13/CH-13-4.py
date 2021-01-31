import PyPDF2
import os

# 旋转页面

os.chdir('D:\\Coding\\Python\\CH-13')

minutesFile = open('meetingminutes.pdf', 'rb')
pdfReader = PyPDF2.PdfFileReader(minutesFile)

page = pdfReader.getPage(0)
page.rotateClockwise(90)

pdfWriter = PyPDF2.PdfFileWriter()
pdfWriter.addPage(page)

resulePdfFile = open('rotatePage.pdf', 'wb')
pdfWriter.write(resulePdfFile)
resulePdfFile.close()
minutesFile.close()