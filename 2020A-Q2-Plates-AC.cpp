#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

// 我的思路基本是对的：动态规划思想
// 用beauty[i][j]表示第i摞中，取前j个盘子的魅力值。
// 用maxb[i][j]表示前i摞中取j个盘子，能够获得的最大魅力值。
// 1.对于maxb[1][0]到maxb[1][p]来说，因为只有1摞，则只需要依次相加即可。
// 2.对于第2摞来说，可以选择第2摞的0个盘子，或1个盘子，或2个盘子，则需要遍历，直到min(第2摞盘子数，需要的盘子数)结束。
//   对于第2摞，假设需要P个盘子，第2摞中取cnt个盘子，则其魅力值为: beauty[2][cnt]+maxb[1][P-cnt],遍历取最大值即可。
// 3.对于第i摞，遍历求beauty[j][cnt]+maxb[j-1][P-cnt]的最大值。


#define maxN 60     // 很生气，第一次开到（50+1）竟然没有过，害得找了半天代码的错误，建议以后做题开大些
#define maxP 1520
int main()
{
    int T,t,N,n,K,k,P;
    int beauty[maxN][maxP];
    int maxb[maxN][maxP];
    int max_temp = 0;
    int cnt;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        memset(beauty, 0, sizeof(beauty));
        memset(maxb, 0, sizeof(maxb));
        scanf("%d %d %d", &N, &K, &P);

        // 输入魅力值
        for(n=1; n<=N; n++)
        {
            for(k=1; k<=K; k++)
            {
                scanf("%d", &beauty[n][k]);
            }
        }

        
        // 第i摞中，取前j个盘子的魅力值
        for(n=1; n<=N; n++)
        {
            for(k=1; k<=P; k++)
            {
                // 依次相加
                beauty[n][k] += beauty[n][k-1];
                /* printf("%d ", beauty[n][k]); */ 
            }
            /* printf("\n"); */ 
        }
    
        // 计算前i摞中，去j个盘子，能够获得的最大魅力值
        for(n=1; n<=N; n++)
        {
            for(k=1; k<=P; k++)
            {
               // 依次遍历，使用第j摞的0个盘子，1个盘子，2个盘子，...，min(k,K)个盘子  求最大值
                //maxb[n][k] = maxb[n-1][k];
               for(cnt=0; cnt<=min(k,K); cnt++)
               {
                    maxb[n][k] = max(maxb[n][k], beauty[n][cnt]+maxb[n-1][k-cnt]);
               }
               /* printf("%d ", maxb[n][k]); */   
            }
            /* printf("\n"); */ 
        }

        printf("Case #%d: %d\n", t, maxb[N][P]);
    }

    return 0;
}


