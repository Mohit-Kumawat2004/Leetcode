/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    
    //step 1 for special case when size is 5
    //calculate length of linkedlist to prevent error
    int getLength(ListNode* head)
    {
        int len = 0;
        while(head != NULL)
        {
            len++;
            head = head -> next;
        }
        return len;
    }
    
    //step 2 - reverse only 2 nodes of a linked list rest recursion will solve
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        //base case
        if(head == NULL && head -> next == NULL)
        {
            return head;
        }
        
        //length error check
        if(getLength(head)<k)
        {
            return head;
        }
        
        //reverse linked list
        ListNode* prev = NULL;
        ListNode* curr = head;
        int cnt = 0;
        while(curr != NULL && cnt<k)
        {
            ListNode* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
            cnt ++;
        }
        
        //step 3 - recursion call 
        if(curr != NULL)
        {
            head -> next = reverseKGroup(curr , k);
        }
        
        
        //last step
        return prev;
    }
};