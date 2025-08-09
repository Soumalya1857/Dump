class Solution {
public:
    vector<string> next(string lock){
        // returns the states possible by reaching just 1 step
        vector<string> ans;
        for(int i=0; i<lock.length(); i++){
            string copy = lock, copy1 = lock;
            // +1
            copy[i] = ((lock[i]-'0')+1)%10 + '0';
            ans.push_back(copy);

            // -1
            copy1[i] = ((lock[i]-'0')-1 + 10)%10 + '0';
            ans.push_back(copy1);
        }
        return ans;
    }
    int openLock(vector<string>& deadends, string target) {
        // every state will have 4 possibilities
        unordered_map<string, bool> dead, visited;
        for(string d : deadends){
            dead[d] = true;
        }

        queue<pair<string, int>> q;
        q.push({"0000", 0});

        while(!q.empty()){
            pair<string, int> curr = q.front(); q.pop();

            if(dead[curr.first])
                continue;

            if(visited[curr.first]) 
                continue;
            
            if(curr.first == target)
                return curr.second;

            visited[curr.first] = true;

            vector<string> nextStates = next(curr.first);
            for(string s : nextStates){
                if(!dead[s]){
                    q.push({s,curr.second+1});
                }
            }
        }

        return -1;
    }
};

// https://leetcode.com/problems/open-the-lock/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        if (deadSet.count("0000")) return -1;
        queue<string> q({"0000"});
        for (int steps = 0; !q.empty(); ++steps) {
            for (int i = q.size(); i > 0; --i) {
                auto curr = q.front(); q.pop();
                if (curr == target) return steps;
                for (auto nei : neighbors(curr)) {
                    if (deadSet.count(nei)) continue;
                    deadSet.insert(nei); // Marked as visited
                    q.push(nei);
                }
            }
        }
        return -1;
    }
    vector<string> neighbors(const string& code) {
        vector<string> result;
        for (int i = 0; i < 4; i++) {
            for (int diff = -1; diff <= 1; diff += 2) {
                string nei = code;
                nei[i] = (nei[i] - '0' + diff + 10) % 10 + '0';
                result.push_back(nei);
            }
        }
        return result;
    }
};