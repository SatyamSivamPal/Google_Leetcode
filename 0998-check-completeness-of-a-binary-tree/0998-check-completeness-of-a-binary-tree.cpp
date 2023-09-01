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
    bool isCT(TreeNode * root, int cnt, int index)
    {
        if(root == NULL)
        {
            return true;
        }

        if(index >= cnt)
        {
            return false;
        }

        else{
            bool left = isCT(root->left, cnt, 2*index + 1);
            bool right = isCT(root->right, cnt, 2*index + 2);

            return (left && right);
        }
        
    }
    int count(TreeNode * root)
    {
        if(root == NULL)
        {
            return 0;
        }
        return count(root->left) + count(root->right) + 1;
    }
    bool isCompleteTree(TreeNode* root) {
        TreeNode * temp = root;
        int cnt = 0;

        cnt = count(root);

        if(isCT(root, cnt, 0))
        {
            return true;
        }
        return false;
    }
};