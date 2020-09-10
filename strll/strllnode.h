namespace DataStructs{
class STRLLNode{
  bool headDataNeedsInit;
  STRLLNode* DuplicateList(STRLLNode* node);
  void Append(STRLLNode* node, char data[]);
  void DestroyList(STRLLNode* node);
  void PrintNodes(STRLLNode* node);
  int AppendUnique(STRLLNode* node, char str[]);
  public:
  char* data;
  STRLLNode* next;
  STRLLNode();
//  ~STRLLNode();
  STRLLNode(const char data[]);
  STRLLNode DuplicateList();
  void Append(const char data[]);
  void DestroyThisList();
  void PrintNodes();
  int AppendUnique(const char str[]);
};
}
