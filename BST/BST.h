#include <iostream>
#include "Node.h"
using namespace std;
int c = 0;

template <class T>
class BST
{

    Node<T> *rt;
    int count;

    Node<T> *insertHelp(Node<T> *root, T item)
    {
        if (root == NULL)
        {
            root = new Node<T>(item);
            count++;
        }
        else if (item > root->value)
        {
            root->right = insertHelp(root->right, item);
        }
        else if (item < root->value)
        {
            root->left = insertHelp(root->left, item);
        }

        return root;
    }
    Node<T> *getMin(Node<T> *root)
    {
        // cout<<root->value<<endl;
        if (root == NULL)
            return NULL;
        if (root->left == NULL)
            return root;
        return getMin(root->left);
    }
    Node<T> *deleteMin(Node<T> *root)
    {
        if (root->left == NULL)
        {
            Node<T> *tmp = root;
            Node<T> *newroot = root->right;
            delete tmp;
            return newroot;
        }
        else
        {
            root->left = deleteMin(root->left);
            return root;
        }
    }
    bool findHelp(Node<T> *root, T item)
    {
        if (root == NULL)
        {
            return false;
        }
        else if (item > root->value)
        {
            return findHelp(root->right, item);
        }
        else if (item < root->value)
        {
            return findHelp(root->left, item);
        }
        else
        {
            return true;
        }
    }
    Node<T> *deleteHelp(Node<T> *root, T item)
    {
        if (root == NULL)
        {
            return NULL;
        }
        else if (item > root->value)
        {
            root->right = deleteHelp(root->right, item);
        }
        else if (item < root->value)
        {
            root->left = deleteHelp(root->left, item);
        }
        else
        {
            Node<T> *temp = root;
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                count--;
                return NULL;
            }
            else if (root->left == NULL)
            {
                root = root->right;
                delete temp;
                count--;
            }
            else if (root->right == NULL)
            {
                root = root->left;
                delete temp;
                count--;
            }
            else
            {
                Node<T> *tmp = getMin(root->right);
                root->value = tmp->value;
                root->right = deleteMin(root->right);
                count--;
            }
        }
        return root;
    }
    void preHelp(Node<T> *root)
    {
        if (root == NULL)
            return;
        cout << root->value << " ";
        preHelp(root->left);
        preHelp(root->right);
    }
    void postHelp(Node<T> *root)
    {
        if (root == NULL)
            return;
        postHelp(root->left);
        postHelp(root->right);
        cout << root->value << " ";
    }
    void inHelp(Node<T> *root)
    {
        if (root == NULL)
            return;
        inHelp(root->left);
        cout << root->value << " ";
        inHelp(root->right);
    }
    void printHelp(Node<T>* root)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->left==NULL&& root->right==NULL)
        {
            cout<<root->value<<" ";
            return;
        }
        cout<<root->value;
        cout<<"(";
        printHelp(root->left);
        cout<<",";
        printHelp(root->right);
        cout<<")";


    }

public:
    BST()
    {
        rt = NULL;
        count = 0;
    }
    void insert(T item)
    {
        rt = insertHelp(rt, item);
        count++;
    }
    bool find(T item)
    {
        return findHelp(rt, item);
    }
    void Delete(T item)
    {

        rt = deleteHelp(rt, item);
    }
    void preOrder()
    {
        preHelp(rt);
        cout << "\n";
    }
    void postOrder()
    {
        postHelp(rt);
        cout << "\n";
    }
    void inOrder()
    {
        inHelp(rt);
        cout << "\n";
    }
    void print()
    {
        cout<<"(";
        printHelp(rt);
        cout<<")";
        cout << "\n";

    }
};
