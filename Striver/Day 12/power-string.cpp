class Solution{
	public:
	    
	    void generate(string s, string curr, int idx, vector<string>& ans)
	    {
	        if(idx == s.length()) 
	        {
	           if(curr != "") ans.push_back(curr);
	            return;
	        }
	        
	        generate(s, curr, idx+1, ans);
	        generate(s, curr+s[idx], idx+1, ans);
	    }
	    
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> ans;
		    generate(s,"", 0,ans);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};
// prb: https://practice.geeksforgeeks.org/problems/power-set4302/1#


// BIT MANIPULATION

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    
		    // take 1 to 2^len - 1
		    // the binary representations denotes which char to grant in the string 
		    vector<string> ans;
		    int size = s.length();
		    for(int i = 1; i<= pow(2,size)-1; i++)
		    {
		        string res = "";
		        for(int j=0;j<16;j++)
		        {
		            if( i & (1<<j)) // if jth bit is set of i we will pick jth char of s
		            {
		                res += s[j];
		            }
		        }
		        
		        ans.push_back(res);
		    }
		    sort(ans.begin(), ans.end());
		    return ans;
		}
};
// solution: https://www.youtube.com/watch?v=b7AYbpM5YrE&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=68