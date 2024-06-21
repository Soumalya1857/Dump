// neetcode: https://www.youtube.com/watch?v=NrHpgTScOcY
// https://leetcode.com/problems/naming-a-company/description/

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        // somehow group the names based on first character

        // also we need to know the same suffixed string because they are also not forming new names (coffee, cafe) (toffee, time)


        unordered_map<char, unordered_set<string>> mp;

        for(string str : ideas){
            mp[str[0]].insert(str.substr(1,str.length()-1));
        }

        long long result = 0;
        for(auto itr1 = mp.begin(); itr1 != mp.end(); itr1++){
            for(auto itr2=mp.begin(); itr2 != mp.end(); itr2++){
                if(itr1->first == itr2->first){
                    continue;
                }


                // need to find how many different suffixed values are there
                int intersection = 0;

                // traverse itr1->second and check if that suffix present in itr2->second

                for(auto it=itr1->second.begin(); it!= itr1->second.end(); it++){
                    if(itr2->second.find(*it) != itr2->second.end()){
                        intersection++;
                    }
                }

                int unique1 = itr1->second.size() - intersection;
                int unique2 = itr2->second.size() - intersection;

                result += (unique1 * unique2);

            }
        }

        return result;


    }
};