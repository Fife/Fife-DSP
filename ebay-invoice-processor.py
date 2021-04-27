import csv

rawList = []
sanitizedList = []

with open('C:/Users/Fife/Documents/Fife-Electronics/Ebay-Invoices/invoiceId-6069749409.csv', newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=' ', quotechar='|')
    for row in reader:
        rawList.append(row)


for entries in rawList:
    entries[0] = entries[0].replace('"', '')
    print(entries)
