/*
* SplayTree.h
*
* Modified by haifeng on 2023-4-17
* ----------
* Reference:
* 邓俊辉 《数据结构》(C++语言版) P.208
*
* Here the following code is based on class BinarySearchTree
** 
*/
#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#include "dsexceptions.h"
#include <iostream>    // For NULL
//#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

// Based on
// BinarySearchTree class
//
// CONSTRUCTION: with ITEM_NOT_FOUND object used to signal failed finds
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// void remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// Comparable findMin( )  --> Return smallest item
// Comparable findMax( )  --> Return largest item
// boolean isEmpty( )     --> Return true if empty; else false
// void makeEmpty( )      --> Remove all items
// void printTree( )      --> Print tree in sorted order
// ******************ERRORS********************************
// Throws UnderflowException as warranted


// based on class BinarySearchTree
template <typename Comparable>
class SplayTree
{
private:
    //这里 BinaryNode 必须放在前面, 或者放到 SplayTree 类的外面. 否则编译会给出错误.
    struct BinaryNode
    {
        Comparable element;
        BinaryNode* left;
        BinaryNode* right;
        BinaryNode* parent;//Note it will be used by SplayTree, while BinarySearchTree and AVL tree generally will not use it.

        BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt, BinaryNode* p)
            : element(theElement), left(lt), right(rt), parent(p) { }
    };

