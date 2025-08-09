class Solution {
public:
    bool isPossible(int idx, vector<string>& strs)
    {
        int size = strs.size();
        string match = strs[0].substr(0,idx+1);
        
        for(int i=0; i<=idx;i++)
        {
            char ch = match[i];
            for(int j=0;j<size;j++)
            {
                if(strs[j][i] != ch) return false;
            }
        }
        
        return true;
    }
    string longestCommonPrefix(vector<string>& strs) {
        
        // can be done using binary search
        // search space will be length of shortest string 
        int size = strs.size(), res=0;
        int minLen = INT_MAX;
        for(int i=0;i<size;i++) minLen = minLen < strs[i].size() ? minLen : strs[i].size();
        
        int low = 0, high = minLen-1;
        while(low <= high)
        {
            int mid = (low+high)>>1;
            if(isPossible(mid,strs))
            {
                res = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        
        return isPossible(0,strs) ? strs[0].substr(0,low) : "";
    }
};


// java solution
public String longestCommonPrefix(String[] strs) {
    if (strs == null || strs.length == 0)
        return "";
    int minLen = Integer.MAX_VALUE;
    for (String str : strs)
        minLen = Math.min(minLen, str.length());
    int low = 1;
    int high = minLen;
    while (low <= high) {
        int middle = (low + high) / 2;
        if (isCommonPrefix(strs, middle))
            low = middle + 1;
        else
            high = middle - 1;
    }
    return strs[0].substring(0, (low + high) / 2);
}

private boolean isCommonPrefix(String[] strs, int len){
    String str1 = strs[0].substring(0,len);
    for (int i = 1; i < strs.length; i++)
        if (!strs[i].startsWith(str1))
            return false;
    return true;
}
// prb: https://leetcode.com/problems/longest-common-prefix
// sol: https://leetcode.com/problems/longest-common-prefix/solution/