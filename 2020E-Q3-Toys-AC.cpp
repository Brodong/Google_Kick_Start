/***********************************************
♡        Filename : 2020E-Q3-Toys.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-12-15 09:53:07
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <vector>
using namespace std;

// 可能自己脑袋比较笨，一直没有想到用优先队列（官方题解）。。。

// 思路分两步：
// 1.判断能够一直玩下去。如果能，则输出解。
// 2.如果不能，则计算能玩耍的最长时间。
//
// 如果一个玩具可以被持续玩下去，则其R[i]<=Sum_E-E[i]，即玩了一圈后再次玩到它时，已经忘记这个玩具了。
// 特别注意的是，如果一个玩具R[i]>Sum_E-E[i]，则考虑将其删除，删除其后,不仅仅要更新sum, 还要删除R[i]>Sum_E_update-E[i]的玩具
// 为了使得删除操作变得简单,这里使用优先队列,根据R[i]+E[i]降序排列.
// 这样,队列前面的玩具满足条件,则队列后面的元素就一定满足条件。
// 如果最后队列变为空，则说明没有可能实现 玩无限时间的玩具。
// 
// 如果队列为空，则需要计算玩耍玩具的最长时间。
// 仍旧使用优先队列，依次遍历每一个玩具，如果满足，则更新玩耍时间，同时维护最大玩耍时间和删除的玩具数目。
// 如果不满足，则考虑删除这个玩具。但是删除这个玩具后，还要保证前面的玩具可以玩，因此需要遍历将前面不符合条件的玩具删除。之后更新玩耍时间和删除玩具的数目。
//
void solve()
{
    int N;
    scanf("%d", &N);
    vector<int> E(N), R(N);
    priority_queue< pair<int, int> > pq;
    int i,j;
    long long sum = 0, sum2 = 0;
    long long min_del = 0;
    long long del = 0;
    long long max_play = 0;
    long long play = 0;
    for(i=0; i<N; i++)
    {
        scanf("%d %d", &E[i], &R[i]);
        pq.push({E[i]+R[i], i});
        sum += E[i];
    }
    sum2 = sum;
    while(!pq.empty())
    {
        if(pq.top().first<=sum2)
        {
            break;
        }
        else
        {
            pq.pop();
            sum2 -= E[pq.top().second];
        }
    }

    if(!pq.empty())
    {
        printf("%d INDEFINITELY\n", N-(int)pq.size());
    }
    else
    {                                              
        max_play = sum;
        play = sum;
        min_del = 0;
        del = 0;
        for(i=0; i<N; i++)
        {
            if(E[i]+R[i]<=sum)
            {
                play += E[i];
                pq.push({E[i]+R[i], i});
                if(play > max_play)
                {
                    max_play = play;
                    min_del = del;
                }
            }
            // 不满足条件，考虑删除玩具
            else
            {
                sum -= E[i];
                play -= E[i];
                del ++;
                // 前面需要删除的玩具
                while(!pq.empty() && (pq.top().first > sum)){
                    sum -= E[pq.top().second];
                    play -= 2*E[pq.top().second];
                    pq.pop();
                    del++;
                }
            }
        }
        printf("%lld %lld\n", min_del, max_play);
    }
    E.clear();
    R.clear();
    while(!pq.empty()) pq.pop();
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
