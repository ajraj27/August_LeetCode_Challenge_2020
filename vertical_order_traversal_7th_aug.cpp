/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    struct cmp{
        bool operator()(const vector<int>& a,const vector<int>& b){
            return a[1]<b[1] || (a[0]==b[0] && a[1]==b[1] && a[2]>b[2]);
        }
    };
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root) return {};
        vector<vector<int> > ans;
        
        map<int,priority_queue<vector<int>,vector<vector<int>>,cmp> >m;
        queue<pair<TreeNode*,vector<int>> > q;

        q.push({root,{0,0}});
        
        while(!q.empty()){
            auto z=q.front();
            q.pop();
            TreeNode* u=z.first;
            int x=z.second[0],y=z.second[1];
            
            m[x].push({x,y,u->val});
            
            if(u->left) q.push({u->left,{x-1,y-1}});
            if(u->right) q.push({u->right,{x+1,y-1}});
        }
        
        for(auto &x:m){
            vector<int> res;
            while(!x.second.empty()){
                res.push_back(x.second.top()[2]);
                x.second.pop();
            }
            
            ans.push_back(res);
        }
        
        return ans;
    }
};