/***********************************************
♡        Filename : 2020H-Q2-BoringNumber.cpp
♡
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-11-26 22:22:28
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <strstream>
using namespace std;

// 如果直接遍历，然后对每个数的每一位求奇偶性，则test1可以通过
// 但是test2数据太大，直接遍历则超时。
// 可以用组合数学的思想来做。
// 比如我们有一个数9734，我们计算1000到9734间一共有多少个符合题目的数字。
// 对于第1位（奇位），而小于9的奇数有4个，则如果以这4个奇数为第1位，则有4*5*5*5个数。
// 因为第1位为9，是奇数，因此可以考虑对第2位进行计算，
// 对于第2位（偶位），而小于7的偶数有4个，则如果以9为第一位，这4个偶数为第2位，则有1*4*5*5个数。
// 因为第2位为7，是奇数，因此结束计算（后面的数一定不符合）
//
// 那么0-9734中有多少个满足条件的数呢？
// 对于4位的数，可以按照上面的方法做；对于3位数，应该有5^3个；对于2位数，应该有5^2个；对于1位数，应该有5^1个。
//
// 那么比如计算123-9734中有多少个满足的数呢？
// 我们可以转化为求(0-9724)的个数减去(0-123)的个数。
//
// 其中，因为对于2位数和1位数，两者是重复的，减去之后为0，因此可以免去计算。


// L 和 R 范围是1-1e18，longlong比较保险
typedef long long ll;

// 1,2,3……之前（包括）一共有多少个偶数
int under_even[10]={1,1,2,2,3,3,4,4,5,5};
// 一共有少个奇数
int under_odd[10]={0,1,1,2,2,3,3,4,4,5};

// longlong转string
string lltoString(long long t)
{
    std::string result;
    std::strstream ss;
    ss <<  t;
    ss >> result;
    return result;
}

// 对每一位，计算 剩余的奇/偶数，然后乘以len-1个5
ll cnt_part(int res, int len)
{
    ll ans = 0;
    int i;
    ans = res;
    for(i=1; i<len; i++)
    {
        ans *= 5;
    }
    return ans;
}

// 计算个数，例如1000-1234之间符合条件的个数
ll cnt_ans(string num)
{
    int len = num.length();
    int i;
    // 奇偶位标记
    bool flag = false;
    ll ans = 0;
    ll res = 0;
    // 对每一位进行遍历
    for(i=0; i<len; i++)
    {
        flag = !flag;
        // 当前是奇数位
        if(flag)
        {
            // 计算可选择的奇数个数
            if((num[i]-'0')%2) res = under_odd[num[i]-'0']-1;
            else res = under_odd[num[i]-'0'];
            // 可选择数*5*5*5……
            if(res>0) ans += cnt_part(res, len-i);
            
            // 如果当前的数也是奇数，则可以对下一位进行计算
            if((num[i]-'0')%2)
                continue;
            // 如果当前数不是奇数，则后面的数都不是了，则停止遍历
            else
                break;
            
        }
        // 当前是偶数位
        else
        {
            if(!((num[i]-'0')%2)) res = under_even[num[i]-'0']-1;
            else res = under_even[num[i]-'0'];
            if(res>0) ans += cnt_part(res, len-i);
            
            if(!((num[i]-'0')%2))
                continue;
            else 
                break;
        }
    }
    // 因为之前判断可选择的奇偶个数的时候，没有包括这个数本身
    // 因此遍历到最后一位的时候，需要再特殊判断一下最后一位是否满足，若满足加1
    // i==len 遍历到最后一位
    // len%2 判断最后一位是奇数还是偶数
    if(i==len && len%2 && (num[len-1]-'0')%2)
        ans++;

    if(i==len && !(len%2) && !((num[len]-'0')%2))
        ans ++;

    return ans;
}
void solve()
{
    ll L,R;
    string num_L, num_R;
    long long ans1, ans2, ans3;
    int i,j;
    ans1 = ans2 = ans3 = 0;
    scanf("%lld %lld", &L, &R);
    num_L = lltoString(L-1);
    num_R = lltoString(R);
    ans1 = cnt_ans(num_L);
    ans2 = cnt_ans(num_R);

    // 若两个数的位数不一样
    // 比如，56-1575
    // 函数计算的是0-55之间的个数和1000-1575之间的个数
    // 因此对于后者，需要加上位数为3和位数为2时，符合条件的个数
    // 分别是5^3,5^2
    for(i=num_L.length(); i<num_R.length(); i++)
        ans3 += pow(5,i);
    
    printf("%lld\n", ans2+ans3-ans1);
}
int main()
{
    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        printf("Case #%d: ", t);
        solve();
    }
}
