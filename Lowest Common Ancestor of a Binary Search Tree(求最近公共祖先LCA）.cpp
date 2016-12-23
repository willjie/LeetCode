/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: ��The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).��

        _______6______
       /              \
    ___2__          ___8__
   /      \        /      \
   0      _4       7       9
         /  \
         3   5
For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another example is LCA of nodes 2 and 4 is 2, 
since a node can be a descendant of itself according to the LCA definition.
*/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
       //���õݹ��������ȱ���
       
       //������Ⱦ�������������������������Ŀ��ڵ㣬�������Ŀ����һ�������ϣ����ȱ������ĸ� �ĸ������������
       
       TreeNode *left,*right;
       left = right = NULL;
       if(root == NULL || root == p || root == q)
       {
           return root;
       }
       
       left = lowestCommonAncestor(root->left,p,q);
       right = lowestCommonAncestor(root->right,p,q);
       if(left != NULL && right != NULL)
       {
           return root;
       }
       
       return left == NULL? right:left;
       
    }
    
};