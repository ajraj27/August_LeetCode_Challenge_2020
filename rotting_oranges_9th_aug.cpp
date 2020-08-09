class Solution {
public:
    int valid(int x,int y,int n,int m){
        if(x<0 || x>=n || y<0 || y>=m)
            return 0;
        return 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid[0].size(),n=grid.size();
        queue<pair<pair<int,int>,int> > q;
        int mx=0;
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==2)
                    q.push(make_pair(make_pair(i,j),0));
        
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty()){
            pair<pair<int,int>,int> temp=q.front();
            q.pop();
            int x=temp.first.first;
            int y=temp.first.second;
            int curr=temp.second;
             mx=max(mx,curr);
           
            for(int j=0;j<4;j++){
                int newx=x+dx[j];
                int newy=y+dy[j];
                
                if(valid(newx,newy,n,m) && grid[newx][newy]==1){
                    q.push(make_pair(make_pair(newx,newy),curr+1));
                    grid[newx][newy]=2;
                }
                    
            }
        
            
        }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(grid[i][j]==1)
                    return -1;
        
        return mx;
    }
};