import sys
from collections import deque
input = sys.stdin.readline

# 명령의 수 입력 받기
n = int(input())

que = deque(enumerate(map(int, input().split())))

result = []


while que :
  index, number = que.popleft()
  result.append(index+1)

  if number > 0 :
    que.rotate(-(number-1))
    
  else :
    que.rotate(-number)
   

print(*result)