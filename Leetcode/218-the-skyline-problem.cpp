// https://leetcode.com/problems/the-skyline-problem/
//  https://youtu.be/GSBLe8cKu0s?si=zxD2AcIkca4cYJMQ => good explaination
// https://leetcode.com/problems/the-skyline-problem/solutions/2094329/c-easiest-explanation-ever-guaranteed-beginner-friendly-detailed-o-nlogn/
// https://leetcode.com/problems/the-skyline-problem/submissions/1284898339/

// Done solution

class Solution {
public:
    bool static compare(pair<int, pair<int,char>>& below, pair<int, pair<int,char>>& above)
    {
        if (below.first < above.first) {
            return true;
        }
        else if (below.first == above.first){

            if(below.second.second == 'e' && above.second.second == 'e'){
                return below.second.first < above.second.first; // if end, remove the smaller building first
            }else if(below.second.second == 's' && above.second.second == 's'){
                return below.second.first > above.second.first; // if start, add the bigger building first
            } else{     //  if(below.second.first == above.second.first){
                return below.second.second > above.second.second; // start should come first
            }
        }

        return false;
    }


    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        // no priority queue supports for good find and deletion
        // so we can use multiset
        // priority_queue< pair<int, pair<int,int>>, vector<inpair<int, pair<int,int>>>, Compare>  pq;
        // priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> activeHeightPq; // heights, end


        // multiset<pair<int, pair<int, char>>, decltype(Compare)> ms(Compare);

        vector<pair<int, pair<int,char>>> sortedBuild;
        multiset<int, greater<int>> height; // height priority
        height.insert(0);


        int top = 0; // calculate the active top

        vector<vector<int>> ans;

        for(vector<int> building : buildings){
            sortedBuild.push_back({building[0], {building[2], 's'}}); // s is start, e is end ( X, height, 's)
            sortedBuild.push_back({building[1], {building[2], 'e'}});
        }

        sort(sortedBuild.begin(), sortedBuild.end(), compare);

        for(auto wall : sortedBuild){

            if(wall.second.second == 's'){
                height.insert(wall.second.first); // insert height
            } else if(wall.second.second == 'e'){
                height.erase(height.find(wall.second.first));
            }

            int currMax = *height.begin();
            if(currMax != top){
                top = currMax;
                if(wall.second.second == 's') {
                    ans.push_back(vector<int>{wall.first, wall.second.first});
                }

                else if(wall.second.second == 'e'){
                    ans.push_back(vector<int>{wall.first, top});
                }
            }
        }


        return ans;



        // while(!pq.empty()){
        //     auto currBuild = pq.top();
        //     pq.pop();


        //     int activeHeight = 0;
        //     if(!activeHeightPq.empty()){
        //         activeHeight = activeHeightPq.top();
        //     }

        //     if(currBuild.second.second == 0){ // building starting
        //         if(currBuild.second.first > activeHeight){
        //             ans.push_back({currBuild.first, currBuild.second.first});
        //             activeHeights.push({currBuild.second.first, })
        //         }
        //     }
        // }

    }
};



// =====================================================

// some good solution

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        multiset<int> pq{0};

        vector<pair<int, int>> points;

        for(auto b: buildings){
            points.push_back({b[0], -b[2]});
            points.push_back({b[1], b[2]});
        }

        sort(points.begin(), points.end());

        // for(auto point : points){
        //     cout << "x: " << point.first << " h:" << point.second << endl;
        // }

        int ongoingHeight = 0;

        // points.first = x coordinate, points.second = height
        for(int i = 0; i < points.size(); i++){
            int currentPoint = points[i].first;
            int heightAtCurrentPoint = points[i].second;

            if(heightAtCurrentPoint < 0){
                pq.insert(-heightAtCurrentPoint);
            } else {
                pq.erase(pq.find(heightAtCurrentPoint));
            }

            // after inserting/removing heightAtI, if there's a change
            auto pqTop = *pq.rbegin();
            if(ongoingHeight != pqTop){

                cout << points[i].first << " " << points[i].second << endl;
                cout << ongoingHeight << " " << pqTop  << endl;
                cout << "================" << endl;
                ongoingHeight = pqTop;
                ans.push_back({currentPoint, ongoingHeight});
            }
        }

        return ans;
    }
};
