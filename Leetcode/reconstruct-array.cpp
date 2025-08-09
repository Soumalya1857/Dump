#include <bits/stdc++.h>
using namespace std;

class Solution{

// https://leetcode.com/discuss/interview-question/5150959/Google-onsite-L3-Question
    public:
        vector<int> solve(vector<int> arr){
            int n = arr.size();

            vector<int> ans;
            deque<int> dq;

            for(int i=0; i<n; i++){
                dq.insert(i+1);
            }
            // the smaller number is itself is the number but in the updated available array
            // the num will be the number what the index is saying
            // but everytime we push a data in ans, we need to delete that element from array

            // Ex: 4,0,1,0,0
            // 4th element of 1,2,3,4,5 is 5
            // add 5, now array becomes 1,2,3,4
            // ans = 5

            // 0th element of 1,2,3,4 is 1
            // add 1, now array becomes 2,3,4
            // ans = 5,1

            // 1st element of 2,3,4 is 2
            // add 2, now the array becomes 3,4
            // ans = 5,1,2

            // 0th element of 3,4 is 3
            // add 3 and array becomes 4
            // ans = 5,1,2,4,

            // 0th element of 0 is 4
            // add 4 and array becomes --
            // ans = 5,1,2,4,3

            for(int i=0; i<n; i++){
                int num = dq.at(arr[i]);
                ans.push_back(num);

                dq.erase(num);
            }
        }
}

int main(){

    Solution solution;
    vector<int> input{4,0,1,0,0};
    vector<int> ans = solution.solve(input);

    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}


//=========================================================
//Use ordered set, which provides two extra function than regular set both of which works in O(log n)
//st.find_by_order(k) //iterator of kth element 0 indexed or == st.end()
//st.order_of_key(val) // number of elements strictly less than val
//
//so,here's O(n * log n) solution using ordered_set;

vector<int> getOriginalArray(vector<int>& input, int n){

	ordered_set<int> st;

	for(int idx = 1; idx <= n; idx++){
		st.insert(idx);
	}

	vector<int> originalArray;

	for(int idx = 0; idx < input.size(); idx++){

		int k = input[idx];

		auto itr = st.find_by_order(k);

		originalArray.push_back(*itr);

		st.erase(itr);
	}

	return originalArray;
}