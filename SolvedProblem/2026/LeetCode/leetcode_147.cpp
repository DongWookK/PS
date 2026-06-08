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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode* sort_head = new ListNode;
        ListNode* cur = head;

        while (nullptr != cur)
        {
            /*
                sort_head는 항상 유지.
                cur은 정렬될애 넘기고 next로 설정 (while문 조건)
            */
            ListNode* cur_next = cur->next;

            ListNode* comp = sort_head;
            while (nullptr != comp->next
                && comp->next->val < cur->val)
            {
                comp = comp->next;
            }

            cur->next = comp->next;
            comp->next = cur;

            cur = cur_next;

        }

        ListNode* result = sort_head->next;
        delete sort_head;

        return result;
    }
};