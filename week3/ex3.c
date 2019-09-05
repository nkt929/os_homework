#include <stdio.h>
#include <stdlib.h>

struct Node {
	int value;
	struct Node *next;
};

typedef struct Node* List;

void insert_node(List* head, int n, int val) {
    if ((*head) == NULL) {
        *head = (List) malloc(sizeof(struct Node));
        (*head) -> value = val;
        (*head) -> next = NULL;
    }
    else {
        int i = 0;
        
        List temp = (*head);
        while ((i < n - 1) && ((*head)->next != NULL)) {
            temp = temp->next;
            i++;
        }
        
        List new_node = (List) malloc(sizeof(struct Node));
        new_node -> value = val;
        temp -> next = new_node;
        new_node -> next = NULL;
    
    }
}


void delete_node(List* temp, int n) {
    List head = *temp;
    
    if (n == 0) {
        *temp = (*temp) -> next;
    }
    else {
        int i = 0;
        
        while ((i < n - 1) && ((head)->next != NULL)) {
            head = head->next;
            i++;
        }
        head -> next = head  -> next -> next;
    }
}


void printLinkedList(List head) {
    while (head != NULL) {
        printf("%d ", head -> value);
        head = head -> next;
    }
    printf("\n");
}

int main(){
	List list = NULL;
    
    
    
	insert_node(&list, 0,  1);
	insert_node(&list, 1, 2);
    insert_node(&list, 2, 3);
    insert_node(&list, 3, 4);
    
    printLinkedList(list);
    
    delete_node(&list, 0);
    
	printLinkedList(list);
	return 0;
}
