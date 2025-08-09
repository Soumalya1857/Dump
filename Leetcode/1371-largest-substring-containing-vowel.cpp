class Solution {
public:
    int findTheLongestSubstring(string s) {
        // sliding window approach with diminiting value

        int windowSize = s.length();
        unordered_map<char, int> freq;

        for(windowSize = s.length(); windowSize >=0; windowSize--){
            // calculate freq map
            int endIndex = s.length()-1, startIndex = s.length()-windowSize;

            for(int index = startIndex; index <= endIndex; index++) freq[s[index]]++;
            char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

            // slide the window and check
            while(startIndex >= 0){
                int count[5] = {0};
                for(int i=0; i<5; i++){
                    count[i] = freq[vowels[i]];
                }

                bool isAcheived = true;
                for(int i : count){
                    //cout << i << " ";
                    if(i%2 == 1) {
                        isAcheived = false;
                        break;
                    } 
                }

                //cout << endl;
                
                if(isAcheived) return windowSize;

                if(startIndex == 0) break;

                // update the window
                freq[s[startIndex-1]]++;
                freq[s[endIndex]]--;

                startIndex--;
                endIndex--;

            }

            freq.clear();
        }

        return 0;
    }
};

// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/submissions/1111329062/

// but this can be optimized somehow