class Solution {
public:
    pair<int,int> getCoord(int num, int n){
        if(num == n*n){
            if(n%2 == 0) return {0,0};
            else return {0,n-1};
        }
        int row = n - (num/n ) -1;
        int col = row%2 == 0 ?  n-1-((num%n-1)+n)%n : ((num%n-1)+n)%n;

        return {row, col};
    }

    int snakesAndLadders(vector<vector<int>>& board) {
        // bfs with visited array
        int row = board.size();

        vector<vector<bool>> visited(row+2, vector<bool>(row+2,false));

        queue<pair<int,int>> q; // val, count
        q.push({1,0});

        while(!q.empty()){
            pair<int,int> curr = q.front(); q.pop();
            auto pos = getCoord(curr.first, row);
            if(visited[pos.first][pos.second]) continue;

            cout << "position x: " << pos.first << " pos y: " << pos.second << " move:" << curr.second << " value: " << curr.first <<  endl;

            visited[pos.first][pos.second] = true;
            if(curr.first == row*row){
                return curr.second;
            }

            for(int i = curr.first+1; i<=min(curr.first + 6, row*row); i++){
               // cout << "error1\n";
                pair<int, int> pos = getCoord(i,row);
               // cout << "error2\n";
                if(!visited[pos.first][pos.second]){
                    if(board[pos.first][pos.second] == -1){
                        q.push({i, curr.second+1});
                    } else{
                        q.push({board[pos.first][pos.second], curr.second + 1});
                    }
                }
            }
        }

        return -1;
    }
};

// https://leetcode.com/problems/snakes-and-ladders/description/


// solution: https://leetcode.com/problems/snakes-and-ladders/solutions/3092265/c-simple-bfs-with-full-explanation-beats-100/

// change to 1D array then bfs...wow
class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        int n = board.size(), lbl = 1;
        vector<pair<int, int>> cells(n*n+1);
        vector<int> columns(n);
        iota(columns.begin(), columns.end(), 0);
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) {
                cells[lbl++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n*n+1, -1);
        dist[1] = 0;
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int next = curr + 1; next <= min(curr+6, n*n); next++) {
                auto [row, column] = cells[next];
                int destination = board[row][column] != -1 ? board[row][column] : next;
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1;
                    q.push(destination);
                }
            }
        }
        return dist[n*n];
    }
};