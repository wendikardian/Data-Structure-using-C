def split(word):
    return [char for char in word]


def checkForFreeSwap(str1, str2):
    len1 = len(str1)
    len2 = len(str2)

    if(len1 != len2):
        return False; #artinya tidak freeswap
    
    if(len1 != len2):
        char_seen = []
        for char in str1:
            if char not in char_seen:
                char_seen.append(char)
        if len(char_seen) < len(str1):
            return True;
        return False;

    prev = -1
    curr =-1
    count = 0
    i=0
    while i < len1: 
        if(str1[i] != str2[i]):
            count+= 1
            if count > 2:
                return False
            
            prev = curr
            curr = i
        i = i+1
    
    return (count == 2 and str1[prev] == str2[curr] and str1[curr] == str2[prev])
    

# print(checkForFreeSwap("wendi", "wnedi"))

total = int(input())
arrayword = []
for i in range(total):
    word = input().lower()
    arrayword.append(word)



# totalOfFreeSwap = 0
# MaxtotalOfFreeSwap = 0
# for i in range(1,total):
#     for j in range(0,total):
#         result = checkForFreeSwap(arrayword[i], arrayword[j])
#         if(result == True):
#             totalOfFreeSwap += 1
#     if totalOfFreeSwap > MaxtotalOfFreeSwap:
#         MaxtotalOfFreeSwap = totalOfFreeSwap
#     totalOfFreeSwap = 0  
# print(MaxtotalOfFreeSwap)

totalFreeSwap = 0
for i in range(1, total):
    result= checkForFreeSwap(arrayword[0], arrayword[1])
    if(result == True):
        totalFreeSwap +=1

print(totalFreeSwap)

