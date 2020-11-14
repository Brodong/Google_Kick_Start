#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef long long ll;

// 看到前缀二字就想到了字典树
// 首先建立一个字典树,然后从叶子节点开始,从下往上遍历,对每个子节点遍历
// 对每个子节点计算分成K组字符串的最大的value值
// 可以参考一位UP的视频讲解:https://www.youtube.com/watch?v=2Kb_QyPEMd0&feature=youtu.be&ab_channel=FluentAlgorithms
//
// 第一次提交之后,Test1通过,Test2运行错误
// 原因有两个方面:
// 1.字符串的长度未知,如果用char不知道开多少够,这里使用string类型.
// 2.有一些数据可能int类型不够,因此采用longlong型存储.
//
#define size 26


struct node{
    // 同一前缀的字符串个数
    ll pre;
    // 以该字符串结尾的字符串个数
    ll cnt;
    struct node *children[size];
};

node *root;

// 创建字典树的一个节点
node* createNode()
{
    int i;
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(node));
    newnode->pre = 0;
    newnode->cnt = 0;
    for(i=0; i<size; i++)
    {
        newnode->children[i] = NULL;
    }
    return newnode;
}

// 在字典树中增加一个节点
void insertNode(const std::string s)
{
    //cout<<"The string is "<<s<<endl;
    ll len = s.length();
    ll i;
    struct node *temp;
    temp = root;
    temp->pre++;
    for(i=0; i<len; i++)
    {
        if(temp->children[s[i]-'A']==NULL)
        {
            temp->children[s[i]-'A'] = createNode();
        }
        temp = temp->children[s[i]-'A'];
        temp->pre++;
    }
    temp->cnt++;
}

// 深搜 求结果
ll dfs(node *root, ll K, ll depth)
{
    ll ans=0;
    ll here = root->cnt;
    struct node *child;
    int i;
    if(root->pre<K)
    {
        return 0;
    }
    for(i=0; i<size; i++)
    {
        child = root->children[i];
        if(child==NULL)
            continue;
        // 加上叶子节点的分数
        ans += dfs(child, K, depth+1);
        // 叶子节点分成K组后,剩余的未加入组的节点,加到其父节点中
        here += (child->pre%K);
    }
    // depth即字符串长度 here/k 得出可以分为多少组
    ans += (here/K)*depth;
    return ans;
}

// 释放建立字典树所使用的指针
void deleteTree(struct node *root)
{   
    int i;
    if(root!=NULL)
    {
        for(i=0; i<size; i++)
        {
            deleteTree(root->children[i]);
        }
        free(root);
    }   
}

int main()
{
    int t,T;
    string s;
    ll N,n,K;
    ll ans=0;
    //root = createNode();
    scanf("%d", &T);
    for(t=1; t<=T; t++)
    {
        root = createNode();
        scanf("%lld %lld", &N, &K);
        for(n=1; n<=N; n++)
        {
            //scanf("%s", s);
            cin>>s;
            insertNode(s);
        }
        ans = dfs(root, K, 0);
        printf("Case #%d: %lld\n", t, ans);
    }
    /* std::cout << "Hello world" << std::endl; */
    return 0;
}
