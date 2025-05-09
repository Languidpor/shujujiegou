/*
* SplayTree.h
*
* Modified by haifeng on 2023-4-17
* ----------
* Reference:
* �˿��� �����ݽṹ��(C++���԰�) P.208
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
    //���� BinaryNode �������ǰ��, ���߷ŵ� SplayTree �������. ���������������.
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
        //makeEmpty( );//����ʹ��ϵͳĬ�ϵ���������, ����������.
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

     * �ڲ���ǰӦ������Splay Tree, �����������, �Ų���.
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
     * ��Ϊ���������������е���Сֵ�Ƶ��������ĸ����.
     * Ϊ��ƽ����, Ӧ�ý���ʹ������������Сֵ�������������ֵ
     * remove ��Ҫ�޸�!!!
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
            {//����������ȡ��С��Ԫ�����t��ָ����ֵ, Ȼ�����������ɾ����ֵ.
                t->element = findMin(t->right)->element;
                remove(t->element, t->right);
            }
            else
            {//����һ�����ӻ�û�ж���
                BinaryNode* oldNode = t;
                t = (t->left != NULL) ? t->left : t->right;
                //ע���������t->left==NULL �� t->right==NULL, �� t Ҳ�ǿ�ָ��
                //��ô����Ļ�������.
                if (t != NULL)
                {
                    t->parent = oldNode->parent;
                }
                //��Ҫ����һЩ parent �Ĺ�ϵ.
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
    //������ָ��洢�� _find_parent ��
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
        //ʹ�� unordered_map ��ʹ�ô�ӡ���� level �����ź����
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
            //����ҪС��
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


    //��leftChild��ָ�Ľ��ҵ� p ��ָ�������.
    //������ p->left==NULL, ��Ȼ leftChild ҲҪ�ǿ�
    //ע�� p->left �Ľ����Ϣ�ᶪʧ
    //leftChild->parent �Ľ����ϢҲ�ᶪʧ.
    void attachAsLeftChild(BinaryNode* p, BinaryNode* leftChild) 
    {
        if (leftChild != NULL)
        {
            p->left = leftChild;
            leftChild->parent = p;
        }
    }

    //��leftChild��ָ�Ľ��ҵ� p ��ָ�����ұ�.
    //������ p->right==NULL
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
        //Ŀ���ǽ� v ������ root λ��.
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
                    p->left = v->right;//V��������A�ҵ�p����������
                    if (v->right != NULL)
                    {//��A�ǿ�, ������丸���Ϊ���ڵ�p
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
                    //ע������� v->left ������ NULL
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

                //���϶���, ������ v ����չ
                //ע�⵱ gg==NULL ʱ, ��������
                //���� v!=root, ���Կ���ִ������� isLeftChild ����

                if (isLeftChild(v))
                {
                    if (isLeftChild(p))
                    {
                        /*//zig-zig : һ����
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
                        /*// zig-zag : ֮����, ˫��ת
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
                        /*//zag-zag : һ����
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
                        /*//zag-zig : ֮����
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
                //gg ������� g �ĸ��׽��. �� gg->left �� gg->right �� g
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
                    //break;//�������ɾ��!!!, ��ΪҪ��������� p �� g
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
