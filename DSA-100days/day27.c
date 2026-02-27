#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
        
    temp->next = newNode;
}

// Function to get length
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

// Function to find intersection
int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);
    
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
    
    // Adjust starting point
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++)
            temp1 = temp1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++)
            temp2 = temp2->next;
    }
    
    // Traverse together
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == temp2)
            return temp1->data;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    
    return -1;
}

int main() {
    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    
    int n, m, x;
    
    // First list
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&head1, x);
    }
    
    // Second list
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        insert(&head2, x);
    }
    
    int result = findIntersection(head1, head2);
    
    if (result == -1)
        printf("No Intersection\n");
    else
        printf("%d\n", result);
        
    return 0;
}