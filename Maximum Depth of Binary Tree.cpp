/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*/

/*本题就是求树的深度*/

/*用到了递归的思想（DFS）*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int leftsize,rightsize;
        leftsize = rightsize = 0;
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            leftsize = maxDepth(root->left);
            rightsize = maxDepth(root->right);
        }
        return leftsize > rightsize? leftsize+1:rightsize+1;
        
    }
    
  
};