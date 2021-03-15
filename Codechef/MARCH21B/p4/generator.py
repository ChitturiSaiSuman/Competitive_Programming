"""
Author: Chitturi Sai Suman
Created: 2021-03-05 14:47:06
"""
from random import randint

def generate_input_as_string():
    size = 20
    n = randint(2,size)
    inputs = [randint(1, size) for i in range(n)]
    string = str(n) + '\n' + ' '.join(str(i) for i in inputs)
    return string

def main():
    test = 10
    with open("in.in","w") as file:
        file.write(str(test)+'\n')
        for t in range(test):
            string = generate_input_as_string()
            file.write(string+"\n")

main()