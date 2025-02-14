class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,long long> freq;

        long long sum = 0;

        for(long long i=0; i<wall.size(); i++){
            long long prefix = 0;
            for(long long j=0; j<wall[i].size()-1; j++){ // -1 as I don't want the sum to get stored as freq
                prefix += wall[i][j];
                freq[prefix]++;
            }
        }

        //freq.erase(sum);
        long long maxi = 0;


        for(auto entry: freq){
            maxi = max(maxi, entry.second);
        }


        return wall.size() - maxi;

    }
};

// https://leetcode.com/problems/brick-wall/submissions/1542562065/


class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size(); // Number of rows
        unordered_map<int, int> mp; // Map to store the frequency of each gap position

        // Calculate gap positions for each row
        for (auto& row : wall) {
            vector<int>::size_type curr = 0; // Cumulative position of gaps
            for (int j = 0; j < row.size() - 1; ++j) { // Exclude the last brick
                curr += row[j];
                mp[curr]++; // Increment the count for the current gap position
            }
        }

        int maxGaps = 0; // Maximum number of rows that share a gap position
        for (auto& [gap, count] : mp) {
            maxGaps = max(maxGaps, count);
        }

        // The minimum number of bricks cut is total rows minus max gaps
        return n - maxGaps;
    }
};