import sys
import pdb
from operator import itemgetter

def tree( degs ):
    i_degs = []
    for i in range(len(degs)):
        i_degs.append((i, degs[i]))
    return do_tree( i_degs , len(i_degs))

def do_tree( degs, n ):
    degs = sorted(degs, key=itemgetter(1), reverse=True)
    graph = []
    if len(degs) == 2:
        return [(degs[0][0],degs[1][0])]
    else:
        degs[0] = (degs[0][0], degs[0][1] - 1)
        graph.append((degs[0][0],degs[n-1][0]))
        return graph+(do_tree(degs[:-1], n-1))

if __name__ == "__main__":
    a1 = [3,3,1,1,1,1]
    a2 = [3,2,2,1,1,1]
    print tree(a1)

