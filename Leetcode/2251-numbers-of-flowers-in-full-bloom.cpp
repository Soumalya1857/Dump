/*
Collect start bloom time point array, then sort it.
Collect end bloom time point array, then sort it.

For each time point t in persons:

Binary search the upper bound of t in start, then we find the started flowers.
Binary search the lower bound of t in end, then we find the started flowers.
Blooming flowers = started flowers - ended flowers
*/
class Solution {

private:
    int lowerBound(vector<int> &arr, int time){
        int low = 0, high = arr.size()-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(arr[mid] < time){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }

        return high+1;
    }
    int upperBound(vector<int> &arr, int time){
        int low = 0, high = arr.size()-1;

        while(low <= high){
            int mid = (low + high)/2;

            if(arr[mid] <= time){
                low = mid+1;
            }else{ // arr[mid] > time
                high = mid-1;
            }
        }

        return low; // # of bloom flowers
    }
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {

        // sweep line algorithm
        // intuition: bloomed flower till Time T - ded flower till time T
        // sort bloomDay and dedDay separately
        // time t => upperBound of t in bloom - lowerBound of t in ded


        vector<int> bloom, dead;

        for(vector<int> flower : flowers){
            bloom.push_back(flower[0]);
            dead.push_back(flower[1]);
        }

        sort(bloom.begin(), bloom.end());
        sort(dead.begin(), dead.end());

        vector<int> ans;


        // traverse the people
        for(int i=0; i<people.size(); i++){
            int time = people[i];

            // upper bound in bloom array
            int bloomFlower = upperBound(bloom, time);
            int deadFlower = lowerBound(dead, time);

            //cout << time << " " << bloomFlower << " " << deadFlower << endl;

            ans.push_back(bloomFlower - deadFlower);
        }

        return ans;

    }
};
// https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/
// https://leetcode.com/problems/number-of-flowers-in-full-bloom/solutions/1977099/c-python-binary-search-and-sweep-line/
// https://www.youtube.com/watch?v=zY3Uty9IwvY