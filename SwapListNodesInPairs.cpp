//Swap List Nodes in Paris
//Given a linked list, swap every two adjacent nodes and return its head.

//For example,
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* PairWiseRecur(ListNode *head) {
        if(head==NULL)
            return NULL;

        ListNode *curr = head;
        ListNode *next = head->next;

        if(curr->next != NULL) {
            curr->next = next->next;
            next->next = curr;
            

            curr->next = PairWiseRecur(curr->next);
            return next;
        }
        else
            return curr;
        
    }
    

ListNode* Solution::swapPairs(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
        //nothing to be done if only element or no element
        if(A==NULL || A->next==NULL)
            return A;
        
        return PairWiseRecur(A);
    
}
