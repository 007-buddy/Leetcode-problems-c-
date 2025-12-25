// reverse a linked list using iterative method
// taking threee pointers prev, curr and nextptrq   
//  time complexity: O(n) and space complexity: O(1)

#include<bits/stdc++.h>
using namespace std;

 struct Node {
     int data;
      Node* next;
  };
 
Node* reverse(Node* head) {
    Node* prev=NULL;
    Node* curr=head;
    Node* nextptr=NULL;
    while(curr!=NULL){
        nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    return prev;
    

}