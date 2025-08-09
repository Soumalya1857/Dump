class Solution {
    private List<Integer> clone(List<Integer> list){
        List<Integer> newList = new ArrayList<>();
        for(Integer i : list){
            newList.add(i);
        }

        return newList;
    }

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        List<List<Integer>> ans = new ArrayList<>();
        int n = graph.length;

        Queue<State> q = new LinkedList<>();
        q.add(new State(0, new ArrayList<>()));

        while(!q.isEmpty()){
            State currState = q.peek();
            q.remove();

            if(currState.getCurr() == n-1){
                currState.getCurrPath().add(n-1);
                ans.add(currState.getCurrPath());
                continue;
            }

            for(int nei: graph[currState.getCurr()]){
                List<Integer> newPath = clone(currState.getCurrPath());
                newPath.add(currState.getCurr());
                q.add(new State(nei, newPath));
            }
        }

        return ans;
    }
}

class State{
    int curr;
    List<Integer> currPath;

    State(int curr, List<Integer> currPath){
        this.curr = curr;
        this.currPath = currPath;
    }

    public int getCurr(){
        return this.curr;
    }

    public List<Integer> getCurrPath(){
        return this.currPath;
    }
}

// https://leetcode.com/problems/all-paths-from-source-to-target/

// better solution <Efficient in terms of memeory>
class Solution {

    public List<Integer> path = new ArrayList<>();
    public List<List<Integer>> result = new ArrayList<>();

    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        int target = graph.length - 1; 

        dfs(target, graph, 0);
        path.remove(path.size() - 1);

        return result;
    }

    public void dfs(int target, int[][] graph, int node){
        path.add(node);

        if (node == target){
            result.add(new ArrayList<>(path));
            return;
        }

        for (int child: graph[node]){
            dfs(target, graph, child);
            path.remove(path.size() - 1);
        }

        return;
    }
}