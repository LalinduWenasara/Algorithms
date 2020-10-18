
def binarySearch(arr, l, e, x):
    if e >= l:
        mid = l + (e - l) / 2

        if arr[mid] == x:
            return mid

        if arr[mid] > x:
            return binarySearch(arr, l,
                                mid - 1, x)

        return binarySearch(arr, mid + 1, e, x)


    return -1

def exponentialSearch(arr, n, x):

    if arr[0] == x:
        return 0


    i = 1
    while i < n and arr[i] <= x:
        i = i * 2


    return binarySearch(arr, i / 2,
                        min(i, n - 1), x)



arr = [2, 3, 4, 10, 40]
n = len(arr)
x = 10
result = exponentialSearch(arr, n, x)
if result == -1:
    print
    "Element not found in thye array"
else:
    print
    "Element is present at index %d" % (result)

