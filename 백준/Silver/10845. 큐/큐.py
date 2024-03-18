import sys
from queue import Queue

n = int(input())

que = Queue()

for i in range(n) :
  data = sys.stdin.readline().split()
  if(data[0] == "push") :
    que.put(data[1])
  elif(data[0] == "pop") :
    if que.qsize() < 1 :
      print(-1)
    else :
      print(que.get())
  elif(data[0] == "size") :
    print(que.qsize())
  elif(data[0] == "empty") :
    if que.qsize() < 1 :
      print(1)
    else :
      print(0)
  elif(data[0] == "front") :
    if que.qsize() < 1 :
      print(-1)
    else :
      print(que.queue[0])
  elif(data[0] == "back") :
    if que.qsize() < 1 :
      print(-1)
    else :
      print(que.queue[-1])
