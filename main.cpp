#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;

};

bool detectCycle(ListNode *head)
{
    if (head==nullptr) return 0;
    
    ListNode *i = head;
    ListNode *j = head;
    if(head->next == nullptr) return false;
    
    j = j->next;
    while(i != j && i != nullptr && j != nullptr && j->next != nullptr)
    {
        cerr << i->val << " " << j->val << "\n";
        i = i->next;
        j = j->next->next;
    }
    
    if(i == j) return true;
    return false;
}

void input(ListNode*& head)
{
    int n;
    cin >> n;
    if (n==0) return;
    
    ListNode* cur = head;
    ListNode* last;
    while (n)
    {
        last = cur;
        cur->val = n;
        cur->next = new ListNode;
        cur = cur->next;
        cur->next = nullptr;
        cin >> n;
    }
    last->next = head->next;
}

signed main()
{
	ListNode *head = new listNode;
	input(head);
    
    if(detectCycle(head)) cout << "there is a cycle\n";
    else cout << "There is not a cycle\n";
	return 0;
}
