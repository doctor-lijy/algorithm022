//
//  main.cpp
//  反转链表-206
//
//  Created by YJLi on 2021/1/6.
//

#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
};

class Solution {
    
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = NULL, *pre = head;
        while (pre != NULL) {
            ListNode *t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return cur;
    }
    
    /* 链表尾加入新元素*/
    ListNode* addNode(ListNode*head ,int addValue) {
        ListNode* newNode=new ListNode();
         newNode->next=NULL;
         newNode->val=addValue;
        ListNode* p=new ListNode();
         p=head; //list的头结点
         if(head == NULL) {
           head=newNode; //新节点为链表头节点
         } else {
            while(p->next != NULL)//找到尾节点
                p= p->next;
            p->next=newNode; //在尾节点后面加入新节点
         }
         return head;
    }
    
    /*从头到尾遍历链表*/
    void travelList(ListNode*head) {
        ListNode* pNode=head;
        if(head==NULL)
            return ;
        else {
          cout<<pNode->val<<'\t';
          while(pNode->next!=NULL) {
              pNode=pNode->next;
              cout<<pNode->val<<'\t';
          }
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "==============\n";
    Solution solu;
    ListNode *head = NULL;
    for (int i = 1; i <= 5; i++) {
        head = solu.addNode(head, i);
    }
    solu.travelList(head);
    cout<<endl;
    ListNode *reverseNode = solu.reverseList(head);
    
    cout<<endl;
    solu.travelList(reverseNode);
    cout<<endl;
    
    std::cout << "==============\n";
    return 0;
}
