
def search(arr, d, y):
    for m in range(0, d):
        if (arr[m] == y):
            return m;
    return -1;

arr = [4, 8, 26, 30, 13];
p = 30;
k = len(arr);
result = search(arr, k, p)
if (result == -1):
    print("Element is not present in array")
else:
    print("Element is present at index", result);