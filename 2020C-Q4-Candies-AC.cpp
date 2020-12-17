/***********************************************
♡        Filename : 2020C-Q4-Candies.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-12-17 09:29:13
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

// 如果直接对原数组操作，则查询操作为O(n)，而更新操作复杂度为O(1)。
// 如果构建前缀和数组，则查询操作为O(1)，而更新操作复杂度为O(n)。
// 因此出现了矛盾。
//
// 一个比较常用的方法就是使用线段树方法。
// 构建两个线段树：
// 假设数组元素为[t1,t2,t3,t4,t5...]
// 1.第一棵树，构建了t1,-t2,t3,-t4,t5...等元素的线段树
// 2.第二棵树，构建了1*t1, 2*(-t2), 3*t3, 4*(-t4), 5*t5...等元素的线段树
// 则每次查询的结果"Q L R"可以表示为，(第二棵树-第一棵树*(L-1)) * ((-1)^(L-1))
//
// 都是线段树的基础操作：建立树、更新树、查询树
// 
const int maxn = 2e5+10;

int t[maxn];
long long tree[maxn<<2][2]; // 第一棵树tree[][0],第二棵树tree[][1]

void build_tree(int node, int start, int end)
{
    if(start==end)
    {
        tree[node][0] = t[start];
        tree[node][1] = t[start]*start;
    }
    else
    {
        int mid = (start+end)/2;
        int leftnode = node*2;
        int rightnode = node*2+1;
        build_tree(leftnode, start, mid);
        build_tree(rightnode, mid+1, end);
        tree[node][0] = tree[leftnode][0] + tree[rightnode][0];
        tree[node][1] = tree[leftnode][1] + tree[rightnode][1];
    }
}

void update_tree(int node, int start, int end, int idx, int val)
{
    if(start==end)
    {
        //t[idx] = val;
        tree[node][0] = val;
        tree[node][1] = val*start;
    }
    else
    {
        int mid = (start+end)/2;
        int leftnode = node*2;
        int rightnode = node*2+1;
        if(idx<=mid)
        {
            update_tree(leftnode, start, mid, idx, val);
        }
        else
        {
            update_tree(rightnode, mid+1, end, idx, val);
        }
        tree[node][0] = tree[leftnode][0] + tree[rightnode][0];
        tree[node][1] = tree[leftnode][1] + tree[rightnode][1];
    }
}

// 查询第一棵树
long long query_tree1(int node, int start, int end, int L, int R)
{
    if(L>end || R<start) return 0;
    else if((start == end) || (L<=start && end<=R) ) return tree[node][0];
    else{
        int mid = (start+end)/2;
        int leftnode = node*2;
        int rightnode = node*2+1;
        long long sum_left = query_tree1(leftnode, start, mid, L, R);
        long long sum_right = query_tree1(rightnode, mid+1, end, L, R);
        return sum_left + sum_right;
    } 
}


// 查询第二棵树
long long query_tree2(int node, int start, int end, int L, int R)
{
    if(L>end || R<start) return 0;
    else if((start == end) || (L<=start && end<=R) ) return tree[node][1];
    else{
        int mid = (start+end)/2;
        int leftnode = node*2;
        int rightnode = node*2+1;
        long long sum_left = query_tree2(leftnode, start, mid, L, R);
        long long sum_right = query_tree2(rightnode, mid+1, end, L, R);
        return sum_left + sum_right;
    } 
}

void solve()
{
    int N, Q;
    scanf("%d %d", &N, &Q);
    int i,j;
    memset(t, 0, sizeof(t));
    memset(tree, 0, sizeof(tree));
    
    for(i=1; i<=N; i++)
    {
        scanf("%d", &t[i]);
        if(!(i&1))
        {
            t[i] = -t[i];
        }
    }

    build_tree(1, 1, N);

    long long ans = 0;
    char c;
    int num1, num2;
    for(i=1; i<=Q; i++)
    {
        scanf(" %c", &c);
        if(c=='U')
        {
            scanf("%d %d", &num1, &num2);
            if(!(num1&1)) num2 = -num2;
            update_tree(1, 1, N, num1, num2);
        }
        else
        {
            scanf("%d %d", &num1, &num2);
            long long sum1 = query_tree1(1, 1, N, num1, num2);
            long long sum2 = query_tree2(1, 1, N, num1, num2);
            sum2 = sum2-sum1*(num1-1);
            if(!(num1&1)) sum2 = -sum2;
            ans += sum2;
        }

        //printf("%lld\n", ans);
    }
    printf("%lld\n", ans);
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
