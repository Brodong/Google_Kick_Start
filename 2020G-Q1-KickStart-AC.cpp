/***********************************************
♡        Filename : 2020G-Q1-KickStart.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-11-30 17:12:05
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;


// 直接遍历 
// 遇到KICK则加1
// 遇到START则 加num(KICK)
// 但是注意到
// KICKICK中有2个KICK，K是可以重复的
const int maxlen = 1e5+20;
char s[maxlen];
void solve()
{
    int i;
    long long cnt = 0;
    long long ans = 0;
    memset(s, 0, sizeof(s));
    scanf(" %s", s);
    for(i=0; i<strlen(s); i++)
    {
        if(s[i] == 'K' && s[i+1] == 'I' && s[i+2] == 'C' && s[i+3] == 'K')
        {
            cnt ++;
            i += 2;
        }

        if(s[i] == 'S' && s[i+1] == 'T' && s[i+2] == 'A' && s[i+3] == 'R' && s[i+4] == 'T')
        {
            ans += cnt;
            i += 4;
        }
        if(i == strlen(s)-4 || i == strlen(s))
            break;
    }
    printf("%lld\n", ans);
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
