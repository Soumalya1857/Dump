class Solution {
public:
    
    int calculate(int round, int index/*0 based indexing*/, int people)// given n and index of a person, this calculate no of candies he got
    {
        // index s are of n+1
         if(round<0) return 0;
        int n = round;
        int res = (index+1)*(n+1) + people*((n*(n+1))/2);
        return res;
    }
    
    
    vector<int> distributees(long long int candies, int num_people) {
        
        int persons= (int)((sqrt(8*candies+1)-1.0)/2.0); // total no of person that can get candies
        int excess = candies-(persons*(persons+1))/2; // last person will get these
        
        
        int last_person_index = persons % num_people;    
        int round = persons/num_people;
        
        vector<int>ans(num_people,0);
        
        for(int index=0;index<num_people;index++)
        {
            if(index < last_person_index)
            {
                ans[index] = calculate(round, index, num_people);
            }
            else if(index == last_person_index)
            {
                ans[index] = calculate(round-1,index,num_people) + excess;
            }
            else
            {
                ans[index] = calculate(round-1,index,num_people);
            }
        }
        
        return ans;
    }
};

/*
https://leetcode.com/explore/challenge/card/august-leetcoding-challenge/551/week-3-august-15th-august-21st/3427/
*/