class Solutioin{

    public:

        int solve(vector<int> &arr, int index, int prevIndex, int res){
            if(index == arr.size()){
                return res;
            }

            // not take first

            int localRes = solve(arr, index+1, prevIndex, res);


            // take condition
            if( prevIndex == -1 || (prevIndex != -1 && arr[index] > arr[prevIndex])){
                localRes = max(localRes, solve(arr, index+1, index, res+1));
            }

            return localRes;
        }


        int longestIncreasingSubsequence(vector<int> &arr){
            return solve(arr, 0,-1, 0);

            return maxiRes;
        }

        // time complexity = O(2^n)
        // for memorization= to handle -1 case, just take dp array of n+1
};

// Dijksta's algo

class Solution{
    bool static compare(pair<int,int> &a, pair<int,int> &b){
        if(a.second < b.second){
            return true;
        }else if(a.second > b.second){
            return false;
        }else{
            return a.first < b.first;
        }
    }
    void dijkstraAlgo(vector<vector<int>> &edges, int n){ // node1, node2, wt
        vector<vector<pair<int,int>>> adj(n);

        for(vector<int> edge: edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        priority_queue<pair<int,int>, compare> pq;

        pq.push({0,0});
        vector<int> dist(n, 1e8);
        dist[0] = 0;

        while(!pq.empty()){
            int currNode = pq.top().first;
            int currWeight = pq.top().second;
            pq.pop();

            for(pair<int,int> nei : adj[currNode]){
                if(dist[nei.first] > currWeight + nei.second){
                    dist[nei.first] = currWeight + nei.second;
                    pq.push({nei.first, dist[nei.first]}); // push with updated weight
                }
            }
        }

        return dist;
    }
}
;