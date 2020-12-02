/***********************************************
♡        Filename : 2020G-Q2-MaximumCoins.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-12-01 22:01:20
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
using namespace std;


// 只能是在斜下方方向对角线行走，遇到边界停止。
// 则对所有的可能情况进行计算，然后取最大值即可
const int maxn = 1e3+20;

void solve()
{
    int N;
    int num[maxn][maxn];
    memset(num, 0, sizeof(num));
    int i, j;
    long long ans=0;
    map<int, long long> mp;
    scanf("%d", &N);
    
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d", &num[i][j]);
            mp[i-j] = mp[i-j]+num[i][j];
            long long temp = mp[i-j];
            ans = max(ans, temp);
        }
    }
    printf("%lld\n", ans);
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
