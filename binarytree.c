//c program for implementing Binary Search Tree
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
typedef struct node1
{
        struct node1 *Lchild,*Rchild;
        int data;
}node;
void inorder(node *Root)
{
node *ptr=Root;
if(ptr!=NULL)
        {
        inorder(ptr->Lchild);
        printf("%d ",ptr->data);
        inorder(ptr->Rchild);
        }

}
void postorder(node *Root)
{
node *ptr=Root;
if(ptr!=NULL)
        {
        postorder(ptr->Lchild);
        postorder(ptr->Rchild);
        printf("%d ",ptr->data);
        }
}
void preorder(node *Root)
{
node *ptr=Root;
if(ptr!=NULL)
	{
	printf("%d ",ptr->data);
	preorder(ptr->Lchild);
	preorder(ptr->Rchild);
	}
}
void buildbst(node* Root)
  {
  int flag;
  int item,i=1;
  node *ptr,*ptr1,*new;
  while(i==1)
    {
    ptr=Root;
    flag=1;
    printf("enter the value of next node   :");
    scanf("%d",&item);
    while((ptr!=NULL)&&(flag==1))
      {
      if(item<(ptr->data))
        {
        ptr1=ptr;
        ptr=ptr->Lchild;
        }
     else if(item>(ptr->data))
        {
	ptr1=ptr;
	ptr=ptr->Rchild;
	}
     else if(item==(ptr->data))
	{
	flag=0;
	printf("Unable to create a new  node   \n          data already exists      \n DUPLICATION NOT POSSIBLE!! \n");
	}
     }
    if(ptr==NULL)
      {
      new=(node*)malloc(sizeof(node));
      new->data=item;
      new->Lchild=NULL;
      new->Rchild=NULL;
      }
    if((ptr1->data)>item)
      {
      ptr1->Lchild=new;
      }
    else if((ptr1->data)<item)
      {
      ptr1->Rchild=new;
      }
    printf("Do you want to add next node to tree...yes-1/no-0        \n    enter 1/0    \n");
    scanf("%d",&i);
  }
}
void main()
  {
  int value;
  node*root;
  root=(node*)malloc(sizeof(node));
  printf("enter the value of root   : ");
  scanf("%d",&value);
  root->data=value;
  root->Lchild=NULL;
  root->Rchild=NULL;
  printf("\n>>>>>>>>Creating the Binary Search Tree<<<<<<<<<<<\n");
  buildbst(root);
  printf("\nSuccesfully created the tree\n");
  printf("Inorder traversal of the tree: ");
  inorder(root);
  printf("\n");
  printf("Postrder traversal of the tree: ");
  postorder(root);
  printf("\n");
  preorder(root);
  printf("\n *-----End -----*\n");
  }
  //Contribution by LINSMARIYA
