from collections import Counter
from itertools import product
num = list(zip(*[[int(k) for k in input().split()] for i in range(int(input()))]))
AB = Counter(map(sum, product(*num[:2])))
print(sum(AB[-c-d] for c,d in product(*num[2:])))