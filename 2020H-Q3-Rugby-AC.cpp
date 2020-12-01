/***********************************************
♡        Filename : 2020H-Q3-Rugby.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-12-01 13:28:20
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;


// 感觉像是考数学思维的一道题，反正看完题没有想到怎么做
// 官方的题解是：
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff49/000000000043b027#analysis
//
// x和y轴分开计算，计算每个人最终的理想x和理想y。
//
// 首先看y，最终所有的人要移动到同一行上，因此所有人都是垂直移动。
// 通过证明可以得到，如果理想的y是所有y的中位数，则垂直移动的总步数是最优的。
//
// 接下来看x，移动后保持原来的X轴从小到大顺序，可以保证总移动次数最少
// 那每个人的理想x应该是多少呢？
// 对于每个人，他前面有i个人，如果第一个人firstx的位置是x-i，则他将不需要移动
// 每个人都有一个理想的firstx, 分别是x0-0, x1-1, x2-2, x3-3...
// 则最优的firstx应该是所有的firstx的中位数
// 知道了最优的第一个人的位置，则后面所有人的位置也就知道了
const int maxn = 1e5+20;

int x[maxn];
int y[maxn];
long long solve()
{
    int N;
    memset(x, 0, sizeof(0));
    memset(y, 0, sizeof(0));
    int i, mid;
    int firstx, midy;
    long long ansx = 0;
    long long ansy = 0;

    scanf("%d", &N);
    for(i=0; i<N; i++)
        scanf("%d %d", &x[i], &y[i]);
    
    sort(x, x+N);

    // 每个人的理想firstx
    for(i=0; i<N; i++)
        x[i] -= i;

    
    sort(x, x+N);
    sort(y, y+N); 

    mid = N/2;

    // 第一个人的理想x位置
    // 每个人的理想y位置
    firstx = x[mid]; 
    midy = y[mid];
    for(i=0; i<N; i++)
    {
        ansx += abs(x[i]-firstx);
        ansy += abs(y[i]-midy);
    }
    return ansx+ansy;
}
int main()
{
    int t, T;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        printf("Case #%d: %lld\n", t, solve());
    }
}
