class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int boats = 0, start = 0, end = people.size()-1;

        while(start <= end){
            if(people[start] + people[end] <= limit){
                boats++;
                start++;
                end--;
            } else{
                boats++;
                end--;
            }
        }

        return boats;

    }
};

// https://leetcode.com/problems/boats-to-save-people/