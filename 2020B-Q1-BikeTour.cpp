#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define maxN 100

// 直接遍历
//
int main()
{
    int t,T;
    int N,n;
    int height[maxN];
    int cnt = 0;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        cnt = 0;
        memset(height, 0, sizeof(height));
        scanf("%d", &N);
        for(n=0; n<N; n++)
        {
            scanf("%d", &height[n]);
        }
        for(n=1; n<N-1; n++)
        {
            if(height[n]>height[n-1] && height[n]>height[n+1])
            {
                cnt++;
            }
            
        }
        printf("Case #%d: %d\n", t, cnt);
    }
    
    /* std::cout << "Hello world" << std::endl; */
    return 0;
}

