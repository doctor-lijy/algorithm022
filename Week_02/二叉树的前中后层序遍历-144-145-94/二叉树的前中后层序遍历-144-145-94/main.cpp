//
//  main.cpp
//  二叉树的前中后层序遍历-144-145-94
//
//  Created by YJLi on 2021/1/12.
/*
 leetcode
 144.二叉树的前序遍历
 145.二叉树的后序遍历
 94.二叉树的中序遍历
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    /*
     这是构造函数
     构造函数也可以不写，但是new一个新的节点的时候就比较麻烦
     例如有构造函数，定义初始值为9的节点：

     TreeNode* a = new TreeNode(9);
     
     没有构造函数的话就要这么写：

     TreeNode* a = new TreeNode();
     a->val = 9;
     a->left = NULL;
     a->right = NULL;
     */
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
 递归的实现就是：每一次递归调用都会把函数的局部变量、参数值和返回地址等压入调用栈中，然后递归返回的时候，从栈顶弹出上一次递归的各项参数，这就是递归为什么可以返回上一层位置的原因。
 递归函数三要素
 1.确定递归函数的参数和返回值：
 确定哪些参数是递归的过程中需要处理的，那么就在递归函数中加上这个参数，并且还要明确每次递归的返回值是什么进而确定递归函数的返回类型
 2.确定终止条件：
 递归算法在运行的时候，经常会遇到栈溢出的错误，就是没写终止条件或者终止条件写的不对，系统也是用一个栈结构来保存每一层递归的信息，如果递归没有终止，系统的内存栈必然溢出
 3.确定单层递归的逻辑：
 确定每一层递归需要处理的信息。在这里就是重复调用自己来实现递归的过程
 */

class Solution {
    
public:
    
    //递归实现二叉树遍历
    /*
     二叉树的前序遍历
     1.确定递归函数的参数和返回值：因为要打印出前序遍历节点的数值，所以参数里需要传入vertor在放节点的数值，除了这一点不需要在处理什么数据了也就不需要返回值，所以递归函数返回类型就是void
     */
    void preTraversal(TreeNode *cur, vector<int> &vec) {
        /*
         2.确定终止条件：在递归的过程中，当前遍历的节点是空的，那么本层递归就要结束了，如果当前遍历的这个节点是空，就直接return；*/
        if (cur == NULL) {
            return;
        }
        /*
         3.确定单层循环逻辑：前序遍历是根->左->右的顺序，所以在单层递归的逻辑，要先取中间节点的数值*/
        vec.push_back(cur->val);
        preTraversal(cur->left, vec);
        preTraversal(cur->right, vec);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preTraversal(root, result);
        return result;
    }
    
