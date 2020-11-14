#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// So easy...
// 从最后一天到前一天遍历, D = D-D%x[i]; 最后的D就是结果

using namespace std;
typedef long long ll;
#define maxN 1000+50
int main()
{
    int t,T;
    ll N,D,n;
    ll x[maxN];
    scanf("%d", &T);
    ll ans;
    for(t=1; t<=T; t++)
    {
        memset(x, 0, sizeof(x));
        scanf("%lld %lld", &N, &D);
        for(n=0; n<N; n++)
        {
            scanf("%lld", &x[n]);
        }
        ans = D;
        for(n=N-1; n>=0; n--)
        {
            ans -= ans%x[n]; 
        }

        printf("Case #%d: %lld\n", t, ans);
    }
    /* std::cout << "Hello world" << std::endl; */
    return 0;
}

