
#include <stdlib.h>
#include <assert.h>

#include "list.h"


struct node {
  void* val;
  struct node* next;
};


struct list {
  struct node* head;
};


struct list* list_create() {
  struct list* list = malloc(sizeof(struct list));
  list->head = NULL;
  return list;
}


void list_free(struct list* list) {
  assert(list);

 
  struct node* next, * curr = list->head;
  while (curr != NULL) {
    next = curr->next;
    free(curr);
    curr = next;
  }

  free(list);
}


void list_insert(struct list* list, void* val) {
  assert(list);

  struct node* node = malloc(sizeof(struct node));
  node->val = val;
  node->next = list->head;
  list->head = node;
}


int list_isempty(struct list* list) {
  assert(list);
  if (list->head) {
    return 0;
  } else {
    return 1;
  }
}


void* list_head(struct list* list) {
  assert(list);

  if (list->head) {
    return list->head->val;
  } else {
    return NULL;
  }
}


void list_remove_head(struct list* list) {
  assert(list);

  if (list->head) {
    struct node* old_head = list->head;
    list->head = old_head->next;
    free(old_head);
  }
}
