#include <iostream>
#include "bst.h"

namespace DataStructs{

BST::~BST(){
  if(root != NULL){
    EmptyTree(root);
  }
}
void BST::EmptyTree(struct Node* root){
  // Traverse tree (lrn to avoid deleting parents before children) and delete each node:
  if(root == NULL){
    return;
  }
  EmptyTree(root->left);
  EmptyTree(root->right);
  delete root;
}

void BST::Add(int number){
  Add(root, number);
}
void BST::Add(struct Node*& root, int number){ // Pass ref to ptr so ptr can be modified.
 // Base case:
  if(root == NULL){// || (root->data == 0 && root->left == NULL && root->right == NULL)){
    root = new struct Node; // Heap declaration. // Failed b/c set POINTER to new val
    root->data = number; // Sets new Node pointed to by ^ to number, not our original root Node.
  }
  else if(number < root->data){
    Add(root->left, number);
  }
  else if(number > root->data){
    Add(root->right, number);
  }
}

void BST::Delete(int number){
  root = SimpleDelete(root, number);
}

struct BST::Node* BST::SimpleDelete(struct Node* searchNode, int number){
  // SIMPLIFIED REWRITE
  if(searchNode == NULL){
    return NULL;
  }

  int diffNumberCurrNodeData = diffValFromNodeData(searchNode, number);
  if(diffNumberCurrNodeData > 0){
    // number > searchNode->data
    searchNode->right = SimpleDelete(searchNode->right, number);
    return searchNode;
  }
  else if(diffNumberCurrNodeData < 0){
    // number < searchNode->data
    searchNode->left = SimpleDelete(searchNode->left, number);
    return searchNode;
  }
  else{ // number == searchNode->data
    if(searchNode->left != NULL && searchNode->right != NULL){ // searchNode has TWO children.
      // Find largest node in left subtree:
      struct Node* prev = searchNode;
      struct Node* curr = searchNode->left;
      while(curr->right != NULL){
	prev = curr;
	curr = curr->right;
      }
      struct Node*& replaceValNode = curr;

      //Replace data in searchNode:
      searchNode->data = replaceValNode->data;

      // Call delete on largest node in left subtree:
      replaceValNode = SimpleDelete(replaceValNode, replaceValNode->data);
      
      // Return searchNode
      return searchNode;
    }
    else if(searchNode->left != NULL){ // searchNode has ONE child only.
      struct Node* leftChild = searchNode->left;
      delete searchNode;
      return leftChild;
    }
    else if(searchNode->right != NULL){
      struct Node* rightChild = searchNode->right;
      delete searchNode;
      return rightChild;
    }
    else{ // searchNode has NO children.
      delete searchNode;
      return NULL;
    }
  }
}
int BST::diffValFromNodeData(struct Node* node, int val){
  if(node == NULL){
    return 0;
  }
  return (val - node->data);
}

bool BST::Contains(int number){
  return(Contains(root, number));
}
bool BST::Contains(struct Node* root, int number){
  // Base cases:
  if(root == NULL){
    return false;
  }
  if(number == root->data){
    return true;
  }

  if(number < root->data){
    Contains(root->left, number);
  }
  if(number > root->data){
    Contains(root->right, number);
  }
}

int BST::GetInOrderSuccessor(){
  if(root->right != NULL){
    return RetrieveSuccessor(root->right);
  }
}
int BST::RetrieveSuccessor(Node* rootRight){
  if(rootRight->left == NULL){
    return rootRight->data;
  }
  return RetrieveSuccessor(rootRight->left);
}

BST BST::Duplicate(){
  return BST(Duplicate(root));
}
struct BST::Node* BST::Duplicate(struct Node* root){
/* Writing as if we have no internal control of data struct. */
  // Base case:
  if(root == NULL){
    return NULL;
  }

  struct Node* dupeTreeRoot = new struct Node;
  dupeTreeRoot->left = Duplicate(root->left);
  dupeTreeRoot->right = Duplicate(root->right);
  dupeTreeRoot->data = root->data;
  return dupeTreeRoot;
}

void BST::PrintFromSortedLL(){
  LLNode* ll = ToSortedLinkedList(root);
  LLNode* temp = ll;
  while(temp != NULL){
    std::cout << temp->data << std::endl;
    temp = temp->next;
  }
}
struct BST::LLNode* BST::ToSortedLinkedList(struct Node* root){
  if(root == NULL){
    return NULL;
  }
  
