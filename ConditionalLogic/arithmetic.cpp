// https://www.youtube.com/watch?v=4F72VULWFvc&ab_channel=GoogleTechTalks
#include<iostream>

namespace noPolymorphism{
class Node
{
  char operation;
  float value;
  Node* left;
  Node* right;
  float evaluate(){
    switch (operation)
    {
    case '+':
      return left->evaluate() + right->evaluate();  
    case '*':
      return left->evaluate() * right->evaluate();
    case '#':
      return value;
    default:
      break;
    }
  }
};
}

// Refactor 
// removes Value node no more has left and right nodes and hence no null pointers (Null point exception)
// No extra values are need in each class either value or operation
namespace trail2{
class Node{
public:
virtual double evaluate() = 0;
};

class ValueNode : public Node {
public:
float value;
double evaluate() override {
  return value;
}
};

class OperatorNode : public Node {
public:
Node* left;
Node* right;
char operation;
double evaluate() override{
  switch (operation)
  {
  case '+':
    return left->evaluate() + right->evaluate();  
  case '*':
    return left->evaluate() * right->evaluate();
  default:
    break;
  }
}
};
}
// Above "Operation Node" Here switch statment still exist.
// And can be furthur divided by using polymorphism

namespace polymorphed{

class Node{
public:
virtual double evaluate() = 0;
};

class ValueNode : public Node {
public:
float value;
double evaluate() override {
  return value;
}
};

class OperatorNode : public Node {
public:
Node* left;
Node* right;
};

class additionNode : public OperatorNode {
double evaluate() override {
  return left->evaluate() + right->evaluate();
}
};

class multiplicationNode : public OperatorNode {
double evaluate() override {
  return left->evaluate() * right->evaluate();
}
};

}