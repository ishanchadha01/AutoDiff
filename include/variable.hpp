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
            // Create AutoDiffNode* for addend 1
            // AutoDiffNode* addend_ptr1 = this;
            // addend_ptr1->inputs = this->inputs;
            // addend_ptr1->id = this->id;
            // addend_ptr1->val = this->val;

            // // Create AutoDiffNode* for addend 2
            // AutoDiffNode* addend_ptr2 = new Variable();
            // addend_ptr2->inputs = addend.inputs;
            // addend_ptr2->id = addend.id;
            // addend_ptr2->val = addend.val;

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

        // Variable operator*(const Variable& multiplier) {
        //     // Create AutoDiffNode* for multiplier 1
        //     AutoDiffNode* mult_ptr1 = this;
        //     mult_ptr1->inputs = this->inputs;
        //     mult_ptr1->id = this->id;
        //     mult_ptr1->val = this->val;
        //     mult_ptr1->is_placeholder = this->is_placeholder;

        //     // Create AutoDiffNode* for multiplier 2
        //     AutoDiffNode* mult_ptr2 = new Variable();
        //     mult_ptr2->inputs = multiplier.inputs;
        //     mult_ptr2->id = multiplier.id;
        //     mult_ptr2->val = multiplier.val;
        //     mult_ptr2->is_placeholder = multiplier.is_placeholder;

        //     // Product placeholder
        //     AutoDiffNode* oper_node = new Mult(mult_ptr1, mult_ptr2);
        //     AutoDiffNode* product_placeholder = new Variable();
        //     product_placeholder->inputs = {oper_node};
        //     product_placeholder->is_placeholder = true;

        //     Variable* product_ptr = dynamic_cast<Variable*>(product_placeholder);
        //     return *product_ptr;
        // };

        // Variable operator/(Variable divisor) {
        //     // Create AutoDiffNode* for dividend
        //     AutoDiffNode* dividend_ptr = this;
        //     dividend_ptr->inputs = this->inputs;
        //     dividend_ptr->id = this->id;
        //     dividend_ptr->val = this->val;
        //     dividend_ptr->is_placeholder = this->is_placeholder;

        //     // Create AutoDiffNode* for divisor
        //     AutoDiffNode* divisor_ptr = new Variable();
        //     divisor_ptr->inputs = divisor.inputs;
        //     divisor_ptr->id = divisor.id;
        //     divisor_ptr->val = divisor.val;
        //     divisor_ptr->is_placeholder = divisor.is_placeholder;

        //     // Quotient placeholder
        //     AutoDiffNode* oper_node = new Divide(dividend_ptr, divisor_ptr);
        //     AutoDiffNode* quotient_placeholder = new Variable();
        //     quotient_placeholder->inputs = {oper_node};
        //     quotient_placeholder->is_placeholder = true;

        //     Variable* quotient_ptr = dynamic_cast<Variable*>(quotient_placeholder);
        //     return *quotient_ptr;
        // };
        // Variable power(Variable exponent) {
        //     // Create AutoDiffNode* for base
        //     AutoDiffNode* base_ptr = this;
        //     base_ptr->inputs = this->inputs;
        //     base_ptr->id = this->id;
        //     base_ptr->val = this->val;
        //     base_ptr->is_placeholder = this->is_placeholder;

        //     // Create AutoDiffNode* for exponent
        //     AutoDiffNode* exponent_ptr = new Variable();
        //     exponent_ptr->inputs = exponent.inputs;
        //     exponent_ptr->id = exponent.id;
        //     exponent_ptr->val = exponent.val;
        //     exponent_ptr->is_placeholder = exponent.is_placeholder;

        //     // Output placeholder
        //     AutoDiffNode* oper_node = new Pow(base_ptr, exponent_ptr);
        //     AutoDiffNode* output_placeholder = new Variable();
        //     output_placeholder->inputs = {oper_node};
        //     output_placeholder->is_placeholder = true;

        //     Variable* output_ptr = dynamic_cast<Variable*>(output_placeholder);
        //     return *output_ptr;
        // };

        data_type val;
};