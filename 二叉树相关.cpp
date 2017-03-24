//二叉树
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTree {
	public:
		/************************构建二叉树*************************/
		TreeNode* constructTree (std::string s) {
			int i = 0;
			std::string pstr = "";
			bool isRight=false;
			stack<TreeNode*> s1; //存放结点
			stack<char> s2; //存放分隔符
			TreeNode *p,*temp;
			while (isdigit(s[i])) {
				pstr += s[i++];
			}
			TreeNode* root = new TreeNode(std::stoi(pstr));
			root->left=NULL;
			root->right=NULL;
			s1.push(root);
			pstr = "";
			while(i < s.length())
			{
				if(s[i]=='(')
				{
					s2.push(s[i]);
					isRight=false;
				}
				else if(s[i]==',')
				{
					isRight=true;
				}
				else if(s[i]==')')
				{
					s1.pop();
					s2.pop();
				}
				else if(isdigit(s[i]))
				{
					if (isdigit(s[i+1])) {
						pstr += s[i];
					} else {
						pstr += s[i];
						p = new TreeNode(std::stoi(pstr));
						p->left = NULL;
						p->right = NULL;
						temp = s1.top();
						if (isRight == true) {
							temp->right = p;
						}
						else {
							temp->left = p;
						}
						if (s[i + 1] == '(')
							s1.push(p);
						pstr = "";
					}
				}
				i++;
			}
			return root;
		}
		/************************构建二叉树*************************/

		/************************销毁二叉树*************************/
		void destoryTree (TreeNode* root) {
			if (root->left) destoryTree(root->left);
			if (root->right) destoryTree(root->right);
			delete root;
		}
		/************************销毁二叉树*************************/

		/************************递归,非递归方法前,中,后序遍历二叉树*************************/
		//1.递归,前序
		void RecursePreOrder(TreeNode* root) {
			if (root != NULL) {
				std::cout << root->val << " ";
				RecursePreOrder(root->left);
				RecursePreOrder(root->right);
			}
		}

		//2.递归,中序
		void RecurseInOrder(TreeNode* root) {
			if (root != NULL) {
				RecurseInOrder(root->left);
				std::cout << root->val << " ";
				RecurseInOrder(root->right);
			}
		}

		//3.递归,后序
		void RecurseAftOrder(TreeNode* root) {
			if (root != NULL) {
				RecurseAftOrder(root->left);
				RecurseAftOrder(root->right);
				std::cout << root->val << " ";
			}
		}

		//4.非递归,前序
		void NonRecursePreOrder(TreeNode* root) {
			stack<TreeNode*> s;
			TreeNode* p = root;
			while (p != NULL || !s.empty()) {
				while (p != NULL) {
					std::cout << p->val << " ";
					s.push(p);
					p = p->left;
				}
				if (!s.empty()) {
					p = s.top();
					s.pop;
					p = p->right;
				}
			}
		}

		//5.非递归,中序
		void NonRecurseInOrder(TreeNode* root) {
			stack<TreeNode*> s;
			TreeNode* p = root;
			while (p != NULL || !s.empty()) {
				while (p != NULL) {
					s.push(p);
					p = p->left;
				}
				if (!s.empty()) {
					p = s.top();
					cout << p->val << " ";
					s.pop();
					p = p->right;
				}
			}
		}

		//6.非递归,后序
		void NonRecurseAftOrder(TreeNode* root) {
			stack<TreeNode*> s;
			TreeNode *cur; //当前结点
			TreeNode *pre=NULL; //前一次访问的结点
			s.push(root);
			while(!s.empty())
			{
				cur=s.top();
				if((cur->left==NULL&&cur->right==NULL)||
						(pre!=NULL&&(pre==cur->left||pre==cur->right)))
				{
					cout<<cur->val <<" "; //如果当前结点没有孩子结点或者孩子节点都已被访问过
					s.pop();
					pre=cur;
				}
				else
				{
					if(cur->right!=NULL)
						s.push(cur->right);
					if(cur->left!=NULL)
						s.push(cur->left);
				}
			}
		}
		/************************递归,非递归方法前,中,后序遍历二叉树*************************/

		//判断是否是有效的二叉搜索树
		bool isValidBST(TreeNode* root) {
			return validateBST(root, LONG_MIN, LONG_MAX);
		}

		//判断是否是镜像树
		bool isSymmetric(TreeNode* root) {
			return isSym(root, root);
		}

		//根据前序，中序序列构建二叉树
		TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			if (preorder.size() != inorder.size()) return NULL;
			int n = preorder.size();
			return buildBT(preorder, inorder, 0, n - 1, 0, n - 1);
		}

	private:
		bool validateBST(TreeNode *root, long minVal, long maxVal) {
			if (!root) return true;
			if (root->val <= minVal || root->val >= maxVal) return false;
			return validateBST(root->left, minVal, root->val) && validateBST(root->right, root->val, maxVal);
		}

		bool isSym(TreeNode *lr, TreeNode *rr) {
			if (!lr && !rr) return true;
			if ((lr && !rr) || (rr && !lr)) return false;
			if (lr == rr) return isSym(lr->left, lr->right);
			if (lr->val != rr->val) return false;
			return isSym(lr->left, rr->right) && isSym(lr->right, rr->left);
		}

		TreeNode* buildBT(vector<int> &preorder, vector<int> &inorder, int s1, int e1, int s2, int e2) {
			if (s1 > e1 || s2 > e2) return NULL;
			TreeNode* p = new TreeNode(preorder[s1]);
			int pIndex = -1;
			for (int i = s2; i <= e2; ++i) {
				if (inorder[i] == p->val) {
					pIndex = i;
				}
			}
			if (pIndex == -1) return NULL;
			int leftTreeSize = pIndex - s2;
			int rightTreeSize = e2 - pIndex;
			p->left = buildBT(preorder, inorder, s1+1, s1+leftTreeSize, s2, pIndex-1);
			p->right = buildBT(preorder, inorder, e1-rightTreeSize +1, e1, pIndex+1, e2);
			return p;
		}
};

int main () {
}
