#include<iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
typedef ListNode* List;
ListNode* reverse(ListNode* head){
    ListNode* temphead = new ListNode(0,head);
    ListNode* curNode = head;
    ListNode* anshead = new ListNode(0);
    while(curNode!=NULL){
        temphead->next = curNode->next;
        curNode->next = anshead->next;
        anshead->next = curNode;
        curNode = temphead->next;
    }
    ListNode* ans =anshead->next;
    delete temphead;
    delete anshead;
    return ans;

}
int main(){

}