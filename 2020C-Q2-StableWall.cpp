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
#define maxN 30+5
// 26个顶点
#define maxP 26

// 字母矩阵
char alp[maxN][maxN];
int main()
{
    int t,T;
    int R,C;
    int i,j,k;
    int cnt; // 统计字母个数
    scanf("%d", &T);
    // 拓扑图
    vector< vector<int> > G(maxP);
    // 入度
    int indegree[maxP];
    // 拓扑排序的输出队列
    queue<int> topsort,topsort2;
    for(t=1; t<=T; t++)
    {
        scanf("%d %d", &R, &C);
        memset(alp, 0, sizeof(alp));
        // 有一些多余的字母可能没有用,因此用-1标记
        memset(indegree, -1, sizeof(indegree));
        for(i=0; i<R; i++)
            for(j=0; j<C; j++)
            { 
                scanf(" %c", &alp[i][j]);
                indegree[alp[i][j]-'A'] = 0;
            }
    
        // 统计字母个数
        cnt = 0;
        for(i=0; i<maxP; i++)
            if(indegree[i] == 0)
                cnt++;
        // 建立拓扑图形
        for(i=0; i<C; i++)
        {
            for(j=R-1; j>0; j--)
            {
                // 如果上下两个字母相同,则不添加任何边
                if(alp[j][i] == alp[j-1][i])
                {
                }
                else
                {
                    //如果不相同,需要查看是否有这个边,重复的边只保留一次
                    for(k=0; k<G[alp[j][i]-'A'].size(); k++)
                    {
                        if(G[alp[j][i]-'A'][k] == alp[j-1][i]-'A')
                            break;
                    }
                    if(k == G[alp[j][i]-'A'].size())
                    {
                        G[alp[j][i]-'A'].push_back(alp[j-1][i]-'A');
                        // 入度加1            
                        indegree[alp[j-1][i]-'A']++;
                    }
                }
            }
        }


        // 建好图后, 就可以拓扑排序了
        // 先添加入度为0的序列入队
        for(i=0; i<maxP; i++)
        {
            if(indegree[i] == 0)
                topsort.push(i);
        }
        
        // j用来维护输入了多少个顶点
        j=0;
        while(!topsort.empty())
        {
            // 输出入度为0的顶点,由于不知道有没有环,还不呢输出
            // printf("%c", topsort.front()+'A');
            k = topsort.front();
            topsort2.push(k);
            topsort.pop();
            j++;
            // 删除该顶点出发的边,并且对应的顶点入度-1
            for(i=0; i<G[k].size(); i++)
            {
                indegree[G[k][i]]--;
                // 如果为0,则加入队列
                if(indegree[G[k][i]] == 0)
                    topsort.push(G[k][i]);
            }

        }

        // 记得删除所有的点
        for(i=0; i<maxP; i++)
        {
            G[i].clear();
        }

        printf("Case #%d: ",t);
        if(j == cnt)
        {
            while(!topsort2.empty())
            {
                printf("%c", topsort2.front()+'A');
                topsort2.pop();
            }
            printf("\n");
        }
        else
            printf("-1\n");
        /* printf("Case #%d: ",t); */
        
    }
    /* std::cout << "Hello world" << std::endl; */
    return 0;
}

