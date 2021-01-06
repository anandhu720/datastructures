#include <iostream>
#include <stdio.h>
#include "arrayqueuecpp.h"

class tree
{
public:
    node *root;
    tree() { root = NULL; }
    void createtree();
    void preorder(node *p);
    void postorder(node *p);
    void inorder(node *p);
    void levelorder(node *p);
    void height(node *root);
};

void tree::createtree()
{
    node *p, *t;
    int x;
    queue q(100);

    //entering root node
    printf("enter the value of root node\n");
    scanf("%d", &x);
    root = new node;
    root->data = x;
    root->leftchild = root->rightchild = NULL;
    q.enqueue(root);

    //entering left and right node
    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("enter the left child of %d\n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->leftchild = t;
            q.enqueue(t);
        }
        printf("enter the right child of %d\n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->rightchild = t;
            q.enqueue(t);
        }
    }
}
