// source http://www.crazyforcode.com/sort-linked-list-0s-1s-2s/

*/Given a Singly linked list with each node containing either 0, 1 or 2. Write code to sort the list.
Input : 1 -> 1 -> 2 -> 0 -> 2 -> 0 -> 1 -> 0
Output : 0 -> 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2

Solution:
You can do that in O(n).

Traverse the linked list from the beginning and count the number of 0s, 1s and 2s. (Let the counts be p, q, r)
Now traverse the linked list again and set first p nodes to 0, q nodes to 1 and r nodes to 2.

*/
/* Link list node */
struct node
{
    int data;
    struct node* link;
};
 
// Function to sort a linked list of 0s, 1s and 2s
void sortList(struct node *start)
{
    int count[3] = {0, 0, 0}; 
    struct node *ptr = start;
 
    /* count total number of '0', '1' and '2'
     * count[0] will store total number of '0's
     * count[1] will store total number of '1's
     * count[2] will store total number of '2's  */
    while (ptr)
    {
        count[ptr->data] += 1;
        ptr = ptr->link;
    }
 
    int i = 0;
    ptr = start;
 
    while (ptr)
    {
        if (count[i] == 0)
            ++i;
        else
        {
            ptr->data = i;
            count[i]--;
            ptr = ptr->link;
        }
    }
}
