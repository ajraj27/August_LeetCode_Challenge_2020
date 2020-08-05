class WordDictionary {
public:
    /** Initialize your data structure here. */
    typedef struct node{
        int cnt;
        node* child[26];
    } trie;
    
    trie* root;
    WordDictionary() {
        root=new trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        trie* curr=root;
        
        for(char c:word){
            int l=c-'a';
            
            if(!curr->child[l]) curr->child[l]=new trie();
            curr=curr->child[l];
        }
        
        curr->cnt++;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return util(word,0,root);
    }    
    
    bool util(string& word,int idx,trie* curr){
        int n=word.length();
        
        for(int i=idx;i<n;i++){
            if(word[i]!='.'){
                int l=word[i]-'a';
                if(!curr->child[l]) return false;
                curr=curr->child[l];
            } else{
                for(int j=0;j<26;j++){
                    if(curr->child[j]) if(util(word,i+1,curr->child[j])) return true;
                }
                
                return false;
            }
        }
        
        return curr->cnt>0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */