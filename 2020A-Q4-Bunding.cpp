#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

// 看到前缀二字就想到了字典树
// 首先建立一个字典树,然后从叶子节点开始,从下往上遍历,对每个子节点遍历
// 对每个子节点计算分成K组字符串的最大的value值
// 可以参考一位UP的视频讲解:https://www.youtube.com/watch?v=2Kb_QyPEMd0&feature=youtu.be&ab_channel=FluentAlgorithms


#define size 26

struct node{
    int pre;
    int cnt;
    struct node *children[26];
};

struct node *root;
// 字典树 创建一个节点
node* createNode()
{
    node *newnode;
    int n;
    newnode = (struct node*)malloc(sizeof(node));
    newnode->pre = 0;
    newnode->cnt = 0;
    for(n=0; n<size; n++)
    {
        newnode->children[n] = NULL;
    }
    return newnode;
}

// 字典树 插入节点
void insertNode(char str[50])
{
    int length = strlen(str);
    int k;
    struct node *temp;
    temp = root;
    temp->pre++;
    for(k=0; k<length; k++)
    {
        if(temp->children[str[k]-'A']==NULL)
        {
            temp->children[str[k]-'A'] = createNode();
        }
        temp = temp->children[str[k]-'A'];
        temp->pre++;
    }
    temp->cnt++;
}

// 深度有限搜索遍历
int dfs(node *temp, int K, int depth)
{
    
    int n;
    struct node *child;
    int ans = 0;
    int res = temp->cnt;
    if(temp->pre < K)
        return 0;
    for(n=0; n<size; n++)
    {
        child = temp->children[n];
        if(child == NULL)
            continue;
        ans += dfs(child, K, depth+1);
        res += child->pre%K;
    }
    ans += (res/K)*depth;
    return ans;
}

int main()
{
    int t,T,N,K,n;
    char str[50];
    scanf("%d", &T);
    //root = createNode();
    for(t=1; t<=T; t++)
    {
        root = createNode();
        scanf("%d %d", &N, &K);
        for(n=1; n<=N; n++)
        {
            memset(str, 0, sizeof(str));
            scanf("%s", str);
            insertNode(str);
        }
        printf("Case #%d: %d\n", t, dfs(root,K,0));
    }
    //std::cout << "Hello world" << std::endl;
    return 0;
}

