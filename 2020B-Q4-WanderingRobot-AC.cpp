/***********************************************
♡        Filename : 2020B-Q4-WanderingRobot.cpp
♡  
♡     Description : ---
♡          Author : Li Xudong
♡         Contact : 757264690@qq.com
♡         Created : 2020-11-20 13:56:52
***********************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
using namespace std;


// 代码是根据官方给出的方法写得。
// 官方解释：https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc8/00000000002d8565#analysis
// 
// 对于从(0,0)到(x,y),概率P(x,y)为 pow(0.5,x+y)*方法数，而方法数=C(x,x+y)
// 
// 但是若(x,y)处于最后一行或者最后一列，则不能按照上面的方式计算概率
// 假设最后一行有3个方格，
// 则对于第1个方格，其概率为pow(0.5, H);
// 则对于第2个方格，其概率为 第一个方格的概率+上面一个方格的概率*0.5
// 即，pow(0,5,H)+P(i, j-1)
// 则对于第3个方格，其概率为 第二个方格的概率+上面一个方格的概率*0.5
//
// 对于最后一列，方法与最后一行相同。
//
// 为了防止溢出，做log处理
// 
// 计算log(num!),以2为底
//
//

const int max_num = 2*1e5+20;

// log(0), log(1), log(2), log(3), log(4)……
double log_arr[max_num];
/*
将log计算结果存储为数组，时间会快一些，否则会TLE
double mylog(int num)
{
  int i;
  double sum = 0.0;
  if(num == 0 || num == 1)
    return sum;
  for(i=1; i<=num; i++)
  {
    sum += log(i)/log(2);
  }
  return sum;
}
*/

// 计算log(P(x,y)) = log( pow(0.5, (x+y)) * C(x,x+y) ) = log((x+y)!) - log(x!) - log(y!) - (x+y)
/*double probility(int x, int y)
{
  return mylog(x+y)-mylog(x)-mylog(y)-(x+y);
}
*/

double probility(int x, int y)
{
    return log_arr[x+y]-log_arr[x]-log_arr[y]-(x+y);
}


// 计算通过的概率之和
double cal(int W, int H, int L, int U, int R, int D)
{
  double ans=0.0, sum=0.0;
  double temp=0.0;
  int i,j,k;
  
  memset(log_arr, 0, sizeof(log_arr));
  
  log_arr[0] = 0.0;
  for(i=1; i<=(W+H); i++)
      log_arr[i] = log_arr[i-1] + log(i)/log(2);
  
  // 处理右上角的方块
  if(R!=W)
  {
    j=min(U,D);
    for(i=R+1; i<=W; i++){
      j--;
      if(j<0)
        break;
      // 最后一列
      if(i==W)
      {
        if(j==0) ans += pow(2, -W);
        else{
          temp = pow(2, -W);
          for(k=1; k<=j; k++)
            temp = temp + 0.5*pow(2, probility(i-1, k));
          ans += temp;
        }
      }
      else
        ans += pow(2,probility(i,j));
    }
  }
  // 处理左下角的方块
  if(L!=0){
    j=max(U,D);
    for(i=L-1; i>=0; i--){
      j++;
      if(j>H)
        break;
      // 最下面一行
      if(j==H)
      {
        if(i==0) ans += pow(2, -H);
        else{
          temp = pow(2, -H);
          for(k=1; k<=i; k++)
            temp = temp + 0.5*pow(2, probility(k, j-1));
          ans += temp;
        }
      }
      else
        ans += pow(2,probility(i,j));
    }
  }
  return ans;
}

void solve()
{
  int W,H,L,R,U,D;
  scanf("%d %d %d %d %d %d", &W, &H, &L, &U, &R, &D);
  //cout<<W<<H<<L<<U<<R<<D<<endl;
  double ans = cal(W-1, H-1, L-1, U-1, R-1, D-1);
  if(ans == 0)
    cout<<"0.0"<<endl;
  else
    cout<<ans<<endl;
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
  return 0;
}
