class Solution {
public:
    template <typename T>
    void print(vector<T> &v){
        for(T b : v){
            cout << b << " ";
        }

        cout << endl;
    }

    void bfs(vector<int>& edges, int node, vector<int> &dist, vector<bool> &isReachable ){
        queue<int> q;
        q.push(node);

        int distance = 0;

        while(!q.empty()){
            distance++;
            int curr = q.front(); q.pop();

            dist[curr] = max(dist[curr], distance);
            isReachable[curr] = true;

            if(edges[curr] != -1 && !isReachable[edges[curr]]){
                q.push(edges[curr]);
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int N = edges.size();
        vector<bool> isReachable1(N, false), isReachable2(N, false);
        vector<int> dist(N,-1);

        bfs(edges, node1, dist, isReachable1);
        bfs(edges, node2, dist, isReachable2);

        // cout << "reachable1 -->\n";
        // print(isReachable1);

        // cout << "reachable2 -->\n";
        // print(isReachable2);

        // cout << "dist -->\n";
        // print(dist);


        int ans = INT_MAX;
        int index = -1;
        for(int i=0; i<N; i++){
            if(isReachable1[i] && isReachable2[i]){
                if(dist[i] < ans){
                    ans = dist[i];
                    index = i;
                }
            }
        }

        return index;

    }
};

// https://leetcode.com/problems/find-closest-node-to-given-two-nodes/