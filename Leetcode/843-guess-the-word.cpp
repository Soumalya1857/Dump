/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */

 // implemented logic is use the compare function on all the wordlist
 // the words generates lesser value than original guess reply <= discard them
 // don't guess same word multiple time

 /*verdict: accepted*/

 // https://leetcode.com/problems/guess-the-word/solutions/556075/how-to-explain-to-interviewer-843-guess-the-word/

class Solution {
public:

    int compare(string secret, string guess){
        int count = 0;
        for(int i=0; i<secret.length(); i++){
            if(secret[i] == guess[i]){
                count++;
            }
        }

        return count;
    }
    void findSecretWord(vector<string>& words, Master& master) {
        	// guess the first word and filter out the words that has same results

        unordered_map<string, bool> mp, alreadyGuessed;

        for(string word : words){
            mp[word] = true;
        }

        int guessCount = 0;

        while(guessCount <= 30){

            string guessString = "";
            int masterReply = -1;

            for(auto itr = mp.begin(); itr!= mp.end(); itr++){
                if(!alreadyGuessed[itr->first]){
                    guessString = itr->first;
                    masterReply = master.guess(guessString);
                    guessCount++;

                    alreadyGuessed[guessString] = true;
                    break;
                }
            }

            //cout << "string: " <<  guessString << " reply: " << masterReply << " guessNum: " << guessCount << endl;

            if(masterReply == guessString.length()) {
                return;
            }

            // this master reply exactly match other strings
            vector<string> deletedStrings;
            for(auto it = mp.begin(); it!= mp.end(); it++){
                if(!(compare(guessString, it->first) == masterReply)){ // needs exact matches with master
                    deletedStrings.push_back(it->first);
                    //cout << "deleted: " << it->first << " score: " << compare(guessString, it->first) << endl;
                }
            }

            // delete
            for(string word : deletedStrings){
                mp.erase(word);
            }
        }

    }
};

// https://leetcode.com/problems/guess-the-word/description/
