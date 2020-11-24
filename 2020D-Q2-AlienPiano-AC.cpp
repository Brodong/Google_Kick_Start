/***********************************************
♡        Filename : 2020D-Q2-AlienPiano.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-11-24 19:17:59
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


// 直接遍历，连续上升5个或者连续下降5个即为一个打破
// 连续上升5个则有4个小于号
// if(cnt_up ==4)则ans加1
// 连续下降同理。
//
const int maxN = 1e4+20;
int num[maxN];
void solve()
{
    memset(num, 0, sizeof(num));
    int i,N;
    int cnt_up = 0;
    int cnt_down = 0;
    scanf("%d", &N);
    scanf("%d", &num[0]);
    int ans = 0;
    for(i=1; i<N; i++)
    {
        scanf("%d", &num[i]);
        if(num[i]>num[i-1])
        {
            cnt_up ++;
            cnt_down = 0;
        }
        else if(num[i]<num[i-1])
        {
            cnt_down ++;
            cnt_up = 0;
        }

        if(cnt_up == 4)
        {
            cnt_up = 0;
            cnt_down = 0;
            ans ++;
        }

        if(cnt_down == 4)
        {
            cnt_down = 0;
            cnt_up = 0;
            ans ++;
        }
    }
    printf("%d\n", ans);
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
