class Solution {
public:
    
    void show(vector<int> &hist)
    {
        for(int k=0;k<hist.size();k++) cout << hist[k] << " ";
            cout << endl;
    }
    
    int calcAreaUnderHistogram(vector<int> hist)
    {
        int n = hist.size();
        int i=0;
        stack<int> s;
        
        int max_area = -1;
        int area = 0;
        int top = 0;
        
        while(i < n)
        {
            if(s.empty() || hist[s.top()] <= hist[i])
            {
                s.push(i); // insert the index
                i++;
            }
            else
            {
                top = s.top();
                s.pop();
                area = hist[top] * (s.empty() ? i: (i-s.top()-1));
                max_area = max(max_area, area);
            }
        }
        
        while(!s.empty())
        {
            top = s.top();
            s.pop();
            area = hist[top] * (s.empty()? i: (i-s.top()-1));
            max_area = max(max_area, area);
        }
        
        return max_area;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        //if(matrix == NULL) return 0;
        int max_area = -1;
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        if(col == 0) return 0;
        
        vector<int> hist(col,0);
        for(int i=0; i< row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]-'0' == 0) hist[j] = 0;
                
                else hist[j] = hist[j] + (matrix[i][j]-'0');
            }
            
            cout << "Hist: ";
            show(hist);
            
           int area =  calcAreaUnderHistogram(hist);
            cout << "area: " << area << endl;
            max_area = max(max_area, area);
        }
        
        return max_area;
        
    }
};


/*
https://leetcode.com/problems/maximal-rectangle/
*/