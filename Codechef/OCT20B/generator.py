from random import randint

def generate_input_as_string():
    pass

def main():
    test = 100000
    size = 100
    with open("input.txt","w") as file:
        file.write(str(test)+'\n')
        for t in range(test):
            string = str(randint(1,size))
            file.write(string+"\n")
main()