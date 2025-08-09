class Solution {
public:
    
    int abs(int n)
    {
        return (n<0)?-n:n;
    }
    int findMinDifference(vector<string>& timePoints) {
        
        int n = timePoints.size();
        vector<int> space;
        int maxi = 50000;
        
        for(string point : timePoints)
        {
            int num = ((point[0]-'0')*10 + (point[1]-'0'))*60 + (point[3]-'0')*10 + (point[4]-'0');
            space.push_back(num);
            space.push_back(num-1440);
        }
        
        sort(space.begin(), space.end());
        for(int i=0;i<space.size();i++) cout << space[i] << " ";
        for(int i=1;i<space.size();i++)
        {
            int temp = space[i] - space[i-1];
            if(temp < maxi) maxi = temp;
        }
        
        return maxi;
    }
};

/*
https://leetcode.com/problems/minimum-time-difference
*/