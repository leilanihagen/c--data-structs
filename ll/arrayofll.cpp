#include <iostream>
#include <random>
#include "llnode.h"

using namespace LL;

LLNode* CreateRandomLL(int numberNodes);
LLNode* LLFromArray(int* array, int size);
void Count2sMain();
int Count2sLL(LLNode* node, int twoCount);
int Count2sArrayOfLL(LLNode** array,int twoCount, int arraySize);
void DeleteLastList();
void Destroy(LLNode* node);

LLNode* CreateRandomLL(int numberNodes){
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dist(-140, 578);

  LLNode* head = new LLNode(dist(gen));
  LLNode* temp = head;
  for(int i=0; i < (numberNodes-1); i++){
    temp->Append(dist(gen));
    temp = temp->next;
  }
  return head;
}
void Count2sMain(){
  // Fill data:
  int s = 4;
  LLNode* llArray[s];

  // LL data:
//  int list1[] = {1, 5, 2};
//  int list2[] = {2};
//  int list3[] = {5, 0, 2, 2, 445};
//  int list4[] = {};

  // Lists:
  LLNode* ll1 = new LLNode(1);
  ll1->next = new LLNode(5);
  ll1->next->next = new LLNode(422);

  LLNode* ll2 = new LLNode(0);

  LLNode* ll3 = new LLNode(3);
  ll3->next = new LLNode(3);
  ll3->next->next = new LLNode(0);
  ll3->next->next->next = new LLNode(-1);
  ll3->next->next->next->next = new LLNode(445);

  LLNode* ll4 = new LLNode;

  llArray[0] = ll1;
  llArray[1] = ll2;
  llArray[2] = ll3;
  llArray[3] = ll4;

  int twoTally = 0;
  twoTally = Count2sArrayOfLL(llArray, 0, 4);
//  twoTally = Count2sLL(llArray[3], 0);
  std::cout << twoTally << std::endl;

//  llArray[0] = LLFromArray(list1, 3);
//  llArray[1] = LLFromArray(list2, 1);
//  llArray[2] = LLFromArray(list3, 6);
//  llArray[3] = LLFromArray(list4, 0);
//  llArray[0]->PrintNodes();
}

int Count2sLL(LLNode* node, int twoCount){
  if(node == NULL){
    return 0;
  }
  if(node->data == 2){
    twoCount++;
  }
  if(node->next != NULL){
    twoCount = Count2sLL(node->next, twoCount);
  }
  return twoCount;
}

int Count2sArrayOfLL(LLNode** array,int twoCount, int arraySize){
  int& recursionCountDown = arraySize;
  if(recursionCountDown != 0){
    twoCount += Count2sLL(*array, 0);
    if(recursionCountDown != 1){
      twoCount = Count2sArrayOfLL(array+1, twoCount, recursionCountDown-1);
    }
    return twoCount;
  }
}

void DeleteLastList(){

  int s = 4;
  LLNode* llArray[s];

  LLNode* ll1 = new LLNode(1);
  ll1->next = new LLNode(5);
  ll1->next->next = new LLNode(422);

  LLNode* ll2 = new LLNode(0);

  LLNode* ll3 = new LLNode(1);
  ll3->next = new LLNode(2);
  ll3->next->next = new LLNode(3);
  ll3->next->next->next = new LLNode(4);
  ll3->next->next->next->next = new LLNode(5);

  LLNode* ll4 = new LLNode;

  llArray[0] = ll1;
  llArray[1] = ll2;
  llArray[2] = ll3;
  llArray[3] = ll4;

  Destroy(ll3);
}

void Destroy(LLNode* node){
  if(node == NULL){
    return;
  }
  LLNode* temp = node->next;
//  delete node;
  Destroy(node->next);
  std::cout << node->data << std::endl;
  delete node;
  return;
//  node = NULL;
}
LLNode* LLFromArray(int array[], int size){
  LLNode* head = new LLNode(array[0]);
  LLNode* temp = head;
  bool firstPass = true;
  bool initHead = true;
  for(int i=1; i<size-1; i++){
//    if(firstPass){
//      temp = head;
//      firstPass = false;
//    }
    temp->Append(array[i]);
    temp = temp->next;
  }
  return head;
}

int main(){

//  Count2sMain();
  DeleteLastList();
//  int s = 5;
//  LLNode* llArray[s];
//
//  std::random_device rd;
//  std::mt19937 gen(rd());
//  std::uniform_int_distribution<> dist(3, 9);
//  for(int i=0; i<s; i++){
//   llArray[i] = CreateRandomLL(dist(gen));
//  }
//  for(int i=0; i<s; i++){
//    llArray[i]->PrintNodes();
//  }
//
//  return 0;
}


