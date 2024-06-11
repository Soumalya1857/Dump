
// https://leetcode.com/problems/hand-of-straights/description/
// editorial: https://leetcode.com/problems/hand-of-straights/editorial/
class Solution {
public:
    void printAll(vector<vector<int>> &v){
        for(int i=0; i<v.size(); i++){
            for(int j=0; j<v[0].size(); j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
    }
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size() % groupSize != 0) return false;

        int totalGroups = hand.size() / groupSize;

        map<int,int> freq;
        for(int i=0; i<hand.size(); i++){
            freq[hand[i]]++;
        }

        // iterate over the map and try to build order
        //vector<vector<int>> allocation(totalGroups, vector<int>());

        for(auto it=freq.begin(); it!=freq.end(); it++){
            int freqNum = it->second;
            int num = it->first;

            while(freq[num] > 0){
                freq[num]--;
                for(int i=1; i<groupSize; i++){
                    if(freq[num+i] != 0){
                        freq[num+i]--;
                    }else{
                        return false;
                    }
                }
            }

            // for(int i=0; i<totalGroups; i++){

            //     while(freqNum > 0){

            //         // if(allocation[i].size() != groupSize){
            //         //     int size = allocation[i].size();
            //         //     if(size > 0 && num != 1+allocation[i][size-1]){
            //         //         printAll(allocation);
            //         //         cout << "num: " << num << endl;
            //         //         return false;
            //         //     }
            //         //     allocation[i].push_back(num);
            //         //     freqNum--;
            //         // }



            //     }
            // }
        }

        return true;
    }
};