import sys
from collections import deque

n = int(input())

que = deque()

for i in range(n) :
  data = sys.stdin.readline().split()
  if(data[0] == "push") :
    que.append(data[1])
  elif(data[0] == "pop") :
    if len(que) < 1 :
      print(-1)
    else :
      print(que.popleft())
  elif(data[0] == "size") :
    print(len(que))
  elif(data[0] == "empty") :
    if len(que) < 1 :
      print(1)
    else :
      print(0)
  elif(data[0] == "front") :
    if len(que) < 1 :
      print(-1)
    else :
      print(que[0])
  elif(data[0] == "back") :
    if len(que) < 1 :
      print(-1)
    else :
      print(que[-1])