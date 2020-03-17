
#include <iostream>
#include <string>
#include <vector>

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    int length(ListNode* head)
    {
        int count = 0;
        while (head != NULL)
        {
            head = head->next;
            count++;

        }
        return count;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = length(head);
        if (len == 1)
            return NULL;
        ListNode* realhead = head;
        int begin_n = len - n;
        if (begin_n == 0)
        {
            realhead = realhead->next;
            return realhead;
        }
        if (begin_n == len - 1)
        {
            while (begin_n > 1)
            {
                head = head->next;
                begin_n--;
            }
            head->next = head->next->next;
            return realhead;

        }
        while (begin_n > 0)
        {
            head = head->next;
            begin_n--;
        }
        if (head->next != NULL)
        {
            head->val = head->next->val;
            head->next = head->next->next;
        }
        else
        {
            (*head) = NULL;

        }

        return realhead;
    }
};

int main()
{

    return 0;
}
//Write a function to delete a node(except the tail) in a singly linked list, given only access to that node.