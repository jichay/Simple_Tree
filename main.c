#include <stdio.h>
#include <stdlib.h>


//struct of node
struct node{
	int val;
	struct node *fg;
	struct node *fd;
};
typedef struct node node;

/**
 * @brief create new tree node
 * @param value the content of the node
 * @return the new node created
 */
node * create_node(int value){
	node * n = (node*)malloc(sizeof(node));
	n->val = value;
	n->fg = NULL;
	n->fd = NULL;
	return n;
}

/**
 * @brief add node to the tree  
 * @param a tree root
 * @param n new node to add
 * @return the root
 */
node * add_node(node * a, node * n){
	if (a == NULL) return n;
	if (n->val < a->val)
		a->fg  = add_node(a->fg, n);
	else if (n->val > a->val)
		a->fd = add_node(a->fd, n);   
	return a;
}

/**
 * @brief print the tree left content root and right content of the tree
 * @param t root of the tree
 */
void print_tree(node * t){
	if(t != NULL){
		print_tree(t->fg);
		printf("|%d|",t->val);
		print_tree(t->fd);
	}
}

int main(int argc, char **argv)
{
	node * t = NULL;
	t = add_node(t,create_node(5));
	t = add_node(t,create_node(12));
	t = add_node(t,create_node(42));
	t = add_node(t,create_node(4));
	t = add_node(t,create_node(2));
	print_tree(t);
	return 0;
}
