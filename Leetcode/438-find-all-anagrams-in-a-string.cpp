class Solution {
public:

    vector<int> findAnagrams(string s, string p) {
        // unordered_map<char, int> freq;
        // int count = p.length();

        // vector<int> ans;

        // for(char ch : p){
        //     freq[ch]--;
        // }

        // int first = 0, last = 0;

        // while(last < s.length() && first <= last){
        //     bool flag = false;

        //     while(count == 0){
        //         freq[s[first]]++;
        //         flag = true;
                
        //         if(freq[s[first]] == 0){
        //             count++;
        //             break;
        //         }

        //         first++;
        //     }

        //     if(flag){
        //         ans.push_back(first);
        //     }




        //     freq[s[last]]--;
        //     last++;
        // }


        // sliding window approach
        // search in a group of 3

        unordered_map<char, int> mp;
        for(char ch: p){
            mp[ch]++;
        }

        vector<int> ans;

        for(int i=0; i<p.size(); i++){
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
        }

        if(mp.size() == 0) ans.push_back(0);


        for(int i=p.length(); i<s.length(); i++){
            int last = i - p.length();

            mp[s[i]]--;
            mp[s[last]]++;

            if(mp[s[i]] == 0) mp.erase(s[i]);
            if(mp[s[last]] == 0) mp.erase(s[last]);

            if(mp.size() == 0) ans.push_back(last+1);
        }

        return ans;
    }
};
// https://leetcode.com/problems/find-all-anagrams-in-a-string/submissions/1542994679/
// https://leetcode.com/problems/find-all-anagrams-in-a-string/solutions/92007/sliding-window-algorithm-template-to-solve-all-the-leetcode-substring-search-problem/


public class Solution {
    public List<Integer> findAnagrams(String s, String t) {
        List<Integer> result = new LinkedList<>();
        if(t.length()> s.length()) return result;
        Map<Character, Integer> map = new HashMap<>();
        for(char c : t.toCharArray()){
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        int counter = map.size();
        
        int begin = 0, end = 0;
        int head = 0;
        int len = Integer.MAX_VALUE;
        
        
        while(end < s.length()){
            char c = s.charAt(end);
            if( map.containsKey(c) ){
                map.put(c, map.get(c)-1);
                if(map.get(c) == 0) counter--;
            }
            end++;
            
            while(counter == 0){
                char tempc = s.charAt(begin);
                if(map.containsKey(tempc)){
                    map.put(tempc, map.get(tempc) + 1);
                    if(map.get(tempc) > 0){
                        counter++;
                    }
                }
                if(end-begin == t.length()){
                    result.add(begin);
                }
                begin++;
            }
            
        }
        return result;
    }
}