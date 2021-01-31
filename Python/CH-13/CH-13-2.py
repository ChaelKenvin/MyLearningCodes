import PyPDF2
import os

#解密pdf

os.chdir('D:\\Coding\\Python\\CH-13')

pdfReader = PyPDF2.PdfFileReader(open('encrypted.pdf', 'rb'))
print(pdfReader.isEncrypted)

# print(pdfReader.getPage(0))

print(pdfReader.decrypt('rosebud'))

print(pdfReader.getPage(0))