// wrong answer bro
class Solution {
public:
    
    static bool compareTo(const vector<int>& box1, const vector<int>& box2){
        // compare on the cube value
        
        if(box1[0]*box1[1]*box1[2] >= box2[0]*box2[1]*box2[2] ) return false;
        return true;
    }
    
    vector<vector<int>> generateAllSeq(vector<vector<int>>& cuboids){
        
        vector<vector<int>> allSeq;
        for(int i=0;i<cuboids.size();i++){
            vector<int> seq1(manage(cuboids[i][0],cuboids[i][1],cuboids[i][2]));
            allSeq.push_back(seq1);
            
            vector<int> seq2(manage(cuboids[i][1],cuboids[i][2],cuboids[i][0]));
            allSeq.push_back(seq2);
            
            vector<int> seq3(manage(cuboids[i][2],cuboids[i][1],cuboids[i][0]));
            allSeq.push_back(seq3);
        }
        
        return allSeq;
    }
    
    vector<int> manage(int w, int l, int h){
        vector<int> ans;
        if(l>w) ans.push_back(w), ans.push_back(l), ans.push_back(h);
        else ans.push_back(l), ans.push_back(w), ans.push_back(h);
        return ans;
    }
    
    int maxHeight(vector<vector<int>>& cuboids) {
        
        
        // sort based on length of base
        // then sort based on base area
        
        // generate all sequence
        
        vector<vector<int>> allSeq(generateAllSeq(cuboids));
        vector<int> ans(allSeq.size());
        
        // now sort it based on cube volm non increasing order
        sort(allSeq.begin(), allSeq.end(), compareTo);
        for(int i=0;i<allSeq.size();i++) ans[i] = allSeq[i][2];
        
        // now go for a LIS on height
        for(int i=1;i<allSeq.size(); i++){
            for(int j=0; j<i;j++){
                if(allSeq[i][0] < allSeq[j][0] && allSeq[i][1] < allSeq[j][1] && allSeq[i][2] < allSeq[j][2]){
                    if(ans[j] + allSeq[i][2] > ans[i]){
                        ans[i] = ans[j] + allSeq[i][2];
                    }
                }
            }
        }
        
        
        int maxAns = INT_MIN;
        for(int i=0;i<ans.size();i++){
            maxAns = max(maxAns, ans[i]);
        }
        
        return maxAns;
        
        
    }
};

// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

// https://github.com/mission-peace/interview/blob/master/src/com/interview/dynamic/BoxStacking.java
// soln: https://leetcode.com/problems/maximum-height-by-stacking-cuboids/discuss/1332434/C%2B%2B-DP-or-LIS-(Beats-100)
// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/discuss/1332434/C%2B%2B-DP-or-LIS-(Beats-100)

int maxHeight(vector<vector<int>>& cuboids){
         
         
         for(vector<int> &cube : cuboids){
             sort(cube.begin(), cube.end());
         }
         
         sort(cuboids.begin(), cuboids.end()); // sort increasingly base on 1st data
         
         // now use LIS on the last parameter that is height
            int n=cuboids.size();
        vector<int> dp(n,0);
        for (int i=0;i<n;i++){
            dp[i]=cuboids[i][2];
            for (int j=0;j<i;j++){
                if (cuboids[j][1]<=cuboids[i][1] && cuboids[j][2]<=cuboids[i][2]){
                    dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
                }
            }
        }
         
        return *max_element(dp.begin(),dp.end());
     }