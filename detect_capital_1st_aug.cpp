class Solution {
public:
    
    int isCapital(char c){
        return (c>='A' && c<='Z');
    }
    
    bool detectCapitalUse(string word) {
        int n=word.length();
        int cnt=0;
        for(char c:word) cnt+=isCapital(c);
        
        if(cnt==n || cnt==0) return 1;
        else if(cnt==1 && isCapital(word[0])) return 1;
        return 0;
    }
};