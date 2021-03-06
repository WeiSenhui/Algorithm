/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // use fast and slow points
        auto fast = head, slow = head;
        while(fast) {
            fast = fast->next;
            slow = slow->next;
            if (fast != NULL) fast = fast->next;
            else break;

            if (fast == slow) {
                slow = head;
                while(fast != slow) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return fast; // second time meet position
            }
        }

        return NULL;
    }
};
