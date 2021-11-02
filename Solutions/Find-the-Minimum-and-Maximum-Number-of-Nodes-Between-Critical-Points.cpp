class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> v;

        ListNode* prev = head, *cur = (prev != nullptr ? prev->next : nullptr), *next = (cur != nullptr ? cur->next : nullptr);

        int idx = 1;
        while (next) {
            if (cur->val < prev->val && cur->val < next->val) v.push_back(idx);
            else if (cur->val > prev->val && cur->val > next->val) v.push_back(idx);

            idx++;
            prev = cur;
            cur = next;
            next = next->next;
        };

        if (v.size() < 2) return {-1, -1};

        int minDistance = 0x7fffffff, maxDistance = 0;

        for (int i = 0; i < v.size() - 1; i++)
            minDistance = min(minDistance, v[i + 1] - v[i]);
        maxDistance = v[v.size() - 1] - v[0];

        return {minDistance, maxDistance};
    };
};
