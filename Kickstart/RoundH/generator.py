from random import randint

def generate_input_as_string():
    size = 100
    query = 5*10**4
    names = []
    length = 20
    for i in range(size):
        name = ''.join([chr(randint(65,90)) for ch in range(length)])
        names.append(name)
    string = str(size)+" "+str(query)+'\n'
    string += ' '.join(names)+'\n'
    for i in range(query):
        a,b = randint(1,size),randint(1,size)
        string += str(a)+' '+str(b)+'\n'
    return string

def main():
    test = 100
    with open("input.txt","w") as file:
        file.write(str(test)+'\n')
        for t in range(test):
            string = generate_input_as_string()
            file.write(string)

main()