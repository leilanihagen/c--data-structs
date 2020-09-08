#include <iostream>
#include "cllnode.h"

using namespace DataStructs;

int main(){
  CLL myList = CLL();
  myList.Append(78);
  myList.Prepend(8);
  myList.Prepend(7);
  myList.Prepend(6);
  myList.PrintNodes();

//  myList.RemoveMiddleNodes();
  CLL l2 = CLL(myList);
  std::cout << std::endl;
  l2.PrintNodes();

//  std::cout << myList.tail->data << "haha" << std::endl;
//  std::cout << myList.tail->next->data << "haha" << std::endl;

//  std::cout << myList.tail->next->data << "haha" << std::endl;
}
