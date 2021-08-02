T = int(input())
results = []
for i in range(T):
    N, M = map(int, input().split())
    binM = bin(M)
    binM = binM[2:]
    ans = ''
    bin_len = len(binM)
    for i, bit in enumerate(binM):
        if(bit=='1'):
            num_exp = bin_len - 1 - i
            string= "(" + str(N) + "<<" + str(num_exp) + ")"
            if(ans==''):
                ans+=string
            else:
                ans+=" + " + string
    results.append(ans)
for result in results:
    print(result)

