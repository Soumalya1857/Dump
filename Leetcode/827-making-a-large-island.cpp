// Brute approach TLE
class Solution {
private:

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0,  0, 1, -1};

    bool isValid(int n, int row, int col){
        return row>=0 && row<n && col>=0 && col<n;
    }

    int solve(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited){
        int n = grid.size();
        queue<pair<int,int>> q;

        int size = 0;

        q.push({row,col});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if(!visited[x][y]){
                size++;
                visited[x][y] = true;
            }
            
            for(int i=0; i<4; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];

                if(isValid(n, newX, newY) && grid[newX][newY] == 1 && !visited[newX][newY]){
                    q.push({newX, newY});
                }
            }

        }

        return size;


    }

    int findLargest(vector<vector<int>> &grid){
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        

        int islandSize = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    islandSize = max(islandSize, solve(grid, i, j, visited));
                }
            }
        }

        return islandSize;

    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        // BRUTE approach
        // turn each 0 to 1 and check size of largest Island

        int n = grid.size();
        bool flag = false;
        int maxi = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    flag = true;
                    grid[i][j] = 1;
                    maxi = max(maxi, findLargest(grid));
                    grid[i][j] = 0;
                }
            }
        }

        if(!flag) return n*n;
        return maxi;
    }
};

// https://leetcode.com/problems/making-a-large-island/description/


// DSU approach, 
// group all the islands
// then try to flip each zeros which connect two islands
// join them and get the max size of island
// TLE....

class DSU{
private:
    int n;
    vector<int> rank, parent;

    void initialize(){
        for(int i=0; i<rank.size(); i++){
            rank[i] = 0;
            parent[i] = i;
        }
    }
public:
    DSU(int n){
        this->n = n;
        rank.resize(n);
        parent.resize(n);
        initialize();
    }

    DSU(DSU &t){
        n = t.get_n();
        rank = t.get_rank();
        parent = t.get_parent();
    }

    int find_parent(int u){
        if(parent[u] == u) return u;

        return parent[u] = find_parent(parent[u]);
    }

    void associate(int u, int v){
        u = find_parent(u);
        v = find_parent(v);

        if(rank[u] > rank[v]){
            parent[v] = u;
        } else if(rank[v] > rank[u]){
            parent[u] = v;
        }else{
            parent[v] = u;
            rank[u]++;
        }
    }

    int get_max_island_size(){
        unordered_map<int,int> freq;
        for(int i=0; i<parent.size(); i++){
            parent[i] = find_parent(i);
            freq[parent[i]]++;
        }

        int maxi = 0;

        // what is the most freq element
        for(auto entry : freq){
            maxi = max(maxi, entry.second);
        }

        return maxi;
    }

    int get_n(){
        return n;
    }

    vector<int> get_rank(){
        return rank;
    }

    vector<int> get_parent(){
        return parent;
    }

};

class Solution {
private:
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0, 0, 1, -1};

    bool isValid(int n, int row, int col){
        return row>=0 && row<n && col>=0 && col<n;
    }

    int translate(int n, int row, int col){
        //cout << n << " " << row << " " << col << " \n";
        return n*row + col;
    }

    pair<int,int> de_translate(int n, int num){
        int row = num / n;
        int col = num % n;

        return {row, col};
    }

    void bfs(vector<vector<int>> &grid, int row, int col, vector<vector<bool>> &visited, DSU &dsu){
        
        int n = grid.size();

        queue<pair<int,int>> q;
        q.push({row, col});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;

            q.pop();

            if(!visited[x][y]){
                visited[x][y] = true;
            }

            for(int i=0; i<4; i++){
                int newx = x + dx[i];
                int newy = y + dy[i];

                if(isValid(n, newx, newy) && !visited[newx][newy] && grid[newx][newy] == 1){
                    q.push({newx, newy});
                    dsu.associate(
                        translate(n,x,y),
                        translate(n,newx, newy)
                    );
                }
            }
        }
    }

    int get_max_island_size(vector<pair<int,int>> &coords, DSU &original_dsu, int n){
        DSU dsu(original_dsu);

        for(int i=0; i<coords.size(); i++){
            for(int j=i+1; j<coords.size(); j++){
                dsu.associate(
                    translate(n,coords[i].first, coords[i].second),
                    translate(n, coords[j].first, coords[j].second)
                );
            }
        }

        return dsu.get_max_island_size();
    }


