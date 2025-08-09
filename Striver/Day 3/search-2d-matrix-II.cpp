class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // place a pointer on the last element of first row (0 col-1)
        // we are not placing it on 1st row 1st col as from there right or down both are increasing side
        // we cannot decide where to go
        // but last element of first row teh sheta na
        
        int row = matrix.size(), col = matrix[0].size();
        
        int i=0,j=col-1;
        
        while(i<row && j>=0)
        {
            if(matrix[i][j] ==target) return true;
            else if(matrix[i][j] > target) j--; // move to prev col
            else if(matrix[i][j] < target) i++; // move to next row
        }
        
        return false;
    }
};

// prob: https://leetcode.com/problems/search-a-2d-matrix-ii
// sol: https://www.youtube.com/watch?v=ZYpYur0znng&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=14
//https://leetcode.com/problems/search-a-2d-matrix-ii/discuss/1367184/C%2B%2B-binary-search-O(logm%2Blogn)-solution