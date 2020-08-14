class Solution {
public:
    int longestPalindrome(string s) {
        map<char,int> m;
        for(char c:s) m[c]++;
        int ans=0,ok=0;
        for(auto x:m){
            if(x.second&1) ans+=x.second-1,ok=1;
            else ans+=x.second;
        }
        
        return ans+ok;
    }
};