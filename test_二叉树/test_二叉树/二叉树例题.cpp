// ��������㷨 -- ��

//1.
class Solution {
public:
    int calculateDepth(TreeNode* root) {

         if(root == nullptr)
         {
             return 0;
         }
         int lmax = calculateDepth(root->left);
         int rmax = calculateDepth(root->right);
         return 1+max(lmax,rmax);
    }
};



//2.
class Solution {
    int maxDepth = 0;
    void dfs(TreeNode * root, int depth)
    {
        if(depth > maxDepth)
        {
            maxDepth = depth;
        }
        if(root)
        {
            dfs(root->left,depth+1);
            dfs(root->right,depth+1);
        }
    }
public:
    int calculateDepth(TreeNode* root) {

        dfs(root,0);
        return maxDepth;
    }
};


// ��ֵ������ 
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        if(!root)
        {
            return true;
        }
        // ��������� ��return���� false�����
        if(root->left)
        {
            if(root->val != root->left->val)
            {
                return false;
            }
            // ������������ �ж����
            if( !isUnivalTree(root->left) )
            {
                return false;
            }
        }
        if(root->right)
        {
            if(root->val != root->right->val)
            {
                return false;
            }
            if(!isUnivalTree(root->right))
            {
                return false;
            }
        }
        // ����false����������return true
        return true;
    }
};
