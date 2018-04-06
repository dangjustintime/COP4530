#ifndef PROJ$_BET_H
#define PROJ4_BET_H

#include <string>

template <typename T>
class BET {
  struct BinaryNode {
    T data;
    BinaryNode * left;
    BinaryNode * right;
  };

  public:
    BET();
    BET(const std::string postfix);
    BET(const BET &);
    ~BET();
    bool buildFromPostfix(const std::string postfix);
    const BET & operator=(const BET &);
    void printInfixExpression();
    void printPostfixExpression();
    size_t size();
    size_t leaf_nodes();
    bool empty();

  private:
    void printInfixExpression(BinaryNode * n);
    void makeEmpty(BinaryNode * n);
    BinaryNode * clone(BinaryNode) const;
    void printPostfixExpression(BinaryNode * n);
    size_t size(BinaryNode * t);
    size_t leaf_nodes(BinaryNode * t);
    BinaryNode * root;

};

#include "bet.hpp"

#endif
