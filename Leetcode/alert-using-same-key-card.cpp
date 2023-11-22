class Solution {
public:

    static bool comparator(const pair<int,int>& a, const pair<int,int> &b){
        if(a.first < b.first) return true;
        else if (a.first > b.first) return false;
        else{
            if(a.second < b.second) return true;
            else return false;
        }
    }
    int extractHour(string time){
        return stoi(time.substr(0,2));
    }

    int extractMin(string time){
        return stoi(time.substr(3,2));
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {

        unordered_map <string, vector<pair<int,int>>> map;
        vector<string> ans;

        for(int i=0; i<keyName.size(); i++){
            int hour = extractHour(keyTime[i]);
            int mins = extractMin(keyTime[i]);

            map[keyName[i]].push_back({hour, mins});
        }

        for(auto entry : map){
            sort(entry.second.begin(), entry.second.end(), comparator);
            int entrySize = entry.second.size();
            // sliding window of size 3
            for(int i=0; i<=entrySize-3; i++){
                if(entry.second[i].first == entry.second[i+2].first){
                    ans.push_back(entry.first);
                    break;
                } else if(entry.second[i].first + 1 == entry.second[i+2].first){
                    if(entry.second[i].second >= entry.second[i+2].second){
                        ans.push_back(entry.first);
                        break;
                    }
                }
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
        
    }
};

// https://leetcode.com/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/