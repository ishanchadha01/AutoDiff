#pragma once

#include "auto_diff_node.hpp"


class Variable : public AutoDiffNode {
  public:
		Variable();
        Variable(data_type aVal);

        NodeType get_type();
        Variable operator+(const Variable& addend) {
            Variable* v = new Variable;
            v->inputs = addend.inputs;
            v->id = addend.id;
            AutoDiffNode* addend_ptr = v;
            AutoDiffNode* node = AutoDiffNode::operator+(addend_ptr);
            Variable* sum_ptr = dynamic_cast<Variable*>(node);
            return *sum_ptr;
        };
        Variable operator*(const Variable& multiplier) {
            Variable* v = new Variable();
            v->inputs = multiplier.inputs;
            v->id = multiplier.id;
            AutoDiffNode* mult_ptr = v;
            AutoDiffNode* node = AutoDiffNode::operator*(mult_ptr);
            Variable* product_ptr = dynamic_cast<Variable*>(node);
            return *product_ptr;
        };
        Variable operator/(Variable divisor) {
            AutoDiffNode* div_ptr = &divisor;
            AutoDiffNode* node = AutoDiffNode::operator/(div_ptr);
            Variable* quotient_ptr = dynamic_cast<Variable*>(node);
            return *quotient_ptr;
        };
        Variable power(Variable exponent) {
            AutoDiffNode* exp_ptr = &exponent;
            AutoDiffNode* node = AutoDiffNode::power(exp_ptr);
            Variable* exp_out = dynamic_cast<Variable*>(node);
            return *exp_out;
        };

        data_type val;
};