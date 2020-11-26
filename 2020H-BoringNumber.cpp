/***********************************************
♡        Filename : 2020H-BoringNumber.cpp
♡
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-11-26 22:22:28
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <strstream>
using namespace std;

typedef long long ll;



string lltoString(long long t)
{
    std::string result;
    std::strstream ss;
    ss <<  t;
    ss >> result;
    return result;
}

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

ll cnt_ans(string num)
{
    int len = num.length();
    int i;
    bool flag = false;
    ll ans = 0;
    ll res = 0;

    for(i=0; i<len; i++)
    {
        flag = !flag;
        if(flag)
        {
            if((num[i]-'0')%2) res = (num[i]-'0')/2 - 1;
            else res = (num[i]-'0')%2;
            if(res>0) ans += cnt_part(res, len-i);
            
            if((num[i]-'0')%2)
                continue;
            else
                break;
            
        }
        else
        {
            if((num[i]-'0')%2) res = (num[i]-'0')/2 - 1;
            else res = (num[i]-'0')/2;
            if(res>0) ans += cnt_part(res, len-i);
            
            if(!((num[i]-'0')%2))
                continue;
            else 
                break;
        }
    }

    if(len%2 && (num[len-1]-'0')%2)
        ans ++;

    if(!(len%2) && !((num[len]-'0')%2))
        ans ++;

    return ans;
}
void solve()
{
    ll L,R;
    string num_L, num_R;
    long long ans1, ans2;
    scanf("%lld %lld", &L, &R);
    num_L = lltoString(L-1);
    num_R = lltoString(R);
    ans1 = cnt_ans(num_L);
    ans2 = cnt_ans(num_R);
    cout<<"ans1="<<ans1<<endl;
    cout<<"ans2="<<ans2<<endl;
    printf("%lld\n", ans2-ans1);
}
int main()
{
    int t,T;
    scanf("%d", &T);
    for(t=1; t<T; t++)
    {
        printf("Case #%d: ", t);
        solve();
    }
}
