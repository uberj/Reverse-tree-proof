#!/bin/python
import random
import sys
from tree import tree
import time

def build_degs(n):
    degs = [1]*n
    while(reduce(lambda x,y: x+y, degs) != 2*(n-1)):
        degs[random.randint(0,n-1)] += 1
    return degs

def time_fun( fun, n ):
    degs = build_degs(n)
    start = time.time()
    fun(degs)
    stop = time.time()
    return (n, stop-start)

def analysis(n):
    # Set to zero
    results = []
    for i in range(2,n):
        data= time_fun(tree,i)
        results.append(data)
    return results

if __name__=='__main__':
    data = analysis(int(sys.argv[1]))
    for n, t in data:
        print str(n)+"  "+str(t)
