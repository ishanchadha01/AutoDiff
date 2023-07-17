#pragma once

#include "auto_diff_node.hpp"


class Variable : public AutoDiffNode {
  public:
		Variable();
        Variable(data_type aVal);

        NodeType get_type();
        Variable operator+(Variable addend) {
            AutoDiffNode* addend_ptr = &addend;
            AutoDiffNode* node = AutoDiffNode::operator+(addend_ptr);
            Variable* sum_ptr = dynamic_cast<Variable*>(node);
            return *sum_ptr;
        };
        Variable operator*(Variable multiplier) {
            AutoDiffNode* mult_ptr = &multiplier;
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