class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> ans;
        if(finalSum & 1) return ans;
        
        // get n(n+1) just less than finalsum
        long long low = 1, high = 1e6, number = -1;
        
        // calculate max number n so that n*(n+1)is less than finalSum
        while(low <= high){
            // cout << "low: " << low << " high: " << high << endl;
            long long mid = (low + high)/2;
            long long decisionNum = mid * (mid + 1);
            if(decisionNum == finalSum){
                number = mid;
                break;
            }
            else if(decisionNum > finalSum){
                high = mid-1;
            }
            else {
                low = mid + 1;
            }
        }
        
        // high will contain the lower bound
        
        if(number != -1){
            for(long long i = 1; i<= number; i++)
                ans.push_back(i*2);
        }
        else{
            // high contains the lower bound
            long long diff = finalSum - high*(high+1);
            //cout << "Diff: " << diff << " Low: " << low << " High: " << high << endl;
            for(long long i=1; i<= high; i++){
                if(i == high) ans.push_back(i*2 + diff);
                else ans.push_back(i*2);
            }
        }
        
        return ans;
    }
};

// try calculating more lower and upper bound
// https://leetcode.com/problems/maximum-split-of-positive-even-integers/


// better solution
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> splits;
        if (finalSum % 2LL == 1) return splits;
        long long sum = 0;
        for (long long i = 2; sum + i <= finalSum; i+=2) {
            splits.push_back(i);
            sum += i;
        }
        if (sum != finalSum) {
            long long diff = finalSum - sum;
            if (splits.empty()) {
                splits.push_back(diff);
            } else {
                splits.back() = splits.back() + diff;
            }
        }
        return splits;
    }
};