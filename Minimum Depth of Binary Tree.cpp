Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

/*这道题就是找出从根节点到最近的叶子结点所经过的结点数*/

/*其实就是DFS（深度优先遍历）*/
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
    int minDepth(TreeNode* root) 
    {
        if(root == NULL)
        {
            return 0;
        }
        if(root->left == NULL)
        {
            return minDepth(root->right) + 1;
        }
        if(root->right == NULL)
        {
            return minDepth(root->left) + 1;
        }
        if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        
       return min(minDepth(root->left),minDepth(root->right)) + 1;
     
       
    }
    
 
};