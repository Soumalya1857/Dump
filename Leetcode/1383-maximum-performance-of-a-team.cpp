class ComparePQ{


    public:
        bool operator()(const pair<int,int> &a, const pair<int,int> &b){
        if(a.first < b.first){
            return true;
        }else if(a.first == b.first){
            return a.second < b.second;
        }

        return false;
    }
}


;

class Solution {
private:
    int mod = 1e9 + 7;
public:
    bool static compare(const pair<int,int> &a, const pair<int,int> &b){
        if(a.second > b.second){
            return true;
        } else if(a.second == b.second){
            return a.first > b.first;
        }

        return false;
    }


    // bool static comparePQ(const pair<int,int> &a, const pair<int,int> &b){
    //     if(a.first < b.first){
    //         return true;
    //     }else if(a.first == b.first){
    //         return a.second < b.second;
    //     }

    //     return false;
    // }

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {

        vector<pair<int,int>> engg; // speed, efficiency

        for(int i=0; i<n; i++){
            engg.push_back({speed[i], efficiency[i]});
        }


        sort(engg.begin(), engg.end(), compare); // efficiency => descending


        priority_queue<pair<int,int>, vector<pair<int,int>>, ComparePQ> pq;


        int currSumOfSpeed = 0;
        int currEfficiency = 1e9;
        int maxPerformance = -1;

        for(int i=0; i<k; i++){
            currSumOfSpeed += engg[i].first;
            currEfficiency = min(currEfficiency, engg[i].second);
        }

        maxPerformance = max( maxPerformance, ((currSumOfSpeed)*currEfficiency)%mod );


        for(int i=k; i<n; i++){
            pair<int,int> top = pq.top();
            pq.pop(); // removed least speed person

            currSumOfSpeed -= top.first;

            // curr engg to go in
            currEfficiency = engg[i].second;
            currSumOfSpeed += engg[i].first;

            maxPerformance = max( maxPerformance, ((currSumOfSpeed)*currEfficiency)%mod );

            pq.push(engg[i]);
        }

        return maxPerformance;

    }
};

// https://leetcode.com/problems/maximum-performance-of-a-team/
