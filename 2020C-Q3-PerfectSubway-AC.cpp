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
#include <map>
#include <unordered_map>

// 运行： g++ 2020C-Q3-PerfectSubway-AC.cpp -std=c++11 ; ./a.out 

// 貌似是以前的组合数学问题,要求求出 子集合元素和 为完全平方数的子集数量
// 比如一个数组a1到a10,
// 假设a5到a7是一个满足的子集，其和为b的平方
// 则a5+a6+a7=b*b
// 等同于sum(1,7)-sum(1,4)=b*b
// 等同于sum(1,7)-b*b = sum(1,4)
// 因此，我们需要对b依次进行遍历，看数组中是否有sum(1,4)存在，如果存在，则有满足的子集和
// 第一次用的set来做，看到别人用map AC了，尝试用map做一下

using namespace std;

const int maxN = 1e5+20;
const int inf = 1e7+20;
int sum[maxN];
unordered_map<int, int> m;
void solve()
{
    int N;
    int n;
    int i,j,k;
    long long ans=0;
    int minn=0;
    scanf("%d", &N);
    memset(sum, 0, sizeof(sum));
    m.clear();

    // 存储和
    for(n=1; n<=N; n++)
    {
        scanf("%d", &k);
        sum[n] += sum[n-1]+k;
        minn = min(minn, sum[n]);
    }

    m[0]=1;

    for(i=1; i<=N; i++)
    {
        for(j=0; j*j<=inf; j++)
        {
            if(m.count(sum[i]-j*j))
            {
                ans += m[sum[i]-j*j];
            }
            if((sum[i]-j*j)<minn)
                break;

        }
        
        m[sum[i]]++;
    }
    printf("%lld\n", ans);

}
int main()
{
    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        //solve();
        printf("Case #%d: ", t);
        solve();
    }
}
