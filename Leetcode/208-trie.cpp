// https://leetcode.com/problems/implement-trie-prefix-tree/
// https://www.youtube.com/watch?v=dBGUmUQhjaM&list=PLgUwDviBIf0pcIDCZnxhv0LkHf5KzG9zp
class Node{

    private:
        Node* children[26];
        bool isEndOfWord;

    public:
        Node(){
            this->isEndOfWord = false;
        }

        bool containsKey(char ch){
            return (children[ch-'a'] != NULL);
        }

        void addKey(char ch){
            this->children[ch-'a'] = new Node();
        }

        Node* get(char ch){
            return this->children[ch-'a'];
        }

        // add setEndOfWord method here

        // add getEndOfWord method here
       
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                node->addKey(word[i]);
            }

            node = node->get(word[i]);
        }

        node->setEndOfWord();
    }

    bool search(string word) {
        Node *node = root;

        for(int i=0; i<word.length(); i++){
            if(!node->containsKey(word[i])){
                return false;
            }

            node = node->get(word[i]);
        }

        return node->getEndOfWord();

    }

    bool startsWith(string prefix) {

        Node *node = root;

        for(int i=0; i<prefix.length(); i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }

            node = node->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */


 // working code
// https://takeuforward.org/data-structure/implement-trie-1/
// https://leetcode.com/problems/implement-trie-prefix-tree/

struct Node {
    // Array to store links to child nodes,
    // each index represents a letter
    Node* links[26];
    // Flag indicating if the node
    // marks the end of a word
    bool flag = false;

    // Check if the node contains
    // a specific key (letter)
    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    // Insert a new node with a specific
    // key (letter) into the Trie
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Get the node with a specific
    // key (letter) from the Trie
    Node* get(char ch) {
        return links[ch - 'a'];
    }

    // Set the current node
    // as the end of a word
    void setEnd() {
        flag = true;
    }

    // Check if the current node
    // marks the end of a word
    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        // Node* node = root;
        // for(int i=0; i<word.length(); i++){
        //     if(!node->containsKey(word[i])){
        //         node->addKey(word[i]);
        //     }

        //     node = node->get(word[i]);
        // }

        // node->setEndOfWord();

        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // Create a new node for
                // the letter if not present
                node->put(word[i], new Node());
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                // If a letter is not found,
                // the word is not in the Trie
                return false;
            }
            // Move to the next node
            node = node->get(word[i]);
        }
        // Check if the last node
        // marks the end of a word
        return node->isEnd();

    }

    bool startsWith(string prefix) {

       Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i])) {
                // If a letter is not found, there is
                // no word with the given prefix
                return false;
            }
            // Move to the next node
            node = node->get(prefix[i]);
        }
        // The prefix is found in the Trie
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
