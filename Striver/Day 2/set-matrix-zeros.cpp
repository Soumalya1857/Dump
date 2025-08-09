class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
//           for(int i=0;i<row;i++)
//         {
//             for(int j=0;j< col ;j++)
//             {
//                 cout << matrix[i][j] << " ";
//             }
//             cout << "\n";
//         }
        
        
        int col0 = 0, row0 = 0;
        
        // traverse every row and if a row contains a 0 make the first element of that row and col as 0
        
        // now only traverse 0th row and col if 0 make that row/col zero
        
        
        for(int i=0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
                if(matrix[i][j] == 0 && i==0) col0 = 1; // 0th col need to 0
                if(matrix[i][j] == 0 && j==0) row0 = 1;  // 0th row need to 0
            }
        }
        
//         for(int i=0;i<row;i++)
//         {
//             for(int j=0;j< col ;j++)
//             {
//                 cout << matrix[i][j] << " ";
//             }
//             cout << "\n";
//         }
        
//         cout << "row0: " << row0 << "  Col0: " << col0 << endl; 
        
        // traverse only first row and col
        // change the first and last row at the last
        
        for(int i=1;i<row;i++)
        {
            if(matrix[i][0] == 0){
                for(int j=0;j<col;j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<col;i++)
        {
            if(matrix[0][i] == 0){
                for(int j=0;j<row;j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        
        // now change the 0 0 cell
        if(matrix[0][0] == 0)
        {
            if(row0) for(int i=0;i<row;i++) matrix[i][0] = 0;
            if(col0) for(int i=0;i<col;i++) matrix[0][i] = 0;
        }
    }
};

// ques: https://leetcode.com/problems/set-matrix-zeroes/
// youtube: https://www.youtube.com/watch?v=M65xBewcqcI&list=PLgUwDviBIf0rPG3Ictpu74YWBQ1CaBkm2&index=7