from random import randint

def generate_input_as_string():
    size = 10**3
    n = randint(1,size)
    q = randint(1,size)
    inputs = str(n) + " " + str(q) + '\n'
    for i in range(q-1):
        a = randint(1,n)
        b = randint(a,n)
        inputs += str(a) + ' ' + str(b) + '\n'
    a = randint(1,n)
    b = randint(a,n)
    inputs += str(a) + ' ' + str(b)
    # string = ' '.join([str(i) for i in inputs])
    return inputs

def main():
    test = 10**3
    with open("input.txt","w") as file:
        file.write(str(test)+'\n')
        for t in range(test):
            string = generate_input_as_string()
            file.write(string+"\n")

main()