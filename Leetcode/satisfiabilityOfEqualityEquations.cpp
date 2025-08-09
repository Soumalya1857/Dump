class Solution {
public:
    
    
    void show(int color[])
    {
        for(int i=0;i<26;i++)
        {
            char au = i + 'a';
            cout << au << " :" << color[i] << endl;
        }
    }
    bool equationsPossible(vector<string>& equations) {
     // not solved by myself..needed the equation
        
       // okay so thats a nice problem
        // basically we need to color each and every element
        // the equal element gets equal color
        // via dfs we will choose
        // now parse the equation to get != ones
        // now check whether they match or not
        // if matches...return false
        // else true
        
        
        
        vector<vector<int>>graph(26);
        for(string eqn: equations)
        {
            if(eqn[1] == '=')
            {
                int a = eqn[0]-'a';
                int b = eqn[3]-'a';
                //if(a!=b)
                {
                    graph[a].push_back(b);
                    graph[b].push_back(a);
                }
                
            }
        }
        
        int color[26] = {0};
        int t = 0;// each char gets a diff color
        
        for(int i=0;i<26;i++)
        {
            if(color[i] == 0)
            {
                t++;
                stack<int>s;
                s.push(i);
                while(!s.empty())
                {
                    int node = s.top();
                    s.pop();
                    for(int equal : graph[node])
                    {
                        if(color[equal] == 0) color[equal] = t, s.push(equal);
                    }
                }
            }
        }
        
        show(color);
        for(string s : equations)
        {
            if(s[1] == '!')
            {
                int a = s[0] - 'a';
                int b = s[3] - 'a';
                
                if(a == b || color[a] == color[b] && color[a] != 0)
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};

// https://leetcode.com/problems/satisfiability-of-equality-equations/

########################################################################################################
class Solution {
public:
    /*
First, going through equality equations and use the union operation to join the variables in one set.

Second, going through inequality equations and verify that the variables are not in the same set using the find operation.

As a refresher, the picture below demonstrates how the disjoined set structure changes based on the equality equations.
    */
    int find(vector<int> &parent,int x)
    {
        if(parent[x] == -1)
            parent[x] = x;
        if(parent[x]!=x)
            parent[x] = find(parent,parent[x]);
        return parent[x];
    }
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26,-1);
        for(string &equation:equations)
        {
            if(equation[1] == '=')
            {
                int x_representative = find(parent,equation[0]-'a');
                int y_representative = find(parent,equation[3]-'a');
                parent[x_representative ] = y_representative;
            }
        }
        for (string &equation:equations){
            if (equation[1] =='!' && find(parent, equation[0]-'a') == find(parent, equation[3]-'a'))
                return false;
        }
        return true;
        
    }
};
######################################################################################################################
// time efficient approach
class Solution {
public:
    int uf[26];
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) uf[i] = i;
        for (string e : equations)
            if (e[1] == '=')
                uf[find(e[0] - 'a')] = find(e[3] - 'a');
        for (string e : equations)
            if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a'))
                return false;
        return true;
    }

    int find(int x) {
        if (x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};

/////////////////////////////////

// better approach
class Solution {
    struct DSU
    {
        DSU(size_t size)
        {
            ranks.resize(size,0);
            for(size_t i=0; i<size; ++i)
            {
                parents.emplace_back(i);
            }
        }
        
        int get(int x)
        {
            int parent=parents[x];
            if(parent!=x)
            {
                parents[x]=get(parent);
            }
            return parents[x];
        }
        
        void uni(int x, int y)
        {
            int parent1=get(x);
            int parent2=get(y);
            if(parent1==parent2)
            {
                return;
            }
            
            if(ranks[parent1]<ranks[parent2])
            {
                parents[parent1]=parent2;
            }
            else if(ranks[parent1]>ranks[parent2])
            {
                parents[parent2]=parent1;
            }
            else
            {
                parents[parent1]=parent2;
                ++ranks[parent2];
            }
        }
        
        vector<int> parents;
        vector<int> ranks;
    };
public:
    bool equationsPossible(vector<string>& equations) {
        DSU dsu(26);
        for(const auto& it:equations)
        {
            int x=static_cast<int>(it[0]-'a');
            int y=static_cast<int>(it[3]-'a');
            if(it[1]=='=')
            {
                dsu.uni(x,y);
            }
        }
        for(const auto& it:equations)
        {
            int x=static_cast<int>(it[0]-'a');
            int y=static_cast<int>(it[3]-'a');
            if(it[1]=='!')
            {
                int parent1=dsu.get(x);
                int parent2=dsu.get(y);
                if(parent1==parent2)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
Copyright © 2020 LeetCodeHelp Center  |  Jobs  |  Bug Bounty  |  Terms  |  Privacy Policy      United States
