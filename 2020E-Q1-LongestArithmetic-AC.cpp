/***********************************************
♡        Filename : 2020E-Q1-LongestArithmetic.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-11-30 13:59:14
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

// 直接遍历即可
void solve()
{
    int N;
    int pre, next;
    int i;
    int ans=-1;
    int cnt=0;
    int temp1, temp2;
    scanf("%d", &N);
    scanf("%d", &pre);
    scanf("%d", &next);
    temp1 = next-pre;
    pre = next;
    cnt ++;
    ans = max(ans, cnt);
    for(i=2; i<N; i++)
    {
        scanf("%d", &next);
        temp2 = next-pre;
        if(temp2 == temp1)
            cnt++;
        else
        {
            cnt = 1;
            temp1 = temp2;
        }
        pre = next;
        ans = max(ans, cnt);
    }
    printf("%d\n", ans+1);
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
