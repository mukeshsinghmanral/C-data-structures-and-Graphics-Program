#include<stdio.h>
#include<stdlib.h>
struct node{
  int data;
  struct node *left,*right;
};
struct node *create();
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
 struct node *insert(struct node *,int);
void exit();
int main(){
    printf("\t\t\t\t\t\t\t\t\t\t------------------------------------TRAVERSALS OF A BINARY TREE-----------------------------------------------");
    printf("\n\n\n\n");
    struct node *root=NULL;
    int choice,data;
    while(1){
    printf("\n1.create tree\n2.preorder\n3.inorder\n4.postorder\n5.insert an item\n6.exit\n");
    printf("enter your choice:");
    scanf("%d",&choice);
    switch(choice){
    case 1 : root=create();
            break;
    case 2 : preorder(root);
            break;
    case 3 : inorder(root);
            break;
    case 4 : postorder(root);
            break;
    case 5 : printf("item to be inserted:");
             scanf("%d",&data);
           root= insert(root,data);
            break;
    case 6 : exit(0);
     break;
     default : printf("invalid choice");
      }
    }
return 0;
}
struct node *create(){
    int x;
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("enter item(-1) for finish:");
    scanf("%d",&x);
    if(x==-1){
        return 0;
    }
    else{
     newnode->data=x;
     printf("enter left child:");
     newnode->left=create();
     printf("enter right child:");
     newnode->right=create();
    }
    return newnode;
}
void preorder(struct node *root){
   if(root==NULL)
    return;
    printf(" %d ",root->data);
  preorder(root->left);
  preorder(root->right);
}
void inorder(struct node *root){
  if(root==NULL)
    return;
  inorder(root->left);
  printf(" %d ",root->data);
  inorder(root->right);
}
void postorder(struct node *root){
 if(root==NULL)
    return;
 postorder(root->left);
 postorder(root->right);
 printf(" %d ",root->data);
}
     struct node* insert(struct node* root, int data)
    {
        struct node *newNode;
         newNode=(struct node *)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;

           if (root == NULL)    //If the tree is empty, return a new, single node
            return newNode(data);
        else
        {
            //Otherwise, recur down the tree
            if (data <= root->data)
                root->left  = insert(root->left, data);
            else
                root->right = insert(root->right, data);
            //return the (unchanged) root pointer
            return root;
        }
    }
