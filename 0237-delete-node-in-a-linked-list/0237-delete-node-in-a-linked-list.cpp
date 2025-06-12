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
    void deleteNode(ListNode* node) {
        // bring the next node's value to this node
        node -> val = node -> next -> val;
        // delete the next node
        node -> next = node -> next -> next;
    }
};