from sys import stdin,stdout # For Fast IO

size = 2*10**6+3 # Maximum Value of (X+Y)
mod=10**9+7
# Precalculation of Factorials
fact=[1]*(size)
for i in range(1,size):
    fact[i]=(fact[i-1]*i)%mod

# One liner for nCr mod p using Fermat's Principle
ncr_mod_p = lambda n,r: (fact[n]*pow(fact[r],mod-2,mod)*pow(fact[n-r],mod-2,mod))%mod

inputs = list(map(str,stdin.read().split("\n"))) # Scan all inputs at once
t = int(inputs[0])
answer = "" # Empty String to store outputs
for i in range(1,t+1):
    x,y,x1,y1,x2,y2=map(int,inputs[i].split()) # coordinates of the Wormhole and two Black Holes
    total = ncr_mod_p(x+y,x) # number of ways to reach the Wormhole from the origin, owing to the movement constraint
    q1 = ncr_mod_p(x1+y1,x1) # number of ways to reach the first black hole from the origin
    rx=(x-x1)
    ry=(y-y1)
    q2=0
    w2=0
    h1=0
    if rx>=0 and ry>=0: # this condition ensures that you follow the movement constraint, i.e. you can only move in the positive direction of any axis, not negative.
        q2 = ncr_mod_p(x-x1+y-y1,x-x1) # number of ways to reach the Wormhole from the first black hole
    p1=q1*q2 # number of ways to reach the Wormhole, form the the origin, through the first black hole 
    sx= x-x2
    sy= y-y2
    w1= ncr_mod_p(x2+y2,x2) # number of ways to reach second black hole from the origin
    if sx>=0 and sy>=0: # this condition ensures that you follow the movement constraint, i.e. you can only move in the positive direction of any axis, not negative.
        w2= ncr_mod_p(x-x2+y-y2,x-x2) # number of ways to reach the Wormhole from the second black hole
    p2=w1*w2 # number of ways to reach the Wormhole, form the the origin, through the second black hole
    cx=x2-x1
    cy=y2-y1
    if cx>=0 and cy>=0: # this condition ensures that you follow the movement constraint, i.e. you can only move in the positive direction of any axis, not negative.
        h1= ncr_mod_p(x2-x1+y2-y1,x2-x1)#  number of ways to reach the second black hole from the first black hole
    add=q1*h1*w2 # number of ways to reach the Wormhole from the origin through both the black holes, i.e. from origin to the first black hole, from the first black hole to the second black hole, and from the second black hole to the Wormhole
    total=total-p1-p2+add # using the principle of inclusion and exclusion
    total=total%(10**9+7)
    answer=answer+str(total)+'\n'
stdout.write(answer)