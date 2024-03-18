import sys

# n = int(sys.stdin.readline())

n = int(input())

stack = [] 

for i in range(n) :
  data = sys.stdin.readline().split()
  if(data[0] == "push") :
    stack.append(data[1])
  if(data[0] == "pop") :
    if len(stack) < 1 :
      print("-1")
    else :
      print(stack.pop())
  elif(data[0] == "size") :
      print(len(stack))
  elif(data[0] == "empty") :
    if len(stack) < 1 :
      print("1")
    else :
      print("0")
  elif(data[0] == "top") :
    if len(stack) < 1 :
      print("-1")
    else :
      print(stack[-1])
    