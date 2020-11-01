from random import randint

def generate_input_as_string():
    size = 10**5
    n = size
    string = str(n)+'\n'
    inputs = [chr(randint(65,90)) for i in range(n)]
    string += ''.join([str(i) for i in inputs])
    return string

def main():
    test = 1
    with open("input.txt","w") as file:
        file.write(str(test)+'\n')
        for t in range(test):
            string = generate_input_as_string()
            file.write(string+"\n")

main()