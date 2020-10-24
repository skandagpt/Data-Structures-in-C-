#include<iostream>
using namespace std;

struct treeNode
{
	int data;
	struct treeNode* left;
	struct treeNode* right;
    treeNode(int data)
    {
        this->data = data;
		left = right = NULL;
    }
};


class tree
{
   public:
    treeNode *root;
    tree()
    {
        root=NULL;
    }
    void inorder(treeNode *);
};


void tree :: inorder(treeNode *ptr)
{
    if(ptr!=NULL)
    {
        inorder(ptr->left);
        cout<<"  "<<ptr->data<<"     ";
        inorder(ptr->right);
    }
}
int main()
{
    tree bintree;
    bintree.root = new treeNode(45);
    bintree.root->left = new treeNode(37);
    bintree.root->right = new treeNode(42);
    bintree.root->right->left = new treeNode(67);
    bintree.root->right->right = new treeNode(12);
    bintree.root->left->left = new treeNode(78);
    bintree.root->left->right = new treeNode(33);
    bintree.root->right->left->right = new treeNode(3);
    cout<<"Inorder traversal:"<<endl;
    bintree.inorder(bintree.root);
    return 0;
}