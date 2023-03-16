#include <iostream>

using namespace std;

struct listNode
{
	int val;
	listNode *next;
	listNode(int x)
	{
		val = x;
		next = nullptr;
	}
};
void input(node*& head)
{
    int n;
    inp >> n;
    if (n==0) return;
    
    node* cur = head;
    while (n)
    {
        cur->data = n;
        cur->next = new node;
        cur = cur->next;
        cur->next = nullptr;
        inp >> n;
    }
}

signed main()
{
	listNode *head = nullptr;
	input(head);
	return 0;
}
