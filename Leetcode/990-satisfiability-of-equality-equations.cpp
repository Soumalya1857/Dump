class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        
        vector<vector<int>> conn(26, vector<int> (26, 0));

        for(string eq: equations){
            if(eq[1] == '!' && eq[0] == eq[3]) return false;

            if(eq[1] == '='){
                conn[eq[0]-'a'][eq[3] - 'a'] = 1;
                conn[eq[3]-'a'][eq[0] - 'a'] = 1;
            }
        }

        for(int i=0; i<26; i++){
            conn[i][i] = 1;
        }

        for(int i=0; i<26; i++){
            for(int j=0; j<26; j++){
                for(int k=0; k<26; k++){
                    if(conn[i][j] != 1){
                        if(conn[i][k] == 1 && conn[k][j] == 1){
                            conn[i][j] = 1;
                            conn[j][i] = 1;
                        }
                    }
                }
            }
        }

        for(string eq: equations){
            if(eq[1] == '!'){
                if(conn[eq[0]-'a'][eq[3]-'a'] == 1) return false;
            }
        }

        return true;
    }
};

// https://leetcode.com/problems/satisfiability-of-equality-equations/

// graph coloring is also possible

// but this question is actually of DSU
class Solution {
public:
    int find(vector<int>& parent, int x) {
        if(parent[x]!=x) parent[x]=find(parent,parent[x]);
        return parent[x];
    }
    
    void unionSets(vector<int>& parent, vector<int>& rank, int x, int y) {
        int rootX=find(parent,x), rootY=find(parent,y);
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]) parent[rootY]=rootX;
            else if(rank[rootX]<rank[rootY]) parent[rootX]=rootY;
            else {
                parent[rootY]=rootX;
                rank[rootX]++;
            }
        }
    }

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26), rank(26,0);
        for(int i=0;i<26;++i) parent[i]=i;
        for(const string& eq : equations) {
            if(eq[1]=='='){
                int x=eq[0]-'a', y=eq[3]-'a';
                unionSets(parent,rank,x,y);
            }
        }
        for(const string& eq : equations) {
            if(eq[1]=='!'){
                int x=eq[0]-'a', y=eq[3]-'a';
                if(find(parent,x)==find(parent,y)) return false;
            }
        }
        return true;
    }
};