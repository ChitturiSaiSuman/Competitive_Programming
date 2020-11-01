import math
t=int(int(input()))
for i in range(t):
    x,y,x1,y1,x2,y2=map(int,input().split())# coordinates of the Wormhole
    total = (math.factorial(x+y))//((math.factorial(x))*(math.factorial(y)))# number of ways to reach the Wormhole from the origin, owing to the movement constraint
    z=total
    q1 = (math.factorial(x1+y1))//((math.factorial(x1))*(math.factorial(y1)))# number of ways to reach the first black hole from the origin
    rx=(x-x1)
    ry=(y-y1)
    q2=0
    w2=0
    h1=0
    if rx>=0 and ry>=0: # this condition ensures that you follow the movement constraint, i.e. you can only move in the positive direction of any axis, not negative.
        q2 = (math.factorial(rx+ry))//((math.factorial(rx))*(math.factorial(ry)))# number of ways to reach the Wormhole from the first black hole
    p1=q1*q2# number of ways to reach the Wormhole, form the the origin, through the first black hole 
    sx= x-x2
    sy= y-y2
    w1= (math.factorial(x2+y2))//((math.factorial(x2))*(math.factorial(y2)))# number of ways to reach second black hole from the origin
    if sx>=0 and sy>=0: # this condition ensures that you follow the movement constraint, i.e. you can only move in the positive direction of any axis, not negative.
        w2= (math.factorial(sx+sy))//((math.factorial(sx))*(math.factorial(sy)))# number of ways to reach the Wormhole from the second black hole
    p2=w1*w2# number of ways to reach the Wormhole, form the the origin, through the second black hole
    cx=x2-x1
    cy=y2-y1
    if cx>=0 and cy>=0: # this condition ensures that you follow the movement constraint, i.e. you can only move in the positive direction of any axis, not negative.
        h1= (math.factorial(cx+cy))//((math.factorial(cx))*(math.factorial(cy)))#  number of ways to reach the second black hole from the first black hole
    add=q1*h1*w2 # number of ways to reach the Wormhole from the origin through both the black holes, i.e. from origin to the first black hole, from the first black hole to the second black hole, and from the second black hole to the Wormhole
    total=total+add-(p1+p2) # using the principle of inclusion and exclusion
    print(total%(10**9+7))