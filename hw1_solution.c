/*
 * This section is dedicated to answering Question 1. The rest of the document includes the linked list code
 * QUESTION 1 ANSWERS
 * A. Ahmed
 * B. 11
 * C. CMPT454 CMPT459
 * D. Masters
 * E. P(X=k)= λ^K * e^-λ / k! formula
             = 1.5^4 * e-1.5 / 4! here λ = 1.5 and K = 4
             = 0.047 solution

 * F. P(X>x) = e^-λ*x formula
      Here, λ = 1/3.8 = 0.26
      Therefore, P(X>6) = e^-0.26*6 = 0.21 solution
         
 * END OF QUESTION 1 ANSWERS
*/
/* In the following code, you need to fill in body 
 * of each function
*/
#include "list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

/*
 * Allocate memory for a node of type struct ListNode and
 * initialize it with the item value.
 * Return a pointer to the new node.
 */
struct ListNode* CreateNode(int item) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->item = item;
    node->next = NULL;
    return node;
}

/*
 * Insert node with specified item at the head of the list.
 */
void InsertAtHead (struct ListNode **head, int item) {
    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->item = item;
    node->next = *head;
    *head = node;
}

/*
 * Create node and insert in the location specified by order
 * If order is larger than number of list element, insert at tail
 * For example, in the list 1, 5, 8, 3, 5
 * InsertAtOrder(head, 100, 3) changes list to 1, 5, 100, 8, 3, 5
 * InsertAtOrder(head, 200, 1) changes list to 200, 1, 5, 8, 3, 5
 * InsertAtOrder(head, 300, 9) changes list to 1, 5, 8, 3, 5, 300
 */
void InsertAtOrder (struct ListNode **head, int item, int order) {
    if(order == 0){return;}

    if(order > CountNodes(*head)){
        if(CountNodes(*head) == 0){
            CreateNode (item);
            return;
        }

        struct ListNode *ptr = *head;
        struct ListNode *tail = NULL;
        while (ptr) {
            tail = ptr;
            ptr = ptr->next;
        }
        struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
        node->item = item;
        node->next = NULL;
        tail->next = node;
        return;
    }

    if(order == 1){
         InsertAtHead (head, item);
         return;
    }

    struct ListNode* left = *head;
    int count = 2;
    while(count < order){
        count++;
        left = left->next;
    }

    struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
    node->item = item;
    node->next = left->next;
    left->next = node;
    return;
}

/*
 * Count number of nodes in the list.
 * Return 0 if the list is empty, i.e., head == NULL
 */
int CountNodes (struct ListNode *head) {
    int count = 0;
    struct ListNode *ptr = head;
	while (ptr) {
        ptr = ptr->next;
		count++;
     }
    return count;
}

/*
 * Return the first node holding the value item
 * return NULL if none found
 */
struct ListNode* FindNode(struct ListNode *head, int item) {
    struct ListNode *ptr = head;
	while (ptr) {
        if(ptr->item == item){return ptr;}
        ptr = ptr->next;
     }
    return NULL;
}

/*
 * Return the value of the item at node number node_number
 * return -32768 if none found
 * For example, in the list 1, 5, 8, 3, 5
 * FindNodeValue(head, 3) returns 8
 */
int FindNodeValue(struct ListNode *head, int node_number) {
    if(node_number > CountNodes(head) || node_number == 0){
        return -32768;
    }

    int count = 2;
    struct ListNode *ptr = head;
	while (count <= node_number) {
        ptr = ptr->next;
		count++;
     }
    return ptr->item;
}

/*
 * Return the order of first node holding the value item
 * return 0 if none found
 * For example, the list 1, 5, 8, 3, 5  
 * FindNodeOrder (head, 5) returns 2
 * FindNodeOrder (head, 3) returns 4
 * FindNodeOrder (head, 7) returns 0
 */
int FindNodeOrder(struct ListNode *head, int item) {
    int count = 0;
    struct ListNode *ptr = head;
	while (ptr) {
        count++;
        if(ptr->item == item){return count;}
        ptr = ptr->next;
     }
    return 0;
}

/*
 * Delete node from the list and free memory allocated to it.
 * This function assumes that node is valid
 */
void DeleteNode (struct ListNode **head, struct ListNode *node) {
    if(CountNodes(*head) <= 0){return;}
    if(*head == node){
        *head = node->next;
        free (node);
        return;
    }

    struct ListNode *left = *head;
    struct ListNode *ptr = left->next;
	while (ptr) {
        if(ptr == node){
            left->next = ptr->next;
            free (ptr);
            return;
        }
        left = ptr;
        ptr = ptr->next;
     }
     return;
}

/*
 * Return the first node containing the item with maximum value.
 * Return NULL if list is empty
 */
struct ListNode* FindMaxNode (struct ListNode *head) {
    if(CountNodes(head) <= 0){return NULL;}
    if(CountNodes(head) == 1){return head;}
    int max = head->item;

    struct ListNode *ptr = head->next;
	while (ptr) {
        if(ptr->item > max){max = ptr->item;}
        ptr = ptr->next;
    }

    return FindNode(head, max);
}


