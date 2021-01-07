//
//  main.cpp
//  链表操作
//
//  Created by YJLi on 2021/1/7.
//

#include <iostream>
#include <stack>

using namespace std;

/*
 链表是一种动态数据结构，因为在创建链表的时候，无需知道链表的长度。
 链表的每个结点包括两个部分：一个是存储数据元素的数据域，另一个是存储下一个结点地址的指针域
 
 c++ 链表操作：添加、遍历、删除、查找
 */

struct node {
    int value;
    node *next;
};

class Solution {
    
public:
    /*
     当插入一个结点的时候，我们只需要为新结点分配内存，然后调节结点的指针指向，新结点就被（逻辑上）链接到链表里
     */
    /* 链表都有一个头指针，一般以head来表示，存放的是一个地址。
     链表中的节点分为两类，头结点和一般节点，头结点是没有数据域的。链表中每个节点都分为两部分，一个数据域，一个是指针域*/
    
    /* 链表尾加入新元素*/
    node *addNode(node*head ,int addValue) {
        node *newNode = new node();
        newNode->next = NULL;
        newNode->value = addValue;
        
        //1.链表通过头节点指针就可以根据链表顺序找到下一个节点的值和地址
        //2.这里的头节点指针就是一个指向链表第一个元素的指针，我的理解就是->这仅仅是一个指针，不是一个节点（不包含数据域的节点）
        //3.插入新节点的时候，首先判断头节点指针指向的地址是否为空，若为空说明当前链接是空的，每次循环遍历，如果遍历p->next==NULL就表示当前节点是最后一个节点，将新元素插入到尾节点的后面
        node *p = head; //list的头结点
        if (head == NULL) {
            head = newNode;//新节点为链表头结点
            
            //我在这里故意写了p=head想验证head指针指向的地址是否和第一个元素的地址相同，
            p = head;
        } else {
            //尾插法每次插入新元素的时候需要找到最后一个元素
            //不断遍历，当当前p->next==NULL，当前节点就是尾节点
            while (p->next != NULL) {//找到尾节点
                p = p->next;
            }
            p->next = newNode;//在尾节点后面加入新节点
            p = p->next;//将p指针指向最后一个元素
        }
        cout<<"头指针地址 = "<<head<<"头指针节点对应的值 = "<<head->value<<">>p节点地址 = "<<p<<"p节点对应的值 = "<<p->value<<endl;
        return head;
    }
    
    /* 链表头加入新元素*/
    node *addNode2(node*head ,int addValue) {
        node *newNode = new node();
        newNode->value = addValue;
        newNode->next = NULL;
        
        node *p = head;
        if (head == NULL) {
            head = newNode;
        } else {
            //头插法只需要每次将头指针指向新加入的元素，之后再将head->next指向上一次头指针指向的元素地址
            head = newNode;
            head->next = p;
        }
        
        return head;
    }
    
    /*
     由于链表中的内存不是一次性连续分配的，因此我们无法保证链表的内存和数组一样是连续的。因此想在链表中找到它的某一个结点，我们只能从头结点开始，沿着指向下一个结点的指针遍历链表，它的时间效率为O（n）
     */
    /*在链表中找到某个值，删除它*/
    node* removeNode(node* head,int value) {
        node *pNode = head, *deleteNode = NULL;
        
        //删除的时候不要忘记先判断当前链表是否为空
        if (head == NULL) {
            cout<<"链表为空"<<endl;
                   return NULL;
        } else {
            /*
             删除元素的时候有三种情况，
             1.删除头节点元素，直接将head=head->next
             2.删除尾节点元素，
             3.删除中间节点元素
             这两种情况都是找到要删除元素的上一个元素，如要删除节点p，直接将p->next=p->next->next
             */
            if (head->value == value) {//删除头节点元素
                deleteNode = head;
                head = head->next;
            } else {
                //先找到要删除元素的上一个元素
                while (pNode->next != NULL && pNode->next->value != value) {
                    pNode = pNode->next;
                }
                deleteNode = pNode->next;
                pNode->next = pNode->next->next;
            }
        }
        if (deleteNode != NULL) {
            delete deleteNode;
            deleteNode = NULL;
        }
        return head;
    }
    
    /*
     从头到尾遍历链表
     */
    void travelList(node *head) {
        node* pNode=head;
        if(head == NULL)
            return ;
        else {
            //通过指针不断往后移动，逐次打印出当前节点的值，直到当前节点的next指向NULL
            cout<<pNode->value<<'\t';
            while(pNode->next != NULL) {
                pNode=pNode->next;
                cout<<pNode->value<<'\t';
            }
        }
        cout<<endl;
    }
    
    /*
     从尾到头打印每个结点，我们从头到尾遍历链表，并把每个节点放在stack结构中，利用stack结构先进后出”的特点，从尾到头打印结点。时间复杂度为O(n).
     */
    /*从尾到头遍历链表*/
    void printNodeReserve(node* head) {
        stack<node*> nodeStack;
        node *pNode = head;
        if (head == NULL) {
            return;
        }
        //遍历链表，并把节点保留在stack里
        //遍历链表，从头节点开始每次将当前节点压入栈中，然后将当前节点next指针指向的节点地址赋值给pNode
        //这里要好好理解，为什么要写成pNode != NULL，要记住pNode是个指向节点的指针，当然可以通过pNode->next找到当前节点的下一个节点的地址，但是这里要做的就是遍历整个链表，刚好最后一个节点的next==NULL，以此为终止条件刚好遍历完成整个链表
        while (pNode != NULL) {
            nodeStack.push(pNode);
            pNode = pNode->next;
        }
        while (!nodeStack.empty()) {
            pNode = nodeStack.top();
            cout<<pNode->value<<" ";
            nodeStack.pop();
        }
        cout<<endl;
    }
    
    /*
     输出链表中倒数第K个结点
     为了实现一次遍历链表就能找到倒数第K个节点，我们定义两个指针p1,p2。第一个指针p1从链表头指针开始往前走k步，此时，第二个指针p2不动。从第k+1步开始，指针p2也开始头链表头开始遍历，两个指针距离是k.当p1遍历完链表，指向一个null值的时候，p2指针正好是倒数第k个结点。
     */
    /*
     查找链表中倒数第k个节点，并输出
     */
    void printKthTOTotal(node *head, int k) {
        //如果链表为空，或k为0，return
        if (head == NULL || k <= 0) {
            return;
        }
        node *pNode1 = head, *pNode2 = head;
        int n = k;
        while (k > 0 && pNode1 != NULL) {
            pNode1 = pNode1->next;
            k--;
        }
        if (k > 0) {
            return;
        }
        while (pNode1 != NULL) {
            pNode1 = pNode1->next;
            pNode2 = pNode2->next;
        }
        cout<<"倒数第"<<n<<"个值 = "<<pNode2->value<<endl;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "===============\n";
    
    Solution solu;
    node *head = NULL, *head2 = NULL;
    int i = 1, j = 1;
    while (i <= 10) {
        head = solu.addNode(head, i++);
    }
    solu.travelList(head);
//    while (j <= 10) {
//        head2 = solu.addNode2(head2, j++);
//    }
//    solu.travelList(head2);
//    head2 = solu.removeNode(head2, 1);
//    solu.travelList(head2);
//    head2 = solu.removeNode(head2, 10);
//    solu.travelList(head2);
    
//    solu.printNodeReserve(head);
    solu. printKthTOTotal(head, 10);
    
    std::cout << "===============\n";
    return 0;
}
