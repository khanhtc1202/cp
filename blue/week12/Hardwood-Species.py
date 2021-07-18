num_test = int(input())
results = ""
string=input()
for i in range(num_test):
    string = '--'
    dict_trees = {}
    sum = 0
    while(1):
        try:
            string=input()
        except EOFError:
            break
        if(string==''):
            break
        if(not string in dict_trees):
            dict_trees[string] = 0
        dict_trees[string]+=1
        sum+=1
    for key in dict_trees:
        dict_trees[key] = dict_trees[key]/sum * 100
    for key in sorted(dict_trees):
        result_string = key + " " + "{:.4f}".format(dict_trees[key]) + "\n"
        results+=result_string
print(results)
