#include <stdio.h>
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
//前序遍历二叉树
int getSize(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	return getSize(root->left) + getSize(root->right) + 1;
}
void _preorder(struct TreeNode* root, int* array, int* idx) {
	if (root) {
		array[*idx] = root->val;
		++(*idx);
		_preorder(root->left, array, idx);
		_preorder(root->right, array, idx);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int*array = (int*)malloc(sizeof(int)*getSize(root));
	*returnSize = 0;
	_preorder(root, array, returnSize);
	return array;
}



struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
//中序遍历二叉树
int getSize(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	return getSize(root->left) + getSize(root->right) + 1;
}
void _Inorder(struct TreeNode* root, int* array, int* idx) {
	if (root) {
		_Inorder(root->left, array, idx);
		array[*idx] = root->val;
		++(*idx);
		_Inorder(root->right, array, idx);
	}
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int*array = (int*)malloc(sizeof(int)*getSize(root));
	*returnSize = 0;
	_Inorder(root, array, returnSize);
	return array;
}


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
//后序遍历二叉树
int getSize(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	return getSize(root->left) + getSize(root->right) + 1;
}
void _Postorder(struct TreeNode* root, int* array, int* idx) {
	if (root) {
		_Postorder(root->left, array, idx);
		_Postorder(root->right, array, idx);
		array[*idx] = root->val;
		++(*idx);
	}
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int*array = (int*)malloc(sizeof(int)*getSize(root));
	*returnSize = 0;
	_Postorder(root, array, returnSize);
	return array;
}


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};
//单值二叉树

bool isUnival(struct TreeNode* root,int key) {
	if (root == NULL)
		return 1;
	return root->val == key && isUnival(root->left, key) && isUnival(root->right, key);
}
bool isUnivalTree(struct TreeNode* root) {
	return isUnivalTree(root, root->val);
}

//二叉树最大深度
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;	
};

int maxDepth(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	int l = maxDepth(root->left);
	int r = maxDepth(root->right);
	return l > r ? l + 1 : r + 1;

}

//翻转二叉树
void _invert(struct TreeNode* root) {
	if (root) {
		struct TreeNode* tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		_invert(root->left);
		_invert(root->right);
	}
}
struct TreeNode* invertTree(struct TreeNode* root) {
	_invert(root);
	return root;
}

//判断两棵树是否相同
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL || q == NULL)
		return false;;
	if (p == NULL && q == NULL)
		return true;
	return q->val == p->val&&isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
//对称二叉树

bool func(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL && q == NULL)
		return 1;
	if (p == NULL || q == NULL)
		return 0;
	return p->val == q->val&&func(p->left, q->right) && func(p->right, q->left);

}
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
	if (p == NULL || q == NULL)
		return false;;
	if (p == NULL && q == NULL)
		return true;
	return q->val == p->val&&isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
//判断是否为子树
bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
	if (t == NULL)
		return true;
	if (s == NULL)
		return false;
	if (isSameTree(s, t))
		return true;
	return isSubtree(s->left, t) || isSubtree(s->right, t);
}