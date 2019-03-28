# system config
import sys
limit = 2000
sys.setrecursionlimit(limit)
# code start here
import time
import random

def seed_sorted_arr(size, min_value):
    arr = []
    counter = 0
    while counter < size:
        arr.append(min_value + counter)
        counter += 1
    return arr

def seed_rand_arr(size, max_value):
    arr = []
    counter = 0
    while counter < size:
        arr.append(random.randint(0, max_value))
        counter += 1
    return arr

def sum_forward(arr):
    sum = 0
    for x in arr:
        sum += x
    return sum

def count_DaC(arr):
    if len(arr) == 1:
        return 1
    return 1 + count_DaC(arr[1:])

def binary_search(arr, key):
    low = 0
    high = len(arr) - 1
    while low <= high:
        mid = (low + high) / 2
        if arr[mid] == key:
            return mid
        if arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def sum_DaC(arr):
    if len(arr) == 1:
        return arr[0]
    return arr[0] + sum_DaC(arr[1:])

def max_value_DaC(arr):
    if len(arr) == 1:
        return arr[0]
    return max(arr[0], max_value_DaC(arr[1:]))

def quick_sort(arr):
    if len(arr) < 2:
        return arr
    pivot = arr[0]
    less, greater = [], []
    for i in arr[1:]:
        less.append(i) if i <= pivot else greater.append(i)
    return quick_sort(less) + [pivot] + quick_sort(greater)

def merge_stage(left, right):
    arr = []
    left_index, right_index = 0, 0
    while left_index < len(left) and right_index < len(right):
        if left[left_index] <= right[right_index]:
            arr.append(left[left_index])
            left_index += 1
        else:
            arr.append(right[right_index])
            right_index += 1
    # load remain part
    while left_index < len(left):
        arr.append(left[left_index])
        left_index += 1
    while right_index < len(right):
        arr.append(right[right_index])
        right_index += 1
    return arr

def merge_sort(arr):
    if len(arr) < 2:
        return arr
    mid = len(arr) / 2
    return merge_stage(merge_sort(arr[:mid]), merge_sort(arr[mid:]))

def run_time(func, print_output, *args):
    start_time = time.time()
    out = func(*args)
    end_time = time.time()
    if print_output: print out
    return end_time - start_time

def main():
    random_value_arr = seed_rand_arr(500000, 10000)
    # print("Time taken by DaC %f" % (run_time(sum_DaC, True, random_value_arr)))
    # print("Time taken by Loop %f" % (run_time(sum_forward, True, random_value_arr)))
    # print("Time taken by DaC %f" % (run_time(count_DaC, True, random_value_arr)))
    # sorted_arr = seed_sorted_arr(10, 0)
    # print("Time taken by Binary %f" % (run_time(binary_search, True, sorted_arr, 9)))
    # print("Time taken by DaC %f" % (run_time(max_value_DaC, True, sorted_arr)))
    print("Time taken by DaC quick sort %f" % (run_time(quick_sort, False, random_value_arr)))
    print("Time taken by DaC merge sort %f" % (run_time(merge_sort, False, random_value_arr)))

if __name__ == "__main__":
    main()