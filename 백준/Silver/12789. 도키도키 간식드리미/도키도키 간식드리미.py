import sys
n = int(input())
stack = []

a = list(map(int,sys.stdin.readline().split()))

number = 1

for i in a :
  stack.append(i)

  while stack and stack[-1] == number :
    stack.pop()
    number += 1
    

if stack :
  print("Sad")
else :
  print("Nice")