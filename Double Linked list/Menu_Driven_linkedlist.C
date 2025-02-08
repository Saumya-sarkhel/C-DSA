#include <stdio.h>
#include <stdlib.h> //Double linked list

struct Node{
    struct Node *prev, *next;
    int data;
};
struct Node *head = NULL;

void insert_Beg();
void insert_End();
void Insert_After_Position();
void Insert_Before_Position();
void Insert_After_Value();
void delete_Begining();
void Delete_From_End();
void Delete_Any_Position();
void count_Nodes();
void display();
Node* reverse(struct Node* head);
void Findmax();
void Findmin();
void LinearSearch();
void selection_sort();
void ins_at_any_pos();


int main(){
    int choice;
    while (1){
        printf("\n1. Insert at beginning \n2. Insert at end \n3. Insert after any position \n4. Insert before any position \n5. Insert after any value \n6. Delete from beginning \n7. Delete from end\n8. Delete from any position\n9. Insert any position\n10. Reverce\n11. Display\n12. Count\n13. Find Max\n14. Find min\n15. Linear search\n16. Selection sort\n17. exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1: insert_Beg();
                break;
        case 2: insert_End();
                break;
        case 3: Insert_After_Position();
                break;
        case 4: Insert_Before_Position();
                break;
        case 5: Insert_After_Value();
                break;
        case 6: delete_Begining();
                break;
        case 7: Delete_From_End();
                break;
        case 8: Delete_Any_Position();
                break;
        case 9: ins_at_any_pos();
                break;
        case 10: head = reverse(head);
                break;
        case 11: display();
                break;
        case 12: count_Nodes();
                break;
        case 13: Findmax();
                break;
        case 14: Findmin();
                break;
        case 15: LinearSearch();
                break;
        case 16: selection_sort();
                display();
                break;
        case 17: exit(0);
        default:
            printf("Invalid choice, enter right choice.\n");
        }
    }
}


void insert_Beg(){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter your data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head = temp;
    }
    else{
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insert_End(){
    struct Node *temp, *p=head;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter your data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head=temp;
    }
    else{
        while (p->next != NULL){
            p = p->next;
        }
        p->next = temp;
        temp->prev = p;
    }
}

void ins_at_any_pos() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* new1 = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter data: ");
    scanf("%d", &new1->data);
    new1->next = NULL;
    new1->prev = NULL;

    int pos;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    pos--;

    if (pos < 0) {
        printf("Invalid position.\n");
        return;
    }

    struct Node* p = head;
    int i = 1;
    while (i != pos && p->next != NULL) {
        i++;
        p = p->next;
    }

    if (i == pos && p->next != NULL) {
        new1->next = p->next;
        p->next->prev = new1;
        p->next = new1;
        new1->prev = p;
    } else if (i == pos && p->next == NULL) {
        p->next = new1;
        new1->prev = p;
    } else {
        printf("Position not exist\n");
    }
}

void Insert_After_Position(){
    int pos;
    struct Node *temp, *p;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter your data: ");
    scanf("%d", &temp->data);
    printf("Enter your position: ");
    scanf("%d", &pos);
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head = temp;
    }
    else{
        p=head;
        int i=1;
        if(pos<=0){
            printf("Invalid Position\n");
            return;
        }
        while (i<pos && p->next!=NULL){
            p = p->next;
            i++;
        }
        if (i==pos && p->next!=NULL){
            temp->next=p->next;
            temp->prev=p;
            p->next=temp;
        }
        else if (i==pos && p->next==NULL){
            p->next=temp;
            temp->prev = p;
        }
        else if (i!=pos && p->next==NULL){
            printf("Invalid Position\n");
        }
    }
}

void Insert_Before_Position(){
    int pos;
    int i = 1;
    struct Node *temp, *p=head;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter your data: ");
    scanf("%d", &temp->data);
    printf("Enter your position: ");
    scanf("%d", &pos);
    pos = pos - 1;
    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head = temp;
    }
    else{
        if(pos<=0){
            printf("Invalid Position\n");
        }
        else if (pos==0){
            temp->next=head;
            head=temp;
        }
        else{
            while (i<pos && p->next!=NULL){
                p = p->next;
                i++;
            }
            if (i==pos && p->next!=NULL){
                temp->next = p->next;
                temp->prev = p;
                p->next=temp;
            }
            else if (i==pos && p->next==NULL){
                p->next=temp;
                temp->prev=p;
            }
            else if (i!=pos && p->next==NULL){
                printf("Invalid Position\n");
            }
        }
    }
}

void Insert_After_Value(){
    int value;
    struct Node *temp, *p=head;
    temp = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter your data: ");
    scanf("%d", &temp->data);
    printf("Enter your value: ");
    scanf("%d", &value);

    temp->next = NULL;
    temp->prev = NULL;
    if (head == NULL){
        head = temp;
    }
    else{
        while (p->data!=value && p->next!=NULL){
            p = p->next;
        }
        if (p->data==value && p->next!=NULL){
            temp->next = p->next;
            temp->prev = p;
            p->next = temp;
        }
        else if (p->data==value && p->next==NULL){
            p->next = temp;
            temp->prev = p;
        }
        else if (p->data!=value && p->next==NULL){
            printf("Value not exist.\n");
        }
    }
}

