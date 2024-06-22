class Solution {

private:
    int findMaxRowIndex(vector<vector<int>> &mat, int col){
        int result = INT_MIN, index = -1;
        for(int i=0; i<mat.size(); i++){
            if(result < mat[i][col]){
                result = mat[i][col];
                index = i;
            }
        }

        return index;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();

        int low = 0, high  = col-1;

        while(low <= high){
            int mid = (low + high)/2;

            int maxRowIndex = findMaxRowIndex(mat, mid);

            int left = mid-1 >= 0 ? mat[maxRowIndex][mid-1] : -1;
            int right = mid+1 < col ? mat[maxRowIndex][mid+1] : -1;

            int curr = mat[maxRowIndex][mid];


            if(curr > left && curr > right){
                return vector<int>{maxRowIndex, mid};
            } else if(curr < left){
                high = mid-1;
            } else{
                low = mid+1;
            }
        }

        return vector<int>{-1,-1};
    }
};

// https://leetcode.com/problems/find-a-peak-element-ii/
// https://www.youtube.com/watch?v=nGGp5XBzC4g&list=PLgUwDviBIf0pMFMWuuvDNMAkoQFi-h0ZF&index=28