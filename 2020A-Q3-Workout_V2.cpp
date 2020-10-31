#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

// 使用二分的方法来解决此问题。
// 如果K=1，则只增加一个数，则这个数一定是增加到间隔最大的两个数之间。
// 对于K>1，我之前想得是模拟这个增加的过程，然后发现超时了。
// 这里有一种二分的方法，首先对最大差值进行二分，假设二分后的差值为Ｎ，
// 然后去判断原来的数组实现最大差值为Ｎ最少需要增加几个数，如果不大于Ｋ个数，则一定能成功。
// 如果成功了，则说明最终的结果是小于Ｎ的。则再对Ｎ进行二分，直到找到能够成功的最大值。
#define maxN 100000+50

int diff[maxN];
// 通过二分法判断能够成功的最大值。
int check(int left, int right, int numb, int K)
{
    int i = 0;
    int mid;
    int cnt;
    int ans;
    while(left<=right)    
    {
        cnt = K;
        /* printf("1.left is %d right is %d\n", left, right); */
        mid = (left+right)/2;
        // 判断实现数组最大间隔为mid，需要多少次，如果在cnt次能成功，则继续二分
        for(i=0; i<numb-1; i++)
        {
            // 如果当前间隔大于mid，则需要添加数字
            if(diff[i]>mid)
            {
                // 如果是mid的倍数，则需要增加(diff[i]/mid)-1个数字即可
                if(diff[i]%mid == 0)
                    cnt -= (diff[i]/mid-1);
                // 如果不是mid的倍数，则需要增加(diff[1]/mid)个数字
                else
                    cnt -= diff[i]/mid;
            }

            // 如果cnt小于0，则说明不能成功，则退出
            if(cnt<0)
            {
                //printf("mid is %d, cnt is %d\n", mid, cnt);
                break;
            }
        }
        /* printf("mid is %d, cnt is %d\n", mid, cnt); */
        // cnt小于0,说明最终的结果在mid和right之间
        if(cnt<0)
        {
            left = mid+1;
        }
        else
        {
            ans = mid;
            right = mid-1;
        }
        /* printf("2.left is %d right is %d\n", left, right); */   
    }
    return ans;
}
int main()
{
    int T,t,N,n,K;
    int num1,num2;
    //int diff[maxN];
    int max_diff = 0;
    //memset(diff, 0, sizeof(diff));
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        memset(diff, 0, sizeof(diff));
        scanf("%d %d", &N, &K);
        scanf("%d", &num1);
        for(n=0; n<N-1; n++)
        {
            scanf("%d", &num2);
            diff[n] = num2-num1;
            /* printf("%d ", diff[n]); */
            max_diff = max(max_diff, diff[n]);
            num1 = num2;
        }
        /* printf("%d\n", max_diff); */
        printf("Case #%d: %d\n", t, check(1,max_diff,N,K));
    }
    /* std::cout << "Hello world" << std::endl; */
    return 0;
}

