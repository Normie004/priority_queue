#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "pri_queue.h"
/** @file pri_queue.c */
static Node_ptr_t head = NULL;
/**
 * Insert a Node into a priority queue.
 * @param priority
 * @param data
 * @author vinayak mathur
 */

void PQ_insert(int priority, char * data) {
 //FIX THIS
    Node_ptr_t new_node = (Node_ptr_t)malloc(sizeof(Node_t));
    
    new_node->priority = priority;
    new_node->data = data;
    new_node->next =NULL;
    
    if(head==NULL || head->priority < priority){
        new_node->next = head;
        head = new_node;
        printf("inserted pri: %d, data: %c\n", priority,data);
        return;
    }
   
    
    Node_ptr_t current = head;
    while(current->next != NULL && current->next->priority >= priority) {
        current = current->next;
    }
    
    new_node->next = current->next;
    current->next = new_node;
    
     printf("inserted pri: %d, data: %c\n", priority,data);
          
        
}


/**
 * Delete and return the node with the highest priority.
 * @return The highest priority Node.
 */
Node_ptr_t PQ_delete() {
  //FIX THIS
    if (head == NULL) {
       return NULL;
    }
    Node_ptr_t highest_priority_node = head;
    head = head->next;
     printf("deleted from queue");
    return highest_priority_node;
   
}

/**
 * Do NOT modify this function.
 * @return A pointer to the head of the list.  (NULL if list is empty.)
 */
Node_ptr_t PQ_get_head() {
    return head;
}

/**
 * Do NOT modify this function.
 * @return the number of items in the queue
 */
int PQ_get_size() {
    int size = 0;
    Node_ptr_t tmp;
    for(tmp = head; tmp != NULL; tmp = tmp->next, size++)
        ;
    return size;
}


