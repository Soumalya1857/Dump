class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int size = nums.size();
        
        
        vector<int> nge(size,-1);
        stack<int> s;
        bool check = false;
        int i;
        // traverse from last
        
        s.push(nums[size-1]);
        
        for(i=size-1;i>=0;i--)
        {
            int curr = nums[i];
            while(!s.empty())
            {
                int top  = s.top();
                if(top > curr) 
                {
                    if(nge[i] == -1) nge[i] = top;
                    break;
                }
                s.pop();
            }
            
            s.push(curr);
        }
        // 2nd pass to populate other entries
        
        for(i=size-1;i>=0;i--)
        {
            int curr = nums[i];
            while(!s.empty() && nge[i] == -1)
            {
                int top  = s.top();
                if(top > curr) 
                {
                    nge[i] = top;
                    break;
                }
                s.pop();
            }
            
            s.push(curr);
        }
        //for(int num : nge) cout << num << " ";
        return nge;
        
    }
};
// prb: https://leetcode.com/problems/next-greater-element-ii/submissions/
// soln: https://www.youtube.com/watch?v=Du881K7Jtk8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=76


// same code just uses the modulo operator
public class Solution {

    public int[] nextGreaterElements(int[] nums) {
        int[] res = new int[nums.length];
        Stack<Integer> stack = new Stack<>();
        for (int i = 2 * nums.length - 1; i >= 0; --i) {
            while (!stack.empty() && nums[stack.peek()] <= nums[i % nums.length]) {
                stack.pop();
            }
            res[i % nums.length] = stack.empty() ? -1 : nums[stack.peek()];
            stack.push(i % nums.length);
        }
        return res;
    }
}