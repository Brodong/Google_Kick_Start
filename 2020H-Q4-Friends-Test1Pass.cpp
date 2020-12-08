/***********************************************
♡        Filename : 2020H-Q4-Friends-Floyd.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-12-08 11:11:14
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

const int maxn = 100+20;
const int inf = 1e9;

bool check(string a, string b)
{
    int i,j;
    int lena = a.length();
    int lenb = b.length();
    for(i=0; i<lena; i++)
    {
        for(j=0; j<lenb; j++)
        {
            if(a[i] == b[j])
                return true;
        }
    }
    return false;
}
void solve()
{
    int i, j, k;
    string s[maxn];
    int matrix[maxn][maxn];
    //memset(matrix, inf, sizeof(matrix));
    int N, Q;
    scanf("%d %d", &N, &Q);
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            matrix[i][j] = inf;
        }
    }
    for(i=0; i<N; i++)
    {
        cin>>s[i];
    }
    
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            if(i!=j && check(s[i], s[j]))
            {
                matrix[i][j] =  1;
            }
        }
    }
    
    for(k=0; k<N; k++)
    {
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                if(i!=j && (matrix[i][k] + matrix[k][j] < matrix[i][j]))
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    /*
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            cout<<matrix[i][j]<<"\t";

        }
        cout<<endl;
    }
    */
    
    for(i=0; i<Q; i++)
    {
        scanf("%d %d", &j, &k);
        if(matrix[j-1][k-1] == inf)
            printf("-1 ");
        else
            printf("%d ", matrix[j-1][k-1]+1);
    }
    printf("\n");
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
