/* NAME: Xudong Li
   NSID:xul395
   Student Number:11206927
*/

/* NAME:Tong Wang   
   NSID: tow087 
   Student Number: 11201222
   CMPT 332 Term 1 2019
*/

#include <stdio.h> 
#include <stdlib.h> 
#include "proc.h"
#include "priorityQ.h"
  
Node* newNode(struct proc *p) 
{ 
    Node* node = (Node*)malloc(sizeof(Node)); 
    node->process = p; 
    node->priority = p->priority; 
    node->next = NULL; 
    return node; 
} 
  
/*get head value*/
int peek(Node** head) 
{ 
    return (*head)->process; 
} 
  
/*remove and return head process*/
void pop(Node** head) 
{ 
    Node* temp = *head; 
    struct proc *tempProc = temp->process;
    (*head) = (*head)->next; 
    free(temp); 
    return tempProc;
} 
  
/*push processes in according to the priority*/
void push(Node** head, struct proc *p) 
{ 
    Node* temp = newNode(p); 
    Node* top = (*head); 

    if ((*head)->priority > p) { 
        temp->next = *head; 
        (*head) = temp; 
    } 
    else { 
        while (top->next != NULL && 
               top->next->priority < p) { 
            top = top->next; 
        } 
        temp->next = top->next; 
        top->next = temp; 
    } 
} 
  
int empty(Node** head) 
{ 
    return (*head) == NULL; 
} 

