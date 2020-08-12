class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        long long int prev=1;
        
        for(int i=1;i<=rowIndex;i++){
            int curr=(prev*(rowIndex-i+1))/i;
            ans.push_back(curr);
            prev=curr;
        }
        
        return ans;
    }
};