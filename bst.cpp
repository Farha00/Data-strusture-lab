#include<iostream>
using namespace std;

class tree
{
    int data;
    tree* left, * right;

public:

    tree(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    tree* IndrScc(tree* root)
    {
        tree* curr = root;
        while (curr && curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }



    tree* remove(tree* root, int key)
    {
        if (key < root->data)
        {
            root->left = remove(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = remove(root->right, key);
        }
        else {
            if (root->left == NULL)
            {
                tree* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == NULL)
            {
                tree* temp = root->left;
                delete root;
                return temp;
            }
            else {
                tree* temp = IndrScc(root->right);
                root->data = temp->data;
                root->right = remove(root->right, temp->data);
            }
        }
        return root;
    }

    tree* insert(tree* root, int data)
    {
        if (root == NULL)
        {
            root = new tree(data);
            return root;
        }
        if (data <= root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);

        return root;
    }

    void insert(int data) {
        insert(this, data);
    }

    void inorder()
    {
        if (this->left != NULL)
            this->left->inorder();

        cout << this->data << " ";

        if (this->right != NULL)
            this->right->inorder();
    }


    void preorder()
    {
        cout << this->data << " ";

        if (this->left != NULL)
            this->left->preorder();

        if (this->right != NULL)
            this->right->preorder();
    }

    void postorder()
    {
        if (this->left != NULL)
            this->left->postorder();

        if (this->right != NULL)
            this->right->postorder();

        cout << this->data << " ";
    }


};

int main()
{
    tree* root = new tree(50);
    root->insert(12);
    root->insert(18);
    root->insert(6);
    root->insert(40);
    root->insert(2);
    cout << "Inorder traversal : ";
    root->inorder();
    cout << "\nPreorder traversal : ";
    root->preorder();
    cout << "\nPostorder traversal : ";
    root->postorder();
    root->insert(4);
    root->insert(15);
    cout << "\n\nNew Inorder : ";
    root->inorder();
    root = root->remove(root, 14);
    cout << "\n\nNew Inorder : ";
    root->inorder();

    return 0;
}