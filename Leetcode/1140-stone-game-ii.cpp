// https://leetcode.com/problems/stone-game-ii/description/
class Solution {
private:
    int solve(vector<int> &prefix, int currM, int index, int currSum){
        if(index >= prefix.size()){
            return currSum;
        }

        // we will only calculate for alice's turn
        int maxVal = INT_MIN;

        for(int m=1; m<=currM; m++){
            // m values including index are up for grabs

            // m for alice
            // max(currM, 2*m) for bob
            //
            int x = index==0 ? 0 :  prefix[index-1];

            maxVal = max(maxVal, solve(prefix, max(2*m,currM), min(index+m-1+2*m+1, (int)prefix.size()-1), currSum+prefix[index+m-1]-x));
        }

        return maxVal;
    }
public:
    int stoneGameII(vector<int>& piles) {

        vector<int> prefix(piles.size());
        prefix[0] = piles[0];

        for(int i=1; i<piles.size(); i++){
            prefix[i] = prefix[i-1]+piles[i];
        }

        return solve(prefix, 2,0,0);
    }
};

// https://leetcode.com/problems/stone-game-ii/solutions/345528/c-beats-100-dp-with-detailed-explanation/
// https://leetcode.com/problems/stone-game-ii/solutions/345528/c-beats-100-dp-with-detailed-explanation/