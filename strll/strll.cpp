#include <iostream>
#include <cstring>
#include "strllnode.h"

namespace DataStructs{

STRLLNode::STRLLNode(const char str[]){
  char* dataNonConst = (char*)str;
  this->data = new char[strlen(dataNonConst) + 1];
  strncpy(this->data, dataNonConst, (strlen(dataNonConst) + 1));
  this->next = NULL;
  headDataNeedsInit = false;
  return;
}
STRLLNode::STRLLNode() : data(), next(NULL), headDataNeedsInit(true) {}
//STRLLNode::~STRLLNode(){
//  DestroyList(this);
//}
//STRLLNode& STRLLNode::operator=(const STRLLNode& object){
//  STRLLNode& nonConstObj = (STRLLNode&)object;
//  // Check if this == object, if so return
//  // Create buffer copy of list "object"
//  if(this != &object){
//    DestroyList(this);
//    this = DuplicateList(&nonConstObj);
//    return *this;
//   }
////  STRLLNode* listCopy = DuplicateList(&nonConstObj);
////  // Delete this list
////  DestroyList(this);
////  // Set *this = buffer copy
////  this = listCopy;
////  //return *this
////  return *this;
//}
//STRLLNode::STRLLNode(const STRLLNode& object){
//  STRLLNode& nonConstObj = (STRLLNode&)object;
//  this = DuplicateList(&nonConstObj);
//}

STRLLNode STRLLNode::DuplicateList(){
  return *DuplicateList(this);
}
STRLLNode* STRLLNode::DuplicateList(STRLLNode* node){
  if(node == NULL){
    return NULL;
  }

  STRLLNode* dupeNode = new STRLLNode(node->data);
  dupeNode->next = DuplicateList(node->next);
  return dupeNode;
}

void STRLLNode::Append(const char data[]){
  char* dataNonConst = (char*)data;
  if(headDataNeedsInit){
    this->data = new char[strlen(dataNonConst) + 1];
    strncpy(this->data, dataNonConst, (strlen(dataNonConst) + 1));
    this->next = NULL;
    headDataNeedsInit = false;
    return;
  }
  Append(this, dataNonConst);
}
void STRLLNode::Append(STRLLNode* node, char data[]){
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
void STRLLNode::DestroyThisList(){
  DestroyList(this);
}
void STRLLNode::DestroyList(STRLLNode* node){
  if(node == NULL){
    return;
  }
  if(node->next != NULL){
    DestroyList(node->next);
  }
  delete[] node;
  node = NULL;
}
void STRLLNode::PrintNodes(){
  PrintNodes(this);
}
void STRLLNode::PrintNodes(STRLLNode* node){
  if(node == NULL){
    return;
  }
  std::cout << node->data << std::endl;
  PrintNodes(node->next);
}

int STRLLNode::AppendUnique(const char str[]){
  char* strNonConst = (char*)str;
  return AppendUnique(this, strNonConst);
}
int STRLLNode::AppendUnique(STRLLNode* node, char str[]){
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

void STRLLNode::MoveTailToHead(){
  if(this == NULL or this->next == NULL){
    // Nothing to move, list contains 1 node.
    return;
  }

  STRLLNode* oldHead = this;
  STRLLNode* secondToLast = GetSecondToLast(this);
  STRLLNode* newHead = secondToLast->next;
  secondToLast->next = NULL; // New end of list.
  newHead->next = oldHead;
  this = newHead;
}
STRLLNode* STRLLNode::GetSecondToLast(STRLLNode* node){
  // We know here that list has at least 2 nodes...
  if(node->next->next == NULL){
    return node;
  }
  return GetSecondToLast(node->next);
}

}
