"""
Author: Chitturi Sai Suman
Created: 2021-02-05 18:39:47
"""
from random import randint

def generate_input_as_string():
    size = 2 * 10**4
    n = size
    inputs = []
    for i in range(n):
        s = ''.join([chr(randint(97, 122)) for j in range(20)])
        inputs.append(s)
    string = str(n) + '\n' + ' '.join(inputs)
    return string

def main():
    test = 1
    with open("in.in","w") as file:
        file.write(str(test)+'\n')
        for t in range(test):
            string = generate_input_as_string()
            file.write(string+"\n")

main()