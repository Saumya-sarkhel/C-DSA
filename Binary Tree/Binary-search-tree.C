#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* lchild, *rchild;
};
typedef struct Node Bst;

void insert(int);
void inorder(Bst*);
void preorder(Bst*);
void postorder(Bst*);
void Maximum(Bst *r);
void Minimum(Bst *r);
int Internal_node(Bst*);
int External_node(Bst*);
int Total_node(Bst*);
Bst *root = NULL;

int main(){
    int x, n;
    while(1){
        printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\n");
        printf("6. Maximum\n7. Minimum\n8. Internal Node\n9. External Node\n10. Total Node\n");
        printf("Enter your choice: ");
        scanf("%d", &x);
        switch(x){
            case 1: printf("\nEnter the enement: ");
                    scanf("%d", &n);
                    insert(n);
                    break;
            case 2: printf("Inorder traversal is: ");
                    inorder(root);
                    break;
            case 3: printf("Prerder traversal is: ");
                    preorder(root);
                    break;
            case 4: printf("Postrder traversal is: ");
                    postorder(root);
                    break;
            case 5: exit(1);
            case 6: Maximum(root);
                    break;
            case 7: Minimum(root);
                    break;
            case 8: int internalNodes = Internal_node(root);
                    printf("Number of Internal Nodes is: %d\n", internalNodes);
                    break;
            case 9: int externalNodes = External_node(root);
                    printf("Number of External Nodes is: %d\n", externalNodes);
                    break;
            case 10: int totalNodes = Internal_node(root) + External_node(root);
                    printf("Number of Total Nodes is: %d\n", totalNodes);
                    break;
            default: printf("\nInvalid choice");
        }
    }
}

void insert(int x){
    Bst *ptr = root, *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->lchild = NULL;
    temp->rchild = NULL;
    if(root == NULL){
        root = temp;
    }
    else{
        while(1){
            if(ptr->data > x){
                if(ptr->lchild == NULL){
                    ptr->lchild = temp;
                    break;
                }
                else
                    ptr = ptr->lchild;
            }
            else{
                if(ptr->rchild == NULL){
                    ptr->rchild = temp;
                    break;
                }
                else
                    ptr = ptr->rchild;
            }
        }
    }
}

void inorder(Bst *r){
    if(r->lchild != NULL)
        inorder(r->lchild);

    printf("%d ", r->data);

    if(r->rchild != NULL)
        inorder(r->rchild);
}
void preorder(Bst *r){
    printf("%d ", r->data);

    if(r->lchild != NULL)
        preorder(r->lchild);

    if(r->rchild != NULL)
        preorder(r->rchild);
}
void postorder(Bst *r){
    if(r->lchild != NULL)
        postorder(r->lchild);

    if(r->rchild != NULL)
        postorder(r->rchild);

    printf("%d ", r->data);
}

void Maximum(Bst *t){
    Bst *ptr = t;
    if(ptr != NULL){
        while(ptr->rchild != NULL)
            ptr = ptr->rchild;
        printf("Maximum value is %d", ptr->data);
    }
    else
        printf("\nEmpty Binary tree.");
}

void Minimum(Bst *t){
    Bst *ptr = t;
    if(ptr != NULL){
        while(ptr->lchild != NULL)
            ptr = ptr->lchild;
        printf("Minimum value is %d", ptr->data);
    }
    else
        printf("\nEmpty Binary tree.");
}

int Internal_node(Bst *t){
    if(t==NULL)
        return 0;

    else if(t->lchild == NULL && t->rchild == NULL)
        return 0;

    else
        return(Internal_node(t->lchild)+Internal_node(t->rchild)+1);
}

int External_node(Bst *t){
    if(t==NULL)
        return 0;

    else if(t->lchild == NULL && t->rchild == NULL)
        return 1;

    else
        return(External_node(t->lchild)+External_node(t->rchild));
}

int Total_node(Bst *t){
    if(t==NULL)
        return 0;
    else
        return Internal_node(t) + External_node(t);
}
