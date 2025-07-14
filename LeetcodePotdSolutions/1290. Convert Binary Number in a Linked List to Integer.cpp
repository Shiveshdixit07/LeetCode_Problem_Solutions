class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int ans = 0;
        int i = 0;
        ListNode *s = head;
        while (head)
        {
            head = head->next;
            i++;
        }
        i--;
        while (s)
        {
            if (s->val)
            {
                ans += (1 << i);
            }
            s = s->next;
            i--;
        }
        return ans;
    }
};