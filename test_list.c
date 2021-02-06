#include <stdio.h>
#include "list.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

/*
 * Custom testing framework
 */

void dumpList(struct ListNode *head);


/*
 * Main()
 */
int main(int argc, char** argv)
{
     struct ListNode *head = NULL;  // start with empty list
     InsertAtOrder (&head, -10, 1); // list = 25, 50, 100
     dumpList(head);
     InsertAtOrder (&head, 75, 3); // list = 25, 50, 75, 100
     dumpList(head);
     InsertAtOrder (&head, 125, 5); // list = 25, 50, 75, 100, 125
     dumpList(head);
     printf("Node Count = %5d\n", CountNodes(head));
     printf("Third element = %5d\n", FindNodeValue(head, 3));
     printf("125 is element number %5d\n", FindNodeOrder(head, 126));
     printf("Max Value is = %5d\n", FindMaxNode(head)->item);
     struct ListNode *element = FindNode(head, 125);
     DeleteNode (&head, element); // list = 25, 50, 75, 125
     dumpList(head);

     // free list
     struct ListNode *ptr = head;
	while (ptr) {
		head = ptr->next;
		free (ptr);
		ptr = head;
     }
     return 0;
}

/*
 * Helper Functions
 */
void dumpList(struct ListNode *head)
{
	struct ListNode *current = head;
	while (current != NULL) {
		printf("%5d", current->item);
		current = current->next;
	}
	printf("\n");
}


