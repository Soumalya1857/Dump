class Solution {
public:
    
    static bool compare(const vector<int>&a, const vector<int>&b){
        if(a[0] < b[0]) return true;
        else if(a[0] > b[0]) return false;
        else{
            if(a[1] < b[1]) return true;
            else return false;
        }
    }
    
  
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        
        vector<vector<int>> series(2*times.size(), vector<int>(3)); // time ---- arrival ------ friendId
        int i = 0, j = 0;
        for(auto x : times){
            vector<int> temp(3);
            
            temp[0] = x[0];
            temp[1] = 1; // arrival
            temp[2] = i;
            
            series[j++] = temp;
            
            temp[0] = x[1];
            temp[1] = 0; // deperture
            temp[2] = i;
            series[j++] = temp;
            
            i++;
        }
        
        sort(series.begin(), series.end(), compare);
        //vector<int>friends(times.size(), -1); // which friend allocated which chair
        unordered_map<int,int> friends;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int chair = 0; chair<times.size();chair++)
                pq.push(chair);
        
        // iterate over time series
        for(auto e : series){
            
            if(e[1] == 1) // arrival
            {
                int currChair = pq.top();
                if(e[2] == targetFriend) return currChair;
                pq.pop();
                friends[e[2]] = currChair;
            }
            
            else if(e[1] == 0)// deperture
            {
                int chair = friends[e[2]];
                friends[e[2]] = -1;
                pq.push(chair);
            }
        }
        
        return friends[targetFriend];
    }
};

// prb: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair
// think aboyut least recently used algo---kinda same
// used pq as mean heap..could have used better stls
// not at all optimmu


class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int k) {

        //sort the times based on their arrival times
        vector<vector<int>> arr(times.size(),vector<int>(3));

        for(int i=0;i<times.size();i++)
        {
            arr[i]={times[i][0],times[i][1],i};
        }

        //sort
        sort(arr.begin(),arr.end());



        priority_queue<int,vector<int>,greater<int>> avail;

        using pi=pair<int,int>;

        //min heap
        priority_queue<pi,vector<pi>,greater<pi>> booked;

        int currChair=0;
        int i=0;
        while(arr[i][2]!=k)
        {
            //check if any seat gets freed for the current time
            while(!booked.empty() && booked.top().first <= arr[i][0])
            {
                auto [time,ch]=booked.top();
                booked.pop();
                avail.push(ch);
            }
            if(avail.empty())
            {
                //use the curr chair
                booked.push({arr[i][1],currChair});
                currChair++;
            }
            else{
                //use the avail chairs
                int ch=avail.top();
                avail.pop();
                booked.push({arr[i][1],ch});
            }
            i++;
        }
         while(!booked.empty() && booked.top().first <= arr[i][0])
            {
                auto [time,ch]=booked.top();
                booked.pop();
                avail.push(ch);
            }
        return (avail.empty()) ? currChair :  avail.top();
    }
};
// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/discuss/1591822/Easy-C%2B%2B-heap-solution-oror-commented
