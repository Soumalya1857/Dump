/*
The greedy choice is to always pick the next activity whose finish time is least among the remaining activities 
and the start time is more than or equal to the finish time of the previously selected activity. 
We can sort the activities according to their finishing time so that we always consider the next activity as minimum finishing time activity.
1) Sort the activities according to their finishing time 
2) Select the first activity from the sorted array and print it. 
3) Do the following for the remaining activities in the sorted array. 
.......a) If the start time of this activity is greater than or equal to the finish time of the previously selected activity 
then select this activity and print it.
*/


class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    static bool compare(const pair<int,int>& a, const pair<int,int> &b)
    {
        return a.second < b.second; // to sort in ascending order
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        
        // sort the start and end states accordingly
        vector<pair<int,int>> meet;
        for(int i=0;i<n;i++) meet.push_back({start[i],end[i]});
        
        sort(meet.begin(), meet.end(), compare);
        int count=0,i=0,j;
        for(j=1;j<n;j++)
        {
            if(meet[i].second < meet[j].first) count++,i=j;
        }
        return count+1;
        
    }
};

// problem: https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620