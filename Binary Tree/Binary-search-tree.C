#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *lchild;
  struct Node *rchild;
};
typedef struct Node Bst;

void insert(int);
void inorder(Bst *);
void preorder(Bst *);
void postorder(Bst *);
void Maximum(Bst *r);
void Minimum(Bst *r);
int Internal_node(Bst *);
int External_node(Bst *);
int Total_node(Bst *);
Bst *DeleteNode(Bst *, int);
int search(Bst *, int);
Bst *findMin(Bst *);
Bst *root = NULL;

int main() {
  int x, n, val;
  while (1) {
    printf("\n1. Insert\n2. Inorder\n3. Preorder\n4. Postorder\n5. Exit\n");
    printf("6. Maximum\n7. Minimum\n8. Internal Node\n9. External Node\n10. "
           "Total Node\n11. Delete Node\n");
    printf("Enter your choice: ");
    scanf("%d", &x);
    switch (x) {
    case 1:
      printf("\nEnter the enement: ");
      scanf("%d", &n);
      insert(n);
      break;
    case 2:
      if (root == NULL) {
        printf("\nTree is empty...");
        break;
      }
      printf("\nInorder traversal is: ");
      inorder(root);
      break;
    case 3:
      if (root == NULL) {
        printf("\nTree is empty...");
        break;
      }
      printf("\nPreOrder traversal is: ");
      preorder(root);
      break;
    case 4:
      if (root == NULL) {
        printf("\nTree is empty...");
        break;
      }
      printf("\nPostOrder traversal is: ");
      postorder(root);
      break;
    case 5:
      exit(1);
    case 6:
      Maximum(root);
      break;
    case 7:
      Minimum(root);
      break;
    case 8:
      printf("\nNumber of Internal Nodes is: %d\n", Internal_node(root));
      break;
    case 9:
      printf("\nNumber of External Nodes is: %d\n", External_node(root));
      break;
    case 10:
      printf("\nNumber of Total Nodes is: %d\n", Total_node(root));
      break;
    case 11:
      if (root == NULL) {
        printf("\nTree is empty...\n");
        break;
      }
      printf("\nEnter the element to be deleted: ");
      scanf("%d", &val);
      if (search(root, val)) {
        root = DeleteNode(root, val);
        printf("Data %d has been deleted...\n", val);
      } else {
        printf("Data %d not found in the tree...\n", val);
      }
      break;
    default:
      printf("\nInvalid choice");
    }
  }
}

void insert(int x) {
  Bst *ptr = root, *temp;
  temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = x;
  temp->lchild = NULL;
  temp->rchild = NULL;
  if (root == NULL) {
    root = temp;
  } else {
    while (1) {
      if (ptr->data > x) {
        if (ptr->lchild == NULL) {
          ptr->lchild = temp;
          break;
        } else
          ptr = ptr->lchild;
      } else {
        if (ptr->rchild == NULL) {
          ptr->rchild = temp;
          break;
        } else
          ptr = ptr->rchild;
      }
    }
  }
}

void inorder(Bst *r) {      // LeftChild-Data-RightChild (LDR)
  if (r->lchild != NULL)
    inorder(r->lchild);

  printf("%d ", r->data);

  if (r->rchild != NULL)
    inorder(r->rchild);
}
void preorder(Bst *r) {     // Data-LeftChild-RightChild (DLR)
  printf("%d ", r->data);

  if (r->lchild != NULL)
    preorder(r->lchild);

  if (r->rchild != NULL)
    preorder(r->rchild);
}
void postorder(Bst *r) {     // LeftChild-RightChild-Data (LRD)
  if (r->lchild != NULL)
    postorder(r->lchild);

  if (r->rchild != NULL)
    postorder(r->rchild);

  printf("%d ", r->data);
}

void Maximum(Bst *t) {
  Bst *ptr = t;
  if (ptr != NULL) {
    while (ptr->rchild != NULL)
      ptr = ptr->rchild;
    printf("Maximum value is %d", ptr->data);
  } else
    printf("\nEmpty Binary tree.");
}

void Minimum(Bst *t) {
  Bst *ptr = t;
  if (ptr != NULL) {
    while (ptr->lchild != NULL)
      ptr = ptr->lchild;
    printf("Minimum value is %d", ptr->data);
  } else
    printf("\nEmpty Binary tree.");
}

int Internal_node(Bst *t) {
  if (t == NULL)
    return 0;
  else if (t->lchild == NULL && t->rchild == NULL)
    return 0;
  else
    return (Internal_node(t->lchild) + Internal_node(t->rchild) + 1);
}

int External_node(Bst *t) {
  if (t == NULL)
    return 0;
  else if (t->lchild == NULL && t->rchild == NULL)
    return 1;
  else
    return (External_node(t->lchild) + External_node(t->rchild));
}

int Total_node(Bst *t) {
  if (t == NULL)
    return 0;
  else
    return Internal_node(t) + External_node(t);
}

Bst *findMin(Bst *node) {
  while (node->lchild != NULL) {
    node = node->lchild;
  }
  return node;
}

Bst *DeleteNode(Bst *root, int value) {
  int s;
  s = search(root, value);
  if (s == 0){
      printf("%d is not present in BST...\n");
      return root;
  }
  else if (value < root->data){
      root->lchild = DeleteNode(root->lchild, value);
  }
  else if (value > root->data){
      root->rchild = DeleteNode(root->rchild, value);
  }
  else {
      // Case 1:leaf node
      if (root->lchild == NULL && root->rchild == NULL){
          free(root);
          return NULL;
      }
      // Case 2:Internal node with one child node
      else if (root->lchild == NULL){
          Bst *temp = root;
          root = root->rchild;
          free(temp);
          return root;
      }
      else if (root->rchild == NULL){
          Bst *temp = root;
          root = root->lchild;
          free(temp);
          return root;
      }
      else // Case 3:Internal node with two child node
      {
          Bst *temp = findMin(root->rchild);
          root->data = temp->data;
          root->rchild = DeleteNode(root->rchild, temp->data);
      }
  }
  return root;
}

int search(Bst *root, int value) {
  if (root == NULL)
    return 0;
  if (root->data == value)
    return 1;
  else if (value < root->data)
    return search(root->lchild, value);
  else
    return search(root->rchild, value);
}
