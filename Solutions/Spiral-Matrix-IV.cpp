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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        vector<vector<int>> nums(m, vector<int>(n, -1));
        int x = 0, y = 0, dir = 1;
        while (head)
        {
            int num = head->val;
            head = head->next;

            nums[x][y] = num;

            if (dir == 1)
            { // 向右
                if (y < n - 1 && nums[x][y + 1] == -1)
                    y++;
                else
                {
                    dir = 2;
                    x++;
                };
            }
            else if (dir == 2)
            { // 向下
                if (x < m - 1 && nums[x + 1][y] == -1)
                    x++;
                else
                {
                    dir = 3;
                    y--;
                };
            }
            else if (dir == 3)
            { // 向左
                if (y > 0 && nums[x][y - 1] == -1)
                    y--;
                else
                {
                    dir = 4;
                    x--;
                };
            }
            else if (dir == 4)
            { // 向上
                if (x > 0 && nums[x - 1][y] == -1)
                    x--;
                else
                {
                    dir = 1;
                    y++;
                };
            }
        };
        return nums;
    }
};