class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> children;
    bool isTerminal;
    TrieNode(char val) {
        data = val;
        isTerminal = false;
    }
};
void insertWord(TrieNode* root, string word){
    //base case
    if(word.length() == 0){
        root->isTerminal = true;
        return;
    }

    //1 case
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        //present
        child = root->children[ch];
    }else{
        //absent
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    //baki recursion sambhal lega
    insertWord(child, word.substr(1));
}
bool searchWord(TrieNode* root, string word){
    //base case
    if(word.length() == 0){
        return root->isTerminal;
    }

    //1 case
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        //present
        child = root->children[ch];
    }else{
        //absent
        return false;
    }
    //baki recursion sambhal lega
    bool recAns = searchWord(child, word.substr(1));
    return recAns;
}
bool searchPrefix(TrieNode* root, string word){
    // base case
    if(word.length() == 0){
        return true;
    }
    // 1 case
    char ch = word[0];
    TrieNode* child;
    if(root->children.find(ch) != root->children.end()){
        // present
        child = root->children[ch];
    }
    else{
        // absent
        return false;
    }
    // baaki recursion
    bool recAns = searchPrefix(child, word.substr(1));
    return recAns;
}
class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode('-'); }

    void insert(string word) {
        insertWord(root, word);
    }

    bool search(string word) {
        return searchWord(root, word);
    }

    bool startsWith(string prefix) {
        return searchPrefix(root, prefix);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */