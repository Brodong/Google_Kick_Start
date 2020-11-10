#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

// 主要的思路,用1减去掉进坑的概率,即是结果
// 通过对掉进坑的概率进行计算,会发现其是有规律的.
// 以测试集5,3,1,2,4,2为例,
// (1,1)(2,1)(3,1)(4,1)(5,1)
// (1,2)(2,2)(3,2)(4,2)(5,2)
// (1,3)(2,3)(3,3)(4,2)(5,3)
// 则一旦机器人走进了(1,2)(2,2)(3,2)(4,2),则失败
// 对于(1,2)机器人需要走1步 0.5
// 对于(2,2)机器人需要走2步 0.5*0.5
// 对于(3,2)机器人需要走3步 0.5*0.5*0.5
// ....
// 对于机器人来说,从(1,1)走到(m,n)一共有C((m-1),(m-1+n-1))走法,一共需要走(m-1+n-1)步.
// 则我们计算机器人从(1,1)走到紧靠坑的上面的方块,记为位置(m,n),则走的方法数和走的步数也可以得到(上一行的公式),
// 在(m,n)位置,则再往下走就失败,概率为 0.5^(走的步数) *走的方法数 *0.5
// 后面的0.5即为最后的往下走的一步,走完则掉进坑
// 为了方便,尽量对输入的值减去1,从(0,0)到(W-1,H-1),怎么方便怎么来
//

#define maxN 100000+50
// 计算C(m,n)的阶乘函数 m!
// 本题中数据太大,计算阶乘可能会溢出
// 所以对分子和分母进行约分,然后再计算
/*
long long jc(long long t)
{
    long long ans = 1;
    long long i;
    if(t==0 || t==1)
        return 1;
    for(i=1; i<=t; i++)
        ans *= i;
    return ans;
}
*/
long long gcd(long long a, long long b)
{
    return a%b==0? b:gcd(b,a%b);
}
// 计算排列组合的函数C(m,m+n);
long long C(long long m, long long n)
{
    long long minn = min(m,n);
    long long i,j;
    // 存储分母
    long long up[maxN];
    // 存储分子
    long long down[maxN];
    long long temp;
    m = m+n;
    memset(up, 0, sizeof(up));
    memset(down, 0, sizeof(down));
    for(i=0; i<minn; i++)
    {
        up[i] = m;
        m--;
        down[i] = i+1;
    }

    // 双层循环,进行分子和分母的约分
    for(i=0; i<minn; i++)
    {
        for(j=0; j<minn; j++)
        {
            temp = gcd(up[i], down[j]);
            up[i] = up[i]/temp;
            down[j] = down[j]/temp;

            // 如果分子为1,则可以退出当前循环
            if(down[j] == 1)
                break;
        }
    }

    temp = 1;
    for(i=0; i<minn; i++)
    {
        temp = temp*up[i]/down[i];
    }
    /*
    for(i=0; i<minn; i++)
    {
        temp /= down[i];
    }
    */
    return temp;
}

// 快速幂取余
double fastpow(long long b)
{
    long long base = 2;
    double result = 1.0;
    while(b>0)
    {
        if(b & 1)
        {
            result *= (1.0/(double)base); 
        }
        b >>= 1;
        base *= base;
    }
    return result;
}

// 从(0,0)走到(m,n)的概率
double Count(long long m, long long n)
{
    double ans = 1.0;
    // 需要走的步数
    long long step = m+n;
    // 方法数
    long long methods = 0;
    methods = C(m,n);

    return fastpow(step)*(double)methods;
}

double solve(long long w, long long h, long long l, long long u, long long r, long long d)
{
    long long i;
    double ans=0.0;

    // 首先是特殊情况,坑占满了某一行或者某一列,则无法达到
    if((l==0 && r==w)||(u==0 && d==h))
        return 0.0;
    // 1.计算机器人走到每一个坑的上面的概率
    // 特殊情况,坑就在第一行
    if(u == 0)
    {
        ans += 0;
    }
    else
    {
        for(i=l; i<=r; i++)
        {
            // Count(i,u-1),即为走到坑上面的概率,再乘以0.5则掉进坑
            ans += Count(i,u-1)*0.5;
        }
    }
    // 2.计算机器人走到每一个坑的左面的概率
    // 特殊情况,坑就在第一列
    if(l == 0)
    {
        ans += 0;
    }
    else
    {
        for(i=u; i<=d;i++)
        {
            ans += Count(l-1,i)*0.5;   
        }
    }
    return 1.0-ans;
}
int main()
{
    long long t,T;
    long long W,H,L,U,R,D;
    scanf("%lld", &T);
    double ans;
    for(t=1; t<=T; t++)
    {
        scanf("%lld %lld %lld %lld %lld %lld", &W, &H, &L, &U, &R, &D);
        printf("Case #%lld: ", t);
        //cout<<solve(W-1,H-1,L-1,U-1,R-1,D-1)<<endl;
        ans = solve(W-1, H-1, L-1, U-1, R-1, D-1);
        if(ans == 0)
            cout<<"0.0"<<endl;
        else
            cout<<ans<<endl;
    }
    /* std::cout << "Hello world" << std::endl; */
    return 0;
}

