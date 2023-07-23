#pragma once

#include "auto_diff_node.hpp"
#include "add.hpp"
#include "mult.hpp"


class Variable : public AutoDiffNode {
  public:
		Variable();
        Variable(data_type aVal);

        NodeType get_type();
        Variable operator+(const Variable& addend) {
            // Create AutoDiffNode* for addend 1
            AutoDiffNode* addend_ptr1 = this;
            addend_ptr1->inputs = this->inputs;
            addend_ptr1->id = this->id;
            addend_ptr1->val = this->val;

            // Create AutoDiffNode* for addend 2
            AutoDiffNode* addend_ptr2 = new Variable();
            addend_ptr2->inputs = addend.inputs;
            addend_ptr2->id = addend.id;
            addend_ptr2->val = addend.val;

            // Sum placeholder
            AutoDiffNode* oper_node = new Add(addend_ptr1, addend_ptr2);
            AutoDiffNode* sum_placeholder = new Variable();
            sum_placeholder->inputs = {oper_node};
            sum_placeholder->is_placeholder = true;
            Variable* sum_ptr = dynamic_cast<Variable*>(sum_placeholder);
            return *sum_ptr;
        };

        Variable operator*(const Variable& multiplier) {
            // Create AutoDiffNode* for multiplier 1
            AutoDiffNode* mult_ptr1 = this;
            mult_ptr1->inputs = this->inputs;
            mult_ptr1->id = this->id;
            mult_ptr1->val = this->val;
            mult_ptr1->is_placeholder = this->is_placeholder;

            // Create AutoDiffNode* for multiplier 2
            AutoDiffNode* mult_ptr2 = new Variable();
            mult_ptr2->inputs = multiplier.inputs;
            mult_ptr2->id = multiplier.id;
            mult_ptr2->val = multiplier.val;
            mult_ptr2->is_placeholder = multiplier.is_placeholder;

            // Sum placeholder
            AutoDiffNode* oper_node = new Mult(mult_ptr1, mult_ptr2);
            AutoDiffNode* product_placeholder = new Variable();
            product_placeholder->inputs = {oper_node};
            product_placeholder->is_placeholder = true;

            Variable* product_ptr = dynamic_cast<Variable*>(product_placeholder);
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