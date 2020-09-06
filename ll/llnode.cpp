#include <iostream>
#include "llnode.h"

namespace LL{

LLNode::LLNode(int val) : data(val), next(NULL), headDataNeedsInit(false) {}
LLNode::LLNode() : data(), next(NULL), headDataNeedsInit(true) {}
LLNode::~LLNode(){
  DestroyList(this); // LEFT OFF FRIDAY
}
void LLNode::Append(int data){
  if(headDataNeedsInit){
    this->data = data;
    headDataNeedsInit = false;
    return;
  }
  Append(this, data);
}
void LLNode::Append(LLNode* node, int data){
  if(node->next == NULL){
    LLNode* newNode = new LLNode;
    newNode->data = data;
    node->next = newNode;
  }
  else{
    Append(node->next, data);
  }
}
void LLNode::DestroyList(){
  DestroyList(this->next);
}
void LLNode::DestroyList(LLNode* node){
  if(node == NULL){
    return;
  }
  if(node->next != NULL){
    DestroyList(node->next);
  }
  delete node;
}
void LLNode::PrintNodes(){
  PrintNodes(this);
}
void LLNode::PrintNodes(LLNode* node){
  if(node == NULL){
    return;
  }
  std::cout << node->data << std::endl;
  PrintNodes(node->next);
}
}
