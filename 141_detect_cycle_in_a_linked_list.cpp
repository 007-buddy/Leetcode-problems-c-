/* 
implementing a two pointer approach to detect a cycle in a linked list
the slow pointer moves one step at a time while the fast pointer moves 
two steps at a time till they meet or the fast pointer reaches the end of the list.
*/ 
   
// time complexity: O(n) and space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

struct Node {
        int data;
        struct Node* next;
    };

bool has_cycle(Node* head) {
  Node* slow=head;
  Node* fast=head;
  while(fast!=NULL && fast->next!=NULL){
    slow=slow->next;
    fast=fast->next->next;
    if(slow==fast)return true;
    
  }
  return false;
}