#include "llnode.h"
using namespace LL;
int main(){
  LLNode* l = new LLNode;
  l->Append(9);
  l->Append(55);
  l->PrintNodes();
  l->DestroyList();
}
