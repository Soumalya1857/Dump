// vvv bad time complexity

class Solution {
public:
    bool isNeighbor(string s1, string s2){
        int count = 0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] != s2[i]) count++;

            if(count > 1) return false;
        }

        return count == 1 ? true : false;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, vector<string>> adj;

        //wordList.push_back(beginWord);
        bool isBeginWordExist = false, isEndWordExist=false;
        for(int i=0; i<wordList.size(); i++){
            if(wordList[i] == beginWord) isBeginWordExist = true;
            if(wordList[i] == endWord) isEndWordExist = true;
            for(int j=i+1; j<wordList.size(); j++){
                if(isNeighbor(wordList[i], wordList[j])){
                    adj[wordList[i]].push_back(wordList[j]);
                    adj[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        if(!isEndWordExist) return 0;

        if(!isBeginWordExist){
            for(int j=0; j<wordList.size(); j++){
                if(isNeighbor(beginWord, wordList[j])){
                    adj[beginWord].push_back(wordList[j]);
                    adj[wordList[j]].push_back(beginWord);
                }
            }
        }


        // bfs
        queue<string> q;
        unordered_map<string, bool> visited;

        q.push(beginWord);
        int count=0;

        while(!q.empty()){
            int size = q.size();
            count+=1;
            while(size--){
                string curr = q.front(); q.pop();

                if(curr == endWord) return count;

                visited[curr] = true;

                for(string nei: adj[curr]){
                    if(!visited[nei]){
                        q.push(nei);
                    }
                }
            }
        }

        return 0;

    }
};

// https://leetcode.com/problems/word-ladder/description/

// https://leetcode.com/problems/word-ladder/solutions/1764371/a-very-highly-detailed-explanation
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> w{wordList.begin(), wordList.end()};
        w.erase(beginWord);
        if(w.find(endWord)==w.end()) return 0;
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty())
        {
            string s =q.front().first;
            int steps=q.front().second;
            q.pop();
            if(s==endWord) return steps;
            for(int i=0,n=s.size();i<n;i++)
            {
                char p=s[i];
                for(char c='a';c<='z';c++)
                    if(p!=c)
                    {
                        s[i]=c;
                        if(w.find(s)!=w.end())
                        {
                            //if(endWord.compare(s)==0) return steps+1;
                            w.erase(s);
                            q.push({s,steps+1});
                        }
                    }
                s[i]=p;
            }
        }
        return 0;
    }
};
