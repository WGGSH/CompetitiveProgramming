import math
import itertools

def C(n,k):
  return int(math.factorial(n) / (math.factorial(k)*math.factorial(n-k)))

N = int(input())
condition1=1
for i in range(N):
  condition1*=4

condition2=C(N,3)
condition3=condition2*(N-1)

answer=condition1-condition2-condition3

print(answer)
