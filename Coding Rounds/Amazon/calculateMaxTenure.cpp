

#include<bits/stdc++.h>
using namespace std;


int generate(Node* node, int &ans)
{
    if(node == NULL)
    {
        // child = 0, sum = 0
        return make_pair(0,0);
    }

    int child = node->subEmployeeNode.size();
    int sum = node->value;

    for(int i=0; i< node->subEmployeeNode.size();i++)
    {
        pair<int,int> temp = generate(node->subEmployeeNode[i], ans);
        child += temp.first;
        sum += temp.second;
    }
    ans = max(sum/child, ans);
    return make_pair(child, sum);
}

int getMaxValueForAManager(Node* president)
{
    int ans = INT_MIN; // will contain the global min
    generate(president,ans);
    return ans;
}