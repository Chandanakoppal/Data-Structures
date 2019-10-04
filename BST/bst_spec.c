#include <assert.h>
#include<stdio.h>
#include "bst.c"

void test_addition()
{
	BST b = bst_new();
	BST *bst = &b;
	bst = bst_add_node(bst, 50);
	assert (bst_count(bst) == 1);
	
	bst = bst_add_node(bst, 30);
	bst = bst_add_node(bst, 70);
	bst = bst_add_node(bst, 100);
	bst = bst_add_node(bst, 200);
	bst = bst_add_node(bst, 200);
    bst = bst_add_node(bst, 90);
    bst = bst_add_node(bst, 1);
	assert (bst_count(bst) == 7);
	
	uint32_t count = bst_count(bst);
    printf("Number of elements: ");
    printf("%d\n", count);

    printf("Inorder\n");
	in_order(bst);
	printf("\n");

	printf("Preorder\n");
	pre_order(bst);
	printf("\n");

	printf("Postorder\n");
	post_order(bst);
	printf("\n");
	
	printf("Ascending Order\n");
	ascending(bst);
	printf("\n");
	
	printf("Descending Order\n");
	descending(bst);
	printf("\n");
	
    bst=bst_delete(bst, 20);
    
	assert (bst_lookup(bst, 30));
	
	int32_t key = 36;
	uint32_t bs = bst_lookup(bst, key);
	if(bs==1){
		printf("%d  is present\n", key);
	}
	 else{
	 	printf("%d is NOT present\n",key);
	 }
	 
	 printf("Height of the tree:");
	 height(bst);	 
	 printf("\n");
	 
	printf("Terminal count of the tree:");
	terminalNodeCount(bst);
	
	printf("\n");
	printf("Maximum element is ");
	max(bst);
	
	printf("\n");
	printf("Minimum element is ");
	min(bst);

}

void test_deletion()
{
	BST b = bst_new();
	BST *bst = &b;
	bst = bst_add_node(bst, 50);
	assert (bst_count(bst) == 1);
	
	bst = bst_add_node(bst, 30);
	bst = bst_add_node(bst, 70);
    
	bst_delete(bst, 20);
}

int main()
{
	test_addition();
	test_deletion();
	return 0;
}

