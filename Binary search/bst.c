/*
 * Name: Joseph Di Lullo
 */

#include <stdlib.h>

#include "bst.h"
#include "stack.h"


struct bst_node {
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};



struct bst {
  struct bst_node* root;
};

struct bst* bst_create() {
  struct bst* bst_root = malloc(sizeof(struct bst));            
  bst_root->root = NULL;    
  return bst_root;
}

void bst_free_helper(struct bst_node* bst_node){
  if ((bst_node -> right == NULL)&&(bst_node -> left != NULL)){
    bst_free_helper(bst_node->left);                                     
    free(bst_node);
    return;
  }
  else if ((bst_node -> left == NULL)&&(bst_node -> right != NULL)){        
    bst_free_helper(bst_node->right);
    free(bst_node);
    return;
    }
  else if ((bst_node -> left != NULL)&&(bst_node -> right != NULL)){        
     bst_free_helper(bst_node->right);
    bst_free_helper(bst_node->left);
    free(bst_node);
    return;
  }
  else{
    return;
      }     


}

void bst_free(struct bst* bst) {
  if (bst -> root == NULL){
    free(bst);                                                    
  }
  else{
    bst_free_helper(bst -> root);
    free(bst);
  }
    return;
}

int bst_size_helper(struct bst_node* bst_node){
  if ((bst_node -> right == NULL)&&(bst_node -> left != NULL)){
    return 1 + bst_size_helper(bst_node->left);
  }
  else if ((bst_node -> left == NULL)&&(bst_node -> right != NULL)){             
    return 1 + bst_size_helper(bst_node->right);
  }
  else if ((bst_node -> left != NULL)&&(bst_node -> right != NULL)){
    return 2 + bst_size_helper(bst_node->right) + bst_size_helper(bst_node->left);          
  }
  else{
    return 0;
  }     


}


int bst_size(struct bst* bst) {
  int counter = 0;
  if (bst -> root == NULL){                                                              
      return counter;
}
  counter = bst_size_helper(bst -> root);                                                 
  return counter + 1;
}


void bst_insert(struct bst* bst, int key, void* value) {
  struct bst_node* bst_node = malloc(sizeof(struct bst_node));
  bst_node -> left = NULL;
  bst_node -> right = NULL;                             
  bst_node -> key = key;
  bst_node -> value = value;

if (bst -> root == NULL){
    bst -> root = bst_node;
  return;
}
struct bst_node* temppointer = bst -> root;                              
  while (1==1){                                                           
  if (temppointer -> key < key){                                         
    if (temppointer -> right == NULL){
      temppointer -> right = bst_node;                                     
      break;
  }
  else {
    temppointer = temppointer -> right;                                   
  }
}
else {
  if (temppointer -> left == NULL){
    temppointer -> left = bst_node;
    break;
  }
  else {
    temppointer = temppointer -> left;
  }
}
}
  return;
}

void bst_remove(struct bst* bst, int key) {

if (bst -> root == NULL){
  return;
}
struct bst_node* parent = NULL;
struct bst_node* succesor = NULL;
struct bst_node* succesorparent = NULL;
struct bst_node* temppointer = bst -> root;
int left = 0;
while (1==1){
  if (temppointer -> key == key){
    if ((temppointer -> right == NULL) && (temppointer -> left == NULL)){
      temppointer = NULL;
      if (left){
        parent -> left = NULL;
      }
      else {
        parent -> right = NULL;
      }
      return;
      }
    if (((temppointer -> right == NULL) && (temppointer -> left != NULL)) || ((temppointer -> right != NULL) && (temppointer -> left == NULL))){
          if (temppointer -> right != NULL){
            if (left){
            parent -> left = temppointer -> right;
            }
            else {
            parent -> right = temppointer -> right;
             }
          }
          else {
            if (left){
            parent -> left = temppointer -> left;
            }
            else {
            parent -> right = temppointer -> left;
             }
          }
        return;
    }
    else{
      succesor = temppointer;
      succesorparent = temppointer;
      succesor = succesor -> right;
      while (1 == 1){
        if (succesor -> left != NULL){
        succesorparent = succesor; 
        succesor  = succesor -> left;
        }
        else {
          break;
        }
      }
      succesor -> left = temppointer -> left;
      succesorparent -> left = succesor -> right;
      if (temppointer -> right != succesor){
        succesor -> right = temppointer -> right;
      }
      else succesor -> right = NULL;

      if (parent == NULL){
        bst-> root = succesor;
      }
      else{
        if (left){
          parent -> left = succesor;
        }
        else{
          parent -> right = succesor;
        }
      }
      free(temppointer);
      return;
    }
    }

if (temppointer -> key < key){
  if (temppointer -> right == NULL){
    return;
  }
  else {
    parent = temppointer;
    temppointer = temppointer -> right;
    left = 0;
  }
}
else {
  if (temppointer -> left == NULL){
    return;
  }
  else {
    parent = temppointer;
    temppointer = temppointer -> left;
    left = 1;
  }
}
}
  return;
}


