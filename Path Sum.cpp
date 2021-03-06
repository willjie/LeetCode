/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

/*前序遍历的递归调用*/

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
    bool hasPathSum(TreeNode* root, int sum) {
        
        int sum1 = 0;
        bool res = HasPath(root,sum,sum1);
       
        return res;    
    }

    bool HasPath(TreeNode *root,int sum,int sum1)
    {
        if(root == NULL)
        {
           return false;
        }
        sum1 += root->val;
        
        if(root->left == NULL && root->right == NULL)
        {
            if(sum1 == sum)
            {
                return true;
            }
            else return false;
        }
        else
         return  HasPath(root->left,sum,sum1) || HasPath(root->right,sum,sum1);
        
    }
};