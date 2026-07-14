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
    ListNode* swapPairs(ListNode* head) {
        // check the node is exist  or not
        ListNode* temp  = head;
        int count = 0;

        while(count < 2){
            if(temp == NULL)  return head;
        temp = temp->next;
        count++;
        }

        ListNode* prevnode = swapPairs(temp );

        temp =head , count = 0;
        while(count < 2){
            ListNode* next = temp->next;
            temp->next = prevnode;

            prevnode = temp;
            temp = next;
            count++;
        }
        return prevnode;
    }


};