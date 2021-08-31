N = int(input())
K = int(input())

dp = [0]*(N+1)

def num_Kvalid(n, k):
    if n==1:
        dp[n] = k-1
        return dp[n]
    if n==2:
        dp[n] = (k-1)*(num_Kvalid(n-1, k) + 1)
        return dp[n]
    if dp[n]!=0:
        return dp[n]
    else:
        dp[n] = (k-1)*(num_Kvalid(n-1, k) + num_Kvalid(n-2, k))
        return dp[n]

print(num_Kvalid(N, K)) 
