class CombinationIterator {
public:
    vector<string> ans;
    string s;
    int l,n,cnt,idx=0;
    
    void getAll(int i,string &str){
        if(str.length()==l){
            ans.push_back(str);
            return;
        }
        
        for(int j=i;j<n;j++){
            str.push_back(s[j]);
            getAll(j+1,str);
            str.pop_back();
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        s=characters;
        l=combinationLength;
        n=characters.length();
        string str="";
        getAll(0,str);
        cnt=ans.size();
    }
    
    string next() {
        return ans[idx++];
        
    }
    
    bool hasNext() {
        return idx<cnt;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */