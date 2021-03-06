/***********************************************
♡        Filename : 2020H-Q4-Friends.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-12-09 10:31:14
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


// 用传统的最短路径算法，只能test1通过，test2会超时
// 最终还是采用了官方给的解决方法
// 
// 总体思想是 求一个点到另一个点的最短距离 转换为 求一个集合到另一个集合的最短距离
//
// 即，将名字拆分成每一个字母。然后两个字母有边当且仅当两个字母存在于同一个名字当中。
// 之后按照floyd算法计算两个字母之间的最短距离。计算得到邻接矩阵。
//
// 下面是第一个测试集的邻接矩阵
/*
  A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 
A 0 1 - 1 2 - - 1 1 - 2 1 - 1 1 - - 2 - 1 2 2 - - 2 2 
B 1 0 - 1 2 - - 1 2 - 2 2 - 1 1 - - 2 - 2 2 2 - - 2 3 
C - - 0 - - - - - - - - - - - - - - - - - - - - - - - 
D 1 1 - 0 2 - - 1 2 - 2 2 - 1 1 - - 2 - 2 2 2 - - 2 3 
E 2 2 - 2 0 - - 2 1 - 1 1 - 1 2 - - 3 - 2 3 1 - - 3 1 
F - - - - - 0 - - - - - - - - - - - - - - - - - - - - 
G - - - - - - 0 - - - - - - - - - - - - - - - - - - - 
H 1 1 - 1 2 - - 0 2 - 2 2 - 1 1 - - 2 - 2 2 2 - - 2 3 
I1 2 - 2 1 - - 2 0 - 1 1 - 1 2 - - 3 - 1 3 1 - - 3 1 
J - - - - - - - - - 0 - - - - - - - - - - - - - - - - 
K 2 2 - 2 1 - - 2 1 - 0 2 - 1 2 - - 3 - 2 3 1 - - 3 2 
L 1 2 - 2 1 - - 2 1 - 2 0 - 2 2 - - 3 - 1 3 2 - - 3 1 
M - - - - - - - - - - - - 0 - - - - - - - - - - - - - 
N 1 1 - 1 1 - - 1 1 - 1 2 - 0 1 - - 2 - 2 2 1 - - 2 2 
O 1 1 - 1 2 - - 1 2 - 2 2 - 1 0 - - 1 - 2 1 2 - - 1 3 
P - - - - - - - - - - - - - - - 0 - - - - - - - - - - 
Q - - - - - - - - - - - - - - - - 0 - - - - - - - - - 
R 2 2 - 2 3 - - 2 3 - 3 3 - 2 1 - - 0 - 3 1 3 - - 1 4 
S - - - - - - - - - - - - - - - - - - 0 - - - - - - - 
T 1 2 - 2 2 - - 2 1 - 2 1 - 2 2 - - 3 - 0 3 2 - - 3 2 
U 2 2 - 2 3 - - 2 3 - 3 3 - 2 1 - - 1 - 3 0 3 - - 1 4 
V 2 2 - 2 1 - - 2 1 - 1 2 - 1 2 - - 3 - 2 3 0 - - 3 2 
W - - - - - - - - - - - - - - - - - - - - - - 0 - - - 
X - - - - - - - - - - - - - - - - - - - - - - - 0 - - 
Y 2 2 - 2 3 - - 2 3 - 3 3 - 2 1 - - 1 - 3 1 3 - - 0 4 
Z 2 3 - 3 1 - - 3 1 - 2 1 - 2 3 - - 4 - 2 4 2 - - 4 0 
*/
// 之后计算LIZZIE 到 BOHDAN 的最短距离，只需要依次遍历这两个名字中的字符，
// 然后查询两个字母之间的最短距离。最后从最短距离中取最小值即可。
//
// 思维很巧妙，但是真的没有想到这种方法，可能是经验不足吧。
//
// 进一步思考，能这样做的原因有两个：
// 1.单个名字，如果有重复字符，不会影响最终结果。
// 2.所有字母之间的权值都是1，不会出现两个字母之间有多个权值。
//


// 26个字母
const int alp = 26;
// 矩阵最大值
const int inf = 1e9;
const int maxn = 5e4+20;
void solve()
{
    int N, Q;
    string s[maxn];
    int i,j,k;
    int matrix[alp][alp];
    int ans=0;
    scanf("%d %d", &N, &Q);
    
    // 初始化
    for(i=0; i<alp; i++)
    {
        for(j=0; j<alp; j++)
        {
            matrix[i][j] = inf;
        
            if(i==j)
                matrix[i][j] = 0;
        }
    }

    
    for(k=1; k<=N; k++)
    {
        cin>>s[k];
        // 两个字母有边
        for(i=0; i<s[k].length(); i++)
        {
            for(j=i+1; j<s[k].length(); j++)
            {
                // 相同的字符，无需边
                if(s[k][i] == s[k][j])
                    continue;

                matrix[s[k][i]-'A'][s[k][j]-'A'] = 1;
                matrix[s[k][j]-'A'][s[k][i]-'A'] = 1;
            }
        }
    }
    // floyd 算法
    for(k=0; k<alp; k++)
    {
        for(i=0; i<alp; i++)
        {
            for(j=0; j<alp; j++)
            {
                if(i!=j && (matrix[i][k]+matrix[k][j] < matrix[i][j]))
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    
    
    // 查询
    int left,right;
    for(i=0; i<Q; i++)
    {
        ans = inf;
        scanf("%d %d", &left, &right);
        j--;
        k--;
        for(j=0; j<s[left].length(); j++)
        {
            for(k=0; k<s[right].length(); k++)
            {
                ans = min(ans, matrix[s[left][j]-'A'][s[right][k]-'A']);
            }
        }
        if(ans == inf)
            printf("-1 ");
        else
            printf("%d ", ans+2);
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

