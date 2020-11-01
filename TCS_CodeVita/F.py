"""
4 7 1
2 8 7
6 3 5
5 8 3
3 1 6
9 4 2
5 2 4
3 7 8
5 1 9
6 1 4
9 4 8
2 5 7
7 9 1
1 9 6
6 2 8
8 6 3
7 2 5
3 9 4
D F2 R' U
"""
def transpose(M):
    for i in range(3):
        for j in range(3):
            if i<j:
                M[i][j],M[j][i]=M[j][i],M[i][j]
    #print(M)
def mirror(M):
    for i in range(3):
        M[i][0],M[i][2]=M[i][2],M[i][0]
    #print(M)
def rotate(M):
    transpose(M)
    mirror(M)
D=[]
for i in range(3):
    D.append(list(map(int,input().split())))
U=[]
for i in range(3):
    U.append(list(map(int,input().split())))
L=[]
for i in range(3):
    L.append(list(map(int,input().split())))
F=[]
for i in range(3):
    F.append(list(map(int,input().split())))
R=[]
for i in range(3):
    R.append(list(map(int,input().split())))
B=[]
for i in range(3):
    B.append(list(map(int,input().split())))

s=list(map(str,input().split()))

def perform_D():
    global D,U,L,F,R,B
    rotate(D)
    temp=L[2]
    L[2]=B[2]
    B[2]=R[2]
    R[2]=F[2]
    F[2]=temp

def perform_U():
    global D,U,L,F,R,B
    rotate(U)
    temp=L[0]
    L[0]=F[0]
    F[0]=R[0]
    R[0]=B[0]
    B[0]=temp
def perform_L():
    global D,U,L,F,R,B
    rotate(L)
    rotate(B)
    rotate(B)
    temp1,temp2,temp3=U[0][0],U[1][0],U[2][0]
    U[0][0],U[1][0],U[2][0]=B[0][0],B[1][0],B[2][0]
    B[0][0],B[1][0],B[2][0]=D[0][0],D[1][0],D[2][0]
    D[0][0],D[1][0],D[2][0]=F[0][0],F[1][0],F[2][0]
    F[0][0],F[1][0],F[2][0]=temp1,temp2,temp3
    rotate(B)
    rotate(B)
def perform_F():
    global D,U,L,F,R,B
    rotate(F)
    temp1,temp2,temp3=L[0][2],L[1][2],L[2][2]
    L[0][2],L[1][2],L[2][2]=D[0][0],D[0][1],D[0][2]
    D[0][0],D[0][1],D[0][2]=R[2][0],R[1][0],R[0][0]
    R[2][0],R[1][0],R[0][0]=U[2][2],U[2][1],U[2][0]
    U[2][2],U[2][1],U[2][0]=temp1,temp2,temp3
def perform_R():
    global D,U,L,F,R,B
    rotate(R)
    temp1,temp2,temp3=F[0][2],F[1][2],F[2][2]
    F[0][2],F[1][2],F[2][2]=D[0][2],D[1][2],D[2][2]
    rotate(B)
    rotate(B)
    D[0][2],D[1][2],D[2][2]=B[0][2],B[1][2],B[2][2]
    B[0][2],B[1][2],B[2][2]=U[0][2],U[1][2],U[2][2]
    U[0][2],U[1][2],U[2][2]=temp1,temp2,temp3
    rotate(B)
    rotate(B)
def perform_B():
    global D,U,L,F,R,B
    rotate(B)
    temp1,temp2,temp3=U[0][0],U[0][1],U[0][2]
    U[0][0],U[0][1],U[0][2]=R[0][2],R[1][2],R[2][2]
    R[0][2],R[1][2],R[2][2]=D[2][2],D[2][1],D[2][0]
    D[2][2],D[2][1],D[2][0]=L[2][0],L[1][0],L[0][0]
    L[2][0],L[1][0],L[0][0]=temp1,temp2,temp3
for i in s:
    if i=='D':
        perform_D()
    elif i=='U':
        perform_U()
    elif i=='L':
        perform_L()
    elif i=='F':
        perform_F()
    elif i=='R':
        perform_R()
    elif i=='B':
        perform_B()
    elif i=="D'":
        perform_D()
        perform_D()
        perform_D()
    elif i=="U'":
        perform_U()
        perform_U()
        perform_U()
    elif i=="L'":
        perform_L()
        perform_L()
        perform_L()
    elif i=="F'":
        perform_F()
        perform_F()
        perform_F()
    elif i=="R'":
        perform_R()
        perform_R()
        perform_R()
    elif i=="B'":
        perform_B()
        perform_B()
        perform_B()
    elif i=="D2":
        perform_D()
        perform_D()
    elif i=="U2":
        perform_U()
        perform_U()
    elif i=="L2":
        perform_L()
        perform_L()
    elif i=="F2":
        perform_F()
        perform_F()
    elif i=="R2":
        perform_R()
        perform_R()
    elif i=="B2":
        perform_B()
        perform_B()
for i in range(3):
    print(*D[i])
print()
for i in range(3):
    print(*U[i])
print()
for i in range(3):
    print(*L[i])
print()
for i in range(3):
    print(*F[i])
print()
for i in range(3):
    print(*R[i])
print()
for i in range(3):
    print(*B[i])