#include <iostream>
#include <vector>
#include <list>

using namespace std;


 // Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
      ListNode* to_remove = checkSublist(head);
      if (!to_remove)
        return (head);
    
      removeSublist(&head, to_remove);
      head = removeZeroSumSublists(head);
      return (head);
    }

    ListNode* checkSublist(ListNode* head) {
      if (!head)
        return (nullptr);
      ListNode* current = head;
      int sum = 0;

      while (current) {
        sum += current->val;
        current = current->next;
        if (sum == 0)
          return head;
      }
      return (checkSublist(head->next));
    }

    ListNode* remove(ListNode* node) {
      ListNode* temp;
      int sum = 0;

      while (node) {
        sum += node->val;
        temp = node;
        node = node->next;
        // delete temp;
        if (sum == 0)
          break;
      }
      return node;
    }

    void removeSublist(ListNode** head, ListNode* to_remove) {
      
      if (*head == to_remove) {
        *head = remove(*head);
        return ;
      }

      ListNode* current = *head;
      while (current->next && current->next != to_remove)
        current = current->next;

      current->next = remove(current->next);
      return ;
    }
};