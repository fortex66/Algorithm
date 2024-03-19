import sys
from collections import deque

# 명령의 수 입력 받기
n = int(input())

que = deque()

for i in range(n) :
  # n개의 줄에 명령어 입력 받기
  order = list(map(int,sys.stdin.readline().split()))

  if order[0] == 1 :
    que.appendleft(order[1])
  elif order[0] == 2 :
    que.append(order[1])
  elif order[0] == 3 :
    if len(que) > 0 :
      print(que.popleft())
    else :
      print(-1)
  elif order[0] == 4 :
    if len(que) > 0 :
      print(que.pop())
    else :
      print(-1)
  elif order[0] == 5 :
    print(len(que))
  elif order[0] == 6 :
    if que :
      print(0)
    else :
      print(1)
  elif order[0] == 7 :
    if len(que) > 0 :
      print(que[0])
    else :
      print(-1)
  elif order[0] == 8 :
    if len(que) > 0 :
      print(que[-1])
    else :
      print(-1)