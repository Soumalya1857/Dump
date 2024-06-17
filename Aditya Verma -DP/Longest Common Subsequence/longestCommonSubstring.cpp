
class Solution{

	private:

		int solve(string &s, int i, int j, int res){
			if(i>j){
				return res;
			}

			if(i ==j){
				return res+1;
}

			if(s[i] == s[j]){
				return solve(s, i+1, j-1, res+2);
}

return max(solve(s, i+1, j, 0) , solve(s,i, j-1, 0);
}
	public:
		int longestCommonSubstring(string s1){
			
		}
};
