#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// m叉数第i层至多有m的i-1个节点



// 前序遍历（DLR）-- 从root开始 遍历所有左子树 再遍历右子树
// 中序遍历（LDR）-- 从左子树开始 再到root 再到右子树
// 后序遍历（LRD）-- 从左子树开始 到右子树 到root

void pre_order(TreeNode* Node)//前序遍历递归算法
{
    if (Node == NULL)
        return;
    printf("%d ", Node->data);//显示节点数据，可以更改为其他操作。在前面
    pre_order(Node->left);
    pre_order(Node->right);
}
void middle_order(TreeNode* Node)//中序遍历递归算法
{
    if (Node == NULL)
        return;
    middle_order(Node->left);
    printf("%d ", Node->data);//在中间
    middle_order(Node->right);
}
void post_order(TreeNode* Node)//后序遍历递归算法
{
    if (Node == NULL)
        return;
    post_order(Node->left);
    post_order(Node->right);
    printf("%d ", Node->data);//在最后
}

int main()
{      
    
	return 0;
}