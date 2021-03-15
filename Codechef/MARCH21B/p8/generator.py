"""
Author: Chitturi Sai Suman
Created: 2021-03-05 14:47:06
"""
from random import randint

def generate_input_as_string():
    size = 500
    n = size
    inputs = [2**(randint(0, 10)) * (randint(1, 1000) % 2) for i in range(n)]
    return str(n) + '\n' + ' '.join(str(i) for i in inputs)

def main():
    test = 100
    with open("in.in","w") as file:
        file.write(str(test)+'\n')
        for t in range(test):
            string = generate_input_as_string()
            file.write(string+"\n")

main()