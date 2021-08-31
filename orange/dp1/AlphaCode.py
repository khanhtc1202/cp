
import sys
sys.setrecursionlimit(20000)

def count(string):
    n = len(string)
    if(n==1):
        dp[n] = 1
        return dp[n]
    if(n==2):
        code_number = int(string)
        if(code_number==10 or code_number==20):
            dp[n] = 1
            return dp[n]
        elif(code_number<=26):
            dp[n] = 2
            return dp[n]
        else:
            dp[n] = 1
            return dp[n]
    elif dp[n]!=0:
        return dp[n]
    else:
        code_number = int(string[:2])
        if(code_number==10 or code_number==20):
            dp[n] = count(string[2:])
            return dp[n]
        elif(code_number<=26):
            if(string[2]=='0'):
                dp[n] = count(string[1:])
            else:
                dp[n] = count(string[1:]) + count(string[2:])
            return dp[n]
        else:
            dp[n] = count(string[1:])
            return dp[n]

results = []
while(1):
    code = input()
    if code == '0':
        break
    dp = [0]*(len(code)+1)
    results.append(count(code))
for result in results:
    print(result)