public:
    SplayTree() :root(NULL), _size(0)
    {
    }

    SplayTree(const SplayTree& rhs) : root(NULL)
    {
        *this = rhs;
    }

    /**
     * Destructor for the tree
     */
    ~SplayTree()
    {
        //makeEmpty( );//不如使用系统默认的析构函数, 否则有问题.
    }

    const Comparable& getRootElement() const
    {
        return root->element;
    }


    /**
     * Find the smallest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable& findMin() const
    {
        if (isEmpty())
        {
            throw UnderflowException();
        }
        return findMin(root)->element;
    }

    /**
     * Find the largest item in the tree.
     * Throw UnderflowException if empty.
     */
    const Comparable& findMax() const
    {
        if (isEmpty())
        {
            throw UnderflowException();
        }
        return findMax(root)->element;
    }

    /**
     * Returns true if x is found in the tree.
     */
    bool contains(const Comparable& x) const
    {
        return contains(x, root);
    }

    BinaryNode* findParent(const Comparable& x)
    {
        BinaryNode* t = root;
        _findParent(x, t);
        return _find_parent;
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
     * It can be determined by comparing root with NULL
     * or _size (is it equal to 0).
     */
    bool isEmpty() const
    {
        return root == NULL;
    }

    /**
     * Print the tree contents in sorted order.
     */
    void printTree(ostream& out = cout) const
    {
        if (isEmpty())
        {
            out << "Empty tree" << endl;
        }
        else
        {
            printTree(root, out);
        }
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty()
    {
        makeEmpty(root);
        _size = 0;
    }

    /**
     * getSizeOfSplayTree()
     * Return the number of elements in the Tree.
     */
    int getSizeOfNodes() const
    {
        return _size;
    }

    /**
     * Insert x into the tree; duplicates are ignored.
     */
    BinaryNode* insert(const Comparable& x)
    {
        BinaryNode* _parent;
        if (_size == 0)
        {
            _parent = NULL;
        }
        else if (_size == 1)
        {
            _parent = root;
        }
        else
        {
            _parent = NULL;
        }
        _parent = findParent(x);
        BinaryNode* p;
        p = insert(x, root, _parent);
        return p;
    }

    /**
     * Insert x in Splay Tree
     * Method 1
     * First, insert x in Binary Search Tree by insert method of BST.
     * Second, splay it.
     */
    BinaryNode* insertInSplayTree(const Comparable& x)
    {
        BinaryNode* p;
        p = insert(x);
        root = splay(p, root);
        return root;
    }

    /**
     * Insert x in Splay Tree
     * Method 2
     * by using the method searchInSplayTree for Splay Tree.
     * It is better than the above method

     * 在插入前应该搜索Splay Tree, 如果不在树中, 才插入.
     */
    BinaryNode* insertInSplayTreeBySearch(const Comparable& x)
    {
        if (!root) {
            return root = new BinaryNode(x, NULL, NULL, NULL);
        }
        BinaryNode* p;
        p = insert(x);
        root = splay(p, root);
        return root;
    }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove(const Comparable& x)
    {
        remove(x, root);
    }

    /**
     * Deep copy.
     */
    const SplayTree& operator=(const SplayTree& rhs)
    {
        if (this != &rhs)
        {
            makeEmpty();
            root = clone(rhs.root);
            _size = rhs._size;
        }
        return *this;
    }

    /**
     * search method in Splay Tree
     */
    BinaryNode* searchInSplayTree(const Comparable& x)
    {
        BinaryNode* p = searchInSplayTree(x, root);
        if (p != NULL)
        {
            root = splay(p, root);
        }
        return root;
    }

    //------------private methods------------

private:

    BinaryNode* root;
    BinaryNode* _find_parent;//for function findParent(x)
    int _size;

    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    BinaryNode* insert(const Comparable& x, BinaryNode*& t, BinaryNode*& theParent)
    {
        if (t == NULL)
        {
            t = new BinaryNode(x, NULL, NULL, theParent);
            
            _size++;
            return t;
        }
        else if (x < t->element)
        {
            insert(x, t->left, t);
        }
        else if (t->element < x)
        {
            insert(x, t->right, t);
        }
        else
        {
            // Duplicate; do nothing
            
        }
        return t;
    }


    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     * Remark: This method should be improved.
     * 因为这里用了右子树中的最小值移到了子树的根结点.
     * 为了平衡树, 应该交替使用右子树的最小值和左子树的最大值
     * remove 需要修改!!!
     */
    void remove(const Comparable& x, BinaryNode*& t)
    {
        if (t == NULL)
        {
            return;   // Item not found; do nothing
        }
        if (x < t->element)
        {
            remove(x, t->left);
        }
        else if (t->element < x)
        {
            remove(x, t->right);
        }
        else
        {//x==t->element
            if (t->left != NULL && t->right != NULL) // Two children
            {//从右子树中取最小的元素替代t所指结点的值, 然后从右子树中删除此值.
                t->element = findMin(t->right)->element;
                remove(t->element, t->right);
            }
            else
            {//仅有一个儿子或没有儿子
                BinaryNode* oldNode = t;
                t = (t->left != NULL) ? t->left : t->right;
                //注意上面如果t->left==NULL 且 t->right==NULL, 则 t 也是空指针
                //那么下面的会有问题.
                if (t != NULL)
                {
                    t->parent = oldNode->parent;
                }
                //还要加入一些 parent 的关系.
                delete oldNode;
                _size--;
            }
        }
    }


    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
     /*
    BinaryNode * findMin( BinaryNode *t ) const
    {
        if( t == NULL )
        {
            return NULL;
        }
        else if( t->left == NULL )
        {
            return t;
        }else
        {
            return findMin( t->left );
        }
    }*/

    BinaryNode* findMin(BinaryNode* t) const
    {
        if (t != NULL)
        {
            while (t->left != NULL)
            {
                t = t->left;
            }
            return t;
        }
        else
        {
            return NULL;
        }
    }
    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    BinaryNode* findMax(BinaryNode* t) const
    {
        if (t != NULL)
        {
            while (t->right != NULL)
            {
                t = t->right;
            }
            return t;
        }
        else
        {
            return NULL;
        }

    }


    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the subtree.
     */
     /****** NONRECURSIVE VERSION*************************
     bool contains( const Comparable & x, BinaryNode *t ) const
     {
         if( t == NULL )
         {
             return false;
         }
         else if( x < t->element )
         {
             return contains( x, t->left );
         }
         else if( t->element < x )
         {
             return contains( x, t->right );
         }
         else
         {
             return true;    // Match
         }
     }
     ****** NONRECURSIVE VERSION*************************/
     /****** NONRECURSIVE VERSION*************************/
    bool contains(const Comparable& x, BinaryNode* t) const
    {
        while (t != NULL)
        {
            if (x < t->element)
            {
                t = t->left;
            }
            else if (t->element < x)
            {
                t = t->right;
            }
            else
            {
                return true;    // Match
            }
        }
        return false;   // No match
    }

    //find parent of element x from position t.
    //父结点的指针存储到 _find_parent 中
    bool _findParent(const Comparable& x, BinaryNode* pt)
    {
        BinaryNode* t = pt;
        if (t == NULL)
        {
            return false;
        }
        while (t != NULL)
        {
            if (x < t->element)
            {
                _find_parent = t;
                t = t->left;
            }
            else if (t->element < x)
            {
                _find_parent = t;
                t = t->right;
            }
            else
            {
                _find_parent = t->parent;
                return true;    // Match, find
            }
        }
        return false;   // No match
    }
    /*****************************************************/


    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty(BinaryNode*& t)
    {
        if (t != NULL)
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            t->parent = NULL;
            delete t;
        }
        //t = NULL;
    }

    /**
     * Internal method to print a subtree rooted at t in sorted order.
     */
    void printTree(BinaryNode* t, ostream& out) const
    {
        //使用 unordered_map 会使得打印出的 level 不是排好序的
        //unordered_map<int, vector<BinaryNode *> > m;
        map<int, vector<BinaryNode*> > m;
        printBinaryTree(t, m, 0);
        for (auto& i : m)
        {
            out << " Level " << i.first << ":\t";
            for (auto& j : i.second)
            {
                out << j->element << "  ";
            }
            out << endl;
        }
        out << "\nThe tree contains " << getSizeOfNodes() << " elements." << endl;
        out << "------*---*---*---*---*------\n" << endl;
    }

    void printBinaryTree(BinaryNode*  t, map<int, vector<BinaryNode*> >& m, int level) const
    {
        if (t != NULL)
        {
            ++level;

            if (t->left != NULL)
            {
                printBinaryTree(t->left, m, level);
            }
            if (t->right != NULL)
            {
                printBinaryTree(t->right, m, level);
            }
            //这里要小心
            m[level].push_back(t);
        }
    }


    /**
     * Internal method to clone subtree.
     */
    BinaryNode* clone(BinaryNode* t) const
    {
        if (t == NULL)
        {
            return NULL;
        }
        else
        {
            return new BinaryNode(t->element, clone(t->left), clone(t->right), t->parent);
        }
    }

    /********** Methods of Splay Tree ******************/

    BinaryNode* searchInSplayTree(const Comparable& x, BinaryNode* t) const
    {
        while (t != NULL)
        {
            if (x < t->element)
            {
                t = t->left;
            }
            else if (t->element < x)
            {
                t = t->right;
            }
            else
            {
                return t;    // Match
            }
        }
        return t;   // No match, t is NULL
    }


    //Add by xhf
    bool isLeftChild(BinaryNode* t) const
    {
        if (t->parent == NULL)
        {
            return false;
        }
        return (t->parent->left) == t;
    }
    bool isRightChild(BinaryNode* t) const
    {
        if (t->parent == NULL)
        {
            return false;
        }
        return (t->parent->right) == t;
    }


    //将leftChild所指的结点挂到 p 所指结点的左边.
    //条件是 p->left==NULL, 当然 leftChild 也要非空
    //注意 p->left 的结点信息会丢失
    //leftChild->parent 的结点信息也会丢失.
    void attachAsLeftChild(BinaryNode* p, BinaryNode* leftChild) 
    {
        if (leftChild != NULL)
        {
            p->left = leftChild;
            leftChild->parent = p;
        }
    }

    //将leftChild所指的结点挂到 p 所指结点的右边.
    //条件是 p->right==NULL
    void attachAsRightChild(BinaryNode* p, BinaryNode* rightChild) 
    {
        if (p->right == NULL && rightChild != NULL)
        {
            p->right = rightChild;
            rightChild->parent = p;
        }

    }

protected:
    //V is the node that has just been accessed, and we should splay it.
    BinaryNode* splay(BinaryNode* v, BinaryNode*& root)
    {
        if (v == NULL) return NULL;

        if (v == root)
        {
            return root;
        }

        BinaryNode* p;// parent of v
        BinaryNode* g;// grandfather of v
        BinaryNode* gg;// parent of grandfather

        //cout<<"the parent is: "<<v->parent->element<<endl;

        p = v->parent;
        if (p == NULL || p == root)
        {
            g = NULL;
            gg = NULL;
        }
        else
        {
            g = p->parent;
            gg = (g == root ? NULL : g->parent);
        }

        int w = 0;
        //BinaryNode* gtmp;
        //目标是将 v 提升到 root 位置.
        while (v != root)
        {
            w++;
            cout << "------splay times : " << w << "------" << endl;

            printTree(root, cout);
            if (p == root)
            {
                /*
                       root  == p (parent of v)             v
                      /                            ==>     / \
                     v                                    B   p
                    / \                                      /
                   B   A                                    A


                  root  == p (parent of v)                  v <--root
                    \                             ==>      / \
                     v                                    p   A
                    / \                                    \
                   B   A                                    B
                */

                if (p->left == v)
                {
                    p->left = v->right;//V的右子树A挂到p的左子树上
                    if (v->right != NULL)
                    {//若A非空, 则更新其父结点为现在的p
                        v->right->parent = p;
                    }
                    v->right = p;//v->right=root;
                    p->parent = v;//root->parent=v;
                    v->parent = NULL;
                    root = v;
                }
                else if (p->right == v)
                {
                    p->right = v->left;
                    //注意下面的 v->left 可能是 NULL
                    if (v->left != NULL)
                    {
                        v->left->parent = p;
                    }
                    v->left = p;//v->right=root;
                    p->parent = v;//root->parent=v;
                    v->parent = NULL;
                    root = v;
                }
            }
            else
            {

                //自上而下, 反复对 v 做伸展
                //注意当 gg==NULL 时, 下面会出错
                //由于 v!=root, 所以可以执行下面的 isLeftChild 函数

                if (isLeftChild(v))
                {
                    if (isLeftChild(p))
                    {
                        /*//zig-zig : 一字形
                              g          v
                             /            \
                            p      ==>     p
                           /                \
                          v                  g
                        */
                        v->parent = gg;

                        p->left = v->right;
                        v->right = p;
                        p->parent = v;

                        g->left = p->right;
                        p->right = g;
                        g->parent = p;

                    }
                    else {
                        /*// zig-zag : 之字型, 双旋转
                          g           gg
                           \           \
                            p           v
                           /           / \
                          v           g   p
                         */

                        v->parent = gg;

                        p->left = v->right;
                        if (v->right != NULL)
                        {
                            v->right->parent = p;
                        }
                        v->right = p;
                        p->parent = v;

                        g->right = v->left;
                        if (v->left != NULL)
                        {
                            v->left->parent = g;
                        }
                        v->left = g;
                        g->parent = v;

                    }

                }
                else
                {// v is right child
                    if (isRightChild(p))
                    {
                        /*//zag-zag : 一字形
                              g                  v
                               \                /
                                p      ==>     p
                                 \            /
                                  v          g
                            */

                        v->parent = gg;

                        p->right = v->left;
                        if (v->left != NULL)
                        {
                            v->left->parent = p;
                        }
                        v->left = p;
                        p->parent = v;

                        g->right = p->left;
                        if (p->left != NULL)
                        {
                            p->left->parent = g;
                        }
                        p->left = g;
                        g->parent = p;

                    }
                    else {
                        /*//zag-zig : 之字型
                                  g        gg
                                 /          \
                                p             v
                                 \           / \
                                  v         p   g
                             */
                        v->parent = gg;

                        p->right = v->left;
                        if (v->left != NULL)
                        {
                            v->left->parent = p;
                        }
                        v->left = p;
                        p->parent = v;

                        g->left = v->right;
                        if (v->right != NULL)
                        {
                            v->right->parent = g;
                        }
                        v->right = g;
                        g->parent = v;

                    }
                }
                //gg 仍是最初 g 的父亲结点. 即 gg->left 或 gg->right 是 g
                //gg = gtmp;
                if (gg != NULL)
                {
                    if (gg->left == g)
                    {
                        gg->left = v;
                    }
                    else if (gg->right == g)
                    {
                        gg->right = v;
                    }
                    v->parent = gg;
                }
                else
                {
                    v->parent = NULL;
                    root = v;
                    //break;//这里必须删除!!!, 因为要更新下面的 p 和 g
                }
            }

            //updateHeight(g);
            //updateHeight(p);
            //updateHeight(v);
            p = v->parent;
            if (p == NULL || p == root)
            {
                g = NULL;
                gg = NULL;
            }
            else
            {
                g = p->parent;
                gg = (g == root ? NULL : g->parent);
            }

        }

        printTree(root, cout);

        delete p;
        delete g;
        delete gg;
        return v;
    }


};

#endif
