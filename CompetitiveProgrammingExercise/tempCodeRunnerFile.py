for i in range(1, total):
    result= checkForFreeSwap(arrayword[0], arrayword[1])
    if(result == True):
        totalFreeSwap +=1

print(totalFreeSwap)