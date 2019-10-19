q = int(input())
for i in range(0, q):
    n = int(input())
    max = -999999999
    index = 0
    arr = []
    line = input().split(" ")
    for x in line:
        arr.append(int(x))
    for j in range(0, n):
        if arr[j] > max:
            max = arr[j]
            index = j
    flag = 0
    flag2 = True
    for j in range(index, index + n - 1):
        j = j % n
        if arr[j] > arr[(j + 1) % n]:
            flag = 1
        else:
            flag2 = False
            break
    if flag2:
        print("YES")
        continue
    flag = 0
    flag2 = True
    o = 1
    j = index
    while o < n:
        if arr[j] > arr[j - 1]:
            flag = 1
        else:
            flag2 = False
            break
        j -= 1
        o += 1
    if flag2:
        print("YES")
    else:
        print("NO")
