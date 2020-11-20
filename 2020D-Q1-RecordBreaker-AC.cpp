/***********************************************
#
#      Filename: 2020D-Q1-RecordBreaker.cpp
#
#        Author: Li Xudong - 757264690@qq.com
#   Description: ---
#        Create: 2020-11-18 16:00:24
# Last Modified: 2020-11-18 16:00:24
#
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
const int maxN = 2e5+20;
int visitor[maxN];

void solve()
{
    int N;
    memset(visitor, 0, sizeof(visitor));
    int i,maxn,cnt;
    scanf("%d", &N);
    for(i=0; i<N; i++)
    {
        scanf("%d", &visitor[i]);
    }
    maxn = -1;
    cnt = 0;
    for(i=0; i<N; i++)
    {
        if(visitor[i]>maxn)
        {
            maxn = visitor[i];
            if(i==N-1)
                cnt++;
            else
            {
                if(visitor[i]>visitor[i+1])
                    cnt++;
            }
        }
    }
    printf("%d\n", cnt);
}
int main()
{
    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}

