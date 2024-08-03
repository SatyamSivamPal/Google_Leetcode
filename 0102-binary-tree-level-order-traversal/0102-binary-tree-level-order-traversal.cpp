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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        map<int, vector<int>>mp;
        vector<vector<int>>ans;
        

        if(root == NULL) {
            return ans;
        }

        q.push({root, 0});

        while(!q.empty())
        {
            pair<TreeNode*, int> p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int lvl = p.second;

            mp[lvl].push_back(node->val);

            if(node->left){
                q.push({node->left, lvl+1});
            }

            if(node->right){
                q.push({node->right, lvl+1});
            }
        }
    
        for(auto it: mp){
            vector<int>temp;
            for(int i = 0; i<it.second.size(); i++){
                temp.push_back(it.second[i]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};