
while True :
  a = input()
  stack = []
  
  if a == '.' :
    break
  
  for j in a :
    if j == '(' or j == '[' :
      stack.append(j)
    elif j == ')' :
      if len(stack) != 0 and stack[-1] == '(':
        stack.pop()
      else :
        stack.append(j)
        break
    elif j == ']' :
      if len(stack) != 0 and stack[-1] == '[':
        stack.pop()
      else :
        stack.append(j)
        break

   
  if len(stack) == 0 :
    print("yes")
  else :
    print("no")