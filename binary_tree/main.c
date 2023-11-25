#include <stdio.h>
#include <stdlib.h>

#define ELEM_MOD "%d"
typedef int ELEM_T;

typedef struct node{
	ELEM_T data;
	struct node *left_son;
	struct node *right_son;
} Node;

int tree_push(Node *ptr_root, ELEM_T new_elem);
int delete_tree(Node *ptr_root);
int in_order(Node *ptr_root);

int main()
{
	Node root = {50, NULL, NULL};
	Node *ptr_root = &root;
	
	for (int i = 0; i < 10; i++)
	{
		tree_push(ptr_root, rand() % 1000);
	}
	printf("\n");

	in_order(ptr_root);
	printf("\n");

	delete_tree(ptr_root);
}

int tree_push(Node *ptr_root, ELEM_T new_elem)
{
	if ((new_elem > ptr_root->data))
	{
		if (ptr_root->right_son == NULL)
		{
			printf("[" ELEM_MOD "]", new_elem);
			ptr_root->right_son = (Node*)calloc(1,sizeof(Node));
			
			(ptr_root->right_son)->data      = new_elem;
			(ptr_root->right_son)->left_son  = NULL;
			(ptr_root->right_son)->right_son = NULL;
		}
		else
			tree_push(ptr_root->right_son, new_elem);
	}
	else if ((new_elem < ptr_root->data))
	{
		if (ptr_root->left_son == NULL)
		{
			printf("[" ELEM_MOD "]", new_elem);
			ptr_root->left_son = (Node*)calloc(1,sizeof(Node));
			
			(ptr_root->left_son)->data      = new_elem;
			(ptr_root->left_son)->left_son  = NULL;
			(ptr_root->left_son)->right_son = NULL;
		}
		else
			tree_push(ptr_root->left_son, new_elem);
	}
	
	return 0;
}

int delete_tree(Node *ptr_root)
{
	if (ptr_root->left_son != NULL)
	{
		if ((ptr_root->left_son)->left_son != NULL | (ptr_root->left_son)->right_son != NULL)
			delete_tree(ptr_root->left_son);

		free(ptr_root->left_son);
		ptr_root->left_son = NULL;
	}
	
	if (ptr_root->right_son != NULL)
	{
		if ((ptr_root->right_son)->left_son != NULL | (ptr_root->right_son)->right_son != NULL)
			delete_tree(ptr_root->right_son);

		free(ptr_root->right_son);
		ptr_root->right_son = NULL;
	}

	return 0;
}

int in_order(Node *ptr_root)
{
	if (ptr_root->left_son != NULL)
		in_order(ptr_root->left_son);
	
	if (ptr_root->right_son != NULL)
		in_order(ptr_root->right_son);

	printf("{" ELEM_MOD "}", ptr_root->data);
	
	return 0;
}

int bin_tree_search(Node *ptr_root, ELEM_T s_elem)
{
	if (ptr_root->data == s_elem)
		return 1;
	
	if (s_elem > ptr_root->data && ptr_root->right_son != NULL)
		bin_tree_search(ptr_root->right_son, s_elem);
	else if (s_elem < ptr_root->data && ptr_root->left_son != NULL)
		bin_tree_search(ptr_root->left_son, s_elem);
	else
		return 0;
}

