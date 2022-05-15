#include <iostream>
#include <bits/stdc++.h>
using namespace std;



template<class t>
class BSTNode
{
public:
    t data;
    BSTNode* right,* left;
};

//class with all used functions .
template<class t>
class BSTFCI
{
public:
    BSTNode<t>* root;
public:
    BSTFCI()
    {
        root = NULL;
    }




    BSTNode<t>* insert(t item, BSTNode<t>* node)
    {
        ///create root...
        if (node == NULL)
        {
            node = new BSTNode<t>;
            node->data = item;
            node->left = node->right = NULL;
        }
///if given data > parent data, we put it at right
        else if (item > node->data)
            node->right = insert(item, node->right);

///if given data < parent data, we put it at left
        else if (item < node->data)
            node->left = insert(item, node->left);

        return node;
    }

    //to access at main
    void create(t item)
    {
        root = insert(item, root);
    }

    ///Pre-order (print root -> left -> right)
   void preOrder(BSTNode<t> *p)
   {
       if(p!=NULL)
       {
           cout<<p->item<<" ";
           preOrder(p->left);
           preOrder(p->right);
       }
   }


    //The function Compute the "height" of a tree. Height is the number of nodes along the longest path from the root node down to the farthest leaf node.
    template<class t2>
    int checkHeightBalance(BSTNode<t2>* node);

    //Function returns true if BST balanced.
    template<class t2>
    bool balanced( BSTNode<t2> *root);


};


template<class T2>
int checkHeightBalance(BSTNode<T2>* node)
{

    if(node == NULL)
        return 0;
    else{
        int t = 1 + max(checkHeightBalance(node->left),checkHeightBalance(node->right));
        return t;
    }


}

//Function returns true if BST balanced.
template<class T2>
bool balanced( BSTNode<T2> *root)
{
    int lefthight,righthight;

    if(root == NULL)
        return 1;


    lefthight = checkHeightBalance(root->left);
    righthight = checkHeightBalance(root->right);
    //difference between left and right must be between 1 and -1
    int d = lefthight - righthight;
    if( (d > -1 && d< 1) && balanced(root->left) && balanced(root->right))
        return 1;
    //otherwise tree not balanced
    return 0;
}
int main() {



    BSTFCI <int> * t = new BSTFCI <int>();
    t ->create(5);
    t ->create(7);
    t ->create(4);
    t ->create(20);
    t ->create(6);

    t ->create(1);



    if(balanced(t->root))
    {
        cout<<"Balanced\n";
    }else{
        cout<<"NotBalanced\n";
    }
    return 0;
}
