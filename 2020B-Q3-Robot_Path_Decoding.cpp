#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <string.h>
#include <stack>
using namespace std;


// 可以想象成数学中计算向量的方式,垂直方向用y,水平方向用x
// 遇到数字index的时候,后面跟着一个左括号,需要对向量的系数乘以index,遇到右括号的时候恢复之前的系数
// 考虑用栈来保存系数,遇到左括号的时候压入系数,遇到右括号的时候弹出系数,则此时栈顶就是下一个的向量的系数

// 向量 first 为垂直方向, second为水平方向
pair<long long, long long> plc;
int maxx = 1e9;
// 计算位置
pair<long long, long long> solve(const std::string str)
{
    long long len = str.length();
    long long i,mul;
    // 系数栈
    stack<long long> index;
    // 直接遍历
    mul = 1;
    for(i=0; i<len; i++)
    {
        if(str[i] >='2' && str[i]<='9')
        {
            index.push(str[i]-'0');
            mul = mul*(str[i]-'0');
        }
        else if(str[i] == '(')
        {
            continue;
        }
        else if(str[i] == ')')
        {
            mul = mul/index.top();
            index.pop();
        }
        else
        {
            if(str[i]=='N')  plc.first = (plc.first - mul + maxx)%maxx;
            if(str[i]=='S')  plc.first = (plc.first + mul + maxx)%maxx;
            if(str[i]=='W')  plc.second = (plc.second - mul + maxx)%maxx;
            if(str[i]=='E')  plc.second = (plc.second + mul + maxx)%maxx;
        }
    }
    return plc;
}

int main()
{
    string s;
    int t,T;
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        cin>>s;
        plc.first = 0;
        plc.second = 0;
        plc = solve(s);
        printf("Case #%d: %lld %lld\n", t, plc.second+1, plc.first+1);
    }
    return 0;
}

