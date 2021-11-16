class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b)
    {
        if(a[0] < b[0]) return true;
        // else if(a[0] > b[0]) return false;\
        // else
        // {
        //     if(a[1] < b[1]) return true;
        //     else return false;
        // }
        
        if(a[0] == b[0])
        {
            return a[1] > b[1];
        }
        
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(), properties.end(), compare);
        int len = properties.size();
        
        // find if it has a greater number at right
        int rightMax = INT_MIN;
        int count = 0, index = len-1;
        for(int i=len-1;i>=0;i--)
        {
            if(rightMax > properties[i][1] /*&& properties[index][0] > properties[i][0]*/) count++;
            // else if(rightMax < properties[i][1])
            // {
            //     rightMax = properties[i][1];
            //     index = i;
            // }
            rightMax = max(rightMax, properties[i][1]);
        }
        
        return count;
        
        
    }
};
// prb: https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/
// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/discuss/1445186/EASY-C%2B%2B-solution-with-great-explanation-and-comments-(nlogn)-sorting