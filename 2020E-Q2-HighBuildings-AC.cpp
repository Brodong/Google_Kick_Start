/***********************************************
♡        Filename : 2020E-Q2-HighBuildings.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-12-10 10:23:53
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

// 有N个楼（最高N米），A从左向右看，B从右向左看。
// 如果前面的楼比后面的楼高，则看不见后面的楼。
// A能看见A个楼，B能看见B个楼，两个人都能看见C个楼
// 最后需要给出一种楼的排列方案，或者输出不存在这种方案。
//
// 我使用的有点类似贪心算法。
// 1. 排列C个高度为N米的楼
// 2. 左边需要排列A-C个楼，右边需要排列B-C个楼，左边和右边的楼的高度均为N-1米。
// 3. 将剩余的楼数目插入这些楼里面，高度为N-2米。
//
// 但是有很多特殊情况需要考虑：
// 1. 左边A-C个，右面B-C个，但是排列完C座后剩余楼数小于(A-C)+(B-C)，则无解。
// 2. 左边的A-C和B-C均为0。
//    2.1 中间楼只有1个，而剩余楼数目大于0，则无法插入，无解。
//    2.2 中间楼不仅1个，则只能是往中间楼里面插。
// 3. 左边A-C或者B-C有一个为0，则只能在非0的一侧插入。


int solve()
{
    int N, A, B, C;
    int res;
    int i,j;
    scanf("%d %d %d %d", &N, &A, &B, &C);
    // 左边排列A-C个N-1米楼
    A = A-C；
    // 右边排列B-C个N-1米楼
    B = B-C;
    // 排列完中间、左边、右边后剩余楼数
    res = N-C-A-B;

    // 特殊情况1   N-C < A+B
    // 特殊情况2.1 无法插入
    if((N-C<A+B) || (A==0 && B==0 && C==1 && res>0))
    {
        printf("IMPOSSIBLE\n");
        return 0;
    }
    // 特殊情况2.2 只能往中间插
    else if(A==0 && B==0 && C>1 && res>0)
    {
        printf("%d ", N);
        for(i=0; i<res; i++)
            printf("%d ", N-1);
        for(i=0; i<C-1; i++)
            printf("%d ", N);
        printf("\n");
        return 0;
    }
    else 
    {
        // 左边A-C座N-1米楼
        for(i=0; i<A; i++)
            printf("%d ", N-1);
        
        // A-C = 0 特殊情况3，一侧为0只能插入另一侧
        // A-C > 0 则将剩余楼插入，高度为N-2米
        if(A>0 && res>0)
        {
            for(i=0; i<res; i++)
                printf("%d ", N-2);
            res = 0;
        }

        // 中间插入C座N米楼
        for(i=0; i<C; i++)
            printf("%d ", N);

        // B-C = 0 特殊情况3
        // B-C > 0 则将剩余楼插入，高度为N-2米
        if(B>0 && res>0)
        {
            for(i=0; i<res; i++)
                printf("%d ", N-2);
            res = 0;
        }

        // 右边B-C座N-1米楼
        for(i=0; i<B; i++)
            printf("%d ", N-1);

        printf("\n");
        return 0;
    }
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

