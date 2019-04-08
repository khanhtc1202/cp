import time, random

def recursion_way(arr, total, i):
    if total == 0:
        return 1
    elif total < 0:
        return 0
    elif i < 0:
        return 0
    elif total < arr[i]:
        return recursion_way(arr, total, i-1)
    else:
        return recursion_way(arr, total - arr[i], i-1) + recursion_way(arr, total, i-1)

def dp_way(arr, total, i, memo):
    key = str(total) + ":" + str(i)
    if key in memo:
        return memo[key]
    if total == 0:
        return 1
    elif total < 0:
        return 0
    elif i < 0:
        return 0
    elif total < arr[i]:
        value = dp_way(arr, total, i-1, memo)
    else:
        value = dp_way(arr, total - arr[i], i-1, memo) + dp_way(arr, total, i-1, memo)
    memo[key] = value
    return value

def run_time(func, print_output, *args):
    start_time = time.time()
    out = func(*args)
    end_time = time.time()
    if print_output: print out
    return end_time - start_time

def seed_rand_arr(size, max_value):
    arr = []
    counter = 0
    while counter < size:
        arr.append(random.randint(0, max_value))
        counter += 1
    return arr

def main():
    memo = {}
    arr = seed_rand_arr(50, 10)
    total = 16
    print("Time taken by recursion %f" %(run_time(recursion_way, True, arr, total, len(arr) - 1)))
    print("Time taken by dp %f" %(run_time(dp_way, True, arr, total, len(arr) - 1, memo)))

if __name__ == "__main__":
    main()