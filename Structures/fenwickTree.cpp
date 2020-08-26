#include<bits/stdc++.h>
using namespace std;



void updateTree(int tree[], int n/*length of the tree arr*/, int index,/*position to be changed*/int val)
{
    while(index <= n)
    {
        tree[index] += val;
        index += index&(-index);
    }
}

int rangeSum(int tree[], int n, int index)// querysum upto index l
{
    int sum = 0;
    while(index > 0)
    {
        sum += tree[index];
        index -= index & (-index);
    }
    return sum;
}


int main()
{
    int tree[10] = {0}; // tree size should be max_element of arr + 1
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    for(int i=0;i<9;i++)
    {
        updateTree(tree,9,i,arr[i]);
    }

    cout << "The tree is: ";
    for(int i=1;i<10;i++) cout << tree[i] << " ";
    cout << "\n";
    return 0;
}