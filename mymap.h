#include<iostream>
#include <stack>

class myex{
    private:
        int id;
    public:
        myex(int k){id=k;}
};

template<class T>
class mymap
{
    struct node
    {
        T data;
        std::string key;
        node* left;
        node* right;
        long height;
    };

    node* root;

    void makeEmpty(node* t)
    {
        if(t == NULL)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }

    node* insert(T x, const string &s, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->key = s;
            t->height = 0;
            t->left = t->right = NULL;
        }
        else if(s < t->key)
        {
            t->left = insert(x,s, t->left);
            if(height(t->left) - height(t->right) == 2)
            {
                if(s < t->left->key)
                    t = singleRightRotate(t);
                else
                    t = doubleRightRotate(t);
            }
        }
        else if(s > t->key)
        {
            t->right = insert(x,s, t->right);
            if(height(t->right) - height(t->left) == 2)
            {
                if(s > t->right->key)
                    t = singleLeftRotate(t);
                else
                    t = doubleLeftRotate(t);
            }
        }

        t->height = max(height(t->left), height(t->right))+1;
        return t;
    }

    node* singleRightRotate(node* &t)
    {
        node* u = t->left;
        t->left = u->right;
        u->right = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(u->left), t->height)+1;
        return u;
    }

    node* singleLeftRotate(node* &t)
    {
        node* u = t->right;
        t->right = u->left;
        u->left = t;
        t->height = max(height(t->left), height(t->right))+1;
        u->height = max(height(t->right), t->height)+1 ;
        return u;
    }

    node* doubleLeftRotate(node* &t)
    {
        t->right = singleRightRotate(t->right);
        return singleLeftRotate(t);
    }

    node* doubleRightRotate(node* &t)
    {
        t->left = singleLeftRotate(t->left);
        return singleRightRotate(t);
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }
    node* GetLeft()
    {
        return this->left;
    }
    node* GetRight()
    {
        return this->right;
    }

    node* remove(const string &s, node* t)
    {
        node* temp;

        // Element not found
        if(t == NULL)
            return NULL;

        // Searching for element
        else if(s < t->key)
            t->left = remove(s, t->left);
        else if(s > t->key)
            t->right = remove(s, t->right);

        // Element found
        // With 2 children
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->key = temp->key;
            t->right = remove(t->key, t->right);
        }
        // With one or zero child
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
        if(t == NULL)
            return t;

        t->height = max(height(t->left), height(t->right))+1;

        // If node is unbalanced
        // If left node is deleted, right case
        if(height(t->left) - height(t->right) == 2)
        {
            // right right case
            if(height(t->left->left) - height(t->left->right) == 1)
                return singleLeftRotate(t);
            // right left case
            else
                return doubleLeftRotate(t);
        }
        // If right node is deleted, left case
        else if(height(t->right) - height(t->left) == 2)
        {
            // left left case
            if(height(t->right->right) - height(t->right->left) == 1)
                return singleRightRotate(t);
            // left right case
            else
                return doubleRightRotate(t);
        }
        return t;
    }

    long height(node* t)
    {
        return (t == NULL ? -1 : t->height);
    }

    long getBalance(node* t)
    {
        if(t == NULL)
            return 0;
        else
            return height(t->left) - height(t->right);
    }

    bool myfind(const string &s, node *t)
    {
        if(t == NULL)
        {
            return false;
        }
        else{
            if(s  == t->key)
            {
                return true;
            }
            else{
                if(s > t->key)
                {
                    return myfind(s,t->right);
                }
                else{
                    return myfind(s,t->left);
                }
            }
        }
    }
    T myfindData(const string &s, node *t)
    {
        if(t == NULL)
        {
            throw myex(1);
            return NULL;
        }
        else{
            if(s  == t->key)
            {
                return t->data;
            }
            else{
                if(s > t->key)
                {
                    return myfindData(s,t->right);
                }
                else{
                    return myfindData(s,t->left);
                }
            }
        }
    }

    void inorder(node* t)
    {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->key << " " << t->data << endl;

        inorder(t->right);
    }
    int mycount(node* t)
    {
        if(t->left == NULL  && t->right != NULL)
            return 1 + mycount(t->right);
        if(t->left != NULL  && t->right == NULL)
            return 1 + mycount(t->left);
        if(t->left == NULL  && t->right == NULL)
            return 1;
        return mycount(t->left) + mycount(t->right)+1;
    }


public:

    mymap()
    {
        root = NULL;
    }

    void insert(const string &s,T x)
    {
        root = insert(x,s, root);
    }

    void remove(const string &s)
    {
        root = remove(s, root);
    }

    void display()
    {
        inorder(root);
    }
    int mysize()
    {
       return mycount(root);
    }
    bool find(const string &s)
    {
        return myfind(s,root);
    }
    T GetDataTree(const string &s)
    {
        return myfindData(s,root);
    }
    class bstit {
private:
    // Stack to store the nodes
    // of BST
    stack<node*> q;

public:
    // Constructor for the class
    bstit(mymap<T> l)
    {
        // Initializing stack
        node* curr = l.root;
        while (curr != NULL)
            q.push(curr), curr = curr->left;
    }

    // Function to return
    // current element iterator
    // is pointing to
    node* curr()
    {
        return q.top();
    }

    // Function to iterate to next
    // element of BST
    void next()
    {
        node* curr = q.top()->right;
        q.pop();
        while (curr != NULL)
            q.push(curr), curr = curr->left;
    }

    // Function to check if
    // stack is empty
    bool isEnd()
    {
        return !(q.size());
    }
    string GetKey()
    {
        return (*curr()).key;
    }
    T GetData()
    {
        return (*curr()).data;
    }
};

// Function to iterator to every element
// using iterator
void iterate(bstit it)
{
    while (!it.isEnd())
        cout << it.curr()->data << " ", it.next();
}
};
