#include "auto_diff_node.hpp"
#include "variable.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "divide.hpp"
#include "pow.hpp"


AutoDiffNode::AutoDiffNode() {
	
}


AutoDiffNode* AutoDiffNode::operator/(AutoDiffNode* divisor) {
    AutoDiffNode* oper_node = new Divide(this, divisor);
    AutoDiffNode* placeholder_node = new Variable();
    placeholder_node->inputs = {oper_node};
    placeholder_node->is_placeholder = true;
    return placeholder_node;
}


AutoDiffNode* AutoDiffNode::power(AutoDiffNode* exponent) {
    AutoDiffNode* oper_node = new Pow(this, exponent);
    AutoDiffNode* placeholder_node = new Variable();
    placeholder_node->inputs = {oper_node};
    placeholder_node->is_placeholder = true;
    return placeholder_node;
}