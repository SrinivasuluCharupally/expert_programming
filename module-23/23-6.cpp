/*
SOurce: http://www.crazyforcode.com/repeatedly-delete-nodes-nodes-linked-list/
Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then delete next N nodes, continue the same until end of the linked list.

Input:
M = 2, N = 2
Linked List: 1->2->3->4->5->6->7->8
Output:
Linked List: 1->2->5->6

The main part of the problem is to maintain proper links between nodes, make sure that all corner cases are handled.

Implementation:
*/

typedef struct _Node
{
    int data;
    struct _Node *link;
}Node;
 
// Function to skip M nodes and then remove N nodes of the linked list.
void SkipAndRemove( node  *head, int M, int N)
{
    node *current = head, *t;
    int count;
  
    while (current)
    {
        // Skip M nodes
        for (count = 1; count<M && current!= NULL; count++)
            current = current->link;
  
        // If we reached end of list, then return
        if (current == NULL)
            return;
  
        // Start from link node and remove N nodes
        t = current->link;
        for (count = 1; count<=N && t!= NULL; count++)
        {
            node *temp = t;
            t = t->link;
            free(temp);
        }
        current->link = t;
  
        // Set current pointer for link iteration
        current = t;
    }
}
Time Complexity: O(n) where n is number of nodes in linked list.