#include<stddef.h>
#include<stdint.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include<limits.h>
#include "bst.h"

BST bst_new()
{
	BST tree = {NULL,0};
	return tree;
}

static TreeNode* _make_new_node(int32_t element)
{
	TreeNode *node = (TreeNode*)malloc(sizeof(TreeNode));
	node->data = element;
	node->left = NULL;
	node->right = NULL;
	return node;
}

uint32_t bst_count(BST *tree)
{
	assert(tree!= NULL);
	return tree->mass;
	
}

BST* bst_add_node(BST *tree, int32_t element)
{
	assert(tree!=NULL);
	TreeNode *cur, *parent;
	cur = parent = tree->root;
	while(cur!= NULL && cur->data!=element)
	{
		parent = cur;
		if(element<cur->data){
			cur = cur->left;
		}
		else if(element>cur->data){
			cur = cur->right;
		}
	}
	if(cur==NULL){
		TreeNode *tnode = _make_new_node(element);
		if(parent==NULL){
			tree->root = tnode;
		}
		else if(element<parent->data){
			parent->left = tnode;
		}
		else if(element>parent->data){
			parent->right = tnode;
		}
		++tree->mass;
		}
		return tree;
	}

static TreeNode* _findmin_(TreeNode *node)
{
	if(node->left==NULL)
	{
		return node;
	}
	else{ 
		return(_findmin_(node->left));
        }
}


uint32_t bst_lookup(BST *tree, int32_t key)
{
	assert(tree!=NULL);
	TreeNode *cur = tree->root;
	while(cur!=NULL && cur->data!=key){
		if(key<cur->data){
			cur = cur->left;
		}
		else if(key>cur->data){
			cur = cur->right;
		}
	}
	return(cur!=NULL);
}

static TreeNode* _delete_(BST *tree, TreeNode *node, int32_t key)
{
	TreeNode *temp;
	if(node==NULL){
		return node;
	}
	else if(key<node->data){
		node->left=_delete_(tree,node->left,key);
	}
	else if(key>node->data){
		node->left=_delete_(tree,node->right,key);
    }
    else if(node->left && node->right){
       temp = _findmin_(node->right);
       node->data = temp->data;
       node->right = _delete_(tree, node->right,node->data);
    }
    else
    {
    	temp=node;
    	if(node->right==NULL){
    		node = node->left;
    	}
    	else{
    		node = node->right;
    	}
    	free(temp);
    	--tree->mass;
    }
    return node;
}


BST* bst_delete(BST *tree, int32_t element)
{
	assert(tree!=NULL);
	tree->root = _delete_(tree, tree->root, element);
	return tree;
}


static void _inorder_(TreeNode *node)
{
	if(node)
	{
		_inorder_(node->left);
		printf("%d\t", node->data);
		_inorder_(node->right);
	}
}

BST* in_order(BST *tree)
{
	assert(tree->root!=NULL);
	_inorder_(tree->root);
}

static void _preorder_(TreeNode *node)
{
	if(node)
	{
		printf("%d\t", node->data);
		_inorder_(node->left);
		_inorder_(node->right);
	}
}

BST* pre_order(BST *tree)
{
	assert(tree->root!=NULL);
	_preorder_(tree->root);
}

static void _postorder_(TreeNode *node)
{
	if(node)
	{
		_inorder_(node->left);
		_inorder_(node->right);
		 printf("%d\t", node->data);
	}
}

BST* post_order(BST *tree)
{
	assert(tree->root!=NULL);
	_postorder_(tree->root);
}

BST* ascending(BST *tree)
{
	assert(tree->root!=NULL);
	_inorder_(tree->root);
}

static void descend(TreeNode *node)
{
	if(node)
	{
		descend(node->right);
		printf("%d\t", node->data);
		descend(node->left);
	}
}

BST* descending(BST *tree)
{
	assert(tree->root!=NULL);
	descend(tree->root);
}


static int32_t findHeight(TreeNode *temp){  
      if(temp)
	  {
	  
	    int leftHeight = 0, rightHeight = 0;  
        if(temp->left != NULL)  
            leftHeight = findHeight(temp->left);  
          
       
        if(temp->right != NULL)  
            rightHeight = findHeight(temp->right);  
          
        int max = (leftHeight > rightHeight) ? leftHeight : rightHeight;  
          
        return (max + 1);  
    }  
}  

BST* height(BST *tree)
{
	assert(tree->root!=NULL);
	int32_t h = findHeight(tree->root);
	printf("%d",h);
}


uint32_t getLeafCount(TreeNode* node) 
{ 
  if(node == NULL)        
    return 0; 
  if(node->left == NULL && node->right==NULL)       
    return 1;             
  else 
    return getLeafCount(node->left)+ 
           getLeafCount(node->right);       
} 

BST* terminalNodeCount(BST *tree)
{
	assert(tree->root!=NULL);
	int32_t h = getLeafCount(tree->root);
	printf("%d",h);
}

int32_t findMax(TreeNode* root) 
{ 
    if (root == NULL) 
      return INT_MIN; 
   int res = root->data; 
    int lres = findMax(root->left); 
    int rres = findMax(root->right); 
    if (lres > res) 
      res = lres; 
    if (rres > res) 
      res = rres; 
    return res; 
} 

BST* max(BST *tree)
{
	assert(tree->root!=NULL);
	int32_t a = findMax(tree->root);
	printf("%d",a);
}

int32_t findMin(TreeNode* root) 
{ 
    if (root == NULL) 
      return INT_MAX; 
   int res = root->data; 
    int lres = findMin(root->left); 
    int rres = findMin(root->right); 
    if (lres < res) 
      res = lres; 
    if (rres < res) 
      res = rres; 
    return res; 
} 

BST* min(BST *tree)
{
	assert(tree->root!=NULL);
	int32_t a = findMin(tree->root);
	printf("%d",a);
}















