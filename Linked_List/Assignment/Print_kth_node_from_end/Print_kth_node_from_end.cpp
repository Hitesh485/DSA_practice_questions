#include <iostream>

using namespace std;

void utility(SinglyLinkedListNode* ptr, int &pos, int &ans)
{
    if (ptr == NULL) return;
    
    utility(ptr->next, pos, ans);
    
    if (pos == 0) ans = ptr->data;
    pos--;
}

int getNode(SinglyLinkedListNode* llist, int positionFromTail) {

    SinglyLinkedListNode* ptr = llist;
    int ans = -1;
    
    utility(ptr, positionFromTail, ans);
    
    return ans;

}

int main ()
{
    
    return 0;
}