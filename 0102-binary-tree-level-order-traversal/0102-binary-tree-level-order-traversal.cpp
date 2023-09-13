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
        queue<TreeNode*>q;
        q.push(root);
        
        vector<vector<int>>ans;

        if(root == NULL)
        {
            return {};
        }

        while(!q.empty())
        {
            int size = q.size();
            vector<int>res;
            TreeNode * temp = NULL;
            
            for(int i=0; i<size; i++)
            {  
                temp = q.front();
                q.pop();

                res.push_back(temp->val);

                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};