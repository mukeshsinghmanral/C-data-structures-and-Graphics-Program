#include<stdio.h>
#include<stdlib.h>

typedef struct BST
{
	int data;
	struct BST *left;
	struct BST *right;
}node;

node *create();
void insert(node *,node *);
void preorder(node *);
void inorder( node *);
void findlocation(node**,node **,int);
node *deleteNode(node *,int);
node *minValueNode(node *);
int main()
{   int choice,item;
	char ch;
	node *root=NULL,*temp;
	while(1){
	printf("\n1.create\n2.preorder\n3.inorder\n4.delete item\n5.exit\n");
	printf("enter your choice:");
	scanf("%d",&choice);
	switch(choice){
       case 1 :
 	do
	{
		temp=create();
		if(root==NULL)
			root=temp;
		else
			insert(root,temp);

		printf("\nDo you want to enter more(y/n)?");
		getchar();
		scanf("%c",&ch);
	}while(ch=='y'|ch=='Y');
          break;
	case 2 :   printf("\nPreorder Traversal: ");
	preorder(root);
	break;
	case 3 :
	printf("\nINORDER TRAVERSALS:");
	inorder(root);
	break;
	case 4 : printf("enter item to be deleted:");
	         scanf("%d",&item);
	         root=deleteNode(root,item);
	case 5 : exit(0);
	break;
	default : printf("invalid");
	  }
	}
	return 0;
}

node *create()
{
	node *temp;
	printf("\nEnter data:");
	temp=(node*)malloc(sizeof(node));
	scanf("%d",&temp->data);
	temp->left=temp->right=NULL;
	return temp;
}

void insert(node *root,node *temp)
{
	if(temp->data<root->data)
	{
		if(root->left!=NULL)
			insert(root->left,temp);
		else
			root->left=temp;
	}

	if(temp->data>root->data)
	{
		if(root->right!=NULL)
			insert(root->right,temp);
		else
			root->right=temp;
	}
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node *root){
    if(root!=NULL)
        {
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
}
 node* deleteNode(node* root, int key)
{    node *temp;

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);


    else if (key > root->data)
        root->right = deleteNode(root->right, key);

   else
    {
        if (root->left == NULL)
        {
             node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
             node *temp = root->left;
            free(root);
        }


         node* temp = minValueNode(root->right);


        root->data = temp->data;

       root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
node *minValueNode(node* current)
{


while (current->left != NULL)
current = current->left;

return current;
}



