from math import gcd,sqrt,log2,log10,factorial
import heapq
from sys import stdin,stdout
def longestCommonPrefix( a): 
      
    size = len(a) 
  
    # if size is 0, return empty string  
    if (size == 0): 
        return "" 
  
    if (size == 1): 
        return a[0] 
  
    # sort the array of strings  
    a.sort() 
      
    # find the minimum length from  
    # first and last string  
    end = min(len(a[0]), len(a[size - 1])) 
  
    # find the common prefix between  
    # the first and last string  
    i = 0
    while (i < end and 
           a[0][i] == a[size - 1][i]): 
        i += 1
  
    pre = a[0][0: i] 
    return pre 
def common_count(t0, t1):
  "returns the length of the longest common prefix"
  for i, pair in enumerate(zip(t0, t1)):
    if pair[0] != pair[1]:
      return i
  return i

def group_by_longest_prefix(iterable):
  "given a sorted list of strings, group by longest common prefix"
  longest = 0
  out = []

  for t in iterable:
    if out: # if there are previous entries 

      # determine length of prefix in common with previous line
      common = common_count(t, out[-1])

      # if the current entry has a shorted prefix, output previous 
      # entries as a group then start a new group
      if common < longest:
        yield out
        longest = 0
        out = []
      # otherwise, just update the target prefix length
      else:
        longest = common

    # add the current entry to the group
    out.append(t)

  # return remaining entries as the last group
  if out:
    yield out
t=int(input())
counter=1
while t>0:
    n,k=map(int,input().split())
    l=[]
    for _ in range(n):
        s=input()
        l.append(s)
    mystring=""
    for i in l:
        mystring=mystring+" "+i
    T = sorted(i.strip() for i in mystring.split() if i)
    l=[]
    for L in group_by_longest_prefix(T):
        l.extend(L)
    l=sorted(l,reverse=True)
    new_list=[]
    temp=[]
    for i in l:
        temp.append(i)
        if len(temp)==k:
            new_list.append(temp)
            temp=[]
    ans=0
    for i in new_list:
        ans+=len(longestCommonPrefix(i))
    print("Case #%d:"%(counter),ans)
    counter+=1
    t-=1
