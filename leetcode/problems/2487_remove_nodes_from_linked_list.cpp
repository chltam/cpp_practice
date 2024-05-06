#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stack;
        stack.push(head);
        head = head->next;
        while (head != nullptr) {

            while (!stack.empty() && head->val > stack.top()->val) {
                stack.pop();
            }
            stack.push(head);
            head = head->next;
        }

        ListNode* next = NULL;

        while (!stack.empty()) {

            head = stack.top();
            stack.pop();
            head->next = next;
            next = head;
        }
        return (head);
    }
};