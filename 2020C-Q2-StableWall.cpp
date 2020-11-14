/***********************************************
#
#      Filename: 2020C-Q2-StableWall.cpp
#
#        Author: Li Xudong - 757264690@qq.com
#   Description: ---
#        Create: 2020-11-12 15:08:39
# Last Modified: 2020-11-13 01:42:42
#
 ***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
#include <set>
using namespace std;

// 这一题其实很简单
// 题目的意思是用字母当多米诺骨牌进行堆叠,判断这个堆叠方案是否稳定,如果稳定,输出堆叠序列
// 但是字母的堆叠是有顺序的,每个字母是一次性堆好的.
// 比如,下面的一个序列:
// MM
// MF
// MM
// 如果先堆字母M,则最右上角的字母M,因为它的下面是空的(还没有堆F呢),所以M容易落下来,则是不稳定的
// 
// 看到先后顺序,首先想到了拓扑排序
// 怎么建图呢?
// 从下面往上开始建立,并且一列一列建立,对于上面的例子,
// 首先第一列都是M,肯定是稳定的,无需增加边,加一个顶点M
// 对于第二列,从往上,分别是M-F-M,则需要在顶点M和顶点F之间增加一条边,之后在顶点F和顶点M之间增加一条边(其实,这时候已经有环了,是不稳定的)
// 建好拓扑图后,拓扑排序,输入节点即可,如果没有将所有节点输出,则有环,输出-1
//
#define maxN 35
// 26个顶点
#define maxP 26

// 字母矩阵
char alp[maxN][maxN];
int main()
{
    int t,T,R,C;
    int i,j,k;

    scanf("%d", &T);
    // 拓扑图
    vector<int> G[maxP];
    // 入度
    int d[maxP];
    // 拓扑排序的输出队列
    queue<int> tst,ans;
    // 字母集合
    set<int> ss;

    for(t=1; t<=T; t++)
    {
        scanf("%d %d", &R, &C);
        memset(alp, 0, sizeof(alp));
        // 拓扑图和入度数组的初始化
        for(i=0; i<maxP; i++)
        {
            G[i].clear();
            d[i] = 0;
        }
        for(i=0; i<R; i++)
            for(j=0; j<C; j++)
            { 
                scanf(" %c", &alp[i][j]);
                ss.insert(alp[i][j]-'A');
            }
            
        // 建立拓扑图形
        for(i=0; i<R-1; i++)
        {
            for(j=0; j<C; j++)
            {
                // 如果上下两个字母相同,则不添加任何边
                if(alp[i][j] != alp[i+1][j])
                {
                    G[alp[i+1][j]-'A'].push_back(alp[i][j]-'A');
                    d[alp[i][j]-'A']++;
                }
            }
        }

        // 建好图后, 就可以拓扑排序了
        // 先添加入度为0的序列入队
        for(i=0; i<maxP; i++)
            if(!d[i] && ss.count(i))
                tst.push(i);

        while(!tst.empty())
        {
            // 输出入度为0的顶点,由于不知道有没有环,还不能输出
            // printf("%c", tst.front()+'A');
            k = tst.front();
            tst.pop();
            ans.push(k);
            // 删除该顶点出发的边,并且对应的顶点入度-1
            for(i=0; i<G[k].size(); i++)
            {
                d[G[k][i]]--;
                // 如果为0,则加入队列
                if(!d[G[k][i]])
                    tst.push(G[k][i]);
            }

        }

        printf("Case #%d: ",t);
        if(ans.size() == ss.size())
        {
            while(!ans.empty())
            {
                printf("%c", ans.front()+'A');
                ans.pop();
            }
            printf("\n");
        }
        else
            printf("-1\n");
        /* printf("Case #%d: ",t); */
        // 清除集合
        ss.clear();
        // 清除所有的顶点
        for(i=0; i<maxP; i++)
            G[i].clear();
        // 清空tst队列、ans队列
        while(!ans.empty())
            ans.pop();
        while(!tst.empty())
            tst.pop();
    }
    return 0;
}

