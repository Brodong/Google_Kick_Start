/***********************************************
♡        Filename : 2020H-Q1-Retype.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-11-27 00:24:16
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef long long ll;
// 根据题意，直接模拟两种方法，输出min值即可。
const int maxnn = 1e9+20;
void solve()
{
    ll N, K, S;
    cin>>N>>K>>S;

    ll ans1,ans2;
    ans1 = K-1+1+N;
    ans2 = (K-1)+(K-S)+(N-S+1);
    cout<<min(ans1,ans2)<<endl;

}

int main()
{
    int t;
	cin >> t;
	for(int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;
}

