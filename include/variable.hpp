#pragma once

#include "auto_diff_node.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "divide.hpp"
#include "pow.hpp"


class Variable : public AutoDiffNode {
  public:
		Variable();
        Variable(data_type aVal) : val(aVal), AutoDiffNode(aVal) {};

        NodeType get_type();
        Variable& operator+(Variable& addend) {
            // Sum placeholder
            AutoDiffNode* addend_ptr1 = this;
            AutoDiffNode* addend_ptr2 = &addend;
            AutoDiffNode* oper_node = new Add(addend_ptr1, addend_ptr2);
            AutoDiffNode* sum_placeholder = new Variable();
            sum_placeholder->inputs = {oper_node};
            sum_placeholder->is_placeholder = true;
            Variable* sum_ptr = dynamic_cast<Variable*>(sum_placeholder);
            return *sum_ptr;
        };
        Variable& operator*(Variable& multiplicand) {
            // Product placeholder
            AutoDiffNode* mult_ptr1 = this;
            AutoDiffNode* mult_ptr2 = &multiplicand;
            AutoDiffNode* oper_node = new Mult(mult_ptr1, mult_ptr2);
            AutoDiffNode* product_placeholder = new Variable();
            product_placeholder->inputs = {oper_node};
            product_placeholder->is_placeholder = true;
            Variable* product_ptr = dynamic_cast<Variable*>(product_placeholder);
            return *product_ptr;
        };
        Variable& operator/(Variable& divisor) {
            // Product placeholder
            AutoDiffNode* div_ptr1 = this;
            AutoDiffNode* div_ptr2 = &divisor;
            AutoDiffNode* oper_node = new Divide(div_ptr1, div_ptr2);
            AutoDiffNode* quotient_placeholder = new Variable();
            quotient_placeholder->inputs = {oper_node};
            quotient_placeholder->is_placeholder = true;
            Variable* quotient_ptr = dynamic_cast<Variable*>(quotient_placeholder);
            return *quotient_ptr;
        };
        Variable& power(Variable& exponent) {
            // Product placeholder
            AutoDiffNode* base_ptr = this;
            AutoDiffNode* exponent_ptr = &exponent;
            AutoDiffNode* oper_node = new Pow(base_ptr, exponent_ptr);
            AutoDiffNode* exp_placeholder = new Variable();
            exp_placeholder->inputs = {oper_node};
            exp_placeholder->is_placeholder = true;
            Variable* exp_ptr = dynamic_cast<Variable*>(exp_placeholder);
            return *exp_ptr;
        };

        data_type val;
        data_type gradient;
};