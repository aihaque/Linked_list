// Linked list header file

#ifndef LIST_H_
#define LIST_H_

struct ListNode {
    int item;
    struct ListNode *next;
};

/*
 * Allocate memory for a node of type struct ListNode and
 * initialize it with the item value.
 * Return a pointer to the new node.
 */
struct ListNode* CreateNode(int item);

/*
 * Insert node with specified item at the head of the list.
 */
void InsertAtHead (struct ListNode **head, int item);

/*
 * Create node and insert in the location specified by order
 * If order is larger than number of list element, insert at tail
 * For example, in the list 1, 5, 8, 3, 5
 * InsertAtOrder(head, 100, 3) changes list to 1, 5, 100, 8, 3, 5
 * InsertAtOrder(head, 200, 1) changes list to 200, 1, 5, 8, 3, 5
 * InsertAtOrder(head, 300, 9) changes list to 1, 5, 8, 3, 5, 300
 */
void InsertAtOrder (struct ListNode **head, int item, int order);

/*
 * Count number of nodes in the list.
 * Return 0 if the list is empty, i.e., head == NULL
 */
int CountNodes (struct ListNode *head);

/*
 * Return the first node holding the value item
 * return NULL if none found
 */
struct ListNode* FindNode(struct ListNode *head, int item);

/*
 * Return the value of the item at node number node_number
 * return -32768 if none found
 * For example, in the list 1, 5, 8, 3, 5
 * FindNodeValue(head, 3) returns 8
 */
int FindNodeValue(struct ListNode *head, int node_number);

/*
 * Return the order of first node holding the value item
 * return 0 if none found
 * For example, the list 1, 5, 8, 3, 5  
 * FindNodeOrder (head, 5) returns 2
 * FindNodeOrder (head, 3) returns 4
 * FindNodeOrder (head, 7) returns 0
 */
int FindNodeOrder(struct ListNode *head, int item);

/*
 * Delete node from the list and free memory allocated to it.
 * This function assumes that node is valid
 */
void DeleteNode (struct ListNode **head, struct ListNode *node);

/*
 * Return the first node containing the item with maximum value.
 * Return NULL if list is empty
 */
struct ListNode* FindMaxNode (struct ListNode *head);


#endif
