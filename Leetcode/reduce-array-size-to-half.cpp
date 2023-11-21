class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> um;

        for(int i : arr){
            um[i]++;
        }

        vector<int> array;
        for(auto entry : um){
            array.push_back(entry.second);
        }

        um.clear();

        sort(array.begin(), array.end(), greater<int>());
        int i, sum=0;
        for(i=0; i<array.size(); i++){
            sum += array[i];
            if(sum >= arr.size()/2) break;
        }

        return i+1;


           
    }
};

// https://leetcode.com/problems/reduce-array-size-to-the-half/