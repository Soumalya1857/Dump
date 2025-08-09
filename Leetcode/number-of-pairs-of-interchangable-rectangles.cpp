class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& v) {
        long long ans = 0;
		int n = v.size();
		unordered_map<double,int> mp;
		
		for(int i=0;i<n;i++){
			mp[(double)v[i][0]/v[i][1]]++;
		}
		
		for(auto i:mp){
			ans += (double)i.second*(i.second-1)/2;
		}
		return ans;
        
    }
};

//https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/