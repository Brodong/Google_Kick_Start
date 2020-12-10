/***********************************************
♡        Filename : 2020E-Q2-HighBuildings.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-12-10 10:23:53
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
int solve()
{
    int N, A, B, C;
    int res;
    int i,j;
    scanf("%d %d %d %d", &N, &A, &B, &C);
    A = A-C;
    B = B-C;
    res = N-C-A-B;
    if((N-C<A+B) || (A==0 && B==0 && C==1 && res>0))
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    else if(A==0 && B==0 && C>1 && res>0)
    {
        printf("%d ", N);
        for(i=0; i<res; i++)
            printf("%d ", N-1);
        for(i=0; i<C-1; i++)
            printf("%d ", N);
        printf("\n");
        return 0;
    }
    else 
    {
        for(i=0; i<A; i++)
            printf("%d ", N-1);

        if(A>0 && res>0)
        {
            for(i=0; i<res; i++)
                printf("%d ", N-2);
            res = 0;
        }

        for(i=0; i<C; i++)
            printf("%d ", N);

        if(B>0 && res>0)
        {
            for(i=0; i<res; i++)
                printf("%d ", N-2);
            res = 0;
        }

        for(i=0; i<B; i++)
            printf("%d ", N-1);

        printf("\n");
        return 0;
    }
}
int main()
{
    int t, T;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        printf("Case #%d: ", t);
        solve();
    }
}

