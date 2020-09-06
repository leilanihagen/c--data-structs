#include <iostream>
#include "bst.h"

using namespace DataStructs;

int main(){
  BST myTree = BST();
  myTree.Add(8);
  myTree.Add(3);
  myTree.Add(9);
//  myTree.Add(12);
//  myTree.Add(11);
//  myTree.Add(1);
//  myTree.Add(5);
//  myTree.Add(4);

  BST myDupe = myTree.Duplicate();
  myDupe.InOrderTraverse();

// myTree.Delete(3);
// myTree.PrintFromSortedLL(); 

//  myTree.Delete(3);
//  myTree.Delete(9);
//  myTree.Delete(11);
//  myTree.Delete(8);
//  myTree.Delete(12);
//  myTree.Delete(1);
//  myTree.Delete(4);
//  myTree.Delete(5);

//  myTree.Delete(12);
//  myTree.Delete(5);
//  myTree.Delete(9);
//  myTree.Delete(11);
//  myTree.Delete(1);
//  myTree.Delete(4);

//  myTree.InOrderTraverse();
//  if(myTree.Contains(20)){
//    std::cout << "Contains 20.";
//  }
//  else{
//    std::cout << "Does not contain 20.";
//  }
//  if(myTree.Contains(57)){
//    std::cout << "Contains 57.";
//  }
//  else{
//    std::cout << "Does not contain 57.";
//  } 
//  std::cout << myTree.ReturnRoot() << std::endl;
}

