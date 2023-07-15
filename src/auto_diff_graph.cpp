#include "auto_diff_graph.hpp"
#include <iostream>


AutoDiffNode::AutoDiffNode() {
	
}

AutoDiffGraph::AutoDiffGraph() {

}

void AutoDiffGraph::add_variable()

// Variable AutoDiffGraph::add_operation(Operator& oper, Variable& var1, Variable& var2) {
//     oper.id += std::to_string(oper.type) + std::to_string(this->operator_count);
//     this->operators[oper.id] = &oper;
//     oper.inputs = {var1.val, var2.val};
//     this->operator_count++;

//     // TODO: this needs to be a placeholder instead of a new variable
//     Variable output;
//     output.val = operator.forward_pass(var1, var2);
//     return output;
// }

void AutoDiffGraph::create_expression() {
    // parse expression
    // create graph
}