nk = list(input().split())
n, k = int(nk[0]), float(nk[1])
energy = list(map(float, input().split()))
avg = sum(energy)/len(energy)
while(1):
    sum_lf = 0
    sum_rg = 0
    cnt_lf = 0
    cnt_rg = 0
    lf = []
    flag = False
    for i in range(n):
        if(energy[i]<avg):
            cnt_lf+=1
            sum_lf+=energy[i]
            lf.append(energy[i])
        else:
            cnt_rg+=1
            sum_rg+=energy[i]
    x = (cnt_lf * sum_rg - cnt_rg * sum_lf) / (cnt_rg * (100 - k)/100 + cnt_lf)
    avg = (sum_rg - x)/(cnt_rg)
    for i in range(len(lf)):
        if(lf[i]>avg):
            flag = True
    if(not flag):
        break
print("%.9f" %(avg))
            




