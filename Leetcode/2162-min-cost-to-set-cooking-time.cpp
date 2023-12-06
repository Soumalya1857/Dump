class Solution {
public:

    int calculate(int hour, int min, int startAt, int moveCost, int pushCost){
        int cost = 0;
        if(hour == INT_MAX || min == INT_MAX) return INT_MAX;
        if(hour == 100) return INT_MAX;
        int h1=0, h2=0, m1=0, m2=0;

        h2 = hour%10;
        hour/=10;
        h1 = hour;

        m2 = min%10;
        min /= 10;
        m1 = min;

        list<int> digits = {h1,h2,m1,m2};

        // drop initial zeros
        while(digits.front() == 0){
            digits.pop_front();
        }

        
        int currFinger = startAt;
        for(int num : digits){
            //cout << num << " ";
            if(currFinger != num){
                cost += moveCost;
            }

            cost += pushCost;
            currFinger = num;
        }

        //cout << endl;

        return cost;
    }

    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        int hour1 = INT_MAX, hour2 = INT_MAX, min1 = INT_MAX, min2 = INT_MAX;

        hour1 = targetSeconds / 60;
        min1 = targetSeconds % 60;

        if(hour1 > 0 && hour1 <= 100 && min1 < 40){
            hour2 = hour1-1;
            min2 = min1 + 60;
        } 


        return min(calculate(hour1, min1, startAt, moveCost, pushCost), 
                    calculate(hour2, min2, startAt, moveCost, pushCost));
    }
};

// https://leetcode.com/problems/minimum-cost-to-set-cooking-time/