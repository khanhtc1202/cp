N = int(input())
A = list(map(int, input().split()))
X = int(input())
sumA = sum(A)
num_in = X//sumA
rest_in = X % sumA

num_A = 0
    
if rest_in == 0:
    print(num_in*len(A)+1)
else:
    num_A += num_in*len(A)
    value = 0
    is_ok = False
    for i in range(len(A)):
        value+=A[i]
        if value > rest_in:
            num_A += (i+1)
            is_ok = True
            break
    print(num_A)
