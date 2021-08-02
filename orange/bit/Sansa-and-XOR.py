T = int(input())
results = []
for i in range(T):
    n = int(input())
    numbers = list(map(int, input().split()))
    xorvalue = 0
    for k in range(1, n+1):
        if(k<=(n//2)):
            num_appear = k*(n-2*k)
        else:
            h = n+1-k
            num_appear = h*(n-2*h)
        if(num_appear%2!=0):
            xorvalue = xorvalue ^ numbers[k-1]
    results.append(xorvalue)
for result in results:
    print(result)

