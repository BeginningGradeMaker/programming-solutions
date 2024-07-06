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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head->next->next) {
            return {-1, -1};
        }
        ListNode *prev = head;
        ListNode *next = head->next->next;
        ListNode *cur = head->next;
        int mn_d = INT_MAX, mx_d = INT_MIN;
        int mn_n = -1, mx_n = -1;

        auto critical = [] (int p, int c, int n) {
            return (p < c && n < c) || (p > c && n > c);
        };

        int i = 1;
        while (next) {
            int yes = critical(prev->val, cur->val, next->val);
            if (yes && mn_n != -1) {
                mn_d = min(mn_d, i - mn_n);
                mx_d = max(mx_d, i - mx_n);
            }
            if (yes) {
                if (mx_n == -1) {
                    mx_n = i;
                }
                mn_n = i;
            }
            prev = cur;
            cur = next;
            next = cur->next;
            i++;
        }

        return mn_d == INT_MAX ? vector<int>{-1, -1} : vector<int>{mn_d, mx_d};
    }
};
