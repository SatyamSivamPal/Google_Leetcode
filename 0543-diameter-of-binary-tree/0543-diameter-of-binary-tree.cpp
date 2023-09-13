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
    pair<int,int> diameter(TreeNode* root)
    {
        if(root == NULL)
        {
            pair<int,int> p = {0,0};
            return p;
        }

        pair<int,int> l = diameter(root->left);
        pair<int,int> r = diameter(root->right);

        int dl = l.first;
        int dr = r.first;
        int h = l.second + r.second;

        pair<int,int>ans;
        ans.first = max(max(dl,dr), h);
        ans.second = max(l.second, r.second) + 1;

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return diameter(root).first;
    }
};