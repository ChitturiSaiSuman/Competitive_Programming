from random import randint

def generate_input_as_string():
    size = 10**6
    n = randint(2,size)
    x = randint(2,size)
    string = str(x) + ' ' + str(n)
    return string

def main():
    test = 100000
    with open("input.txt","w") as file:
        file.write(str(test)+'\n')
        for t in range(test):
            string = generate_input_as_string()
            file.write(string+"\n")

main()