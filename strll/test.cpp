#include "strllnode.h"
using namespace DataStructs;
int main(){
  STRLLNode* l = new STRLLNode("h");
  l->Append("Hello world");
//  l->Append("haha");
  l->AppendUnique("haha");
  l->AppendUnique("haha");
  STRLLNode l2 = l->DuplicateList();
  l2.DestroyThisList();
//  l->Append(55);
  l->PrintNodes();
//  l2.PrintNodes();
//  l->DestroyList();
}