public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU dsu(n*n);
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        bool flag = false;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }

        if(!flag) return n*n;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    bfs(grid, i, j, visited, dsu);
                }
            }
        }

        // now the islands are in one group
        // for each zeros in the grid, try to flip it

        int maxi = dsu.get_max_island_size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){

                    // get all the nearby valid coordinates
                    vector<pair<int,int>> coords;
                    coords.push_back({i,j});
                    for(int k=0; k<4; k++){
                        int newx = i + dx[k];
                        int newy = j + dy[k];

                        if(isValid(n, newx, newy) && grid[newx][newy] == 1){
                            coords.push_back({newx,newy});
                        }
                    }

                    if(coords.size() > 1){
                        maxi = max(maxi, get_max_island_size(coords, dsu, n));
                    }
                }
            }
        }


        return maxi;
    }
};



// ====================================================
/**
 * @brief 
 * Approach 1: Using DFS
Intuition
We are given a binary matrix where each cell is either 0 (representing water) or 1 (representing land) and the ability to flip at most one 0 to 1. Our task is to find the largest island in the matrix, or in other words, the largest group of 1s connected with each other either up, down, left, or right (4-directionally) after the flip operation.

At first, we might think of flipping each 0 to 1 and then calculating the size of the largest island in the modified matrix. However, this brute-force approach is inefficient, especially for larger grids, as it involves multiple recalculations for each flip, which would lead to Time Limit Exceeded (TLE) error.

Instead of recalculating island sizes for every flip, we can take advantage of the fact that flipping a single 0 only affects the islands adjacent to it. Specifically, flipping a 0 merges neighboring islands into one larger island. This insight allows us to efficiently compute the largest island after flipping by precomputing the sizes of all islands first.

Check out the diagram below, where we can see that we can merge two islands into one by flipping a zero in between.

make_large_island

We start by traversing the grid and identifying all the islands using Depth-First Search (DFS). During this traversal, we give each island a unique identifier (like a color). At the same time, we also calculate and store the size of each island in a map, where the key is the island’s unique identifier and the value is its size. This precomputation allows us to avoid recalculating island sizes later.

For a more comprehensive understanding of depth-first search, check out the DFS Explore Card.

After labeling the islands and knowing their sizes, we then look at each 0 in the grid. Flipping a 0 to 1 might connect neighboring islands, creating a larger island. For each 0, we examine the islands around it and collect their unique identifiers using a set (to avoid counting the same island more than once). We then sum up the sizes of these islands to calculate the size of the new island that would be formed if this 0 were flipped to 1.

As we evaluate each potential flip, we compare the size of the island that would be formed with the largest island we’ve seen so far. This ensures that we find the largest possible island we can form by flipping a single 0. We will handle special edge cases (e.g., the grid is full with 1s or 0s) separately.

This strategy is efficient because the grid is only traversed twice:

To label the islands and compute their sizes.
To evaluate the potential island size for each 0 flip.
Algorithm
exploreIsland helper function:
Define the exploreIsland function which recursively explores an island with the given id islandId starting from the given cell (currentRow, currentColumn).

Check if the current cell is out of bounds, is not part of an island or is already visited (i.e., its value is not 1):

If so, return 0, indicating no land is found at this cell.
Mark the current cell with the given islandId to indicate it has been visited.

Recursively explore the four neighboring cells (up, down, left, right) and accumulate the area of the island:

Call exploreIsland for the cell below (currentRow + 1, currentColumn).
Call exploreIsland for the cell above (currentRow - 1, currentColumn).
Call exploreIsland for the cell to the right (currentRow, currentColumn + 1).
Call exploreIsland for the cell to the left (currentRow, currentColumn - 1).
Return the total area of the island (i.e., 1 + the sum of all reachable land cells from the current position).

largestIsland main function:
Initialize islandSizes to store sizes of islands, and islandId starting at 2 (to mark islands).

Traverse through the grid to mark all islands and calculate their sizes:

For each cell in the grid, if the cell contains a land (value 1), call exploreIsland() to mark the island and calculate its size.
For each island, store the size in islandSizes using the islandId as the key and increment islandId for the next island.
Check if there are no islands (empty grid), in which case return 1 (since flipping one 0 would form a new island).

If only one island exists in the entire grid, check if the size of that island is equal to the total grid size:

If true, return the size of the island.
Otherwise, return the size of the island + 1 (as we can expand the island by flipping one 0).
Initialize maxIslandSize to 1, which will store the size of the largest island.

Traverse through the grid again to try converting each 0 to a 1 and calculate the resulting island size:

For each 0, check its neighboring cells (up, down, left, right) to find which islands are connected to it.
Use a unordered set to store unique neighboring island IDs.
Sum the sizes of all unique neighboring islands and add 1 (to account for the flipped 0 turning into a 1).
Update maxIslandSize with the maximum island size found.
Return maxIslandSize, the size of the largest island after trying to expand all possible 0s.

Implementation

Complexity Analysis
Let n be the number of rows in the grid, m be the number of columns in the grid.

Time complexity: O(n×m)

The algorithm consists of two main phases. In the first phase, we iterate over every cell in the grid to identify and mark islands using a Depth-First Search (DFS) approach. During this process, each cell is visited at most once, ensuring that the DFS traversal contributes O(n×m) to the time complexity.

In the second phase, we iterate over every cell again to explore the possibility of converting each 0 to 1 and calculating the potential island size. For each 0, we check its four neighboring cells, which is a constant-time operation. The use of an unordered set ensures that neighboring islands are counted uniquely, and the total work done in this phase is also O(n×m).

Thus, the overall time complexity is dominated by the grid traversal and DFS, resulting in O(n×m).

Space complexity: O(n×m)

The space complexity is primarily determined by the recursion stack used during the DFS traversal and the storage required for the unordered map that keeps track of island sizes. In the worst case, the recursion depth of the DFS can be O(n×m) if the entire grid forms a single large island. The unordered map stores the sizes of all islands, and in the worst case, the number of islands can be proportional to the number of cells, contributing O(n×m) to the space complexity.

Furthermore, the unordered set used to store neighboring islands for each 0 cell has a maximum size of 4, as there are only four possible neighboring cells. This does not significantly impact the overall space complexity.

Therefore, the dominant factors are the recursion stack and the unordered map, resulting in an overall space complexity of O(n×m).

*/

