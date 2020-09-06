#include <iostream>
namespace DataStructs{

class BST{ // Rewrite class as a node type instead of having bst, then all functions
  struct Node{ // operate on a node at any entry point.
    int data;
    struct Node* left;
    struct Node* right;
  };
  struct LLNode{
    int data;
    struct LLNode* next;
  };
  struct Node* root;
  void EmptyTree(struct Node* root);
  void Add(struct Node*& root, int number);
//  void Delete(struct Node* searchNode, struct Node* searchNodeParent, int number);
  struct BST::Node* SimpleDelete(struct Node* searchNode, int number);
  int diffValFromNodeData(struct Node* node, int val);
  bool Contains(struct Node* root, int number);
  struct BST::Node* Duplicate(struct Node* root); // Class not in scope until func. args.
  struct BST::LLNode* ToSortedLinkedList(struct Node* root);
  struct BST::LLNode* GetLLTail(struct LLNode* head);
  void LRN(struct Node* root);
  void NLR(struct Node* root);
  void LNR(struct Node* root);
  public:
  BST(): root(NULL){}
  BST(struct Node* root): root(root){}
  ~BST();
  void Add(int number);
  void Delete(int number);
  bool Contains(int number);
  BST Duplicate();
  void PrintFromSortedLL();
  void PostOrderTraverse();
  void PreOrderTraverse();
  void InOrderTraverse();
  int ReturnRoot();
};  
}
