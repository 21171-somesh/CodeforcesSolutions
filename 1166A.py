import operator as op
from functools import reduce
import math
 
 
def ncr(n, r):
    if n < r:
        return 0
    r = min(r, n - r)
    numer = reduce(op.mul, range(n, n - r, -1), 1)
    denom = reduce(op.mul, range(1, r + 1), 1)
    return numer / denom
 
 
dic = {}
n = int(input())
for i in range(0, n):
    x = input()
    if x[0] not in dic:
        dic[x[0]] = 1
    else:
        dic[x[0]] += 1
ans = 0
for key in dic.keys():
    if dic[key] > 2:
        ans += ncr(math.ceil(dic[key] / 2), 2) + ncr(math.floor(dic[key] / 2), 2)
print(int(ans))