class Solution {
private:
    int exploreIsland(vector<vector<int>>& grid, int islandId, int currentRow,
                      int currentColumn) {
        if (currentRow < 0 || currentRow >= grid.size() || currentColumn < 0 ||
            currentColumn >= grid[0].size() ||
            grid[currentRow][currentColumn] != 1)
            return 0;

        grid[currentRow][currentColumn] = islandId;
        return 1 +
               exploreIsland(grid, islandId, currentRow + 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow - 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow, currentColumn + 1) +
               exploreIsland(grid, islandId, currentRow, currentColumn - 1);
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> islandSizes;
        int islandId = 2;

        // Step 1: Mark all islands and calculate their sizes
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn) {
                if (grid[currentRow][currentColumn] == 1) {
                    islandSizes[islandId] = exploreIsland(
                        grid, islandId, currentRow, currentColumn);
                    ++islandId;
                }
            }
        }

        // If there are no islands, return 1
        if (islandSizes.empty()) {
            return 1;
        }
        // If the entire grid is one island, return its size or size + 1
        if (islandSizes.size() == 1) {
            --islandId;
            return (islandSizes[islandId] == grid.size() * grid[0].size())
                       ? islandSizes[islandId]
                       : islandSizes[islandId] + 1;
        }

        int maxIslandSize = 1;

        // Step 2: Try converting every 0 to 1 and calculate the resulting
        // island size
        for (int currentRow = 0; currentRow < grid.size(); ++currentRow) {
            for (int currentColumn = 0; currentColumn < grid[0].size();
                 ++currentColumn) {
                if (grid[currentRow][currentColumn] == 0) {
                    int currentIslandSize = 1;
                    unordered_set<int> neighboringIslands;

                    // Check down
                    if (currentRow + 1 < grid.size() &&
                        grid[currentRow + 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow + 1][currentColumn]);
                    }

                    // Check up
                    if (currentRow - 1 >= 0 &&
                        grid[currentRow - 1][currentColumn] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow - 1][currentColumn]);
                    }

                    // Check right
                    if (currentColumn + 1 < grid[0].size() &&
                        grid[currentRow][currentColumn + 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn + 1]);
                    }

                    // Check left
                    if (currentColumn - 1 >= 0 &&
                        grid[currentRow][currentColumn - 1] > 1) {
                        neighboringIslands.insert(
                            grid[currentRow][currentColumn - 1]);
                    }

                    // Sum the sizes of all unique neighboring islands
                    for (int id : neighboringIslands) {
                        currentIslandSize += islandSizes[id];
                    }

                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        return maxIslandSize;
    }
};

