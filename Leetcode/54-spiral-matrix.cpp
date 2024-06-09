class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        	int row = matrix.size();
	int col = matrix[0].size();
        vector<int> ans;

	//int marker = INT_MAX;

	int rowStart = 0, rowEnd = row-1, colStart = 0, colEnd = col-1;

	while(true){

for(int j=colStart; j<=colEnd; j++){
	//cout << matrix[rowStart][j] << " ";
    ans.push_back(matrix[rowStart][j]);
}

rowStart++;
if(!(rowStart <= rowEnd && colStart <= colEnd)) break;

/**=============================*/

for(int i=rowStart; i<=rowEnd; i++){
	//cout << matrix[i][colEnd]  << " ";
    ans.push_back(matrix[i][colEnd]);
}

colEnd--;
if(!(rowStart <= rowEnd && colStart <= colEnd)) break;

/*==================================*/

for(int j=colEnd; j>=colStart; j--){
	//cout << matrix[rowEnd][j] << " ";
    ans.push_back(matrix[rowEnd][j]);
}
rowEnd--;
if(!(rowStart <= rowEnd && colStart <= colEnd)) break;
/*=========================*/

for(int i=rowEnd; i>= rowStart; i--){
	//cout << matrix[i][colStart] << " ";
    ans.push_back(matrix[i][colStart]);
    }

colStart++;
if(!(rowStart <= rowEnd && colStart <= colEnd)) break;
}

        return ans;
    }
};

// https://leetcode.com/problems/spiral-matrix/
// https://leetcode.com/problems/spiral-matrix/solutions/20570/clean-java-readable-human-friendly-code/