void* bst_get(struct bst* bst, int key) {
  if (bst -> root == NULL){
  return NULL;
}

  struct bst_node* temppointer = bst -> root;
  while (1==1){
    if (temppointer -> key == key){
      return temppointer -> value;
    }
  if (temppointer -> key < key){
    if (temppointer -> right == NULL){
      return NULL;
  }
    else {
      temppointer = temppointer -> right;
    }
  }
  else {
    if (temppointer -> left == NULL){
      return NULL;
    }
    else {
      temppointer = temppointer -> left;
  }
}
}
  return NULL;
}


int maxDepth(struct bst_node* bst_node){
  int left = 0;
  int right = 0;
  if (bst_node -> left != NULL){
      left =  1 + maxDepth(bst_node -> left);
    }
  if (bst_node -> right != NULL){
    right = 1 + maxDepth(bst_node -> right);
    }
  if ((bst_node -> left == NULL) && (bst_node -> right == NULL)){
    return 0;
  }
  if (left > right){
    return left;
  }
  else {
    return right;
  }
}


 int bst_height(struct bst* bst) {
  int count = 0;
  if (bst -> root == NULL){
    return count;
  }
  count = maxDepth(bst -> root);
  return count;
 }




int bst_path_sum_helper(struct bst_node* bst_node, int sum){
  int ans = 0;
  int subsum = sum - bst_node->key;
  if (subsum == 0 && bst_node -> left == NULL && bst_node -> right == NULL){
    return 1;
  }
  if (bst_node -> left){
    ans = ans + bst_path_sum_helper(bst_node ->left, subsum);
  }
  if (bst_node -> right){
    ans = ans + bst_path_sum_helper(bst_node -> right, subsum);
  }
if (ans >= 1){
  return 1;
}
else {
  return 0;
}

}

int bst_path_sum(struct bst* bst, int sum) {
  return bst_path_sum_helper(bst -> root, sum);
}



int bst_range_sum_helper(struct bst_node* bst_node, int lower, int upper){
  int total = bst_node -> key;
  if ((bst_node -> right == NULL)&&(bst_node -> left != NULL)){
      total = bst_node ->key;
      if ((lower <= total)&&(upper >= total)){
        return total + bst_range_sum_helper(bst_node->left, lower, upper);
      }
      else if (lower <= total){
        return bst_range_sum_helper(bst_node->left, lower, upper);
      }
      else{
        return 0;
      }
  }
  
  else if ((bst_node -> left == NULL)&&(bst_node -> right != NULL)){
      total = bst_node ->key;
      if ((upper >= total) && (lower <= total)){
        return total + bst_range_sum_helper(bst_node->right, lower, upper);
      }
      else if (upper >= total){
        return bst_range_sum_helper(bst_node->right, lower, upper);
      }
    else {
        return 0;
      }
  }
      
  else if ((bst_node -> left != NULL)&&(bst_node -> right != NULL)){
    total = bst_node ->key;
    if ((upper >= total) && (lower <= total)){
      return total + bst_range_sum_helper(bst_node->right, lower, upper) + bst_range_sum_helper(bst_node->left, lower, upper);
    }
    else if (lower <= total){
        return bst_range_sum_helper(bst_node->left, lower, upper);
    }
    else if (upper >= total){
      return bst_range_sum_helper(bst_node->right, lower, upper);
    }
 }
  else{
      if ((upper >= total) && (lower <= total)){
        return total;
      }
      else{
        return 0;
      }
  } 

}



int bst_range_sum(struct bst* bst, int lower, int upper) {
  if (bst -> root == NULL){
    return 0;
  }
  return bst_range_sum_helper(bst -> root, lower, upper);

}


