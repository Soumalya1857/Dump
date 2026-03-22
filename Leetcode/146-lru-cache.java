class Node {
    public int key;
    public int value;

    public Node prev;
    public Node next;

    Node(int key, int value){
        this.key = key;
        this.value = value;
        this.prev = null;
        this.next = null;
    }

    Node(int key, int value, Node prev, Node next){
        this.key = key;
        this.value = value;
        this.prev = prev;
        this.next = next;
    }

}

class DLL {
    public Node head;
    public Node tail;

    DLL(){
        this.head = new Node(-1,-1);
        this.tail = new Node(-1,-1);

        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    public void insertAfterHead(Node node){
        node.next = this.head.next;
        this.head.next = node;
        node.next.prev = node;
        node.prev = this.head;
    }

    public void insertBeforeTail(Node node){
        node.prev = this.tail.prev;
        this.tail.prev = node;
        node.prev.next = node;
        node.next = this.tail;
    }

    public void deleteNode(Node node){
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

    public int deleteLRUNode(){ // delete before tail and return the key
        int key = this.tail.prev.key;
        // delete node
        this.deleteNode(this.tail.prev);
        return key;
    }

}

class LRUCache {
    private HashMap<Integer, Node> map;
    private DLL dll;

    private int capacity;

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>();
        this.dll = new DLL();
    }
    
    public int get(int key) {   

        //System.out.println("[get] key: " + key);
        Node node = map.getOrDefault(key, new Node(-1,-1));
        if(node.value == -1) return -1;

        // update list to keep it at the front
        dll.deleteNode(node);
        dll.insertAfterHead(node);
        map.put(key, node); // update
        //System.out.println("[get] value: " + node.value);
        return node.value;
    }
    
    public void put(int key, int value) {
        // update scenario, no capacity change
        //System.out.println("[put] key:" + key + " value: " + value);
        if(map.containsKey(key)){
            Node node = map.get(key);
            dll.deleteNode(node);
            Node newNode = new Node(key, value);
            dll.insertAfterHead(newNode);
            map.put(key, newNode);
            //System.out.println("New node updated - Key: " + key + " value: " + value);
        } else {
            // new entry
            if(map.size() >= this.capacity) {
                int key1 = dll.deleteLRUNode();
                map.remove(key1);
                //System.out.println("[delete] key: " + key1);
            }

            Node node = new Node(key, value);
            dll.insertAfterHead(node);
            map.put(key, node);
        }
    }
}

// https://leetcode.com/problems/lru-cache/submissions/1955957430/




// =============================================================
// https://www.youtube.com/watch?v=z9bJUPxzFOw

class LRUCache {
    class Node{
        int key;
        int value;

        Node prev;
        Node next;

        Node(int key, int value){
            this.key= key;
            this.value= value;
        }
    }

    public Node[] map;
    public int count, capacity;
    public Node head, tail;
    
    public LRUCache(int capacity) {
        
        this.capacity= capacity;
        count= 0;
        
        map= new Node[10_000+1];
        
        head= new Node(0,0);
        tail= new Node(0,0);
        
        head.next= tail;
        tail.prev= head;
        
        head.prev= null;
        tail.next= null;
    }
    
    public void deleteNode(Node node){
        node.prev.next= node.next;
        node.next.prev= node.prev;       
        
        return;
    }
    
    public void addToHead(Node node){
        node.next= head.next;
        node.next.prev= node;
        node.prev= head;
        
        head.next= node;      
        
        return;
    }
    
    public int get(int key) {
        
        if( map[key] != null ){
            
            Node node= map[key];
            
            int nodeVal= node.value;
            
            deleteNode(node);
            
            addToHead(node);
            
            return nodeVal;
        }
        else
            return -1;
    }
    
    public void put(int key, int value) {
        
        if(map[key] != null){
            
            Node node= map[key];
            
            node.value= value;
            
            deleteNode(node);
            
            addToHead(node);
            
        } else {
            
            Node node= new Node(key,value);
            
            map[key]= node;
            
            if(count < capacity){
                count++;
                addToHead(node);
            } 
            else {
                
                map[tail.prev.key]= null;
                deleteNode(tail.prev);
                
                addToHead(node);
            }
        }
        
        return;
    }
    
}