/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;
        
        // copy a graph
        //unordered_map<Node*, vector<Node*>> um;
        // doing bfs with memo
        vector<bool> visited(105,false);
        vector<bool> created(105, false);
        
        unordered_map<int, Node*> createdNodes;
        
        queue<Node*>q;
        q.push(node);
        while(!q.empty())
        {
            
            Node* curr = q.front();
            q.pop();

            if(!created[curr->val])
            {
                Node* newCurr = new Node(curr->val);
                createdNodes[curr->val] = newCurr;
                created[curr->val] = true;
            }

            if(!visited[curr->val]){
                visited[curr->val] = true;
                Node* newCurr = createdNodes[curr->val];

                for(auto child: curr->neighbors)
                {
                    if(!created[child->val])
                    {
                        Node* newChild = new Node(child->val);
                        createdNodes[child->val] = newChild;
                        created[child->val] = true;
                        //um[newChild] = vector<Node*>();
                    }
                    
                    Node* clonedChild = createdNodes[child->val];
                    newCurr->neighbors.push_back(clonedChild);

                    //cout << "new Curr: " << newCurr->val << " neighbors added:" << clonedChild->val << endl;
                    //cout << "visited " << newCurr->val << " :" << visited[newCurr->val] << endl;
                    if(!visited[child->val])
                    {
                        q.push(child);
                        //cout << "pushed in q: " << child->val << endl;
                    }
                }

            }

        }
        
        return createdNodes[node->val];
    }
};

// https://leetcode.com/problems/clone-graph/


class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};