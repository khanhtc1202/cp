
def convert_K_base(number, k):
    number = str(number)
    n = len(number)
    converted = 0
    for i in range(n):
        converted += int(number[n-i-1])*(k**i)
    return converted


K = int(input())
A, B = map(int, input().split())
decA = convert_K_base(A, K)
decB = convert_K_base(B, K)
print(decA*decB)

