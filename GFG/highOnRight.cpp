#include<bits/stdc++.h>
using namespace std;


	/* Function to replace every element with the
	next greatest element */
	void nextGreatest(int arr[], int n) {
	    // code here

        vector<int> v(n);
        stack<int> s;
        for(int i=n-1;i>=0;i--)
        {
            if(s.size() == 0) v.push_back(-1);
            else if(s.size() > 0 && s.top() > arr[i]) v.push_back(s.top());
            else if(s.size() > 0 && s.top() <= arr[i])
            {
                while(s.size() > 0 && s.top() <= arr[i])
                {
                    s.pop();
                }

                if(s.size() == 0) v.push_back(-1);
                else v.push_back(s.top());
            }

            s.push(arr[i]);
        }

        reverse(v.begin(), v.end());
        for( int i=0; i<n;i++)
        {
            cout << v[i] << " ";
        }

        cout << "\n";

	}


int main()
{

    int n = 5;
    int arr[n] = {1,1,2,1,3};
    cout << "Original ARR: ";
    for(int i=0;i<n;i++) cout <<  arr[i] << " ";
    cout << "\n";
    cout << "Greater arr: ";
    nextGreatest(arr,n);
    
    return 0;
}