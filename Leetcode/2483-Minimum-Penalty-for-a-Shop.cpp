class Solution {
private:
    void printV(vector<int> &arr){
        for(int a : arr){
            cout << a << " ";
        }

        cout << endl;
    }
public:
    int bestClosingTime(string customers) {
        int size = customers.length();
        vector<int> suffixY(size+1, 0), prefixN(size+1, 0);

        prefixN[0] = 0;

        for(int i=1; i<=size; i++){
            prefixN[i] = prefixN[i-1] + (customers[i-1] == 'N' ? 1 : 0);
        }
        //prefixN[size] = prefixN[size-1];
        // ===================================================================

        suffixY[size] = 0;
        suffixY[size-1] = customers[size-1] == 'Y' ? 1 : 0;

        for(int i=size-2; i>=0; i--){
            suffixY[i] = suffixY[i+1] + (customers[i] == 'Y' ? 1 : 0);
        }

        // cout << "prefixN: ";
        // printV(prefixN);

        // cout << "SuffixY: ";
        // printV(suffixY);


        int minHour = -1, minCost = INT_MAX;

        for(int i=0; i<=size; i++){
            if(prefixN[i] + suffixY[i] < minCost){
                minCost = prefixN[i] + suffixY[i];
                minHour = i;
            }
        }

        return minHour;
    }
};

// https://leetcode.com/problems/minimum-penalty-for-a-shop/

// calculate precisely if I am closed at hour i, then how many cost I will incur for all prev 'N's
// and how many cost I will incurr for all upcoming 'Y's

// vector size+1 because we can be open for all the days or closed for all the days


// a simple and great solution from neetcode T__T
class Solution {
public:
    int bestClosingTime(string customers) {
        int res = -1, maxi = 0, pen = 0;
        for(int i = 0 ; i < customers.size() ; ++i) {
            if(customers[i] == 'Y')
                ++pen;
            else
                --pen;
            if(pen > maxi) {
                maxi = pen;
                res = i;
            }
        }
        return ++res;
    }
};