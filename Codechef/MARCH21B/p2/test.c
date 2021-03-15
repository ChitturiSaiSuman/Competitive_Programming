/*
Author: Chitturi Sai Suman
Created: 2021-03-05 14:47:06
*/
#include <stdio.h>
#include <math.h>

static inline int max(int a, int b) {
    return a>b?a:b;
}


int solve(int c) {
    int ans = 0;
    for(int i = 0; i < 1<<(((int)(log2(c))) + 1); i++)
        ans = max(ans, i * (i^c));
    return ans;
}

int main() {
    for(int c = 1; c < 1000; c ++) {
        // if((c & (c-1)) == 0)
            printf("%d\n", solve(c));
        
    }
}