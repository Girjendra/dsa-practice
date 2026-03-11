def solve(n):
    lst =[]
    while n > 0:
        bit = 1 & n
        lst.append(bit)
        n = n >> 1
    
    while len(lst) < 32:
        lst.append(0)
    
    ans = 0
    k = 0
    for i in range(len(lst)-1,-1,-1):
        ans = lst[i]*pow(2, k)
        k += 1

    return ans

n = 462221
print(solve(n))