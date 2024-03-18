import sys
from collections import deque

n,k = map(int,sys.stdin.readline().split())
list = []
que = deque()

for i in range(1,n+1) :
  que.append(i)

for i in range(n) :
  que.rotate(-k+1)
  list.append(que.popleft())

print("<",end="")
print(*list,sep=", ",end="")
print(">")