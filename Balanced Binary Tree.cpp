
/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/*这道题的意思就是每个节点的左右子树的深度差不能超过1*/

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
    bool isBalanced(TreeNode* root) {
        
      
        int leftsize,rightsize;
        if(root == NULL)
        {
            return true;
        }
        
        leftsize = finddepth(root->left);
        rightsize = finddepth(root->right);
        
        if(abs(leftsize - rightsize) > 1) return false;
       
       return isBalanced(root->left) && isBalanced(root->right);  /*递归的思想*/
       
    }
    
    int finddepth(TreeNode *root)          /*求root节点的深度*/
    {
       int leftsize = 0,rightsize = 0;
        
        if(root == NULL)
        {
          return 0;
        }
        leftsize = finddepth(root->left);
        rightsize = finddepth(root->right);
        
        return max(leftsize,rightsize) + 1;
        
       
        
       
    }
};