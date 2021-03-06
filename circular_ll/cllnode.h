namespace DataStructs{
class CLL{
  typedef struct CLLNode{
    int data;
    CLLNode* next;
  }CLLNode;
  bool tailDataNeedsInit;
  CLL::CLLNode* FindTailSuccessor(CLLNode* head);
  void DestroyList(CLLNode* head, CLLNode* tail);
  CLL::CLLNode* DuplicateListImpl(CLLNode* objHead, CLLNode* objTail, CLLNode* newObjTail);
  void PrintNodes(CLLNode* head);
  void ClearMiddle(CLLNode* head);
  public:
  CLL::CLLNode* DuplicateList(CLLNode* objTail);
  CLLNode* tail;
  CLL();
  CLL(int val);
  CLL(const CLL& object);
  ~CLL();
  CLL& operator=(const CLL& object);
  void Append(int data);
  void Prepend(int data);
  void MoveTailToHead();
//  void DestroyThisList();
  void PrintNodes();
  void RemoveMiddleNodes();
};
}
