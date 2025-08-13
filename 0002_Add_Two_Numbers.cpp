#include <bits/stdc++.h>
using namespace std;

// Định nghĩa node cho danh sách liên kết đơn
struct ListNode {
    int val;            // giá trị lưu trong node
    ListNode *next;     // con trỏ tới node tiếp theo

    ListNode() : val(0), next(nullptr) {}                 // constructor mặc định
    ListNode(int x) : val(x), next(nullptr) {}            // constructor với giá trị
    ListNode(int x, ListNode *next) : val(x), next(next) {} // constructor với giá trị + con trỏ
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum = 0;
    int newElement;
    ListNode dummy(0);
    ListNode*cur1 = l1;
    ListNode*cur2 = l2;
    ListNode*cur3 = &dummy;
    while(cur1 || cur2 || sum != 0){
        if(cur1) {
            sum += cur1->val;
            cur1 = cur1 ->next;
        }
        if(cur2) {
            sum += cur2->val;
            cur2 = cur2 ->next;
        }
        newElement = sum % 10;
        cur3->next = new ListNode(newElement);
        sum /= 10;
        cur3 = cur3->next;
    }   
    return dummy.next;
}

void PrintList(ListNode *head){
    // Duyệt danh sách
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout<<"\n";
}

void DeleteList(ListNode *&head){
    ListNode* current = head;
    while (current != nullptr) {
        ListNode*temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

int main() {
    // Tạo 3 node

    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    ListNode node6(6);
    ListNode node7(9);
    ListNode node8(9);
    ListNode* pNode4 = &node4;
    ListNode* pNode5 = &node5;
    ListNode* pNode1 = &node1;
    ListNode* pNode8 = &node8;
    ListNode* pNode7 = &node7;
    // Nối các node lại thành danh sách 1 -> 2 -> 3
    node1.next = &node2;
    node2.next = &node3;
    // node3.next = &node4;
    node4.next = &node5;

    node5.next = &node6;
    // node6.next = &node7;
    // node7.next = &node8;

    PrintList(pNode7);

    PrintList(pNode8);
    ListNode* newNode = addTwoNumbers(pNode7, pNode8);
    PrintList(newNode);

    DeleteList(pNode1);
    DeleteList(pNode4);
    return 0;
}