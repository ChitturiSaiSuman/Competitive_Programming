for test in range(int(input())):
    n=int(input())
    while n%2==0:
        n//=2
    print(n//2)