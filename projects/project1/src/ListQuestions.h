#ifndef LIST_QUESTIONS_H
#define LIST_QUESTIONS_H

#include "LinkedList.h"
#include <stdbool.h>
/*
 * Problem: Determine if a linked list has a cycle
 *
 * Description:
 * Given the head of a linked list, determine if the list contains a cycle. A cycle occurs if a node can be
 * reached again by continuously following the `next` pointer. Internally, 'pos' is used to denote the index
 * of the node that the tail's next pointer is connected to, indicating a cycle. Note that 'pos' is not
 * accessible or passed as a parameter; it's only used for problem understanding and explanation.
 *
 * Task:
 * Implement a function to check if the given linked list has a cycle. The function should return 'true' if a
 * cycle is present and 'false' otherwise.
 *
 * Prototype:
 * bool hasCycle(struct Node *head);
 */

static bool hasCycle(struct Node *head)
{
	struct Node* fast = head;
	struct Node* slow = head;

	while(fast != NULL && fast->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;

		if(fast == slow) {
			return true;
		}
	};
	//Placeholder return statement
	return false;
}

/*
 * Problem: Merge Two Sorted Lists
 *
 * Description:
 * You are given the heads of two sorted linked lists, list1 and list2. Your task is to merge these two
 * lists into one single sorted list. The merged list should be constructed by splicing together the nodes
 * of the first two lists without creating new nodes, but by rearranging the nodes from the given lists.
 *
 * Task:
 * Implement a function that merges two sorted linked lists and returns the head of the newly merged sorted
 * linked list.
 *
 * Prototype:
 * struct Node* mergeTwoLists(struct Node* list1, struct Node* list2);
 *
 * Note:
 * Both list1 and list2 are sorted in non-decreasing order.
 */

static struct Node* mergeLists(struct Node* list1, struct Node* list2)
{
	//Placeholder return statement

	struct Node* dummy = createNode(-1);
	struct Node* head = dummy;

	while(list1 && list2) {
		if(list1->data < list2->data) {
			dummy->next = list1;
			list1 = list1->next;
		} else {
			dummy->next = list2;
			list2 = list2->next;
		}
		dummy = dummy->next;
	}

	if(list1){
		dummy->next = list1;
	} else {
		dummy->next = list2;
	}

	return head->next;
}

#endif
