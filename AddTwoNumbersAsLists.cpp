/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
        int carry = 0, sum = 0; 
        ListNode *result = new ListNode(0);
        ListNode *prevNode; 
        ListNode *head = result; 
        
        while(A != NULL && B != NULL) {
            sum = A->val + B->val + carry;
            if(sum/10>=1) {
                carry = 1; 
                sum = sum%10;
            }
            else {
                carry = 0;
            }
            result->val = sum;
            result->next = new ListNode(0);
            prevNode = result;
            result = result->next;
            
            A = A->next;
            B = B->next;
        }
        
        if(B != NULL) {
            while(B!=NULL) {
                sum = B->val + carry; 
                if(sum/10>=1) {
                    carry = 1; 
                    sum = sum%10;
                }
                else {
                    carry = 0;
                }
                prevNode = result;
                result->val = sum;
                result->next = new ListNode(0);
                result = result->next;
                
                B = B->next;
                
            }
        }
        
        if(A != NULL) {
            while(A != NULL) {
                sum = A->val + carry; 
                if(sum/10>=1) {
                    carry = 1; 
                    sum = sum%10;
                }
                else {
                    carry = 0;
                }
                
                result->val = sum;
                result->next = new ListNode(0);
                prevNode = result; 
                result = result->next;
                
                A = A->next;
                
            }
        }
        
        if(carry) {
            result->val = carry;
        }
        else {
            prevNode->next = NULL;
        }
        return head; 
}