  LLNode* listHead = NULL;
  LLNode* rightSubList = NULL;
  LLNode* leftSubList = NULL;
  LLNode* currNode = new LLNode;

  rightSubList = ToSortedLinkedList(root->right); // R
  currNode->data = root->data;  // N
  leftSubList = ToSortedLinkedList(root->left); // L

  if(leftSubList != NULL){
    listHead = leftSubList;
    LLNode* leftSubListTail = GetLLTail(leftSubList);
    leftSubListTail->next = currNode;
    if(rightSubList != NULL){
      // List is a joining between leftSubList and currNode, so link currNode (curr. tail) to rSub:
      currNode->next = rightSubList;
    }
  }
  else{ // if leftSubList is NULL
    listHead = currNode;
    if(rightSubList != NULL){
      // currNode is the entire list so far, so link head to rightSubList:
      listHead->next = rightSubList;
    }
  }
  
  return listHead;
}
struct BST::LLNode* BST::GetLLTail(struct LLNode* head){
  if(head->next == NULL){
    return head;
  }
  return (GetLLTail(head->next));
}

BST BST::FromArray(int arr[]){
  BST newTree;
  newTree.root = BuildTree(arr);
  return newTree;
}
struct BST::Node* BST::BuildTree(int arr[]){
  int len = strlen(arr);
  if(len == 0){
    // If USER passes empty array.
    return NULL;
  }
  if(len == 1){
    struct Node* leaf = new Node;
    leaf->data = arr[0];
    return leaf;
  }
  
  int rootLoc;
  if(len % 2 == 0){ // Array len even.
    rootLoc = len/2 - 1;
  }
  else{ // Odd.
    rootLoc = (len - 1)/2;
  }
  struct Node* root = new Node;
  root->data = arr[rootLoc];

  int lenLeftSubArr, lenRightSubArr;
  lenLeftSubArr = rootLoc;
  lenRightSubArr = len - rootLoc - 1;
  char leftSubArr[lenLeftSubArr], rightSubArr[lenRightSubArr];

  for(int i=0; i<lenLeftSubArr; i++){
    leftSubArr[i] = arr[i];
  }
  int j = rootLoc + 1;
  for(int i=0; i<lenRightSubArr; i++){
    rightSubArr[i] = arr[j];
    j++;
  }

  root->left = BuildTree(leftSubArr);
  root->right = BuildTree(rightSubArr);

  return root;

//  int mid;
//  if(stop % 2 != 0){
//    mid = (stop-1)/2;
//  }
//  else{
//    mid = stop/2;
//  }
//  struct Node* root = new Node;
//  root->data = arr[mid];
//  if(abs(start - stop) = 3){
//    // Base case, if range == 3 assemble height 2 baby tree:
//    root->left = new Node;
//    root->right = new Node;
//    root->left->data = arr[mid-1];
//    root->right->data = arr[mid+1];
//  }
//  if(abs(start - stop) = 2){
//    // Base case, range == 2 assemble height 2 baby tree:
//    int rootVal;
//    if(arr[mid
//
//    root->left = CreateRoot(arr, start, mid);
//    root->right = CreateRoot(arr, mid, stop);
//  }
//  else{
//    // range/dist <=3, so we must assemble a structure from this and return:
//    //
//
//
//    root->left = NULL;
//    root->right = NULL;
//  }
//  return root;
}

void BST::PreOrderTraverse(){
  // Depth-first preorder traversal.
  NLR(root);
}
void BST::NLR(struct Node* root){
  if(root == NULL){
    return;
  }
  std::cout << root->data << " " << std::endl;
  NLR(root->left);
  NLR(root->right);
}

void BST::InOrderTraverse(){
  // Depth-first inorder traversal.
  LNR(root);
}
void BST::LNR(struct Node* root){
  if(root == NULL){
    return;
  }
  LNR(root->left);
  std::cout << root->data << " " << std::endl;
  LNR(root->right);
}

void BST::PostOrderTraverse(){
  // Depth-first postorder traversal.
  LRN(root);
}
void BST::LRN(struct Node* root){
  if(root == NULL){
    return;
  }
  LRN(root->left);
  LRN(root->right);
  std::cout << root->data << " " << std::endl;
}

int BST::ReturnRoot(){
  return (root->data);
}
}
