#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TUPLE_SIZE  sizeof(int)*2

void print_an_array( int **degs, int n ){
    int i;
    for (i=0; i < n; i++) {
        printf("(%d, %d) ", degs[i][0], degs[i][1]);     
    }
    printf("\n");
}
static inline int sort(int **degs, int n){
    insertion_sort(degs, 0, n);
}

int insertion_sort( int **degs, int i, int n){
    int j;
    int swap;
    int *val;
    val = malloc( TUPLE_SIZE );
    if ( i==n ){
        return;
    } else {
        if( i == 0 )
            goto out;
        memcpy(val,degs[i], TUPLE_SIZE); // Trying to place this.
        for(j=i; j>0; j--) {
            if ( val[1] > degs[j-1][1] ){
                memcpy(degs[j],degs[j-1], TUPLE_SIZE); //Shift up
            } else {
                memcpy(degs[j], val, TUPLE_SIZE);
                break;
            }
        }
        if( j==0 ){
            memcpy(degs[j], val, TUPLE_SIZE);
        }
    }
out:
    insertion_sort( degs, i+1, n);
}

int do_tree(int **degs, int n){
    sort(degs, n);
    if( n==2 ){ 
        printf("(%d, %d) ",degs[0][0], degs[1][0]);
        return;
    }
    // Tail recursion FTW.
    degs[0][1] -= 1;
    printf("(%d, %d) ",degs[0][0], degs[n-1][0]);
    do_tree( degs, n-1 );
}


int main( int argc, char **degs ){
    int **a1;
    int i;
    int n;
    if (argc != 2) {
        printf("usage: ./tree <valid tree string>\nExample:\n./tree 2421111\n./tree 1113131\n./tree 322111\n");
        return;
    }
    n = strlen(degs[1]);
    a1 = malloc(sizeof(int *)*n);
    for( i = 0; i < n; i++ ) {
       a1[i] = malloc(TUPLE_SIZE);
       a1[i][0] = i;
       a1[i][1] = (int)degs[1][i] - 48;
    }
    printf("=== The Tree ===\n");
    do_tree( a1, n );
    printf("\n");
}

