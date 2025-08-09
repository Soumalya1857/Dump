



 // tried the solution with sliding window with binary search, but baddddddd outcome
 // can't do as there can be many places where I have the whole match, but greedy method
 // will always choose the first one

 class Solution {
 public:

     bool compare(unordered_map<char,int>& freq, unordered_map<char,int>& freqT){

         for(auto it=freqT.begin(); it!= freqT.end(); it++){
             if(freq[it->first] < it->second)
                 return false;
         }

         return true;
     }

     int isWindowSizePossible(string s, int windowSize, unordered_map<char,int> &freqT){
         unordered_map<char, int> freq;
         int startIndex = -1;
         for(int i=0; i<windowSize; i++){
             freq[s[i]]++;
         }

         for(int i=windowSize; i<s.length(); i++){

             if(compare(freq, freqT)){
                 startIndex = i-windowSize;
                 return startIndex;
             }

             freq[s[i]]++;
             freq[s[i-windowSize]]--;
         }

         if(compare(freq, freqT)) return s.length() - windowSize;

         return -1;
     }
     string minWindow(string s, string t) {
         // binary search

         // freq of given word
         unordered_map<char, int> freqT;
         for(char ch : t){
             freqT[ch]++;
         }


         // windowSize
         int low = 0, high = s.length()-1, result = -1, startIndex = -1;

         while(low <= high){
             int mid = (low + high)/2;

             startIndex = isWindowSizePossible(s, mid, freqT);

             cout << "low: " << low << " high: " << high << " mid: " << mid << " index: " << startIndex << endl;

             if(startIndex != -1){
                 result = mid;
                 high = mid-1;
             }else{
                 low = mid+1;
             }
         }

          return startIndex == -1 ? "" : s.substr(startIndex, result);
     }


 };


 // actual method consists of two pointers, sliding window
 // VVVV bad solution it seems, leetcode has better solutions
 class Solution {
 public:

 // https://leetcode.com/problems/minimum-window-substring/description/
     bool compare(unordered_map<char,int>& freq, unordered_map<char,int>& freqT){
         for(auto it=freqT.begin(); it!=freqT.end(); it++){
             if(freqT[it->first] > freq[it->first]){
                 return false;
             }
         }

         return true;
     }


     string minWindow(string s, string t) {

         unordered_map<char, int> freqT, freq;
         for(char ch : t){
             freqT[ch]++;
         }

         int shortestWindow = INT_MAX, startIndex = -1;

         int left = 0, right = 0;

         while(left<s.length() && right<s.length()){

             freq[s[right]]++;

             while(compare(freq, freqT) && left <= right){
                 if(shortestWindow > right - left + 1){
                     shortestWindow = min(shortestWindow, right-left+1);
                     startIndex = left;
                 }

                 freq[s[left]]--;
                 left++;

             }

             right++;

         }

         return shortestWindow == INT_MAX ? "" : s.substr(startIndex, shortestWindow);

         // https://leetcode.com/problems/minimum-window-substring/submissions/1282891248/

     }
 };

 // =================================================================
 // better solution
 // stiver: https://www.youtube.com/watch?v=WJaij9ffOIY

 class Solution {
 public:
     string minWindow(string s, string t) {


         unordered_map<char, int> mp;
         for(char ch : t){
             mp[ch]++;
         }


         int left = 0, right = 0, count = 0, startIndex = -1, minLen = INT_MAX;

         while(right < s.length()){

             if(mp[s[right]] > 0){
                 count++;
             }

             while(count == t.length() && left<=right){
                 // got a valid substring
                 if(minLen > right-left+1){
                     minLen = right-left+1;
                     startIndex = left;
                 }

                 mp[s[left]]++;

                 // start increasing i also
                 if(mp[s[left]] > 0){
                     count -= 1; // if anyone gets positive then break the loop
                 }

                 left++;
             }

             mp[s[right]]--; // decrease because right is increasing
             right++;
         }


         return startIndex == -1 ? "" : s.substr(startIndex, minLen);
     }
 };
