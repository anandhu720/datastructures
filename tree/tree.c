#include <stdio.h>
#include <stdlib.h>
#include "arrayqueue.h"

struct node *root = NULL;

//creating tree
void create_tree()
{
    struct node *p, *t;
    int x;
    struct queue q;
    create(&q, 100);

    //entering root node
    printf("enter the value of root node\n");
    scanf("%d", &x);
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->leftchild = root->rightchild = NULL;
    enqueue(&q, root);

    //entering left and right node
    while (!isEmpty(q))
    {
        p = dequeue(&q);
        printf("enter the left child of %d\n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->leftchild = t;
            enqueue(&q, t);
        }
        printf("enter the right child of %d\n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->rightchild = t;
            enqueue(&q, t);
        }
    }
}

//dislaying tree using preorder
void preorder(struct node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->leftchild);
        preorder(p->rightchild);
    }
}

//dsplaying tree using inorder
void inorder(struct node *p)
{
    if (p != NULL)
    {
        inorder(p->leftchild);
        printf("%d ", p->data);
        inorder(p->rightchild);
    }
}

//displaying tree using postorder
void postorder(struct node *p)
{
    if (p != NULL)
    {
        postorder(p->leftchild);
        postorder(p->rightchild);
        printf("%d ", p->data);
    }
}

//counting number of nodes in a tree
int count_node(struct node *p)
{
    int x, y;
    if (p)
    {
        x = count_node(p->leftchild);
        y = count_node(p->rightchild);
        return x + y + 1;
    }
    return 0;
}

//counting number of nodes having two children in a tree
int count_node2(struct node *p)
{
    int x, y;
    if (p)
    {
        x = count_node2(p->leftchild);
        y = count_node2(p->rightchild);
        if (p->leftchild && p->rightchild)
            return x + y + 1;
        return x + y;
    }
    return 0;
}

//sum of all elements in a tree
int sum(struct node *p)
{
    int x, y;
    if (p)
    {
        x = sum(p->leftchild);
        y = sum(p->rightchild);
        return x + y + p->data;
    }
    return 0;
}

//height of the tree
int height(struct node *p)
{
    int x = 0, y = 0;
    if (p == NULL)
        return 0;
    x = height(p->leftchild);
    y = height(p->rightchild);
    if (x > y)
        return x + 1;
    return y + 1;
}

int main()
{
    create_tree();

    printf("%d\n", count_node(root));
    printf("%d\n", count_node2(root));
    printf("%d\n", sum(root));

    return 0;
}