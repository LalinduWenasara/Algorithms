
def ternarySearch(l, r, key, ar):
    while r >= l:

        mid1 = l + (r - l) // 3
        mid2 = r - (r - l) // 3

        if key == ar[mid1]:
            return mid1
        if key == mid2:
            return mid2

        if key < ar[mid1]:

            r = mid1 - 1
        elif key > ar[mid2]:

            l = mid2 + 1
        else:

            l = mid1 + 1
            r = mid2 - 1


    return -1


ar = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]


l = 0


r = 9


key = 5

p = ternarySearch(l, r, key, ar)

print("Index of", key, "is", p)

key = 50

p = ternarySearch(l, r, key, ar)


print("Index of", key, "is", p)
