#include "bst.h"

TNODE* search(TNODE *root, char *name) {
	while (root) {
    if (strcmp(name, root->data.name) == 0) 
       return root;
    else if (strcmp(name, root->data.name)<0) 
       root = root->left;
    else 
      root = root->right;  
  }
  return NULL;
}

void insert(TNODE **rootp, char *name, float score) {
		RECORD r;
		r.score = score;
		strncpy(r.name, name, 40);
		
    TNODE *np = (TNODE*) malloc(sizeof(TNODE));
    np -> data = r;
	 
	 if (*rootp == NULL) { 
	 *rootp = np; }
  else {
    TNODE *tnp = *rootp;
    while (1) {
      if (strcmp(name,tnp->data.name) == 0) {
          printf("\nThe same key value is found");
      }
      else if (strcmp(name , tnp->data.name) < 0 ) {
         if (tnp->left == NULL) {
           tnp->left = np; 
		   break;
         }
         else tnp = tnp->left;
      }   
      else {
         if (tnp->right == NULL) {
            tnp->right = np;
          break;
         }    
         else tnp = tnp->right;
      }
    }
    }
}

void delete(TNODE **rootp, char *name) {
	TNODE *tnp = *rootp, *ptnp = NULL, *smallest_node;
  while (tnp != NULL && strcmp(name, tnp->data.name) != 0) {
    ptnp = tnp;
    tnp = (strcmp(name, tnp->data.name) < 0) ? tnp->left : tnp->right;
  }
  
  if (tnp == NULL) {  // not found
    printf("Not found");
  }
  else { // found
  
    if (tnp->right == NULL) {
      if (ptnp == NULL) {
        *rootp = tnp->left;
      } 
      else {
        if (ptnp->left == tnp)
          ptnp->left = tnp->left;
        else
          ptnp->right = tnp->left;
      }
    }
    else {
      smallest_node = extract_smallest_node(&tnp->right);
      if (ptnp == NULL) {
        *rootp = smallest_node;
      }
      else {
        if (ptnp->left == tnp)
      	ptnp->left = smallest_node;
        else
      	ptnp->right = smallest_node;
      }
      smallest_node->left = tnp->left;
      smallest_node->right = tnp->right; 
    }
    tnp = NULL;  
  
  
  }  
}

TNODE *extract_smallest_node(TNODE **rootp) {
	 if (*rootp == NULL) return NULL;
  
  TNODE *tnp = *rootp, *ptnp = NULL;
  while (tnp->left != NULL) {
    ptnp = tnp;
    tnp = tnp->left;
  }
  
  if (tnp->right == NULL) {
  if (ptnp == NULL)
    *rootp = NULL;
    else 
     ptnp->left = NULL;
  } else {
    if (ptnp == NULL)
    *rootp = tnp->right;
  else 
    ptnp->left = tnp->right;
  }
  return tnp;
}


void display_inorder(TNODE *root) {
    if (root) {
        if (root->left) display_inorder(root->left);
        printf("%-15s%3.1f\n", root->data.name, root->data.score);
        if (root->right) display_inorder(root->right);
    }
}

void clean_tree(TNODE **rootp) {
    TNODE *root = *rootp;
    if (root) {
        if (root->left)
            clean_tree(&root->left);
        if (root->right)
            clean_tree(&root->right);
        free(root);
    }
    *rootp = NULL;
}