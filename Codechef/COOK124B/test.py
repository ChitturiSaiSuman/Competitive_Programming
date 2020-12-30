from itertools import permutations
from random import randint
l = [3,25,29,389]

for i in range(100):
    temp = [i for i in l]
    while len(temp)>2:
        ind1 = randint(0,len(temp)-1)
        val1 = temp.pop(ind1)
        ind2 = randint(0,len(temp)-1)
        val2 = temp.pop(ind2)
        temp.append(val1 * val2)
        # while ind1==ind2:
        #     ind2 = randint(0,len(temp)-1)
    print(sum(temp)==1892)