#include<bits/stdc++.h>
using namespace std;

// return the min no of partitions needed to make the arr
// devide into non-increasing or non-decreasing parts

int returnMinCount(string &arr)
{
    cout << arr << endl;
    int count = 0;
    int n = arr.length();
    bool changed;
    int start = 0;
    int i;
    //string s = "aaabcdebbddefdcbba";
    for(i=0;i<n-1;i++)
    {
        if(arr[i] > arr[i+1]) {changed = false; break;}
        if(arr[i] < arr[i+1]){changed = true; break;}
        else continue;
    }
    
    while(i <= n-2)
    {
        //int previ = i;
        for(i=start;i<n-1;i++)
        {
            if(arr[i] > arr[i+1]) {changed = false; cout<< "dec:" << i << endl;break;}
            if(arr[i] < arr[i+1]){changed = true;cout<< "inc:" << i << endl; break;}
            else continue;
        }
        if(changed == false)// decreasing order detected at i+1 th place
        {
            start = i+1;
            while(arr[start] >= arr[start+1] && start < n-1) start++;
            count++;
            //cout<< "dec: " << start << endl;
        }
        else if(changed == true)
        {
            start = i+1;
            while(arr[start] >= arr[start+1] && start < n-1) start++;
            count++;
            //cout<< "inc: " << start << endl;
        }
    }
    return count;
}

int main()
{

    string s = "aaabcdebbddefdcbba";
    cout << returnMinCount(s) << endl;
    return 0;
}