class Solution {
public:
     bool operator()(
            pair<int, int> const& a,
           pair<int, int> const& b)
        {
            return a.first < b.first;
        }

    int dist(vector<int> a){
        return a[0]*a[0] + a[1]*a[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<vector<int>> ans;

        for(int i =0; i<points.size(); i++){
            pq.push({dist(points[i]), i});
        }

        while(!pq.empty() && k--){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;

    }
};

// https://leetcode.com/problems/k-closest-points-to-origin/

// good solution
// https://leetcode.com/problems/k-closest-points-to-origin/solutions/221532/c-stl-quickselect-priority-queue-and-multiset/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};
