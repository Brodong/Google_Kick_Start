/***********************************************
♡        Filename : 2020F-Q2-MetalHarvest.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-12-10 20:46:40
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;


// 题目给出了一系列任务的开始时间和结束时间
// 然后机器人可以在区间[x,x+k]工作
// 问最少需要启动多少次机器人，则可以做完所有的任务
//
// 思路：
// 1.首先按照任务开始时间排序，然后从1时刻开始放置机器人
// 2.计算当前区间需要多少个机器人，维护时刻的右端点
// 3.判断后面的任务有没有覆盖，如果没有覆盖，则从后面任务的左端点开始放置机器人。
//   如果有覆盖，则从覆盖的时刻开始，继续放置机器人。维护右端点即可。
const int maxn = 1e5+20;
typedef struct period{
    int start, end;
}period;

bool cmp(struct period a, struct period b)
{
    return a.end<b.end;
}

void solve()
{
    period p[maxn];
    int N, K;
    int i, j;
    int ans = 0;
    int R = 0;
    int num = 0;
    memset(p, 0, sizeof(p));
    scanf("%d %d", &N, &K);
    for(i=0; i<N; i++)
    {
        scanf("%d %d", &p[i].start, &p[i].end);
    }
    sort(p, p+N, cmp);
    /*
    for(i=0; i<N; i++)
    {
        cout<<p[i].start<<" "<<p[i].end<<endl;
    }
    */

    for(i=0; i<N; i++)
    {
        // 没有覆盖后面任务
        if(p[i].start>=R)
        {
            num = (p[i].end - p[i].start);
            num = ceil(double(num)/(double)K);
            R = p[i].start + num*K;
            ans += num;
        }
        // 全部覆盖
        else if(p[i].end<=R)
        {}
        // 部分覆盖
        else
        {
            num = (p[i].end - R);
            num = ceil(double(num)/(double)K);
            R = R + num*K;
            ans += num;
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
