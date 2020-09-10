namespace LL{
class LLNode{
  bool headDataNeedsInit;
  void Append(LLNode* node, int data);
  void DestroyList(LLNode* node);
  void PrintNodes(LLNode* node);
  public:
  int data;
  LLNode* next;
  LLNode();
//  ~LLNode();
  LLNode(int data);
  void Append(int data);
  void DestroyThisList();
  void PrintNodes();
};
}
