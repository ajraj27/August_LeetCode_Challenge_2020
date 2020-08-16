class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<=1) return 0;
        
        vector<int> profit(n,0);
        int mx=prices[n-1];
        
        for(int i=n-2;i>=0;i--){
            mx=max(mx,prices[i]);
            
            profit[i]=max(profit[i+1],mx-prices[i]);
        }
        
        int mn=prices[0];
        
        for(int i=1;i<n;i++){
            mn=min(mn,prices[i]);
            
            profit[i]=max(profit[i-1],profit[i]+prices[i]-mn);
        }
        
        return profit[n-1];
    }
};