//
//  main.cpp
//  移除链表元素-203
//
//  Created by YJLi on 2021/2/17.
//
/*
 删除链表中等于给定值val 的所有节点
 */

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val; // 节点上存储的元素
    ListNode *next; // 指向下一个节点的指针
    ListNode(int x) : val(x), next(NULL){} // 节点的构造函数
};

class Solution {
public:
    ListNode *addNode(ListNode *head, int addVal) {
        ListNode *newNode = new ListNode(addVal);
        
        ListNode *p = head;
        if (head == NULL) {
//            p = newNode;
            head = newNode;
        } else {
            //尾插法每次插入新元素的时候需要找到最后一个元素
            //不断遍历，当当前p->next==NULL，当前节点就是尾节点
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = newNode;//在尾节点后面加入新节点
            p = p->next;//将p指针指向最后一个元素
        }
        return head;
    }
    
    void travelList(ListNode *head) {
        ListNode *p = head;
        if (head == NULL) return;
        
        cout<<p->val<<" ";
        while (p->next != NULL) {
            p = p->next;
            cout<<p->val<<" ";
        }
        cout<<endl;
    }
    
    
    /*
     直接使用原来的链表来进行移除节点操作：
     */
    ListNode* removeElements(ListNode* head, int val) {
        // 删除头结点
        while (head != NULL && head->val == val) {// 注意这里不是if，这里使用while的就是不断循环判断新的链表头是否是所需要删除的值
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }
        // 删除非头结点
        ListNode *cur = head;
        while (cur != NULL && cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
    
    /*
     设置一个虚拟头结点在进行移除节点操作：
     */
    ListNode* removeElements2(ListNode* head, int val) {
        ListNode *dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方面后面做删除操作
        ListNode *cur = dummyHead;
        
        while (cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            } else {
                cur = cur->next;
            }
        }
        return dummyHead->next;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Solution solu;
    ListNode *head = NULL;
    vector<int> vec = {1, 2, 6, 3, 4, 5, 6};
    for (int i = 0; i < vec.size(); i++) {
        head = solu.addNode(head, vec[i]);
    }
    solu.travelList(head);
    cout<<endl;
    head = solu.removeElements(head, 6);
    solu.travelList(head);
    cout<<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
