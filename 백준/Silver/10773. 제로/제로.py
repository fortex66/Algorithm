import sys

n = int(input())

stack = []

for i in range(n) :
  data = int(sys.stdin.readline())
  if data == 0 :
    stack.pop()
  else :
    stack.append(data)

print(sum(stack))
    