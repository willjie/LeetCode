
/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
*/
/*这道题的核心就是两个根节点，左跟结点的左节点等于右跟结点的右节点，左跟结点的右节点等于右跟结点的左节点*/

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
    bool isSymmetric(TreeNode* root) {
        
        /*层次遍历，判断两个根结点，一个根节点的左结点等于另一个根节点的右结点*/
        
        queue<TreeNode*> q1,q2;
        if(root == NULL)
        {
            return true;
        }
        else if((root->left == NULL && root->right != NULL) || (root->right == NULL && root->left != NULL))
        {
            return false;
        }
        q1.push(root->left);
        q2.push(root->right);
        
        while(!q1.empty() && !q2.empty())
        {
            TreeNode *temp1 = q1.front();
            TreeNode *temp2 = q2.front();
            q1.pop();
            q2.pop();
            if((temp1 == NULL && temp2 != NULL) || (temp1 != NULL && temp2 == NULL))
            {
                return false;
            }
            if( temp1 != NULL && temp2 != NULL && temp1->val != temp2->val)
            {
                return false;
            }
            else if(temp1 != NULL && temp2 != NULL)
            {
                q1.push(temp1->left);
                q1.push(temp1->right);
                q2.push(temp2->right);
                q2.push(temp2->left);
            }
        }
        return true;
        
        
        
    }
};

/*递归的方法*/
class Solution {
 public:
     bool check(TreeNode *leftNode, TreeNode *rightNode)
     {
         if (leftNode == NULL && rightNode == NULL)
             return true;
             
         if (leftNode == NULL || rightNode == NULL)
             return false;
             
         return leftNode->val == rightNode->val && check(leftNode->left, rightNode->right) && 
             check(leftNode->right, rightNode->left);
     }
     
     bool isSymmetric(TreeNode *root) {
         // Start typing your C/C++ solution below
         // DO NOT write int main() function
         if (root == NULL)
             return true;
             
         return check(root->left, root->right);
     }
 };