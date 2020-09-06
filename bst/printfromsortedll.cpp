namespace DataStructs{

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
}
