// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

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
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        auto p_list1_index = l1;
        auto p_list2_index = l2;
        ListNode *p_storage = new ListNode();
        auto p_head = p_storage;
        size_t carry_over = 0;
        //comparison of each heads and increment
        while (p_list1_index != nullptr || p_list2_index != nullptr)
        {
            //check pointers before summation
            auto index1 = (p_list1_index) ? p_list1_index->val : 0;
            auto index2 = (p_list2_index) ? p_list2_index->val : 0;
            size_t sum = index1 + index2 + carry_over;

            //carry_over
            carry_over = sum / 10;
            p_head->val = sum % 10;

            // check pointers
            p_list1_index = (p_list1_index) ? p_list1_index->next : nullptr;
            p_list2_index = (p_list2_index) ? p_list2_index->next : nullptr;
            if (p_list1_index != nullptr || p_list2_index != nullptr)
            {
                p_head->next = new ListNode();
                p_head = p_head->next;
            }
        }
        if (carry_over)
        {
            p_head->next = new ListNode(carry_over);
        }
        return p_storage;
    }
};