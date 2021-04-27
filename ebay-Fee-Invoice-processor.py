import csv

def sanitize(tempList):
    newList = []
    for item in tempList: newList.append(item)
    del newList[0:3]
    del newList[2]
    return newList

def parseDateRange(tempList):
    tempDateRange = ""
    for entries in tempList[1]:
        tempDateRange += entries
        tempDateRange = tempDateRange.replace('"','')
    return tempDateRange

def parseFees(tempList):
    adFees = []
    sellerFees = []
    for entry in tempList[2:-1]:
        if (entry[6] == "Promoted listing fees"):
            adFees.append((entry[0]+entry[1], entry[5], entry[6], entry[-1]))
        else:
            sellerFees.append((entry[0]+entry[1], entry[5], entry[6], entry[-1]))
    return (adFees, sellerFees)

def generateReport(tempDateRange, tempFeeList):
    tempAdTotal=0 
    tempSellerTotal =0
    for entry in tempFeeList[0]: tempAdTotal = tempAdTotal+float(entry[-1])
    for entry in tempFeeList[1]: tempSellerTotal = tempSellerTotal+float(entry[-1])
    return (round(tempAdTotal,2), round(tempSellerTotal,2), tempDateRange)

def printReport(tempList):
    print("Total Spent on Ads during "+tempList[2])
    print(tempList[0])
    print("Total Spent on Final value Fees and Insertion Fees during "+tempList[2])
    print(tempList[1])

def CSVToList(filePath):
    #Writes CSV contents to a list 
    rawList = []
    with open(filePath, newline='') as csvfile:
        reader = csv.reader(csvfile, delimiter=',', quotechar='|')
        for row in reader:
            rawList.append(row)
    return rawList

def main():
    filePath = 'C:/Users/Fife/Documents/Fife-Electronics/Ebay-Invoices/invoiceId-6069749409.csv'
    rawList = CSVToList(filePath)
    sanitizedList = sanitize(rawList)
    dateRange = parseDateRange(sanitizedList)
    feeList = parseFees(sanitizedList)
    report = generateReport(dateRange, feeList)
    printReport(report)
main()
