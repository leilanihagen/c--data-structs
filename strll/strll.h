namespace DataStructs{
class STRLLNode{
  public:
  char* data;
  STRLLNode* next;
}

class STRLL{
  bool headDataNeedsInit;
  STRLL* DuplicateList(STRLLNode* node);
  void Append(STRLLNode* node, char data[]);
  void DestroyList(STRLLNode* node);
  void PrintNodes(STRLLNode* node);
  int AppendUnique(STRLLNode* node, char str[]);
  public:
  STRLLNode* head;
  STRLL();
//  ~STRLL();
  STRLL(const char data[]);
//  STRLL& operator=(const STRLLNode& object);
//  STRLL(const STRLLNode& object);
  STRLL DuplicateList();
  void Append(const char data[]);
  void DestroyThisList();
  void PrintNodes();
  int AppendUnique(const char str[]);
  void MoveTailToHead();
  STRLL* GetSecondToLast(STRLLNode* node);
};
}
