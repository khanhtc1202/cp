import math
n, s = map(int, input().split())
add_s = 1000000-s
dictionary = {}
for i in range(n):
    x, y, k = map(int, input().split())
    dictionary[(x, y)] = (math.sqrt(x**2 + y**2), k)
dictionary = {k: v for k, v in sorted(dictionary.items(), key=lambda item: item[1])}
count = 0
far_city = -1
for city in dictionary:
    count+=dictionary[city][1]
    if(count>=add_s):
        far_city = city
        break
if(far_city==-1):
    print(-1)
else:
    print(dictionary[far_city][0])
