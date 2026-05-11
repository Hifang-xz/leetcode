struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy; // 哨兵
        dummy.next = head;
        ListNode *fast = &dummy; // 快慢指针
        ListNode *slow = &dummy;
        for (int i = 0; i <= n; ++i)
        { // 先走n+1步
            fast = fast->next;
        }
        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next; // 待删除前的节点
        }
        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummy.next;
    }
};