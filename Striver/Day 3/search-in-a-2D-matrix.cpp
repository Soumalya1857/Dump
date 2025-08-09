class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 2d binary search laagbe 
        
        // first e col e search and then shei row te search
        // col search should return the immediate lower number than the number 
        
        
        // search in the first col for the first time to determine the range
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        if(row == 1 && col == 1) return matrix[0][0] == target;
        
        int low = 0, high = row-1;
        while(low <=high)
        {
            int mid = (low+high)/2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] > target) high = mid-1;
            else low = mid+1;
        }
        
        if(high < 0) return false; // doesn't exist in matrix
        // target can be in high th row
        int low1 = 0, high1 = col-1;
        while(low1<=high1)
        {
            int mid = (low1+high1)/2;
            if(matrix[high][mid] == target) return true;
            else if(matrix[high][mid] > target) high1 = mid-1;
            else low1 = mid+1;
        } 
           
        
        return false;
    }
};

// problem: https://leetcode.com/problems/search-a-2d-matrix/