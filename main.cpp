#include <iostream>

using namespace std;

struct listNode
{
	int val;
	listNode *next;

};

bool detectCycle(listNode *head)
{
    if (head==nullptr) return 0;
    
    listNode *i = head;
    listNode *j = head;
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

void input(listNode*& head)
{
    int n;
    cin >> n;
    if (n==0) return;
    
    listNode* cur = head;
    listNode* last;
    while (n)
    {
        last = cur;
        cur->val = n;
        cur->next = new listNode;
        cur = cur->next;
        cur->next = nullptr;
        cin >> n;
    }
    last->next = head->next;
}

signed main()
{
	listNode *head = new listNode;
	input(head);
    
    if(detectCycle(head)) cout << "there is a cycle\n";
    else cout << "There is not a cycle\n";
	return 0;
}
