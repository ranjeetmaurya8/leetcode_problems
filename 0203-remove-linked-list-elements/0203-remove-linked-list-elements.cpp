
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* curr = temp;

        while (curr->next != NULL) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else {
                curr = curr->next;
            }
        }

        ListNode* newHead = temp->next;
        delete temp;

        return newHead;
    }
};
