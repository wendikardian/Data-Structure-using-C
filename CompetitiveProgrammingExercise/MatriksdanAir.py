def checkTumpah(column, rowLength, matriks):
    count = 0;
    for i in range(rowLength):
        if matriks[column-1][i] == 0:
            count+= 1
    if(count == rowLength):
        return 0
    else :
        return 1

def checkTumpah2(lastRow, column, matriks):
    count = 0
    for i in range(column):
        if(matriks[i][lastRow-1] == 1):
            count += 1
    
    if(count == column):
        return 1;

def checkTumpah3(row, column, matriks):
    for i in range(row):
        if matriks[0][i] == 0:
            return 0
    for i in range(column):
        if matriks[column-1][i] == 0:
            return 0
    
    return 1;


# column = int(input())
# row = int(input())
column, row = map(int, input().split())

matriks = [[0]*column for _ in range(row)]

inputColumn = 0
inputRow = 0


while True:
    inputColumn, inputRow = map(int, input().split())
    # inputColumn = int(input())
    # inputRow = int(input())
    matriks[inputColumn-1][inputRow-1] = 1
    if(inputColumn == column and inputRow == row):
        break

totalAir = 0
if(checkTumpah2(row,column,matriks) == 1):
    if(checkTumpah3(row,column,matriks) == 1):
        for i in range(column):
            for j in range(row):
                if(matriks[i][j] == 0):
                    totalAir += 1
        print(totalAir)
    else :
        print(0)
else:
    countLubang = 0
    for i in range(column):
        result = checkTumpah(i, row, matriks)
        if(result == 0):
            print("0")
            break
        else :
            countLubang += 1
    if countLubang == column:
        if(checkTumpah3(row,column,matriks) == 1):
            for i in range(column):
                for j in range(row):
                    if(matriks[i][j] == 0):
                        totalAir += 1
            print(totalAir)
        else :
            print(0)
# print(matriks)
# print(checkTumpah(2, row, matriks))
# print(checkTumpah2(row, column, matriks))
