/**********************************************
#      Filename: 2020C-Q4-Candies.cpp
#
#        Author: Li Xudong - 757264690@qq.com
#   Description: ---
#        Create: 2020-11-17 19:40:29
# Last Modified: 2020-11-17 21:57:06
#
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

// 看到query和update想到了线段树
// 算法复杂度为o(logn）
// 然而竟然还是TLE了。。。
//

const int maxN = 2*1e5+20;
const int maxN2= 1e8+20;


int t[2][maxN];
int tree[2][maxN2];

void buildTree(int i, int node, int start, int end)
{
    if(start == end)
    {
        tree[i][node]=t[i][start];
    }
    else
    {
        int mid = (start+end)/2;
        int leftnode = node*2 + 1;
        int rightnode = node*2 + 2;
        buildTree(i, leftnode, start, mid);
        buildTree(i, rightnode, mid+1, end);
        tree[i][node] = tree[i][leftnode] + tree[i][rightnode];
    }
}


long long  queryTree(int i, int node, int start, int end, int L, int R)
{

    if(R<start || L>end) return 0;
    if(start==end || (L<=start && end<=R)) return tree[i][node];
    else
    {
        int mid = (start+end)/2;
        int leftnode = node * 2 + 1;
        int rightnode = node * 2 + 2;
        long long sumleft = queryTree(i, leftnode, start, mid, L, R);
        long long sumright = queryTree(i, rightnode, mid+1, end, L, R);
        return sumleft+sumright;
    }
}

void updateTree(int i, int node, int start, int end, int id, int val)
{
    

    if(start==end)
    {
       t[i][id] = val;
       tree[i][node] = val;
    }
    else
    {
       int mid = (start+end)/2;
       int leftnode = node * 2 + 1;
       int rightnode = node *2 + 2;
       if(start<=id && id<=mid)
       {
            updateTree(i, leftnode, start, mid, id, val);
       }
       else
       {
            updateTree(i, rightnode, mid+1, end, id, val);
       }
       tree[i][node] = tree[i][leftnode] + tree[i][rightnode];
    }
}


void solve(){
    int N, Q;
    int i,L,R;
    char c;
    memset(t, 0, sizeof(t));
    memset(tree, 0, sizeof(tree));
    scanf("%d %d", &N, &Q);
    for(i=0; i<N; i++)
    {
        scanf("%d", &t[0][i]);
        t[1][i] = t[0][i]*(i+1);
        if(i & 1) {
            t[0][i] = -t[0][i];
            t[1][i] = -t[1][i];
        }
    }

    buildTree(0, 0, 0, N-1);
    buildTree(1, 0, 0, N-1);

    long long ans = 0;
    long long temp = 0;
    
    for(i=0; i<Q; i++)
    {
        scanf(" %c", &c);
        if(c=='Q')
        {
            scanf("%d %d", &L, &R);
            temp = queryTree(1, 0, 0, N-1, L-1, R-1)-queryTree(0, 0, 0, N-1, L-1, R-1)*(L-1);
            if((L-1) & 1) temp = -temp;
            ans += temp;
        }
        else
        {
            scanf("%d %d", &L, &R);
            if((L-1)& 1)
            {
                updateTree(1, 0, 0, N-1, L-1, -L*R);
                updateTree(0, 0, 0, N-1, L-1, -R);
            }
            else
            {
                updateTree(1, 0, 0, N-1, L-1, L*R);
                updateTree(0, 0, 0, N-1, L-1, R);
            }

        }
    }
    printf("%lld\n", ans);

}
int main()
{
    int T;
    scanf("%d", &T);
    for(int k=1; k<=T; k++)
    {
        printf("Case #%d: ", k);
        solve();
    }
    return 0;
}

