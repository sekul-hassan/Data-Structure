#include<bits/stdc++.h>
using namespace std;
#define nl NULL
#define N '\n'
struct node
{
    int data;
    node *left;
    node *right;
};
node *creat_node(int item)
{
    node *new_node = new node();
    if(new_node==nl){
        cout<<"Error could not create node"<<endl;
        exit(1);
    }
    new_node->data = item;
    new_node->left = nl;
    new_node->right = nl;
    return new_node;
}
void add_l_child(node* a,int data)
{
    a->left = creat_node(data);
}
void add_r_child(node *b,int data)
{
    b->right = creat_node(data);
}
node *creat_tree()
{
    node *a = creat_node(2);
    node *b = creat_node(4);
    node *c = creat_node(7);
    node *d = creat_node(2);
    node *e = creat_node(4);
    node *f = creat_node(5);
    node *g = creat_node(9);
    node *h = creat_node(8);
    node *i = creat_node(8);
    node *j = creat_node(7);

    a->left = b;
    b->left = d;
    d->left = g;
    d->right = h;
    h->right = j;
    a->right = c;
    c->left = e;
    c->right = f;
    f->left = i;
    return a;
}
void pri_order(node *root)
{
    cout<<root->data<<" ";
    if(root->left!=nl){
        pri_order(root->left);
    }
    if(root->right!=nl){
        pri_order(root->right);
    }
}
void in_order(node *root)
{
    if(root->left!=nl){
        in_order(root->left);
    }
    cout<<root->data<<" ";
    if(root->right!=nl){
        in_order(root->right);
    }
}
void post_order(node *root)
{
    if(root->left!=nl){
        post_order(root->left);
    }
    if(root->right!=nl){
        post_order(root->right);
    }
    cout<<root->data<<" ";
}
int main()
{
    node *root ;
    root = creat_tree();
    /// pre-order print
    pri_order(root);
    cout<<N;
    /// post order
    post_order(root);
    cout<<N;
    /// in order
    in_order(root);
    cout<<N;
    return 0;

}
/*

                2
               /  \
              4     7
             /     /  \
            2     4     5
           / \          /
          9   8         8
                \
                  7


*/ 
