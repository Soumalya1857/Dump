class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        vector<bool> visited(n,false);
        
        queue<int> q;
        q.push(0);
       // visited[0] = true;
        while(!q.empty())
        {
            // bfs solution
            int curr = q.front(); q.pop();
            visited[curr] = true;
            for(int temp: rooms[curr])
            {
                if(!visited[temp]) q.push(temp);
            }
        }
        
        for(bool check : visited)
        {
            if(check == false) return false;
        }
        return true;
    }
};

// https://leetcode.com/problems/keys-and-rooms