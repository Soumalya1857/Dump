class Solution {
public:
    
    void printVector(vector<int> &arr)
    {
        for(int nums: arr) cout << nums << " ";
        cout << "\n";
    }
    int trap(vector<int>& height) {
        // need to find larger at right and also left
        
//         int size = height.size();
//         stack<pair<int,int>> s; // first is height and second one is index
        
        
//         vector<int> right(size,-1);
//         s.push({height[0],0});
//         for(int i=1;i<size;i++)
//         {
//             if(s.empty()) s.push({height[i],i});
            
//             while(!s.empty() && s.top().first < height[i])
//             {
//                 // assign tops NGE as height[i]
//                 right[s.top().second] = height[i];
//                 s.pop();
//             }
            
//             s.push({height[i],i});
//         }
        
//         // print -1 for left out elements of the stack
//         while(!s.empty())
//         {
//             right[s.top().second] = -1;
//             s.pop();
//         }
        
        
//         // (min(left,right)-ownheight)*dist
        
        
//         /// similarly make the NEXT GREATEE AT LEFT (NGL)
//         vector<int> left(size,-1);
//         s.push({height[size-1], size-1});
//         for(int i=size-2; i>=0;i--)
//         {
//             if(s.empty()) s.push({height[i],i});
            
//             while(!s.empty() && s.top().first < height[i])
//             {
//                 left[s.top().second] = height[i];
//                 s.pop();
//             }
//             s.push({height[i],i});
//         }
        
//         while(!s.empty())
//         {
//             left[s.top().second] = -1;
//             s.pop();
//         }
        
//         printVector(right);
//         printVector(left);
        
        
//         int sum = 0;
//         for(int i=0;i<size;i++)
//         {
//             if(left[i] != -1 && right[i] != -1)
//             {
//                 sum += min(left[i], right[i]) - height[i];
//                 cout << "index: " << i << " contri: " << min(left[i], right[i]) - height[i] << endl;
//             }
//         }
        
        
//         return sum;
        
        
        // the point is not to create NGE array but to find next highest element on array
        
        int size = height.size(), sum=0;
        vector<int> left(size,-1), right(size,-1);
        
        left[0] = height[0];
        for(int i=1;i<size;i++)
        {
            left[i] = max(height[i], left[i-1]);
        }
        
        right[size-1] = height[size-1];
        for(int i=size-2;i>=0;i--)
        {
            right[i] = max(right[i+1],height[i]);
        }
        
        
        for(int i=0;i<size;i++)
        {
            if(left[i] != -1 && right[i] != -1)
            {
                sum += min(right[i],left[i]) - height[i];
            }
        }
        return sum;
    }
};

// prob: https://leetcode.com/problems/trapping-rain-water/
// soln: https://www.geeksforgeeks.org/trapping-rain-water/
// youtube: https://www.youtube.com/watch?v=m18Hntz4go8&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=42



class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> lmax(size, -1), rmax(size,-1);
        
        int left = -1, right = -1;
        for(int i=0; i<size;i++){
            if(left > height[i]) lmax[i] = left;
            else{
                left = height[i];
                lmax[i] = -1;
            }
        }
        
        for(int i=size-1; i>=0;i--){
            if(right > height[i]) rmax[i] = right;
            else{
                right = height[i];
                rmax[i] = -1;
            }
        }
        
        int ans = 0;
        for(int i=0;i<size; i++){
            ans += max((min(lmax[i], rmax[i])-height[i]),0);
        }
        
        return ans;
    }
};