/*

Approach 2: Using Disjoint Set Union (DSU)
Intuition
Another way to solve this problem is by using a data structure called Disjoint Set Union (DSU), also known as Union-Find.

In DSU, the main goal is to keep track of groups (or sets) of elements where each set has a representative. The key operations in DSU are:

Find: This operation helps to find the representative (or "leader") of the set to which an element belongs. If two elements are in the same set, they will have the same representative.
Union: This operation merges two sets together. If two elements belong to different sets, they are combined into a single set, and the representative of one set becomes the representative of the merged set.
The idea behind DSU is that we represent each island as a set, and then we merge islands when we encounter an adjacent land cell. This helps us keep track of which cells belong to which island and how big each island is.

First, we initialize a DSU structure where each land cell is its own representative (each cell is its own island), meaning that parent[node] = node for every land cell node. We also initialize the islandSize array, where each island starts with a size of 1 (since each island is just one land cell initially). This is represented as islandSize[node] = 1.

As we traverse the grid, whenever we encounter a land cell (1), we check its adjacent cells (up, down, left, right). If an adjacent cell is also land, we union their corresponding sets. This means we merge the two islands (sets) into one larger island. The merging process ensures that the larger island becomes the representative of the merged set, keeping the data structure efficient.

During the merging step, we also update the size of the new island (set) by adding the size of the two merged islands. This is done by maintaining the islandSize array, where islandSize[node] is updated after each union operation.

After the initial union of all adjacent land cells, we then evaluate the potential effect of flipping a 0 (water) cell to 1 (land). When flipping a 0 to 1, it will create a new island that merges with its adjacent islands (if any). To calculate the size of the new island formed by flipping a 0, we simply look at the neighboring islands (sets) and calculate the size of the combined island. We do this by finding the representatives of the neighboring sets using find operations and summing their sizes.

As we evaluate each potential flip, we keep track of the largest island size encountered. If the grid is already filled with 1s or 0s, we handle these edge cases accordingly, but the main idea remains to maximize the island size formed by flipping a single 0.

Algorithm
Define the DisjointSet class:
Initialize parent and islandSize arrays:

parent stores the parent of each node.
islandSize stores the size of the connected island for each root.
Initialize the DisjointSet constructor with n elements:

For each node from l to n-1:
Set parent[node] = node, meaning each node is initially its own parent.
Set islandSize[node] = 1, indicating each island starts with size 1.
Implement findRoot function with path compression:

If the current node is its own parent, return the node as the root.
Otherwise, recursively find the root of the parent and apply path compression by updating the parent of the node.
Implement unionNodes(nodeA, nodeB) function to union two sets based on size:

Find the roots of both nodeA and nodeB using the findRoot function.
If both nodes are already in the same set (i.e., have the same root), do nothing.
Otherwise, union the sets by size:
Attach the smaller island to the larger one:
If the island of nodeA is smaller, set parent[rootA] = rootB and update the size of rootB’s island.
If the island of nodeB is smaller, set parent[rootB] = rootA and update the size of rootA’s island.
In the given Solution class:
Initialize rows and columns to store the grid's dimensions.

Initialize a Disjoint Set Union (DSU) for the entire grid with rows * columns size.

Define direction arrays (rowDirections, columnDirections) for traversing up, down, left, and right.

Step 1: Union adjacent 1s in the grid:

Iterate through each cell in the grid:
If the current cell contains 1, calculate the flattened 1D index for the current cell, as (columns * currentRow) + currentColumn.
For each of the four possible directions (up, down, left, right), check if the neighbor is within bounds and also contains 1.
If the neighbor is valid, flatten the 2D index and use the DSU to union the current cell and the neighbor.
Step 2: Calculate the maximum possible island size:

Initialize maxIslandSize to store the largest island size and hasZero as a flag to check if there are any zeros in the grid.
Initialize a uniqueRoots set to store the unique roots of neighboring 1s for each 0 in the grid.
Iterate through the grid to find all zeros (0 cells):
For each 0, initialize the currentIslandSize to 1 (since we are flipping the 0).
For each direction (up, down, left, right), check if the neighboring cell contains 1 and if so, add the root of the neighboring island to uniqueRoots.
Sum the sizes of the unique neighboring islands using their roots.
Update maxIslandSize with the largest island size found.
Step 3: Return the result:

If there are no zeros in the grid, return the size of the entire grid (i.e., rows * columns).
Otherwise, return maxIslandSize, the largest island size after flipping a zero.
Implementation

Complexity Analysis
Let n be the number of rows in the grid, m be the number of columns in the grid.

Time complexity: O(n×m)

The algorithm consists of two main phases. In the first phase, we iterate over every cell in the grid and we use a Disjoint Set Union (DSU) data structure to union adjacent 1s. For each cell, we check its four neighboring cells, which is a constant-time operation. The DSU operations, including findRoot and unionNodes, are nearly constant time due to path compression and union by size optimizations. Thus, the first phase contributes O(n×m) to the time complexity.

In the second phase, we iterate over every cell again to explore the possibility of converting each 0 to 1 and calculating the potential island size. For each 0, we check its four neighboring cells and use the DSU to find the roots of neighboring islands. The unordered set ensures that neighboring islands are counted uniquely, and the total work done in this phase is also O(n×m).

Therefore, the overall time complexity is dominated by the grid traversal and DSU operations, resulting in O(n×m).

Space complexity: O(n×m)

The space complexity is primarily determined by the DSU data structure, which stores the parent and size of each cell. Both the parent and islandSize arrays require O(n×m) space. Additionally, the unordered set used to store unique roots for neighboring islands has a maximum size of 4, as there are only four possible neighboring cells. This does not significantly impact the overall space complexity.

Therefore, the dominant factor is the DSU data structure, resulting in an overall space complexity of O(n×m).
 * 
 */

