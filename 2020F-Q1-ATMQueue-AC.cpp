/***********************************************
♡        Filename : 2020F-Q1-ATMQueue.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-11-30 18:59:38
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;


// 计算每个人需要排队多少次
// 然后排队少的先离开
// 如果两个人排队次数相同，则序号小的先离开
struct people{
    int label;  //序号
    int cnts;   //排队次数
};

bool cmp(struct people a, struct people b)
{
    // 如果排队次数相同，则序号小的在前
    if(a.cnts == b.cnts)
        return a.label<b.label;
    return a.cnts<b.cnts;
}

const int maxn = 1e5+20;
void solve()
{
    int N,X;
    scanf("%d %d", &N, &X);
    struct people p[maxn];
    memset(p, 0, sizeof(p));
    int i;
    for(i=0; i<N; i++)
    {
        scanf("%d", &p[i].label);
        if(p[i].label%X == 0)
            p[i].cnts = p[i].label/X;
        else
            p[i].cnts = p[i].label/X+1;
        p[i].label = i+1;
    }
    sort(p, p+N, cmp);
    for(i=0; i<N-1; i++)
    {
        printf("%d ", p[i].label);
    }
    printf("%d\n", p[N-1].label);
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
