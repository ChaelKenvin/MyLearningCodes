import PyPDF2
import os

os.chdir('D:\\Coding\\Python\\CH-13')

pdfFileObj = open('meetingminutes.pdf', 'rb')
pdfReader = PyPDF2.PdfFileReader(pdfFileObj)
print(pdfReader.numPages)  # 获得pdf的页数

pageObj = pdfReader.getPage(1)  # 获得页数 0为第一页
print(pageObj.extractText())  # 获取该页面的文本
