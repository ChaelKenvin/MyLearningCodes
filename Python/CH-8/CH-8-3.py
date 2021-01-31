import shelve

shelfFile = shelve.open('mycats')
cats = ['Zophie', 'Pooka', 'Simon']
shelfFile['cats'] = cats
shelfFile.close()

print(type(shelfFile))
# print(shelfFile['cats'])
shelfFile.close()