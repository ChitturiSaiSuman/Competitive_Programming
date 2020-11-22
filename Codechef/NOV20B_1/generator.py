from random import randint

def generate_input_as_string():
    size = 20
    n = randint(1,size)
    k = randint(0,size)
    chars = ["I","_","M",":","X"]
    inputs = [chars[randint(0,4)] for i in range(n)]
    string = str(n)+' '+str(k)+'\n'+''.join([str(i) for i in inputs])
    return string

def main():
    test = 20
    with open("input.txt","w") as file:
        file.write(str(test)+'\n')
        for t in range(test):
            string = generate_input_as_string()
            file.write(string+"\n")

main()