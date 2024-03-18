from collections import deque

n = int(input())

que = deque()

for i in range(n,0,-1) :
  
  que.append(i)

for i in range(n) :
  if len(que) == 1 :
    print(que[0])
  else :
    que.pop()
    back = que.pop()
    que.appendleft(back)
