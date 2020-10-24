#include<iostream>
using namespace std;

struct treeNode
{
	int data;
	struct treeNode* left;
	struct treeNode* right;
	treeNode ()
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
    void insert(int item);
    struct treeNode* deletea(struct treeNode* roota,int item);
    void inorder(treeNode *);
    struct treeNode* minValue(struct treeNode* node) ;
};

void tree :: insert(int item)
{
    treeNode *p = new treeNode;
    treeNode *parent;
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    parent = NULL;
    if(root == NULL)
        root=p;
    else
    {
        treeNode *ptr;
        ptr=root;
        while(ptr!=NULL)        
        {
            parent=ptr;
            if(item > ptr->data )        
                ptr = ptr->right;
            else
                ptr=ptr->left;
        }   
        if(item < parent->data)
            parent->left = p;
        else
            parent->right = p;
    }
}

struct treeNode* tree :: deletea(struct treeNode* roota,int item) 
{ 
    if(roota == NULL)
        return roota;
    if (item < roota->data)
        roota->left = deletea(roota->left, item); 
    else if (item > roota->data) 
        roota->right = deletea(roota->right, item); 
    else
    { 
        if (roota->left == NULL) 
        { 
            struct treeNode *temp = roota->right; 
            free(roota); 
            return temp; 
        } 
        else if (roota->right == NULL) 
        { 
            struct treeNode *temp = roota->left; 
            free(roota); 
            return temp; 
        } 
  
        struct treeNode* temp = minValue(roota->right);  
        roota->data = temp->data; 
        roota->right = deletea(roota->right, temp->data); 
    } 
    return roota;
} 

struct treeNode* tree :: minValue(struct treeNode* node) 
{ 
    struct treeNode* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
    return current; 
} 


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
    bintree.insert(45);
    bintree.insert(67);
    bintree.insert(76);
    bintree.insert(7);
    bintree.insert(12);
    bintree.insert(33);
    bintree.insert(9); 
    int i;
    cout<<"Inorder traversal:"<<endl;
    bintree.inorder(bintree.root);
    cout<<endl;
    cout<<"Enter item to insert : ";
    cin>>i;
    bintree.insert(i);
    cout<<"Inorder traversal:"<<endl;
    bintree.inorder(bintree.root);
    cout<<endl;
    cout<<"Enter item to delete : ";
    int n;
    cin >> n;
    bintree.deletea(bintree.root , n);
    cout<<"after deletion : "<<endl;
    bintree.inorder(bintree.root);
    return 0;
}