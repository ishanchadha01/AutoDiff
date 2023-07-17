#include "operator.hpp"


Operator::Operator() {
  this->id = "operator/undefined";
}


NodeType Operator::get_type() {
    return OPERATOR;
}



