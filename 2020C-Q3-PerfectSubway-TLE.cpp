/***********************************************
#
#      Filename: 2020C-Q3-PerfectSubway.cpp
#
#        Author: Li Xudong - 757264690@qq.com
#   Description: ---
#        Create: 2020-11-13 17:42:55
# Last Modified: 2020-11-15 00:44:57
#
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <set>

// 不知道为什么，此代码仅有Test1Pass， Test2 TLE了。。。
// 原来用map可以过，用set却通不过，看来还是map快
//

// 貌似是以前的组合数学问题,要求求出 子集合元素和 为完全平方数的子集数量
// 比如一个数组a1到a10,
// 假设a5到a7是一个满足的子集，其和为b的平方
// 则a5+a6+a7=b*b
// 等同于sum(1,7)-sum(1,4)=b*b
// 等同于sum(1,7)-b*b = sum(1,4)
// 因此，我们需要对b依次进行遍历，看数组中是否有sum(1,4)存在，如果存在，则有满足的子集和


using namespace std;
const int inf = 1e7+20;
const int maxN = 1e5+20;
int main()
{
    int t,T,N;
    int i;
    int sum[maxN];
    int minn;
    int k;
    long long ans;
    scanf("%d", &T);
    multiset<int> ss; 
    for(t=1; t<=T; t++)
    {
        
        minn = 0;
        ans = 0;
        ss.clear();
        scanf("%d", &N);
        memset(sum, 0, sizeof(sum));
        // 依次求和
        for(i=1; i<=N; i++)
        {
            scanf("%d", &k);  
            sum[i] = sum[i-1]+k;   
            minn = min(minn, sum[i]);
        }
        
        ss.insert(0);
        for(i=1; i<=N; i++)
        {
            // 对于每一个sum[i]进行暴力遍历
            for(k=0; k*k<inf; k++)
            {
                // 如果存在
                if(ss.count(sum[i]-k*k))
                {
                    ans += ss.count(sum[i]-k*k);
                }
                if(sum[i]-k*k<minn)
                    break;
            }
            ss.insert(sum[i]);
        }
        printf("Case #%d: %lld\n", t, ans);
        
    }
    return 0;
}

