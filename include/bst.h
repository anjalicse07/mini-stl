#pragma once
#include"treenode.h"
#include"less.h"

template<typename T,typename compare=Less<T>>
class BST
{
    private:
    TreeNode<T>* root;
    size_t sz;
    compare comp;

    TreeNode<T>* insert(TreeNode<T>* node,const T& value)
    {
       if(node==nullptr)
       {
        sz++;
        return new TreeNode<T>(value);
       }
       if(comp(value,node->data))
       {
        node->left=insert(node->left,value);
        if (node->left != nullptr)
            node->left->parent = node;
       }
       else if(comp(node->data,value))
       {
        node->right=insert(node->right,value);
        if (node->right != nullptr)
            node->right->parent = node;
       }
       return node;
    }

    TreeNode<T>* findnode(TreeNode<T>* node,const T& value)const
    {
        if(node==nullptr)
        {
            return nullptr;
        }
        if(comp(value,node->data))
        {
            return findnode(node->left,value);
        }
        if(comp(node->data,value))
        {
            return findnode(node->right,value);
        }
        return node;

    }

    TreeNode<T>* minNode(TreeNode<T>* node)const
    {
        if(node==nullptr)
        {
            return nullptr;
        }
        while(node->left!=nullptr)
        {
            node=node->left;
        }
        return node;
    }

    TreeNode<T>* maxNode(TreeNode<T>* node)const
    {
        if(node==nullptr)
        {
            return nullptr;
        }
        while(node->right!=nullptr)
        {
            node=node->right;
        }
        return node;
    }

    void clear(TreeNode<T>* node)
    {
        if(node==nullptr)
        return;

        clear(node->left);
        clear(node->right);

        delete node;

    }

    TreeNode<T>* clone(TreeNode<T>* node)
    {
     if(node==nullptr)
     return nullptr;
     TreeNode<T>* newnode=new TreeNode<T>(node->data);

     newnode->left=clone(node->left);
     newnode->right=clone(node->right);
     
     if(newnode->left)
     newnode->left->parent=newnode;
     if(newnode->right)
     newnode->right->parent=newnode;

     return newnode;
    }

    TreeNode<T>* erasenode(TreeNode<T>* node,const T& value)
    {
        if(node==nullptr)
        {
            return nullptr;
        }
        if(comp(value,node->data))
        {
            node->left=erasenode(node->left,value);

            if(node->left)
            {
                node->left->parent=node;
            }
            return node;
        }
        else if(comp(node->data,value))
        {
            node->right=erasenode(node->right,value);

            if(node->right)
            {
                node->right->parent=node;
            }
            return node;
        }
        else
        {
            if(node->left==nullptr && node->right==nullptr)
            {
                delete node;
                sz--;
                return nullptr;
            }
            if(node->right==nullptr)
            {
                TreeNode<T>* temp=node->left;
                delete node;
                sz--;
                return temp;
            }
            if(node->left==nullptr)
            {
                TreeNode<T>* temp=node->right;
                delete node;
                sz--;
                return temp;
            }
            else
            {
                TreeNode<T>* succ=minNode(node->right);
                node->data=succ->data;
                node->right=erasenode(node->right,succ->data);
                if(node->right)
                node->right->parent=node;
                return node;
            }
        }
    }

    public:
    BST():root(nullptr),sz(0),comp(){}
    ~BST()
    {
        clear();
    }

    void insert(const T& value)
    {
        root=insert(root,value);
    }

    size_t size()const
    {
        return sz;
    }

    bool empty()const
    {
        return sz==0;
    }

    bool contains(const T& value)const
    {
        return findnode(root,value)!=nullptr;
    }

    const T& minimum() const
    {
        return minNode(root)->data;
    }

    const T& maximum() const
    {
        return maxNode(root)->data;
    }

    void clear()
    {
        clear(root);
        root=nullptr;
        sz=0;
    }

    BST(const BST&other):root(clone(other.root)),sz(other.sz),comp(other.comp)
    {
    }

    BST& operator=(const BST& other)
    {
        if(this!=&other)
        {
            clear();

            root=clone(other.root);
            sz=other.sz;
            comp=other.comp;
        }
        return* this;
    }

    void erase(const T& value)
    {
        root=erasenode(root,value);
        if(root)
        root->parent=nullptr;
    }

    public:

    class iterator
    {
        private:
        TreeNode<T>* current;
    
        public:

        iterator(TreeNode<T>* node =nullptr):current(node)
        {}


        T& operator*()const
        {
            return current->data;
        }

        T* operator->()const
        {
            return &(current->data);
        }

        bool operator==(const iterator& other)const
        {
            return current==other.current;
        }

        bool operator!=(const iterator& other)const
        {
            return current!=other.current;
        }

        iterator& operator++()
        {
            if(current==nullptr)
            return *this;

            if(current->right)
            {
                current=current->right;
                while(current->left!=nullptr)
                {
                    current=current->left;
                }
                return *this;
            }
            TreeNode<T>* parent=current->parent;
            while(parent && current==parent->right)
            {
                current=parent;
                parent=parent->parent;
            }
            current=parent;
            return *this;
        }

        iterator operator++(int)
        {
            iterator temp=*this;
            ++(*this);
            return temp;
        }

        iterator& operator--()
        {
            if(current==nullptr)
            {
                return *this;
            }
            if(current->left)
            {
                current=current->left;
                while(current->right)
                {
                    current=current->right;
                }
                return *this;
            }
            
            TreeNode<T>* parent=current->parent;

            while(parent && current==parent->left)
            {
                current=parent;
                parent=parent->parent;
            }
            current=parent;

            return *this;
        }

        iterator operator--(int)
        {
            iterator temp=*this;
            --(*this);
            return temp;
        }
    };
        iterator begin() const
        {
            return iterator(minNode(root));
        }

        iterator end() const
        {
            return iterator(nullptr);
        }

        iterator find(const T& value) const
        {
            return iterator(findnode(root,value));
        }
};

