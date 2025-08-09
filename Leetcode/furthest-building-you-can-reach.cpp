class Solution {
public:
    int abso(int n){
        return n<0 ? -n : n;
    }
    // int solve(vector<int>&heights, int bricks, int ladders, int index){
    //     if(index >= heights.size()-1 || (bricks <= 0 && ladders <= 0)){
    //         return index;
    //     }

    //     if(index < heights.size()-1 && heights[index] >= heights[index+1]){
    //         return solve(heights, bricks, ladders, index+1);
    //     }
    //     else{

    //         int ladderIndex=INT_MIN, bricksIndex=INT_MIN;
    //         // if ladders can be used
    //         if(ladders > 0) {
    //             ladderIndex = solve(heights, bricks, ladders-1, index+1);
    //         }

    //         if(index < heights.size()-1 && abso(heights[index+1]-heights[index]) <= bricks){
    //             bricksIndex = solve(heights, bricks-abso(heights[index+1]-heights[index]), ladders, index+1);
    //         }

    //         return max(ladderIndex, bricksIndex);
    //     }

    //     // int ladderIndex=INT_MIN, bricksIndex=INT_MIN;
    
        
    // }
    // int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
    //     return solve(heights, bricks, ladders, 0);
    // }

    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int i=0;
        for(i=0; i<heights.size()-1; i++){
            // if(i<heights[i]-1 && heights[i] >= heights[i+1]) {
            //     cout << "index updated to: " << i+1 << endl;
            //     continue;
            // }
               

            
            // if(abso(heights[i+1]-heights[i]) <= bricks){
            //     pq.push(abso(heights[i+1]-heights[i]));
            //     bricks-= abso(heights[i+1]-heights[i]);
            //     cout << "bricks here: " << bricks << " index to: " << i+1 << endl;
            //     continue;

            // } else {
            //     bool isInside = false;
            //     while(!pq.empty() && abso(heights[i+1]-heights[i]) > bricks && ladders > 0 ){
            //       int top = pq.top(); pq.pop();
            //       bricks += top;
            //       cout << "bricks there: " << bricks << " index to: " << i+1 << endl;
            //       ladders--;
            //       isInside = true;
            //     }
            //     if(isInside){
            //         pq.push(abso(heights[i+1]-heights[i]));
            //         bricks-= abso(heights[i+1]-heights[i]);
            //     }
            //     if(!isInside) break;
            // }

            // if(abso(heights[i+1]-heights[i]) > bricks && ladders<=0) break;

            int diff = heights[i+1]-heights[i];
            if(diff <= 0) continue;

            bricks -= diff;
            pq.push(diff);

            if(bricks<0){
                bricks += pq.top();
                ladders--;
                pq.pop();
            }

            if(ladders<0) break;
        }

        //if(i == heights.size()-2 && heights[heights.size()-2] >= heights[heights.size()-1]) i++;

        return i;
    }
};


// https://leetcode.com/problems/furthest-building-you-can-reach/