#ifndef NODES_H
#define NODES_H
#include "m_malloc.h"

typedef struct node_s {
    int data;
    struct node_s* left;
    struct node_s* right;
} node;

void insertData(node* Root,int d);

/* You have to use the standard libary for this */
#ifdef _INC_STDIO
void printNodes_i(node* Root,int level);
void printNodes(node* Root);
#endif

int nodeHeight_i(node* Root, int level);
int nodeHeight(node* Root);
node* findNode(node* Root,int val);
#endif
