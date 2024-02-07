// TLE

class Solution {

private:

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool isValid(int row, int col, int x, int y){
    return x>=0 && x<row && y>=0 && y<col;
}

struct Node{
    int row, col;
    int minTillNow;
    map<pair<int,int>,bool> visited;


    Node(int row, int col, int minTill, map<pair<int,int>,bool> up) : row(row), col(col), minTillNow(minTill), visited(up){}
};

int abso(int n){
    return n<0 ? -n : n;
}
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();

        int globalMinEffort = INT_MAX;
        map<pair<int,int>,bool> vis;

        stack<Node> s;
        Node node(0,0,INT_MAX,vis);

        s.push(node);

        while(!s.empty()){
            Node currNode = s.top(); s.pop();

            globalMinEffort = min(globalMinEffort, currNode.minTillNow);
            currNode.visited[{currNode.row, currNode.col}] = true;

            if(currNode.row == row-1 && currNode.col == col-1){
                continue;
            }

            for(int i=0; i<4; i++){
                int currX = currNode.row + dx[i];
                int currY = currNode.col + dy[i];

                if(isValid(row, col, currX, currY) && !currNode.visited[{currX, currY}]){
                    Node temp(
                        currX,
                        currY,
                        min(currNode.minTillNow, abso(heights[currX][currY] - heights[currNode.row][currNode.col])),
                        currNode.visited
                    );

                    s.push(temp);
                }
            }
        }

        return globalMinEffort;
    }
};


// optimized with a priority queue and visited array

class Solution {

private:

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool isValid(int row, int col, int x, int y){
    return x>=0 && x<row && y>=0 && y<col;
}

struct Node{
    int row, col;
    int maxTillNow;
    map<pair<int,int>,bool> visited;


    Node(int row, int col, int minTill, map<pair<int,int>,bool> up) : row(row), col(col), maxTillNow(minTill), visited(up){}
};

int abso(int n){
    return n<0 ? -n : n;
}
public:
    class MyComp{
        public:
            bool operator()(const Node &a, const Node &b){
                return a.maxTillNow > b.maxTillNow;
            }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();

        //int globalMinEffort = INT_MAX;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        map<pair<int,int>, bool> vis;

        //stack<Node> s;
        priority_queue<Node, vector<Node>, MyComp> s; // ascending on maxTillNow
        Node node(0,0,0,vis);

        s.push(node);

        while(!s.empty()){
            Node currNode = s.top(); s.pop();
            visited[currNode.row][currNode.col] = true;
            //globalMinEffort = min(globalMinEffort, currNode.maxTillNow);


            if(currNode.row == row-1 && currNode.col == col-1){
                //cout << globalMinEffort << endl;
                return currNode.maxTillNow;
            }

            for(int i=0; i<4; i++){
                int currX = currNode.row + dx[i];
                int currY = currNode.col + dy[i];

                if(isValid(row, col, currX, currY) && !visited[currX][currY]/*!currNode.visited[{currX, currY}]*/){
                    Node temp(
                        currX,
                        currY,
                        max(currNode.maxTillNow, abso(heights[currX][currY] - heights[currNode.row][currNode.col])),
                        currNode.visited
                    );

                    s.push(temp);
                }
            }
        }

        return 0;
    }
};

// https://leetcode.com/problems/path-with-minimum-effort/

class Solution {

private:

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool isValid(int row, int col, int x, int y){
    return x>=0 && x<row && y>=0 && y<col;
}

struct Node{
    int row, col;
    int maxTillNow;


    Node(int row, int col, int minTill) : row(row), col(col), maxTillNow(minTill){}
};

int abso(int n){
    return n<0 ? -n : n;
}
public:
    class MyComp{
        public:
            bool operator()(const Node &a, const Node &b){
                return a.maxTillNow > b.maxTillNow;
            }
    };
    int minimumEffortPath(vector<vector<int>>& heights) {

        int row = heights.size();
        int col = heights[0].size();

        //int globalMinEffort = INT_MAX;
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        //stack<Node> s;
        priority_queue<Node, vector<Node>, MyComp> s; // ascending on maxTillNow
        Node node(0,0,0);

        s.push(node);

        while(!s.empty()){
            Node currNode = s.top(); s.pop();
            visited[currNode.row][currNode.col] = true;
            //globalMinEffort = min(globalMinEffort, currNode.maxTillNow);


            if(currNode.row == row-1 && currNode.col == col-1){
                //cout << globalMinEffort << endl;
                return currNode.maxTillNow;
            }

            for(int i=0; i<4; i++){
                int currX = currNode.row + dx[i];
                int currY = currNode.col + dy[i];

                if(isValid(row, col, currX, currY) && !visited[currX][currY]/*!currNode.visited[{currX, currY}]*/){
                    Node temp(
                        currX,
                        currY,
                        max(currNode.maxTillNow, abso(heights[currX][currY] - heights[currNode.row][currNode.col]))
                    );

                    s.push(temp);
                }
            }
        }

        return 0;
    }
};