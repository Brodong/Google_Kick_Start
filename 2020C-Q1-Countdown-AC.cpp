#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define maxN 200000+50

// 直接遍历+判断即可
int main()
{
    int num[maxN];
    int t,T,N,n,K,k,temp_K;
    int cnt,flag;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        cnt = 0;
        memset(num, 0, sizeof(num));
        scanf("%d %d", &N, &K);
        // 先全部输入
        for(n=0; n<N; n++)
        {
            scanf("%d", &num[n]);
        }
        for(n=0; n<N; n++)
        {
            // 发现K值,判断是否为m-countdown
            if(num[n] == K)
            {
                flag = 1;
                temp_K = K;
                // 向后遍历K个数
                for(k=0; k<K; k++)
                {
                    if(num[n+k] == temp_K)
                    {
                        temp_K = temp_K-1;
                        continue;
                    }
                    else
                    {
                        flag = 0;       
                        break;
                    }
                }
                if(flag == 1)
                {
                    cnt++;
                    //n = n+K;
                }
            }
        }
        printf("Case #%d: %d\n", t, cnt);
    }

    /* std::cout << "Hello world" << std::endl; */
    return 0;
}

