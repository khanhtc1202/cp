def insertion_sort(arr):
    for i in range(1, len(arr)):
        sortingItem = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > sortingItem:
            # move item that bigger than sorting item to next index
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = sortingItem

arr = [19, 30, 1, 7, 3, 6, 0, 20]
insertion_sort(arr)
print(arr)