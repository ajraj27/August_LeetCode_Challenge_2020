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
    int ans=0;
    map<int,int> m;
    
    void solve(TreeNode* root,int curr,int sum){
        if(!root) return ;
        curr+=root->val;
        ans+=m[curr-sum];
        m[curr]++;
        solve(root->left,curr,sum);
        solve(root->right,curr,sum);
        if(m[curr]>1) m[curr]--;
        else m.erase(curr);
    }
    int pathSum(TreeNode* root, int sum) {
        m[0]=1;
        solve(root,0,sum);
        return ans;
    }
};