results = []

def find_exchange(x):
    if(x<=6):
        return x
    elif(x in dictionary):
        return dictionary[x]
    else:
        sum = find_exchange(x//2)+find_exchange(x//3)+find_exchange(x//4)
        if(sum>x):
            dictionary[x] = sum
            return sum
        else:
            dictionary[x] = x
            return x


while(1):
    try:
        n = input()
    except EOFError:
        break
    if(len(n)==0):
        break
    n = int(n)
    dictionary = {}
    money = find_exchange(n)
    results.append(money)

for result in results:
    print(result)