void delete_Begining(){
    struct Node *p;
    if(head==NULL){
      printf("Empty list\n");
    }
    else{
      p = head;
      head = head->next;
      head->prev = NULL;
      p->next=NULL;
      printf("Deleted data is : %d\n",p->data);
      free(p);
    }
}

void Delete_From_End(){
    struct Node *p=head, *q=head;
    if(head==NULL){
      printf("Empty list\n");
      return;
    }
    else{
      while(p->next!=NULL){
          q=p;
          p=p->next;
      }
        q->next=NULL;
        p->prev=NULL;
        printf("Deleted data is : %d\n",p->data);
        free(p);
    }
}

void Delete_Any_Position(){
    struct Node *p, *q, *s;
    if (head == NULL){
        printf("\nThe list is Empty");
    }
    else{
        int i, pos;
        printf("\nEnter the position: ");
        scanf("%d", &pos);
        if (pos == 1 && head->next == NULL){
            printf("\nDeleted data is %d", head->data);
            head = NULL;
        }
        else if (pos == 1){
            p = head;
            head = head->next;
            head->prev == NULL;
            p->next = NULL;
            printf("\nDeleted data is %d", p->data);
        }
        else{
            p = head;
            q = head;
            i = 1;
            while (p->next != NULL && i != pos){
                q = p;
                p = p->next;
                i++;
            }
            s = p->next;
            if (pos == i && p->next != NULL){
                q->next = p->next;
                s->prev = q;
                p->next = NULL;
                p->prev = NULL;
                printf("\nDeleted data is %d", p->data);
            }
            else if (pos == i && p->next == NULL){
                q->next = NULL;
                p->prev = NULL;
                printf("\nDeleted data is %d", p->data);
            }
            else{
                printf("\nPosition not found");
            }
        }
    }
}

// void Delete_Any_Position(){
//     int pos, i=1;
//     printf("Enter Your position: ");
//     scanf("%d",&pos);
//     struct Node *p=head, *q=head;
//     if(head==NULL){
//       printf("Empty list\n");
//     }
//     else{
//         if(p->prev==NULL && p->next==NULL){
//             head=p->next;
//             head->prev=NULL;
//             p->next=NULL;
//             printf("Deleted Data is :%d\n",p->data);
//             free(p);
//         }
//         else{
//             if(pos<=0){
//             printf("Invalid Position\n");
//             return;
//             }
//             else if(pos==1){
//             head = p->next;
//             head->prev = NULL;
//             p->next=NULL;
//             printf("Deleted data is : %d\n",p->data);
//             }
//             else{
//                 while(p->next!=NULL && i<pos){
//                     q=p;
//                     p=p->next;
//                     i++;
//                 }
//                 if(i==pos && p->next!=NULL){
//                     q->next=p->next;
//                     p->next->prev=q;
//                     printf("Deleted Data is : %d\n",p->data);
//                 }
//                 else if(i==pos && p->next==NULL){
//                     printf("Deleted data is : %d\n",p->data);
//                 }
//                 else if(i!=pos && p->next==NULL){
//                     printf("Invalid position\n");
//                 }
//             }
//         }
//     }
// }

void count_Nodes(){
    struct Node *ptr=head;
    int count=0;
    while(ptr!=NULL){
        ptr=ptr->next;
        count++;
    }
    printf("The total number of Node is : %d\n",count);
}

struct Node *reverse(struct Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node *prev = NULL;
    Node *temp = head;
    Node *next = NULL;
    while(temp != NULL){
        prev = temp->prev;

        temp->prev = temp->next;
        temp->next = prev;
        temp = temp->prev;
    }
    printf("\nReverse successful")
    return prev->prev;
}


void display(){
    struct Node *ptr = head;
    printf("NULL");
    while (ptr != NULL)
    {
        printf(" <-> %d", ptr->data);
        ptr = ptr->next;
    }
    printf(" <-> NULL\n");
}

void Findmax(){
    struct Node *p;
    int max;
    if(head==NULL){
        printf("Empty list");
    }
    else{
        p=head;
        max=p->data;
        for(p=head; p!=NULL; p=p->next){
            if(max<p->data){
                max=p->data;
            }
        }
        printf("%d is maximum in list.\n",max);
    }
}

void Findmin(){
    struct Node *p;
    int min;
    if(head==NULL){
        printf("Empty list");
    }
    else{
        p=head;
        min=p->data;
        for(p=head; p!=NULL; p=p->next){
            if(min>p->data){
                min=p->data;
            }
        }
        printf("%d is minimum in list.\n",min);
    }
}

void LinearSearch(){
    struct Node *p = head;
    if(head == NULL){
        printf("Empty list..\n");
    }
    else{
        int key, flag = 0;
        printf("Enter the value you want to search: ");
        scanf("%d", &key);
        while(p != NULL){
            if(p->data == key){
                printf("%d found in the list.\n", key);
                flag = 1;
                break;
            }
            p = p->next;
        }
        if(flag == 0){
            printf("\nItem not found.\n");
        }
    }
}

void selection_sort(){
    if(head == NULL){
        printf("Empty list..\n");
        return;
    }
    struct Node *p, *q, *min;
    int t;
    for(p = head; p->next != NULL; p=p->next){
        min = p;
        for(q = p->next; q != NULL; q = q->next){
            if(q->data < min->data){
                min = q;
            }
        }
        if(min != p){
            t = min->data;
            min->data = p->data;
            p->data = t;
        }
    }
}
