#include <iostream>
/**
 * Definition for singly-linked list. */
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  bool hasDupelicates(ListNode* head) {
    ListNode* traverser = head;
    int prevVal = 0;
    bool foundDupe = false;
    
    do {
      prevVal = traverser->val;
      traverser = traverser->next;
      if(traverser != NULL && traverser->val == prevVal){
        foundDupe = true;
      }
    } while(traverser != NULL && foundDupe == false);
    
    if(foundDupe == true){
      return true;
    }
    return false;
  }
  ListNode* removeNumber(ListNode* node, int number){
    if(node == NULL){
      return NULL;
    }
    else if(node->val == number){
      node->next = removeNumber(node->next, number); // Remove all occurances step.
      ListNode* nodeNext = node->next;
      delete node;
      return nodeNext;
    }
    else{
      node->next = removeNumber(node->next, number);
      return node;
    }
  }
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if(hasDupelicates(head) == false){
      return head;
    }
    
    ListNode* prev = NULL;
    ListNode* curr = head;
    while(curr->next != NULL){
      prev = curr;
      curr = curr->next;
      
      if(prev->val == curr->val){
	// Remove prev node (ensures all occurance get deleted, as each will == prev):
        head = removeNumber(head, prev->val); // Should remove all occurances of number.
	// IF value prev pointer is changed, this doesn't change what the pointer to prev
	// from prevprevs->next is pointing to...
      }
    }
    return head;
  }
  void printList(ListNode* head){
    if(head == NULL){
      return;
    }

    std::cout << head->val << " ";
    printList(head->next);
  }
};
