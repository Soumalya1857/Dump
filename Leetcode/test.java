import java.util.*;

class Node1{
    int val;
    int frequencty;
}

class NodeComparator implements Comparator<Node1> {
    public int compare(Node1 node1, Node1 node2){
        return node1.getVal() - node2.getVal();
    }
}
class Application{

    void getDuplicate(List<Integer> arr){

    Set<Node1> set = new HashSet<>();
    PriorityQueue<Node1> pq = new PriorityQueue<>(new NodeComparator());
    set.add(new Node1());
    }

}// https://leetcode.com/problems/implement-trie-prefix-tree/description/
// ========================================================
// https://leetcode.com/problems/implement-trie-prefix-tree/description/

// string.toCharArray

class Node{
    char curr;
    Node[] children;
    Boolean isEndOfWord;

    public Node(char ch){
        curr = ch;
        children = new Node[26];
        isEndOfWord = false;
    }
    public Node(){
        children = new Node[26];
        isEndOfWord = false;
    }

    public Boolean isPresent(char ch){
        return children[ch-'a'] != null;
    }

    public void insertNode(Node node){
        children[node.curr - 'a'] = node;
    }

    public void setIsEndOfWord(Boolean val){
        this.isEndOfWord = val;
    }

}

class Trie{

    Node parentNode;

    public Trie(){
        parentNode = new Node();
    }

    public void insert(String str){
        char[] arr = str.toCharArray();
        Node currNode = parentNode;
        for(char ch : arr){
            if(currNode.isPresent(ch)){
                currNode = currNode.children[ch-'a'];
            }else{
                currNode.insertNode(new Node(ch));
                currNode = currNode.children[ch-'a'];
            }
        }

        currNode.setIsEndOfWord(true);
    }

    public Boolean search(String str){
        char[] arr = str.toCharArray();
        Node currNode = parentNode;

        for(char ch: arr){
            if(currNode.isPresent(ch)){
                currNode = currNode.children[ch-'a'];
            }else{
                return false;
            }
        }

        return currNode.isEndOfWord;
    }

    public Boolean isStartsWith(String str){
        char[] arr = str.toCharArray();
        Node currNode = parentNode;

        for(char ch: arr){
            if(currNode.isPresent(ch)){
                currNode = currNode.children[ch-'a'];
            }else{
                return false;
            }
        }

        return true;
    }



}


class Solutions {
    // impl of adj list


    ArrayList<ArrayList<Integer>> adjList = new ArrayList<ArrayList<Integer>>(10);
    for(int i=0; i<10; i++) adjList.get(i) = new ArrayList<>();

    List<List<Integer>> edges = new ArrayList<>();
    for(List<Integer> edge: edges){
        adjList[edge.get(0)].add(edge(1));
        adjList[edge.get(1)].add(edge(0));
    }



}































