for test in range(int(input())):
    n = int(input())
    x_list = []
    y_list = []
    x_sum = 0
    y_sum = 0
    x_square_sum = 0
    y_square_sum = 0
    for i in range(n):
        x,y = map(int,input().split())
        x_list.append(x)
        y_list.append(y)
        x_sum +=x
        y_sum +=y
        x_square_sum+=x*x
        y_square_sum+=y*y
    dist = []
    for i in range(n):
        temp = (n-1)*x_list[i]*x_list[i]
        temp += (n-1)*y_list[i]*y_list[i]
        temp -= (2*x_list[i]*(x_sum-x_list[i]))
        temp -= (2*y_list[i]*(y_sum-y_list[i]))
        temp += (x_square_sum-x_list[i]*x_list[i])
        temp += (y_square_sum-y_list[i]*y_list[i])
        dist.append(temp)
    ind = 0
    for i in range(n):
        if dist[i]<dist[ind]:
            ind = i
    print(x_list[ind],y_list[ind])