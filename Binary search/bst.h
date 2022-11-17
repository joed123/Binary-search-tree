

#ifndef __BST_H
#define __BST_H


struct bst;


struct bst* bst_create();
void bst_free(struct bst* bst);
int bst_size(struct bst* bst);
void bst_insert(struct bst* bst, int key, void* value);
void bst_remove(struct bst* bst, int key);
void* bst_get(struct bst* bst, int key);


int bst_height(struct bst* bst);
int bst_path_sum(struct bst* bst, int sum);
int bst_range_sum(struct bst* bst, int lower, int upper);


#endif
