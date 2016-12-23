/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

/*����⻹�ǲ�ȡ�Ĳ�α�����˼�룬�õ��˶���*/

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode *> qlist;
        vector<vector<int>> v1;        /*��ά����*/
        if(root == NULL)
        {
            return v1;
        }
     
       qlist.push(root);
       while(!qlist.empty())
       {   
            vector<int> level;
           int size = qlist.size();                    /*����ط����ص㣬�õ���ǰ���е�������������һ��Ľ�����*/
           
           for(int i = 0 ;i < size;i++)
           {
               TreeNode *temp = qlist.front();
               level.push_back(temp->val);
               qlist.pop();
               if(temp->left != NULL)
               {
                    qlist.push(temp->left);   
               }
               if(temp->right != NULL)
               {
                   qlist.push(temp->right);
               }
           }
           
           v1.push_back(level);        									/*vector�¿�������ֱ��װ��*/
           
       }
       return v1;
        
    }
};