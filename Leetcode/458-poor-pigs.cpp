class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // best explanation: https://youtu.be/YQJLNxveyKg?si=K5wU5v5JeE4RcuvT
        // https://leetcode.com/problems/poor-pigs/solutions/94266/another-explanation-and-solution/
        // https://leetcode.com/problems/poor-pigs/solutions/94273/solution-with-detailed-explanation/

        // (trial + 1) ^ pigs >= buckets
        // => pigs = log(buckets/(trial+1))

        //if(buckets <= ((minutesToTest/minutesToDie)+1)) return 1;

        return (int)ceil(log2(buckets)/log2((minutesToTest/minutesToDie)+1));
    }
};

// https://leetcode.com/problems/poor-pigs/submissions/1281996525/