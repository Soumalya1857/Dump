class DSU{
    int num;
    public:

        vector<int>rank, parent;

        void makeSet(int num){
            vector<int> rank(num, 0);
            vector<int> parent(num,-1);

            for(int i=0; i<num; i++){
                parent[i] = i;
            }

            this->rank = rank;
            this->parent = parent;
        }

        DSU(int num){
            this->num = num;
            makeSet(num);
        }

        int findParent(int u){
            if(parent[u] == u){
                return u;
            }

            return parent[u] = findParent(parent[u]);
        }

        void makeUnion(int u, int v){
            u = findParent(u);
            v = findParent(v);

            if(rank[u] > rank[v]){
                parent[v] = u;
            }else if(rank[v] > rank[u]){
                parent[u] = v;
            }else{
                parent[v] = u;
                rank[u]++;
            }
        }


};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mp; // mail, index
        DSU dsu(accounts.size());

        for(int i=0; i<accounts.size(); i++){
            for(int j=1; j<accounts[i].size(); j++){

                if(mp.find(accounts[i][j]) == mp.end()){
                    mp[accounts[i][j]] = i;
                }else{
                    dsu.makeUnion(mp[accounts[i][j]], i);
                }
            }
        }

        vector<vector<string>> temp(accounts.size()), ans;//(accounts.size());

        for(auto it = mp.begin(); it!=mp.end(); it++){
            string email = it->first;
            int index = dsu.findParent(it->second);
            temp[index].push_back(email);
        }

        // sort the ans
        for(vector<string>& list : temp){
            if(list.size() > 0){
                sort(list.begin(), list.end());
            }
        }

        // create ans
        for(int i=0; i<accounts.size(); i++){
            if(temp[i].size() == 0) continue;

            vector<string> mailString;
            mailString.push_back(accounts[i][0]);
            for(string mail: temp[i]){
                mailString.push_back(mail);
            }

            ans.push_back(mailString);
        }



        return ans;
    }
};

// https://leetcode.com/problems/accounts-merge/submissions/1285045088/
// https://www.youtube.com/watch?v=FMwpt_aQOGw&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=50