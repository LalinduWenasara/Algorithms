arr = [6, 54, 5, 125, 222, 113, 0]

def bubbleSort(arr):
    n = len(arr)
    for x in range(n-1):
        for i in range(0, n-x-1):
            if arr[i] > arr[i + 1] :
                arr[i], arr[i + 1] = arr[i + 1], arr[i]


bubbleSort(arr)
print ("Sorted array ")
for x in range(len(arr)):
    print ("% d" % arr[x]),