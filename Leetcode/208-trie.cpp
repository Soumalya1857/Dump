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

        void setEndOfWord(){
            this->isEndOfWord = true;
        }

        bool getEndOfWord(){
            return this->isEndOfWord;
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