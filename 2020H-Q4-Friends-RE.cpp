/***********************************************
♡        Filename : 2020H-Q4-Friends.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-12-08 12:00:42
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
const int maxn = 100+20;
const int inf = 1e9;

// 两人人，如果名字里面有相同的字符，则是朋友，否则不是朋友
// 要计算两个朋友之间的最短朋友链（最短距离）
//
// 为了方便查询A点和B点之间的距离，选用floyd最短路径算法
//
// 本代码只能Test1通过。
// 用传统的最短路径算法，则只能Test1通过，Test2不通过。
// 
// 原因：Test2 的数据量较大。
// 1.开这么大的字符串数组，空间不够。
// 2.就算能够开这么大，也一定TLE。
//
//
// 检查两个人是否是朋友
bool check(string a, string b)
{
    int i,j;
    int lena = a.length();
    int lenb = b.length();
    for(i=0; i<lena; i++)
    {
        for(j=0; j<lenb; j++)
        {
            if(a[i] == b[j])
                return true;
        }
    }
    return false;
}
void solve()
{
    int i, j, k;
    string s[maxn];
    // 邻接矩阵
    int matrix[maxn][maxn];
    //memset(matrix, inf, sizeof(matrix));
    int N, Q;
    scanf("%d %d", &N, &Q);
    // 邻接矩阵初始化，所有值都为inf
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            matrix[i][j] = inf;
        }
    }
    for(i=0; i<N; i++)
    {
        cin>>s[i];
    }
    
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            // 如果是朋友，则添加边，邻接矩阵更新值
            if(i!=j && check(s[i], s[j]))
            {
                matrix[i][j] =  1;
            }
            if(i==j)
                matrix[i][j] = 0;
        }
    }
    // floyd算法更新值，计算最短路径
    for(k=0; k<N; k++)
    {
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                if(i!=j && (matrix[i][k] + matrix[k][j] < matrix[i][j]))
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    /*
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            cout<<matrix[i][j]<<"\t";

        }
        cout<<endl;
    }
    */
    
    // 查询矩阵，输出结果
    for(i=0; i<Q; i++)
    {
        scanf("%d %d", &j, &k);
        if(matrix[j-1][k-1] == inf)
            printf("-1 ");
        else
            printf("%d ", matrix[j-1][k-1]+1);
    }
    printf("\n");
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

