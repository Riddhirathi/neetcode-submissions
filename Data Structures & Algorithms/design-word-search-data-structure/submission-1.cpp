class WordDictionary {
private:
    class Node{
    public:
        int isEnd;
        Node* alpha[26];
        Node(){
            for(int i=0; i<26; i++){
                alpha[i]=nullptr;
            }
            isEnd = false;
        }
    };
    Node* root;

    bool dfs(Node* curr, string& word, int index){
        if(index==word.size()) return curr->isEnd;
        char ch = word[index];
        if(ch!='.'){
            int i = ch-'a';
            if(curr->alpha[i]==nullptr){
                return false;
            }
            return dfs(curr->alpha[i], word, index+1);
        }
        for(int i=0; i<26; i++){
            if(curr->alpha[i]!=nullptr){
                if(dfs(curr->alpha[i], word, index+1))
                    return true;
            }
        }
        return false;
    }
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* curr = root;
        for(auto ch: word){
            int index = ch-'a';
            if(curr->alpha[index]==nullptr){
                curr->alpha[index] = new Node();
            }
            curr = curr->alpha[index];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(root, word, 0);
    }
};
