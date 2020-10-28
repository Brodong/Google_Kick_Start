#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int main()
{
    int T,t,N,n,B,temp;
    int maxx;
    int cost[100000];
    scanf("%d", &T);
    for(t=0; t<T; t++)
    {
        scanf("%d", &N);
        scanf("%d", &B);
        for(n=0; n<N; n++)
        {
            scanf("%d", &temp);
            cost[n] = temp;
        }
        sort(cost, cost+N);
        maxx = 0;
        for(n=0; n<N; n++)
        {
            if(cost[n]<=B)
            {
                maxx += 1;
                B -= cost[n];
            }
            else
                break;
        }
        printf("Case #%d: %d\n", t+1, maxx);
    }
    
    return 0;
}
