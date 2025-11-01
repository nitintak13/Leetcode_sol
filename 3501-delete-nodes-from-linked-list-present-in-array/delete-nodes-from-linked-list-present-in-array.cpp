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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        ListNode* node = head;
        unordered_map<int, int> mp;
        for (auto it : nums) {
            mp[it]++;
        }
        ListNode* prev = NULL;
        ListNode* dum = new ListNode(-1);
        dum->next = head;
        while (node != nullptr) {
            if (mp.find(node->val) != mp.end()) {
                if (node == head) {
                    dum->next = node->next;
                    prev = dum;
                } else {
                    prev->next = node->next;
                }
            } else {
                prev = node;
            }

            node = node->next;
        }
        return dum->next;
    }
};