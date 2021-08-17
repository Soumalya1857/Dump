class Solution{
    public:
        bool canPlace(vector<int>&cows, int n, int cowNum, int dist)
        {
            int coord = cows[0]; // placed 1st cow at first place
            int count = 1;

            for(int i=1;i<n;i++)
            {
                if(cows[i]-coord >= dist) // next cow should be separated by atleast dist
                {
                    coord = cows[i];
                    count++;
                }
                if(count == cowNum) return true;
            }

            return false;
        }
        int aggresiveCows(vector<int> &cows, int n, int cowNum){

            // pick a number to check can it be a valid ans
            // largest min diff
            sort(cows.begin(), cows.end());
            int size = cows.size(), res=-1;
            int low=1, high=arr[size-1];

            while(low <= high)
            {
                int mid = (low+high) >> 1;
                if(canPlace(cows,n,cowNum,mid))
                {
                    res = mid;
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }

            return -1;
        }
};
