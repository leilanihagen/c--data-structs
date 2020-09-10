#include <iostream>
#include "cllnode.h"

namespace DataStructs{

CLL::CLL(int val){
  tail = new CLLNode;
  tail->data = val;
  tail->next = tail;
  tailDataNeedsInit = false;
}
CLL::CLL(){
  tail = new CLLNode;
  tail->next = tail;
  tailDataNeedsInit = true;
}
CLL::~CLL(){
  DestroyList(tail->next, tail);
//  CLLNode* current = tail->next;  
//  CLLNode* next;
//  while(current != tail){
//    next = current->next;
//    delete current;
//    current = next;
//  }
//  delete tail;
}
void CLL::DestroyList(CLLNode* head, CLLNode* tail){
  if(head != tail){
    DestroyList(head->next, tail);
  }
  delete head;
}

CLL::CLL(const CLL& object){
  CLL* newList = new CLL;
  if(object.tailDataNeedsInit){
    newList->tail = new CLLNode;
    newList->tail->next = tail;
    newList->tailDataNeedsInit = true;
  }
  else{
    newList->tailDataNeedsInit = false;
  }
  newList->tail = DuplicateList(object.tail);
}

CLL::CLLNode* CLL::DuplicateList(CLLNode* objTail){
  CLLNode* objHead = objTail->next;
  // Manually create newList's tail:
  CLLNode* newTail = new CLLNode;
  newTail->data = objTail->data;
  // Pass tail into implementation function:
  newTail->next = DuplicateListImpl(objHead, objTail, newTail);
  return newTail;
}
CLL::CLLNode* CLL::DuplicateListImpl(CLLNode* objHead, CLLNode* objTail, CLLNode* newObjTail){
  CLLNode*& traverser = objHead;
  if(traverser != objTail){
    CLLNode* newNode = new CLLNode;
    newNode->data = traverser->data;
    newNode->next = DuplicateListImpl(traverser->next, objTail, newObjTail);
    return newNode;
  }
  else{
    return newObjTail;
  }
}
CLL& CLL::operator=(const CLL& object){
//  CLL* buffer = new CLL;
//  buffer->tail = object.tail;
  // Make sure not assigning to self:
  if(this == &object){ // Superfluous but good so don't create whole new list in mem.
    return *this;
  }

// Create new list:
  CLL* newList = new CLL;
  newList->tail = DuplicateList(object.tail);
  DestroyList(this->tail->next, this->tail);
  this->tail = newList->tail;
  return *this;  
}
  
//CLLNode::~CLLNode(){
//  DestroyList(this); // LEFT OFF FRIDAY
//}
void CLL::Append(int data){
  if(tailDataNeedsInit){
    tail->data = data;
    tailDataNeedsInit = false;
    return;
  }
  CLLNode* newNode = new CLLNode;
  newNode->data = data;
  newNode->next = tail->next;
  tail->next = newNode;
  tail = newNode;
}

void CLL::Prepend(int data){
  if(tailDataNeedsInit){
    tail->data = data;
    tailDataNeedsInit = false;
    return;
  }
  CLLNode* newNode = new CLLNode;
  newNode->data = data;
  newNode->next = tail->next;
  tail->next = newNode;
}

void CLL::PrintNodes(){
  if(!tailDataNeedsInit){
    PrintNodes(tail->next);
  }
}
void CLL::PrintNodes(CLLNode* head){
  std::cout << head->data << std::endl;
  if(head != tail){
    PrintNodes(head->next);
  }
}
void CLL::MoveTailToHead(){
  tail = FindTailSuccessor(tail->next);
}
CLL::CLLNode* CLL::FindTailSuccessor(CLLNode* head){
  if(head->next == tail){
    return head;
  }
  return FindTailSuccessor(head->next);
}
 
void CLL::RemoveMiddleNodes(){
  CLLNode*& head = tail->next;
  ClearMiddle(head->next);
  head->next = tail;
}
void CLL::ClearMiddle(CLLNode* headNext){
  if(headNext == tail){
    return;
  }
  ClearMiddle(headNext->next);
  delete headNext;
}

//void CLLNode::DestroyThisList(){
//  DestroyList(this->next);
//}
//void CLLNode::DestroyList(CLLNode* node){
//  if(node == NULL){
//    return;
//  }
//  if(node->next != NULL){
//    DestroyList(node->next);
//  }
//  delete node;
//}
//void CLLNode::PrintNodes(){
//  PrintNodes(this);
//}
//void CLLNode::PrintNodes(CLLNode* node){
//  if(node == NULL){
//    return;
//  }
//  std::cout << node->data << std::endl;
//  PrintNodes(node->next);
//}

}
