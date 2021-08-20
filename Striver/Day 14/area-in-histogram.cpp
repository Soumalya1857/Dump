// naive solution
// take every col and try to expand it on right and left separately
// for that col max value will be left+right
// take max all over the columns

// we can expand on right upto => which is the smaller element on right
// we can expand to left upto => which is the smaller element on left
// (rightsmaller - leftSmaller + 1) * height of self

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        // get next smaller elements
        // get right smaller elements for every ai
        // (right smaller - left smalller + 1) * ai
        
        int size = heights.size(), maxArea = INT_MIN;
        vector<int>nextSmaller(size,-1);
        vector<int> prevSmaller(size,-1);
        
        stack<int> s;
        // next smaller element
        for(int i=size-1; i>=0;i--)
        {
            while(!s.empty())
            {
                int top = s.top();
                if(heights[top] < heights[i])
                {
                    nextSmaller[i] = top -1; // to point to the last non smaller element
                    break;
                }
                s.pop();
            }
            if(s.empty()) nextSmaller[i] = size-1;
            s.push(i);
        }
        
        // clear the stack 
        while(!s.empty()) s.pop();
        
        // prev smaller elements
        for(int i=0;i<size;i++)
        {
            while(!s.empty())
            {
                int top = s.top();
                if(heights[top] < heights[i])
                {
                    prevSmaller[i] = top + 1; // to point to the last non smaller element
                    break;
                }
                s.pop();
            }
            if(s.empty()) prevSmaller[i] = 0;
            s.push(i);
        }
        
        for(int i=0;i<size;i++)
        {
            int left = prevSmaller[i];
            int right = nextSmaller[i];
            //cout << "index: " << i << " left: " << left << " right: " << right << " height:" << heights[i] << endl;
            int area = (right-left+1)*heights[i];
            maxArea = max(maxArea,area);
        }
        
        return maxArea; 
    }
};
// prb: https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/
// soln: https://www.youtube.com/watch?v=X0X6G-eWgQ8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=82
// https://github.com/striver79/SDESheet/blob/main/largestRectangleHistorgram2passCpp



// one pass solution
// https://www.youtube.com/watch?v=jC_cWLy7jSI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=82
// non intuitive though
