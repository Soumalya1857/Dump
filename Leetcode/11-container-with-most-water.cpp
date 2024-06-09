
class Solution {
public:
    int maxArea(vector<int>& height) {
	int left=0, right = height.size()-1;
	int ans = -1;
	while(left < right){
	ans = max(ans, (right-left) * min(height[left], height[right]));
	if(height[left] > height[right]){
	right--;
} else{
	left++;
}
}

return ans;


    }
};

// https://leetcode.com/problems/container-with-most-water/
// https://leetcode.com/problems/container-with-most-water/solutions/
