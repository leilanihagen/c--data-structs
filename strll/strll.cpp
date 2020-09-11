#include <iostream>
#include <cstring>
#include "strll.h"

namespace DataStructs{

STRLLNode::STRLLNode(const char str[]){
  char* dataNonConst = (char*)str;
  data = new char[strlen(dataNonConst) + 1];
  strncpy(data, dataNonConst, (strlen(dataNonConst) + 1));
  next = NULL;
}
STRLL::STRLL(const char str[]){
  char* dataNonConst = (char*)str;
  head->data = new char[strlen(dataNonConst) + 1];
  strncpy(head->data, dataNonConst, (strlen(dataNonConst) + 1));
  head->next = NULL;
  headDataNeedsInit = false;
  return;
}
STRLL::STRLL() : data(), next(NULL), headDataNeedsInit(true) {}
//STRLL::~STRLL(){
//  DestroyList(head);
//}
//STRLL& STRLL::operator=(const STRLL& object){
//  STRLL& nonConstObj = (STRLL&)object;
//  // Check if head == object, if so return
//  // Create buffer copy of list "object"
//  if(head != &object){
//    DestroyList(head);
//    head = DuplicateList(&nonConstObj);
//    return *head;
//   }
////  STRLL* listCopy = DuplicateList(&nonConstObj);
////  // Delete head list
////  DestroyList(head);
////  // Set *head = buffer copy
////  head = listCopy;
////  //return *head
////  return *head;
//}
//STRLL::STRLL(const STRLL& object){
//  STRLL& nonConstObj = (STRLL&)object;
//  head = DuplicateList(&nonConstObj);
//}

STRLL STRLL::DuplicateList(){
  return *DuplicateList(head);
}
STRLLNode* STRLL::DuplicateList(STRLLNode* node){
  if(node == NULL){
    return NULL;
  }

  STRLLNode* dupeNode = new STRLLNode(node->data);
  dupeNode->next = DuplicateList(node->next);
  return dupeNode;
}

void STRLL::Append(const char data[]){
  char* dataNonConst = (char*)data;
  if(headDataNeedsInit){
    head->data = new char[strlen(dataNonConst) + 1];
    strncpy(head->data, dataNonConst, (strlen(dataNonConst) + 1));
    head->next = NULL;
    headDataNeedsInit = false;
    return;
  }
  Append(head, dataNonConst);
}
void STRLL::Append(STRLLNode* node, char data[]){
  if(node->next == NULL){
    STRLLNode* newNode = new STRLLNode;
    newNode->data = new char[strlen(data) + 1];
    strncpy(newNode->data, data, (strlen(data) + 1)); // +1 for null terminator.
    node->next = newNode;
    newNode->next = NULL;
  }
  else{
    Append(node->next, data);
  }
}
void STRLL::DestroyThisList(){
  DestroyList(head);
}
void STRLL::DestroyList(STRLLNode* node){
  if(node == NULL){
    return;
  }
  if(node->next != NULL){
    DestroyList(node->next);
  }
  delete[] node;
  node = NULL;
}
void STRLL::PrintNodes(){
  PrintNodes(head);
}
void STRLL::PrintNodes(STRLLNode* node){
  if(node == NULL){
    return;
  }
  std::cout << node->data << std::endl;
  PrintNodes(node->next);
}

int STRLL::AppendUnique(const char str[]){
  char* strNonConst = (char*)str;
  return AppendUnique(head, strNonConst);
}
int STRLL::AppendUnique(STRLLNode* node, char str[]){
  if(node == NULL){
    return 1; // Error code 1 == did not append.
  }

  if(strcmp(node->data, str) == 0){
    return 1;
  }

  if(node->next == NULL){
    STRLLNode* unique = new STRLLNode;
    unique->data = new char[strlen(str) + 1];
    strncpy(unique->data, str, (strlen(str) + 1));
    node->next = unique;
    unique->next = NULL;
    return 0; // Successfully appended unique.
  }

  AppendUnique(node->next, str);
}

void STRLL::MoveTailToHead(){
  if(head == NULL or head->next == NULL){
    // Nothing to move, list contains 1 node.
    return;
  }

  STRLLNode* oldHead = head;
  STRLLNode* secondToLast = GetSecondToLast(head);
  STRLLNode* newHead = secondToLast->next;
  secondToLast->next = NULL; // New end of list.
  newHead->next = oldHead;
  head = newHead;
}
STRLLNode* STRLL::GetSecondToLast(STRLLNode* node){
  // We know here that list has at least 2 nodes...
  if(node->next->next == NULL){
    return node;
  }
  return GetSecondToLast(node->next);
}

}
