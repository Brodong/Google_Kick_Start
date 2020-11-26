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

typedef long long ll;

int under_even[10]={1,1,2,2,3,3,4,4,5,5};
int under_odd[10]={0,1,1,2,2,3,3,4,4,5};

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
            if((num[i]-'0')%2) res = under_odd[num[i]-'0']-1;
            else res = under_odd[num[i]-'0'];
            if(res>0) ans += cnt_part(res, len-i);
            
            if((num[i]-'0')%2)
                continue;
            else
                break;
            
        }
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
