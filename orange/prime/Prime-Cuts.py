def sieveEratosthenes(n):
    mark = [True] * (n+1)
    primes = []
    mark[0] = mark[1] = False
    for i in range(2, int(n**0.5) + 1):
        if mark[i] == True:
            for j in range(i*i, n+1, i):
                mark[j] = False
    for i in range(2, n+1):
        if mark[i] == True:
            primes.append(i)
    return primes

results = []
while(1):
    try:
        inputs = list(map(int, input().split()))
    except EOFError:
        break
    if(len(inputs)==0):
        break
    number, c = inputs[0], inputs[1]
    primes = sieveEratosthenes(number)
    primes = [1] + primes
    n = len(primes)
    if(n % 2 == 1):
        idx_1 = (n-1)//2 + 1 - c
        idx_2 = (n-1)//2 + c - 1
        if(idx_1<0):
            results.append([number, c, primes])
        else:
            # print(n, idx_1, idx_2, primes[idx_1:(idx_2+1)])
            results.append([number, c, primes[idx_1:(idx_2+1)]])
    else:
        idx_1 = n//2 - c
        idx_2 = n//2 + c - 1 
        if(idx_1<0):
            results.append([number, c, primes])
        else:
            results.append([number, c, primes[idx_1:(idx_2+1)]])
for i, result in enumerate(results):
    print(str(result[0])+" "+str(result[1])+": ", end='')
    for prime in result[2]:
        print(prime, end=' ')
    if i!=len(results)-1:
        print("\n")

    
