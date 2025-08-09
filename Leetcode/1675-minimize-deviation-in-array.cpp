class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // slash the max of the array if it's an even
        // multiply the min of the array if it's odd

        // loop continues till min is even and max is odd

        int size = nums.size();


        set<int> s;
        for(int num : nums){
            s.insert(num);
        }

        int globalDiff = INT_MAX;

        while(size--){
            int mini = *s.begin();
            int maxi = *s.rbegin();

            globalDiff = min(globalDiff, (maxi-mini));

            // if(mini%2 ==0 && maxi%2==1){
            //     break;
            // }

            if(mini%2 == 1){
                s.erase(s.find(mini));
                s.insert(mini*2);
            }

            mini = *s.begin();
            maxi = *s.rbegin();
            globalDiff = min(globalDiff, (maxi-mini));



            if(maxi%2 == 0){
                s.erase(s.find(maxi));
                s.insert(maxi/2);
            }

            mini = *s.begin();
            maxi = *s.rbegin();
            globalDiff = min(globalDiff, (maxi-mini));
        }


        return globalDiff;

    }


};

// https://leetcode.com/problems/minimize-deviation-in-array/?source=submission-noac
        // https://leetcode.com/problems/minimize-deviation-in-array/description

// ============================================================================
// ============================================================================

class Solution {
public:
    int minimumDeviation(vector<int>& nums) {

         // slash the max of the array if it's an even
        // multiply the min of the array if it's odd

        // loop continues till min is even and max is odd

        /*
        We have two types of operations: double odd numbers, and halve even numbers. We can try to sort all numbers, and increase the smallest number (if it's odd) and decrease the largest number (if it's even). This can get quite complicated.

Intuition 1: we can divide even numbers multiple times - till we get an odd number, but we can only double odd numbers once. After that, it will become an even number.

Intuition 2: Even numbers never increase.

Flip: we can double all odd numbers first, so we can get forget of the second operation. Now, we only need to decrease the largest number - while it's even, which results a very simple solution.

Solution
Double odd numbers and put all numbers into a max heap. Track the smallest number. Track the minimum difference between the top of the heap and the smallest number. While the top of the heap is even, remove it, divide, and put back to the heap.

Two solutions below use the same approach; the first one is easier to read, and the second one - faster (since we use the array version of max heap).
        */



        int res = INT_MAX, min_n = INT_MAX;
        priority_queue<int> pq;
        for (auto n : nums) {
            n = n % 2 ? n * 2 : n;
            pq.push(n);
            min_n = min(min_n, n);
        }
        while (pq.top() % 2 == 0) {
            res = min(res, pq.top() - min_n);
            min_n = min(min_n, pq.top() / 2);
            pq.push(pq.top() / 2);
            pq.pop();
        }
        return min(res, pq.top() - min_n);

        // https://leetcode.com/problems/minimize-deviation-in-array/?source=submission-noac
        // https://leetcode.com/problems/minimize-deviation-in-array/description
    }
    //int minimumDeviation(vector<int>& nums) {
        // slash the max of the array if it's an even
        // multiply the min of the array if it's odd

        // loop continues till min is even and max is odd



        // int size = nums.size();
        // int miniN = INT_MAX;


        // set<int> s;
        // for(int num : nums){
        //     num = num%2==0 ? num : num*2; // push all even, no need to check odd
        //     s.insert(num);
        //     miniN = min(miniN, num);
        // }

        // int globalDiff = INT_MAX;
        // int maxi = *s.rbegin();
        // while(maxi %2 == 0){ // maximum is even
        //     globalDiff = min(globalDiff, maxi-miniN);
        //     miniN = min(miniN, maxi / 2);
        //     s.erase(s.find(maxi));
        //     s.insert(maxi/2);

        //     maxi = *s.rbegin();
        // }

        // return globalDiff;





        // while(maxi%2 == 0){

        //     globalDiff = min(globalDiff, (maxi-mini));

        //     if(maxi % 2 == 0){
        //         s.erase(s.find(maxi));
        //         maxi = maxi/2;
        //         s.insert(maxi);
        //     }

        //     mini = *s.begin();
        //     maxi = *s.rbegin();

            // // if(mini%2 ==0 && maxi%2==1){
            // //     break;
            // // }

            // if(mini%2 == 1){
            //     s.erase(s.find(mini));
            //     s.insert(mini*2);
            // }

            // mini = *s.begin();
            // maxi = *s.rbegin();
            // globalDiff = min(globalDiff, (maxi-mini));



            // if(maxi%2 == 0){
            //     s.erase(s.find(maxi));
            //     s.insert(maxi/2);
            // }

            // mini = *s.begin();
            // maxi = *s.rbegin();
            // globalDiff = min(globalDiff, (maxi-mini));
        //}


        //return globalDiff;

    //}


};