class PrefixTree {
private:
    class Node{
    public:
        bool isEnd;
        Node* alpha[26];
        Node(){
            for(int i=0; i<26; i++){
                alpha[i]=nullptr;
            }
            isEnd=false;
        }
    };
    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* curr = root;
        for(auto ch: word){
            int index = ch-'a';
            if(curr->alpha[index]==nullptr) 
                curr->alpha[index] = new Node();
            curr = curr->alpha[index]; 
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(auto ch: word){
            int index = ch-'a';
            if(curr->alpha[index]==nullptr) 
                return false;
            curr = curr->alpha[index]; 
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(auto ch: prefix){
            int index = ch-'a';
            if(curr->alpha[index]==nullptr) 
                return false;
            curr = curr->alpha[index]; 
        }
        return true;
    }
};
