class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(!(k&1)) return -1;
        if(k % 5 == 0) return -1;

        int lastRemainder = 1;
        if(lastRemainder % k == 0) return 1;

        for(int i = 1; i<100001; i++){
            lastRemainder = ((((lastRemainder%k) * (10 % k)) % k) + 1)%k;
            if(lastRemainder == 0) return i+1;
        }

        return -1;

    }
};

// https://leetcode.com/problems/smallest-integer-divisible-by-k/



class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(!(k&1)) return -1;
        if(k % 5 == 0) return -1;

        int lastRemainder = 1;
        if(lastRemainder % k == 0) return 1;

        // by pigeonHole principle if the loop continues more than k times
        // then we have a duplicate remainder 
        // and which means it's a loop by itself
        // no solution exists

        // https://leetcode.com/problems/smallest-integer-divisible-by-k/editorial/comments/1197777

        for(int i = 1; i<=k; i++){
            lastRemainder = ((((lastRemainder%k) * (10 % k)) % k) + 1)%k;
            if(lastRemainder == 0) return i+1;
        }

        return -1;

    }
};

// https://leetcode.com/problems/smallest-integer-divisible-by-k/

/*
That's a great insight. Here are a few additional thoughts on how I interpreted it

The number K divides the whole number space in K buckets identified by 0,1,....,K-1.
Every number 'num' can be assigned to one of these buckets on the basis for bucket-id= num % K
An interesting feature of these buckets is that if we multiply any item of bucket A by say M, and the resulting number falls is bucket B, then it is assured that it holds true for all the items of that bucket.
For e.g. let's say K=3, so we have all the number assigned to one of these 3 buckets

bucket-0 [0,3,6,9,...] 
bucket-1 [1,4,7,10,..] 
bucket-2 [2,5,8,11,...]
Now let's do an operation of multiplying by 10 and adding 1.

0           * 10 + 1 = 1
(bucket-0)            (bucket-1)

3           * 10 + 1 = 31
(bucket-0)            (bucket-1)

6           * 10 + 1 = 61
(bucket-0)            (bucket-1)
So we can see that this operation always results in the number belonging to bucket '0' getting mapped to bucket '1'.

Let's try with another bucket,

2           * 10 + 1 = 21
(bucket-2)            (bucket-0)

5           * 10 + 1 = 51
(bucket-2)            (bucket-0)

11           * 10 + 1 = 111
(bucket-2)            (bucket-0)
Here again we can see that this operation always results in the number belonging to bucket '2' getting mapped to bucket '0'.

The above observation translates into the following:

For a given operation (multiply by 10 and add 1) in this case, all the numbers belonging to a bucket-A always get transformed to numbers belonging bucket-B. So if we end up in a cycle of BucketA -> BucketB -> BucketC and then back to BucketA, we'll keep circulating in this cycle infinitely and never reach our goal (the bucket of numbers with 0-remainder). To avoid this, we must break out immediately if we see the same bucket again which we have already see earlier. This is precisely the purpose of the set to store the already "seen" remainders.

Since the bucket to which the result belongs after the operation (multiply by 10 and add 1), is independent of the number itself and just depends on the bucket of that number, the operation result is effectively equivalent to doing the operations on its bucket's identifier (i.e. the remainder) That's why we can do
n = reminder * 10 + 1; instead of n = n*10 + 1

Here's the implementation based on these observations:

class Solution {
    public int smallestRepunitDivByK(int K) {
        if(K % 2 == 0 || K % 5 == 0) {
            return -1;
        }
        int n = 1;
        int ans = 1;
        Set<Integer> seenRemainders = new HashSet<>();
        int remainder = n % K;
        while(remainder != 0) {
            if(seenRemainders.contains(remainder)) {
                return -1;
            }
            seenRemainders.add(remainder);
            n = remainder * 10 + 1;
            remainder = n % K;
            ans++;
        }
        return ans;
    }
}
*/