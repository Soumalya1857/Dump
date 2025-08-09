// https://leetcode.com/problems/number-of-good-paths/description/

//Got MLE with this
class Solution {

private:

bool isGoodPath(vector<vector<int>> &adj, vector<int> &vals, int start, int end){
    if(vals[start] != vals[end]) return false;
    if(start == end) return true;

    stack<pair<int,int>> s; // index curr node, maxTillNow
    s.push({start, vals[start]});

    vector<bool> visited(vals.size(), false);

    while(!s.empty()){
        pair<int,int> curr = s.top(); s.pop();
        if(start == 1 || start == 4){
            // cout << "node: " << curr.first;
            // cout << "max: " << curr.second;
        }
        visited[curr.first] = true;
        if(curr.first == end){
            if(curr.second <= vals[start]){
                return true;
            }

            continue;
        }

        for(int nei : adj[curr.first]){
            if(!visited[nei]){
                s.push({nei, max(vals[nei], curr.second)});
            }
        }
    }

    return false;
}
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int ans = vals.size();
        // 2d array addition
        map<int,vector<int>> freq; // val => vector of index

        for(int i=0; i<vals.size(); i++){
            freq[vals[i]].push_back(i);
        }

        // for(auto entry : freq){
        //     cout << entry.first << endl;
        //     for(int x : entry.second) cout << x << " ";
        //     cout << endl;
        // }

        vector<vector<int>> adj(vals.size());

        for(int i=0; i<edges.size(); i++){
            //cout << edges[i][0] <<"-" << edges[i][1] << "\n";
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }


        for(auto entry : freq){
            //cout << entry.second.size()<< "boobies\n";
            if(entry.second.size() > 1){
                int size = entry.second.size();
                for(int i=0; i<size; i++){
                    for(int j=i+1; j<size; j++){
                        //if(entry.first == 1) cout << i << " " << j << "<= hehe" << endl;
                        if(isGoodPath(adj, vals, entry.second[i], entry.second[j])){
                            ans++;
                        }
                    }
                }
            }
        }



        return ans;
    }
};

// solution can be done with DSU
// disjoint set union
// but seemed forced solution
// https://www.youtube.com/watch?v=rv2GBYQm7xM&t=619s


class Solution {

private:

vector<int> rank, parent;
void makeSet(){
    for(int i=0; i<rank.size(); i++) {
        rank[i] = 0;
        parent[i] = i;
    }
}

int getParent(int n){
    if(n == parent[n]){
        return n;
    }

    return parent[n] = getParent(parent[n]);
}

void makeUnion(int a, int b){
    a = getParent(a);
    b = getParent(b);

    if(rank[a] > rank[b]){
        parent[b] = a;
    } else if(rank[b] > rank[a]){
        parent[a] = b;
    } else{
        parent[b] = a;
        rank[a]++;
    }
}
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        rank.resize(vals.size());
        parent.resize(vals.size());

        makeSet();

        int res = 0;
        unordered_map<int,int> count;
        vector<vector<int>> adj(vals.size());
        for(vector<int> edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        map<int, vector<int>> freq;
        vector<bool> visited(vals.size(), false);
        for(int i=0; i<vals.size(); i++){
            freq[vals[i]].push_back(i);
        }

        // sorted => as map already store values/keys in a sorted order
        for(auto entry: freq){
            int val = entry.first;
            vector<int> values = entry.second;

            for(int i=0; i<values.size(); i++){
                int currIndex = values[i];

                visited[currIndex] = true;

                for(int nei: adj[currIndex]){
                    if(vals[nei] <= vals[currIndex]){
                        makeUnion(nei, currIndex);
                        visited[nei] = true;
                    }
                }
            }

            // how many same values are there in the disjoint sets?
            for(int i : values){
                count[getParent(i)]++;
                res += 1;
            }
        }

        return res;

    }
};

// working coede
class Solution {
public:
	int find(vector<int>& y,int i) {
		if(i==y[i]) return i;
		y[i]=find(y,y[i]);
		return y[i];
	}
	int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size(),m=edges.size(),ans=0;
		vector<vector<int>> x(n);
		vector<int> y(n);
		for(int i=0;i<n;i++){
			y[i]=i;
			x[i]={vals[i],1};
		}
        sort(edges.begin(),edges.end(),[&](vector<int>& a,vector<int>& b){
	    	return max(vals[a[0]],vals[a[1]])<max(vals[b[0]],vals[b[1]]);
		});
		for(int i=0;i<m;i++){
			int a=find(y,edges[i][0]);
			int b=find(y,edges[i][1]);
			if(x[a][0]!=x[b][0]){
				if(x[a][0]>x[b][0]) y[b]=a;
				else y[a]=b;
			}
			else{
				y[a]=b;
				ans+=x[a][1]*x[b][1];
				x[b][1]+=x[a][1];
			}
		}
		return ans+n;
	}
};


