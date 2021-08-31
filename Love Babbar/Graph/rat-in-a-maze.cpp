class Solution{
    
    public:
        
        class State{
            public:
                int x;
                int y;
                string path;
                vector<vector<bool>> visited;
                
                State(int x, int y, string path, vector<vector<bool>> visited)
                {
                    this->x = x;
                    this->y = y;
                    this->path = path;
                    this->visited = visited;
                }
                
                State(const Solution::State& a)
                {
                    this->x = a.x;
                    this->y = a.y;
                    this->path = a.path;
                    this->visited = a.visited;
                    
                }
        };
        
        
    public:
    
    bool isValid(int n, int i, int j)
    {
        if(i>=0 && i<n)
            if(j>=0 && j<n)
                return true;
                
        return false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        State start(0,0,"", visited);
        vector<string> ans;
        queue<State> q;
        q.push(start);
        
        int dx[4] = {1,0,0,-1};
        int dy[4] = {0,-1,1,0};
        char dir[4] = {'D','L','R','U'};
        
        while(!q.empty())
        {
            State curr = q.front();
            q.pop();
            
            if(curr.x == n-1 && curr.y == n-1)
            {
                //cout << curr.path << endl;
                ans.push_back(curr.path);
            }
            visited[curr.x][curr.y] = true;
            
            for(int i=0;i<4;i++)
            {
                int x = curr.x + dx[i];
                int y = curr.y + dy[i];
                
                if(isValid(n,x,y) && m[x][y] == 1 && !visited[x][y])
                {
                    State temp(x,y,curr.path+dir[i], visited);
                    q.push(temp);
                }
            }
        }
        
        return ans;
        
    }
};
