class Solution {
public:
    bool isPalindrome(string s, int i, int j)
    {
       // int len = s.length();
        //if(len == 0) return false;
        while(i<j)
        {
            if(s[i++] != s[j--]) return false;
        }
        
        return true;
    }
    
    void solve(string &s, int index, string store, vector<string>curr, vector<vector<string>>&ans)
    {
        if(index >= s.length()){ 
            ans.push_back(curr);
            return;
        }
        
//         if(isPalindrome(store)) curr.push_back(store);
        
//         solve(s, index+1, store+s[index], curr, ans);
        
//         // start a new thread
//         solve(s,index+1, "", curr, ans);
        
        for(int i=index; i<s.length();i++)
        {
            if(isPalindrome(s,index,i)) 
            {
                curr.push_back(s.substr(index,i-index+1));
                solve(s,i+1,store,curr,ans);
                curr.pop_back();
                
            }                      
                                                          
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        vector<vector<string>> ans;
        string store = "";
        solve(s, 0, store, curr, ans);
        return ans;
    }
};

// prb: https://leetcode.com/problems/palindrome-partitioning/submissions/
// soln: https://leetcode.com/problems/palindrome-partitioning/solution/
// soln: https://www.youtube.com/watch?v=WBgsABoClE0&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=52

class Solution {

private:

    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;

            i++;
            j--;
        }

        return true;
    }

    void solve(string &s, int index, vector<string> partition, vector<vector<string>> &ans){

        if(index == s.length()){
            // add to ans
            ans.push_back(partition);
            return;
        }


        for(int i=index; i<s.length(); i++){
            string subString = s.substr(index, i-index+1);

            if(isPalindrome(s, index, i)){
                partition.push_back(subString);
                solve(s, i+1, partition, ans);
                partition.pop_back();
            }
        }


    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> partition;
        vector<vector<string>> ans;

        solve(s,0,partition, ans);
        return ans;
    }
};