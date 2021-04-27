import csv

rawList = []
sanitizedList = []
adFees = []
sellerFees = []
adTotal = 0

#Writes CSV contents to a list 
with open('C:/Users/Fife/Documents/Fife-Electronics/Ebay-Invoices/invoiceId-6069749409.csv', newline='') as csvfile:
    reader = csv.reader(csvfile, delimiter=',', quotechar='|')
    for row in reader:
        rawList.append(row)

def sanitize(tempList):
    del tempList[0:6]
    return tempList

sanitizedList = sanitize(rawList)
for entry in sanitizedList:
    if (entry[6] == "Promoted listing fees"):
        adFees.append((entry[0]+entry[1], entry[5], entry[6], entry[-1]))
    else:
        1+1 #toDo: Add Seller Fees Logic

for entry in adFees: adTotal = adTotal+float(entry[-1])
print(adTotal)
    
