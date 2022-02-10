// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (!l1 && !l2)
        {
            return nullptr;
        }
        auto p_mergeList = new ListNode();
        auto p_list1_head = l1;
        auto p_list2_head = l2;
        auto p_head = p_mergeList;
        while (p_list1_head != nullptr || p_list2_head != nullptr)
        {
            //merging
            if (p_list1_head && p_list2_head)
            {
                auto const val1 = p_list1_head->val;
                auto const val2 = p_list2_head->val;
                if (val1 < val2)
                {
                    p_head->val = val1;
                    p_list1_head = p_list1_head->next;
                }
                else
                {
                    p_head->val = val2;
                    p_list2_head = p_list2_head->next;
                }
            }
            else if (p_list1_head)
            {

                p_head->val = p_list1_head->val;
                p_list1_head = p_list1_head->next;
            }
            else if (p_list2_head)
            {

                p_head->val = p_list2_head->val;
                p_list2_head = p_list2_head->next;
            }

            //Incrementor
            if (p_list1_head != nullptr || p_list2_head != nullptr)
            {
                p_head->next = new ListNode();
                p_head = p_head->next;
            }
        }
        return p_mergeList;
    }
};