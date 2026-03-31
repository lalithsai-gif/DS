#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL,*p,*temp,*found;

struct node *newNode(int item)
{
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}

struct node *insertion(struct node *root,int key)
{
    if(root==NULL)
        return newNode(key);
    if(key < root->data)
        root->left = insertion(root->left,key);
    else if(key > root->data)
        root->right = insertion(root->right,key);
    return root;
}

struct node *createBST(struct node *root)
{
    int n,i,key;
    printf("Enter no.of nodes you want in BST:");
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        printf("Enter key value : ");
        scanf("%d",&key);
        root=insertion(root,key);
    }
    return root;
}

struct node *minvalueBST(struct node *root)
{
    p=root;
    while(p!=NULL && p->left!=NULL)
        p=p->left;
    return p;
}

struct node *maxvalueBST(struct node *root)
{
    p=root;
    while(p!=NULL && p->right!=NULL)
        p=p->right;
    return p;
}

struct node *deletion(struct node *root,int key)
{
    if(root==NULL)
        return root;
    if(key < root->data)
        root->left = deletion(root->left,key);
    else if(key > root->data)
        root->right = deletion(root->right,key);
    else
    {
        if(root->left == NULL)
        {
            temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            temp=root->left;
            free(root);
            return temp;
        }
        else
        {
            temp=minvalueBST(root->right);
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
        }
    }
    return root;
}

int numofnodesBST(struct node *root)
{
    if(root==NULL)
        return 0;
    else
        return numofnodesBST(root->left) + numofnodesBST(root->right) + 1;
}

int numintnodesBST(struct node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 0;
    else
        return numintnodesBST(root->left) + numintnodesBST(root->right) + 1;
}

int numExtnodesBST(struct node *root)
{
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    else
        return numExtnodesBST(root->left) + numExtnodesBST(root->right);
}

int maxdepthBST(struct node *root)
{
    if(root==NULL)
        return -1;
    else
    {
        int l,r;
        l=maxdepthBST(root->left);
        r=maxdepthBST(root->right);
        if(l>r)
            return l+1;
        else
            return r+1;
    }
}

void preorder(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

struct node *search_value(struct node *root,int key)
{
    if(root==NULL || root->data == key)
        return root;
    if (key < root->data)
        return search_value(root->left, key);
    else
        return search_value(root->right, key);
}
void search(struct node *root)
{
    int key;
    printf("Enter key value to search:");
    scanf("%d",&key);
    found=search_value(root,key);
    if (found != NULL)
        printf("Value %d found in BST\n", key);
    else
        printf("Value %d not found in BST\n", key);
}

void main()
{
    int choice,key,height;
    while(1)
    {
        printf("\n1.Create binary serach tree\n");
        printf("2.Insertion\n");
        printf("3.Deletion\n");
        printf("4.Min value\n");
        printf("5.Max value\n");
        printf("6.No. of nodes\n");
        printf("7.No. of internal nodes\n");
        printf("8.No. of External nodes\n");
        printf("9.Height/max depth\n");
        printf("10.Preorder traversal\n");
        printf("11.Inorder traversal\n");
        printf("12.Postorder traversal\n");
        printf("13.Search an element\n");
        printf("14.EXIT\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: root=createBST(root);
                    break;
            case 2: printf("Enter value to insert:");
                    scanf("%d",&key);
                    root=insertion(root,key);
                    break;
            case 3: printf("Enter key value to delete:");
                    scanf("%d",&key);
                    root=deletion(root,key);
                    break;
            case 4: temp=minvalueBST(root);
                    printf("Minimum value: %d\n",temp->data);
                    break;
            case 5: temp=maxvalueBST(root);
                    printf("Maximum value: %d\n",temp->data);
                    break;
            case 6: printf("total No. of nodes in BST = %d\n",numofnodesBST(root));
                    break;
            case 7: printf("No of. internal nodes in BST = %d\n",numintnodesBST(root));
                    break;
            case 8: printf("No. of External nodes in BST = %d\n",numExtnodesBST(root));
                    break;
            case 9: height=maxdepthBST(root);
                    printf("Maxdepth = %d\n",height);
                    break;
            case 10:printf("Preorder traversal : ");
                    preorder(root);
                    break;
            case 11:printf("Inorder traversal : ");
                    inorder(root);
                    break;
            case 12:printf("Postorder traversal : ");
                    postorder(root);
                    break;
            case 13:search(root);
                    break;
            case 14:printf("Exiting\n");
                    exit(0);
                    break;
            default:printf("Entered invalid choice\n");
                    break;   
        }
    } 
}
