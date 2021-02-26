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
    ListNode(int x): val(x), next(NULL){};
};

class Solution {
    
public:
    /*
     一个链表只要知道了头节点只可以逐次遍历出链表
     双指针法
     这里使用了双指针法，一个指针pre在前，一个指针cur在后，
     pre指针初始指向头节点，逐次往后移动，直到最后一个节点next指针指向的地址NULL
     cur指针初始 = NULL，跟着pre指针的脚步逐步向后，每次将pre指向的节点的next指针反向
     这样pre最后=NULL时，刚好cur指针指向的节点是链表的最后一个节点，且是next指针反向链表的头结点，返回这个头结点指针即可
     1 -> 2 -> 3 -> 4 -> 5 -> NULL
     NULL<- 1 <- 2 <- 3 <- 4 <- 5
     */
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = NULL, *pre = head;
        while (pre != NULL) {
            ListNode *t = pre->next; //1.先记录下pre的下一个节点
            pre->next = cur; //2.再将当前pre指向的节点的next指针反转
            cur = pre;//3.将cur指针后一步
            pre = t;//4.最后pre指针后移一步
        }
        return cur;
    }
    
    /*
     递归的本质就是利用栈和形参
      形参 = 在函数定义中出现的参数可以看做是一个占位符，它没有数据，只能等到函数被调用时接收传递进来的数据，所以称为形式参数，简称形参。
     实参（实际参数）= 函数被调用时给出的参数包含了实实在在的数据，会被函数内部的代码使用，所以称为实际参数，简称实参
     
     递归的基本思想，是把规模较大的一个问题，分解成规模较小的多个子问题去解决，而每一个子问题又可以继续拆分成多个更小的子问题。
      最重要的一点就是假设子问题已经解决了，现在要基于已经解决的子问题来解决当前问题；或者说，必须先解决子问题，再基于子问题来解决当前问题。
     递归是咋跑的？？？这点要弄清楚了
     我的理解递归就是函数嵌套和形参使用
     例如A嵌套B，B嵌套C，C嵌套D，
     1.在函数执行顺序上只有当D执行完了才会执行在C函数体中调用D函数那一行后面的逻辑代码，
     2.只有当C执行完了才会执行在B函数体中调用C函数那一行后面的逻辑代码，
     3.只有当B执行完了才会执行在A函数体中调用B函数那一行后面的逻辑代码，
     递归就是自己调自己，多层循环的调用自己，就是将B、C、D函数都换成了A，即A嵌套A(B)， A(B)嵌套A(C)，A(C)嵌套A(D)
     
     这里形参变化就是
     1.将最子问题D的结果当做形参传递给C函数，然后求出C函数的结果；
     2.将最子问题C的结果当做形参传递给B函数，然后求出B函数的结果；
     3.将最子问题B的结果当做形参传递给A函数，然后求出A函数的结果；得到最终结果
     
     递归函数函数法
     递归的模板：终止条件，递归调用，逻辑处理
     
     使用递归函数，一直递归到链表的最后一个节点，该节点就是反转后的头结点，记作ret
     此后，每次函数再返回过程中，让当前节点的下一个节点的next指针指向当前节点
     同时让当前节点的next指针指向NULL，从而实现从链表尾部开始的局部反转
     当递归函数全部出栈后，链表反转完成
     */
    ListNode *reverseList2(ListNode *head) {
        /*
         终止条件
         当链表为空或者当前节点的next = NULL（即当前节点是最后一个节点）直接返回
         */
        if (head == NULL || head->next == NULL) {
            return head;
        }
        /*
         递归调用
         从当前节点的下一个节点开始递归调用
         */
        //这个过程中head作为形参是不断地在变化的
        ListNode* ret = reverseList2(head->next);
        //将head挂到head->next节点的后面就完成了链表的反转
        head->next->next = head;
        //这里head相当于变成了尾结点，next都是为空的，否则会构成环
        head->next = NULL;
        return ret;
    }
    
    ListNode *reverseList4(ListNode *head) {
        ListNode *cur = head, *pre = NULL;
        while (cur != NULL) {
            ListNode *tmp = cur->next; // 保存cur的下一个节点
            cur->next = pre; // 翻转操作
            // 更新pre 和 cur指针
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
    
    ListNode *reverse(ListNode *pre, ListNode *cur) {
        if (cur == NULL) return pre;
        ListNode *tmp = cur->next;
        cur->next = pre;
        return reverse(cur, tmp);
    }
    ListNode *reverseList3(ListNode *head) {
        return reverse(NULL, head);
    }
    
    /* 链表尾加入新元素*/
    ListNode* addNode(ListNode*head ,int addValue) {
        ListNode* newNode = new ListNode(addValue);
        ListNode* p = new ListNode(0);//创建一个虚拟的头结点next指针指向head
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
//    ListNode *reverseNode = solu.reverseList(head);
    
    ListNode *reverseNode = solu.reverseList4(head);
    cout<<endl;
    solu.travelList(reverseNode);

    cout<<endl;
    
    std::cout << "==============\n";
    return 0;
}
