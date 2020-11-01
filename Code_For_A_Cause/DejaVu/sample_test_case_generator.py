from random import randint
def solve(n,s1,s2,x):
    res=0
    flag=1
    p=bin(n).replace("0b","")
    l=len(p)
    answer = [None,None]
    for j in range(l):
        if p[j]=='1':
            res+=1
        else:
            if res&1:
                answer[0] = s1
                flag=0
                break
            else:
                res=0
    if flag==1:
        if s1=='Karthik':
            answer[0] = "Suman"
        else:
            answer[0] = "Karthik"
    if n%(x+1)==0:
        if s2=='Karthik':
            answer[1] = "Suman"
        else:
            answer[1] = "Karthik"
    else:
        answer[1] = s2
    return answer
input_file=open("sample_input.txt","w")
output_file=open("sample_output.txt","w")
test_cases = 5
input_file.write(str(test_cases)+'\n')
players = ["Karthik","Suman"]
for test in range(test_cases):
    n = randint(1,10)
    x = randint(1,n)
    input_file.write(str(n)+'\n')
    s1 = players[randint(0,1)]
    input_file.write(s1+'\n')
    s2 = players[randint(0,1)]
    input_file.write(s2+' ')
    input_file.write(str(x)+'\n')
    answer1,answer2 = solve(n,s1,s2,x)
    output_file.write(answer1+'\n'+answer2+'\n')
input_file.close()
output_file.close()