class DisjointSet {
public:
    vector<int> parent;
    vector<int> islandSize;

    // Constructor to initialize DSU with `n` elements
    DisjointSet(int n) {
        parent.resize(n);
        islandSize.resize(n);
        for (int node = 0; node < n; node++) {
            // Each node is its own parent initially with size 1
            parent[node] = node;
            islandSize[node] = 1;
        }
    }

    // Function to find the root of a node with path compression
    int findRoot(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findRoot(parent[node]);
    }

    // Function to union two sets based on size
    void unionNodes(int nodeA, int nodeB) {
        int rootA = findRoot(nodeA);
        int rootB = findRoot(nodeB);

        // Already in the same set
        if (rootA == rootB) return;

        // Union by size: Attach the smaller island to the larger one
        if (islandSize[rootA] < islandSize[rootB]) {
            // Attach rootA to rootB
            parent[rootA] = rootB;
            // Update size of rootB's island
            islandSize[rootB] += islandSize[rootA];
        } else {
            // Attach rootB to rootA
            parent[rootB] = rootA;
            // Update size of rootA's island
            islandSize[rootA] += islandSize[rootB];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int columns = grid[0].size();

        // Initialize DSU for the entire grid
        DisjointSet ds(rows * columns);

        // Direction vectors for traversing up, down, left, and right
        vector<int> rowDirections = {1, -1, 0, 0};
        vector<int> columnDirections = {0, 0, 1, -1};

        // Step 1: Union adjacent `1`s in the grid
        for (int currentRow = 0; currentRow < rows; currentRow++) {
            for (int currentColumn = 0; currentColumn < columns;
                 currentColumn++) {
                if (grid[currentRow][currentColumn] == 1) {
                    // Flatten 2D index to 1D
                    int currentNode = (columns * currentRow) + currentColumn;

                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = currentRow + rowDirections[direction];
                        int neighborColumn =
                            currentColumn + columnDirections[direction];

                        // Check bounds and ensure the neighbor is also `1`
                        if (neighborRow >= 0 && neighborRow < rows &&
                            neighborColumn >= 0 && neighborColumn < columns &&
                            grid[neighborRow][neighborColumn] == 1) {
                            int neighborNode =
                                columns * neighborRow + neighborColumn;
                            ds.unionNodes(currentNode, neighborNode);
                        }
                    }
                }
            }
        }

        // Step 2: Calculate the maximum possible island size
        int maxIslandSize = 0;
        // Flag to check if there are any zeros in the grid
        bool hasZero = false;
        // To store unique roots for a `0`'s neighbors
        unordered_set<int> uniqueRoots;

        for (int currentRow = 0; currentRow < rows; currentRow++) {
            for (int currentColumn = 0; currentColumn < columns;
                 currentColumn++) {
                if (grid[currentRow][currentColumn] == 0) {
                    hasZero = true;
                    // Start with the flipped `0`
                    int currentIslandSize = 1;

                    for (int direction = 0; direction < 4; direction++) {
                        int neighborRow = currentRow + rowDirections[direction];
                        int neighborColumn =
                            currentColumn + columnDirections[direction];

                        // Check bounds and ensure the neighbor is `1`
                        if (neighborRow >= 0 && neighborRow < rows &&
                            neighborColumn >= 0 && neighborColumn < columns &&
                            grid[neighborRow][neighborColumn] == 1) {
                            int neighborNode =
                                columns * neighborRow + neighborColumn;
                            int root = ds.findRoot(neighborNode);
                            uniqueRoots.insert(root);
                        }
                    }

                    // Sum up the sizes of unique neighboring islands
                    for (int root : uniqueRoots) {
                        currentIslandSize += ds.islandSize[root];
                    }

                    // Clear the set for the next `0`
                    uniqueRoots.clear();

                    // Update the result with the largest island size found
                    maxIslandSize = max(maxIslandSize, currentIslandSize);
                }
            }
        }

        // If there are no zeros, the largest island is the entire grid
        if (!hasZero) return rows * columns;

        return maxIslandSize;
    }
};




