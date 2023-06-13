#ifndef NODES_C
#define NODES_C
#include "nodes.h"

void insertData(node* Root,int d){
    node* new = m_malloc(sizeof(node));
    new->data = d;
    new->left = (void*) 0;
    new->right = (void*) 0;

    if (Root->left == (void*) 0){
        Root->left = new;
    } else {
        if (Root->right == (void*) 0){
            Root->right = new;
        } else {
            insertData(Root->left,d);
        }
    }
}

/* You have to use the standard libary for this */
#ifdef _INC_STDIO
void printNodes_i(node* Root,int level){
    printf("%d: %d\n",level,Root->data);
    if (Root->left != (void*) 0) {printNodes_i(Root->left,++level);}
    if (Root->right != (void*) 0) {printNodes_i(Root->right,++level);}
}

void printNodes(node* Root){
    printf("top: %d\n",Root->data);
    if (Root->left != (void*) 0) {printNodes_i(Root->left,1);}
    if (Root->right != (void*) 0) {printNodes_i(Root->right,1);}
}
#endif

int nodeHeight_i(node* Root, int level){
    if (Root->left != (void*) 0) {
        nodeHeight_i(Root->left,++level);
    }else{
        if (Root->right != (void*) 0) {
            nodeHeight_i(Root->right,++level);
        }else{
            return level;
        }
    }
}

int nodeHeight(node* Root){
    if (Root->left != (void*) 0) {
        nodeHeight_i(Root->left,2);
    }else{
        if (Root->right != (void*) 0) {
            nodeHeight_i(Root->right,2);
        }else{
            return 1;
        }
    }
}

node* findNode(node* Root,int val){
	if (Root->data == val){
		return Root;
	} else {
		if (Root->left != (void*) 0){
			if(findNode(Root->left,val) == (void*) 0){
				return findNode(Root->right,val);
			}
			return findNode(Root->left,val);
		}else{
			if (Root->right != (void*) 0){
				return findNode(Root->right,val);
			}else{
				return (void*) 0;
			}
		}
	}
	
	return (void*) 0;
}
#endif
