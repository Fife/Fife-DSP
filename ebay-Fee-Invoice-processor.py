import csv
adFees = []
sellerFees = []

def sanitize(tempList):
    del tempList[0:3]
    del tempList[2]
    return tempList

def parseDateRange(tempList):
    tempDateRange = ""
    for entries in tempList[1]:
        tempDateRange += entries
        tempDateRange = tempDateRange.replace('"','')
    return tempDateRange

def parseFees(tempList):
    for entry in tempList[2:-1]:
        if (entry[6] == "Promoted listing fees"):
            adFees.append((entry[0]+entry[1], entry[5], entry[6], entry[-1]))
        else:
            sellerFees.append((entry[0]+entry[1], entry[5], entry[6], entry[-1]))

def generateReport(tempDateRange):
    tempAdTotal=0 
    tempSellerTotal =0
    for entry in adFees: tempAdTotal = tempAdTotal+float(entry[-1])
    for entry in sellerFees: tempSellerTotal = tempSellerTotal+float(entry[-1])
    return (round(tempAdTotal,2), round(tempSellerTotal,2), tempDateRange)

def printReport(tempList):
    print("Total Spent on Ads during "+tempList[2])
    print(tempList[0])
    print("Total Spent on Final value Fees and Insertion Fees during "+tempList[2])
    print(tempList[1])

def fileReader():
    #Writes CSV contents to a list 
    rawList = []
    with open('C:/Users/Fife/Documents/Fife-Electronics/Ebay-Invoices/invoiceId-6069749409.csv', newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=',', quotechar='|')
        for row in reader:
            rawList.append(row)
    return rawList

def main():
    rawList = fileReader()
    sanitizedList = sanitize(rawList)
    dateRange = parseDateRange(sanitizedList)
    parseFees(sanitizedList)
    report = generateReport(dateRange)
    printReport(report)
main()
    