    /*
     二叉树的中序遍历
     1.确定递归函数的参数和返回值：因为要打印出中序遍历节点的数值，所以参数里需要传入vertor在放节点的数值，除了这一点不需要在处理什么数据了也就不需要返回值，所以递归函数返回类型就是void
     */
    void inTraversal(TreeNode *cur, vector<int> &vec) {
        /*
         2.确定终止条件：在递归的过程中，当前遍历的节点是空的，那么本层递归就要结束了，如果当前遍历的这个节点是空，就直接return；*/
        if (cur == NULL) {
            return;
        }
        /*
         3.确定单层循环逻辑：中序遍历是左->根->右的顺序，所以在单层递归的逻辑，要先遍历左子树，直至当前节点左孩子节点==NULL，直接reture，然后取中间节点的数值*/
        inTraversal(cur->left, vec);
        vec.push_back(cur->val);
        inTraversal(cur->right, vec);
    }
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        inTraversal(root, result);
        return result;
    }
    
    /*
     二叉树的后序遍历
     1.确定递归函数的参数和返回值：因为要打印出后序遍历节点的数值，所以参数里需要传入vertor在放节点的数值，除了这一点不需要在处理什么数据了也就不需要返回值，所以递归函数返回类型就是void
     */
    void postTraversal(TreeNode *cur, vector<int> &vec) {
        /*
         2.确定终止条件：在递归的过程中，当前遍历的节点是空的，那么本层递归就要结束了，如果当前遍历的这个节点是空，就直接return；*/
        if (cur == NULL) {
            return;
        }
        /*
         3.确定单层循环逻辑：中序遍历是左->右->根的顺序，所以在单层递归的逻辑，要先遍历左子树，直至当前节点节点左孩子节点==NULL，直接reture，然后在遍历当前节点右孩子节点==NULL，直接reture， 最后取中间节点的数值*/
        postTraversal(cur->left, vec);
        postTraversal(cur->right, vec);
        vec.push_back(cur->val);
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        postTraversal(root, result);
        return result;
    }

    /*
     迭代实现二叉树遍历
     用栈实现二叉树的前中后序遍历
     */
    /*
     前序遍历 （迭代法）
     前序遍历是根->左->右，栈结构是先进后出，每次循环依据栈是否为空，不为空弹出栈顶元素，再顺序将栈顶元素的右孩子节点和左孩子节点压入栈中，循环判断，直至栈结构为空
     每次先处理中间节点，将中间节点压入栈中，然后根据栈结构先进后出原则，将右孩子压入栈中，再将左孩子压入栈中
     */
    vector<int> preorderTraversal2(TreeNode *root) {
        stack<TreeNode *> st;//创建栈结构存储二叉树遍历节点
        vector<int> result;//存储先序遍历的二叉树节点数组
        if (root == NULL) {//如果根节点不存在直接返回
            return result;
        }
        st.push(root);//先将根节点压入栈中
        /*
         栈结构 先进后出
         先序遍历 根->左->右
         1、当前栈是否为空
         2、判断当前栈顶元素是否是中间节点，若是记录下来，弹出栈顶元素，将栈顶元素存入向量容器中，
         3、先判断栈顶元素右孩子是否存在，若窜在将当前节点的右孩子节点压入栈中，
         4、再判断栈顶元素左孩子节点是否存在，若存在，将左孩子节点压入栈中
         5、循环第1步到第4部，直至栈为空
         */
        while (!st.empty()) {//当栈中为空说明二叉树遍历结束
            TreeNode *node = st.top();
            st.pop();//弹出当前栈顶元素
            result.push_back(node->val);//将当前栈顶元素存入向量容器中
            if (node->right) {//先判断右孩子是否存在，若存在，压入栈
                st.push(node->right);
            }
            if (node->left) {//在判断左孩子是否选在，若存在，压入栈
                st.push(node->left);
            }
        }
        
        return result;
    }
    
    /*
     中序遍历（迭代法）
     中序遍历 左->根->右 栈结构是先进后出
     先访问的二叉树顶部的节点，然后一层一层向下访问，直到到达树左面的最底部，再开始处理节点（就是将节点的数值存入到向量容器中），这就造成访问顺序和处理顺序不一致
     所以在使用迭代法实现中序遍历，就需要借助指针的遍历来帮助访问节点，栈则用来处理节点上的元素（这里为什么会想到使用指针不得而知，或许是经验吧？？？）
     */
    vector<int> inorderTraversal2(TreeNode *root) {
        vector<int> result;
        stack<TreeNode *> st;
        TreeNode *cur = root;
        /*
         这里判断的依据：中序遍历先打印左孩子节点，但二叉树访问是从根节点开始的，这里借助指针指向访问
         1、从根节点开始访问，将节点指针cur指向根节点root，将访问的节点压入栈；
         2、因为是中序遍历，将指针指向当前节点的左孩子；
         3、判断当前指针指向的节点是否存在，若存在，压入栈中，将指针指向当前节点的左孩子，直至当前节点为NULL；
         4、若指针指向的节点为NULL，说明当前节点是树左面的最底部，也是栈顶元素；
         5、取出栈顶元素，弹出栈顶元素，将节点存入向量容器中，将cur指向栈顶元素的右孩子，从步骤1到步骤4循环；
         6、依次弹出栈顶元素，存入向量容器，当栈元素为空的时候，cur指定根节点的右孩子，再依次入栈循环，直至栈为空，遍历结束
         */
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);
                cur = cur->right;
            }
        }
        
        return result;
    }
    
    /*
     后序遍历（迭代法）
     后序遍历 左->右->根
     前序遍历 根->左->右 栈规则先进后出
        入栈顺序根先入栈，栈顶弹出存储到向量容器，右子树入栈，后左子树入栈，循环弹出，向量容器根左右
       改变代码入栈顺序，根先入栈，栈顶弹出存储到向量容器，左子树入栈，后右子树入栈，循环弹出，向量容器根右左，反转数组左右根
     */
    vector<int> postorderTraversal2(TreeNode *root) {
        stack<TreeNode *>st;
        vector<int > result;
        if (root == NULL) {
            return result;
        }
        st.push(root);
        while (!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) {
                st.push(node->left);
            }
            if (node->right) {
                st.push(node->right);
            }
        }
        /*
         向量容器中存储顺序是根右左，反转之后就是左右根，就是后序遍历的结果
         例如：前序遍历：5 4 1 2 6 中序遍历：1 4 2 5 6 后序遍历：1 2 4 6 5
          修改前序遍历入栈顺序为根左右，则向量容器中数据顺序就为：5 6 4 2 1，反转向量容器之后就是后序遍历结果
         */
        reverse(result.begin(), result.end());
        
        return result;
    }
    
    /*
     迭代法统一风格的代码
     针对三种遍历方式，使用迭代法是可以写出统一风格的代码
     
     标记法
     将访问的节点放入栈中，把要处理的节点也放入栈中但是要做标记。
     如何标记呢，就是要处理的节点放入栈之后，紧接着放入一个空指针作为标记。
     */
    /*
     别人的一个总结借鉴：
     以中序遍历为例：
     1、栈的特性入栈和出栈顺序相反，想要输出 《左中右》那么入栈的顺序就是《右中左》
     2、入栈的处理：可以把整个树简化成3个节点一组的多个子树（即父节点，左孩子，右孩子）这个三个节点组成的子树。每次循环处理的实际就是将这样的3个节点按照规则顺序（右中左）进行入栈。所以才有了代码中看到的：每次都是先将栈顶元素去除，然后以栈顶元素作为父节点的3个节点子树按照规则顺序（右中左）入栈。
     3、NULL节点的加入和出栈规则的规定：保证了当左孩子作为栈顶元素时，不会立即出栈，而是会将当前左孩子（即栈顶元素）作为下次遍历的父节点按照规则顺序入栈。直到当前的左孩子作为父节点再无孩子（无孩子时，入栈规则就成了（父节点，NULL节点）），遇到NULL节点了，才进行出栈。这样就保证了左孩子先出栈了。
     */
    
    /*
     中序遍历标记法
     */
    vector<int> inorderTraversal3(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) {
            st.push(root);
        }
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != NULL) {
                st.pop();// 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right) {
                    st.push(node->right);// 添加右节点（空节点不入栈）
                }
                st.push(node);// 添加中节点
                st.push(NULL);// 中节点访问过，但是还没有处理，加入空节点做为标记
                if (node->left) {
                    st.push(node->left);// 添加左节点（空节点不入栈）
                }
            } else {// 只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();// 将空节点弹出
                node = st.top();// 重新取出栈中元素
                st.pop();//将该栈顶元素弹出
                result.push_back(node->val);// 加入到结果集
            }
        }
        
        return result;
    }
    
    /*
     前序遍历标记法
     */
    vector<int> preorderTraversal3(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) {
            st.push(root);
        }
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != NULL) {
                st.pop();// 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right) {
                    st.push(node->right);// 添加右节点（空节点不入栈）
                }
                if (node->left) {
                    st.push(node->left);// 添加左节点（空节点不入栈）
                }
                st.push(node);// 添加中节点
                st.push(NULL);// 中节点访问过，但是还没有处理，加入空节点做为标记
            } else {// 只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();// 将空节点弹出
                node = st.top();// 重新取出栈中元素
                st.pop();//将该栈顶元素弹出
                result.push_back(node->val);// 加入到结果集
            }
        }
        
        return result;
    }
    
    /*
     后序遍历标记法
     */
    vector<int> postorderTraversal3(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root != NULL) {
            st.push(root);
        }
        while (!st.empty()) {
            TreeNode *node = st.top();
            if (node != NULL) {
                st.pop();// 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                st.push(node);// 添加中节点
                st.push(NULL);// 中节点访问过，但是还没有处理，加入空节点做为标记
                if (node->right) {
                    st.push(node->right);// 添加右节点（空节点不入栈）
                }
                if (node->left) {
                    st.push(node->left);// 添加左节点（空节点不入栈）
                }
            } else {// 只有遇到空节点的时候，才将下一个节点放进结果集
                st.pop();// 将空节点弹出
                node = st.top();// 重新取出栈中元素
                st.pop();//将该栈顶元素弹出
                result.push_back(node->val);// 加入到结果集
            }
        }
        
        return result;
    }
    
    TreeNode *root;
    
    //递归实现构造二叉树
    /*
     递归前序构造二叉树
     */
    /*
     这里通过使用向量容器顺序存储二叉树的各个节点
     左节点的存储索引下标：2*i+1
     右节点的存储索引下标：2*i+2
     这里约定存储#是标识该节点是空节点
     */
    TreeNode *createBinaryTree(vector<int>list, int start) {
        if (list[start] == '#') {
            return NULL;
        }
        TreeNode *root = new TreeNode(list[start]);
        int lnode = 2*start + 1;
        int rnode = 2*start + 2;
        if (lnode > list.size() - 1) {//判断当前索引是否超过数组的长度
            root->left = NULL;
        } else {
            root->left = createBinaryTree(list, lnode);
        }
        if (rnode > list.size() - 1) {
            root->right = NULL;
        } else {
            root->right = createBinaryTree(list, rnode);
        }
        return root;
    }
    //这个是对上面的一个更简洁的写法
    TreeNode *createBinaryTreeByLevel(vector<int> elem, int curindex){
        if (curindex > elem.size() - 1 || elem[curindex] == NULL)
            return NULL;
        TreeNode* node = new TreeNode(elem[curindex]);
        //left
        node->left = createBinaryTreeByLevel(elem, 2 * curindex + 1);
        //right
        node->right = createBinaryTreeByLevel(elem, 2 * curindex + 2);
        
        return node;
    }
    TreeNode* Insert(TreeNode* root,int data) {
        if(root == NULL) { // empty tree
            root = new TreeNode(data);
            }
            // if data to be inserted is lesser, insert in left subtree.
            else if(data != -1) {
                root->left = Insert(root->left,data);
            }
            // else, insert in right subtree.
            else {
                root->right = Insert(root->right,data);
            }
        return root;
    }
    
    //他么的，搞了半天也没搞明白递归构造二叉树是怎么弄的，先搁置下往下进行，说明递归还是没有学明白，明天继续吧
    
    /*
     计算二叉树的节点个数 = 根节点 + 左子树节点个数 + 右子树节点个数
     */
    int treeNodeCount(TreeNode *head) {
        if (head == NULL) return 0;
        
        return 1 + treeNodeCount(head->left) + treeNodeCount(head->right);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "============\n";
    Solution solu;
//    vector<int> datanum = {1,2,3,4,5,NULL,6,NULL,NULL,7,8,NULL,NULL,NULL,NULL};
//    solu.root = solu.createBinaryTreeByLevel(datanum, 0);
    vector<int> datanum = {1, 2, 3, 4, 5,'#',6,'#','#', 7 ,8};
        //1,2,3,4,5,'#',6,'#','#',7,8,'#','#','#','#' 后面的#可省略
    solu.root = solu.createBinaryTree(datanum, 0);
    
//    solu.root = NULL;  // Creating an empty tree
//        /*Code to test the logic*/
//    solu.root = solu.Insert(solu.root,1);
//    solu.root = solu.Insert(solu.root,2);
//    solu.root = solu.Insert(solu.root,3);
//    solu.root = solu.Insert(solu.root,4);
//    solu.root = solu.Insert(solu.root,5);
//    solu.root = solu.Insert(solu.root,-1);
//    solu.root = solu.Insert(solu.root,6);
//    solu.root = solu.Insert(solu.root,-1);
//    solu.root = solu.Insert(solu.root,-1);
//    solu.root = solu.Insert(solu.root,7);
//    solu.root = solu.Insert(solu.root,8);
//    solu.root = solu.Insert(solu.root,-1);
//    solu.root = solu.Insert(solu.root,-1);
//    solu.root = solu.Insert(solu.root,-1);
//    solu.root = solu.Insert(solu.root,-1);

    int treeNodeCount = solu.treeNodeCount(solu.root);
    cout<<"二叉树的节点个数 = "<<treeNodeCount<<endl;
    
    cout<<"前序遍历结果：";
    cout<<endl;
    vector<int> preResult = solu.preorderTraversal(solu.root);
    for (int i = 0; i <preResult.size(); i++) {
        cout<< preResult.at(i)<< " ";
    }
    cout<<endl;
    vector<int> preResult2 = solu.preorderTraversal2(solu.root);
    for (int i = 0; i <preResult2.size(); i++) {
        cout<< preResult2.at(i)<< " ";
    }
    cout<<endl;
    cout<<"中序序遍历结果：";
    cout<<endl;
    vector<int> inResult = solu.inorderTraversal(solu.root);
    for (int i = 0; i < inResult.size(); i++) {
        cout<< inResult.at(i)<< " ";
    }
    cout<<endl;
    vector<int> inResult2 = solu.inorderTraversal2(solu.root);
    for (int i = 0; i < inResult2.size(); i++) {
        cout<< inResult2.at(i)<< " ";
    }
    cout<<endl;
    cout<<"后序遍历结果：";
    cout<<endl;
    vector<int> postresult = solu.postorderTraversal(solu.root);
    for (int i = 0; i < postresult.size(); i++) {
        cout<< postresult.at(i)<< " ";
    }
    cout<<endl;
    vector<int> postresult2 = solu.postorderTraversal2(solu.root);
    for (int i = 0; i < postresult2.size(); i++) {
        cout<< postresult.at(i)<< " ";
    }
   
    cout << endl;
    std::cout << "============\n";
    return 0;
}

