// finding LCA in log time

// preprocessing in NlogN and the each query in log(Height) time

class TreeAncestor{
    private:
        vector<vector<int>>up;
        vector<int> depth;
        int LOG;

    public:
        TreeAncestor(int n, vector<int>& parent)
        {
            LOG = 0;
            while((1<<(LOG)) <=n ) LOG++; // ceiling of logarithm // or we can hardcode it to 20/30 something
        
            up = vector<vector<int>>(n,vector<int>(LOG));
            depth = vector<int>(n); // root at 0th level and everybody else at some positive level

            // preprocessing

            parent[0] = 0; // to remove acessing some ancestor that doesn't even exist

            for(int v=0; v<n;v++)
            {
                up[v][0] = parent[v];
                if(v!=0) depth[v] = depth[parent[v]] + 1; // if not root then calculate depth

                for(int j=1;j<LOG;j++)
                {
                    up[v][j] = up[ up[v][j-1] ][j-1]; // parent er parent
                }
            }

        }

        int getKthAncestor(int node, int k)
        {
            if(depth[node] < k) return -1;

            for(int j=0;j<LOG;j++)
            {
                if(k & (1<<j))
                {
                    node = up[node][j]; // for 19 it will trigger 1 2 16
                }
            }

            return node;
        }
};
// youtube:https://www.youtube.com/watch?v=oib-XsjFa-M&t=907s



// easy explanation
// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/discuss/1298231/2-Minute-Read-Easy-Binary-Lifting

/*
So, I tried it using the Brute Force way, but it gave TLE. The Brute Force was to move through the parent array one by one, till you got k parents up, and then return that.
This got me the hint of using Binary Lifting, what we do in Binary Lifting is basically we minimize the steps required to reach the kth parent of a node.
How do we do that? Using the properties of Binary Number System. So here goes a breif description of how we can use Binary Lifting to solve our problem.

This technique is similar to Binary Exponentiation. What we do is, we store the parent of a node which are at power's of 2 above the node, i.e. we store the 1st parent (20), the 2nd parent (21), the 4th parent (22), the 8th parent (23), and so on till log(n) + 1 where n is the number of nodes, because in the worst case, the tree could be linear, and since you can represent any number in at max log(n) + 1 bits, hence we store till 2log(n) + 1.

Now when we get a query to report the kth parent of a node, for example, let's say k = 11, we would use the magic of Binary Representation of k, which in this case is 1011. Now starting from the Least Significant bit, we would move right, and if a bit is 1, let's say at a position i, we would change our node to 2i th parent of that node, and repeat this process again. This way, we would be jumping up the tree, from parent to parent, not one parent at a time, but in powers of 2 which would drastically reduce our Time Complexity from O(n) to O(log n).

If you wan't to learn more about Binary Lifting and the complete thinking and applying process behind it, there is wonderfull tutorial video by Algorithms Live.

Below is the Java Code of the above approach.
*/

// Java solution
class TreeAncestor {
    
    int dp[][];
    int m;
    int n;
    
    public TreeAncestor(int n, int[] parent) {
        this.n = n;
        this.m = (int) (Math.log(n) / Math.log(2)) + 1;
        dp = new int[m][n];
        for(int i[] : dp) {
            Arrays.fill(i, -1);
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    dp[i][j] = parent[j];
                }
                else {
                    if(dp[i - 1][j] == -1) dp[i][j] = -1;
                    else dp[i][j] = dp[i - 1][dp[i - 1][j]];
                }
            }
        }
    }
    
    public int getKthAncestor(int node, int k) {
        int row = 0;
        while(k > 0) {
            if((k & 1) == 1) {
                if(node == -1) return -1;
                node = dp[row][node];
            }
            k >>= 1;
            row++;
        }
        return node;
    }
}