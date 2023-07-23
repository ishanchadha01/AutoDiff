#include "auto_diff_graph.hpp"
#include <iostream>


AutoDiffGraph::AutoDiffGraph(Variable& aHead) {
    this->head = &aHead;

    // Add nodes to list using DFS for topological sort
    AutoDiffNode* head_ptr = &aHead;
    _dfs(head_ptr);
};



void AutoDiffGraph::_dfs(AutoDiffNode* node) {
    if (dynamic_cast<Variable*>(node) != nullptr) {
        node->id = "variables/" + std::to_string(variable_count);
        this->variable_count++;
    } else if (dynamic_cast<Operator*>(node) != nullptr) {
        node->id = "operators/" + std::to_string(operator_count);
        this->operator_count++;
    }
    this->nodes[node->id] = node;
    for (AutoDiffNode* input : node->inputs)
        _dfs(input);
    this->top_sort.push_back(node->id);
};


void AutoDiffGraph::forward_pass() {
    for (auto& node_id : this->top_sort) {
        if (node_id.rfind("operator", 0) == 0) {
            AutoDiffNode* node = nodes[node_id];
            Operator* oper = dynamic_cast<Operator*>(nodes[node_id]);
            if (dynamic_cast<Add*>(oper) != nullptr) oper = dynamic_cast<Add*>(oper);
            else if (dynamic_cast<Mult*>(oper) != nullptr) oper = dynamic_cast<Mult*>(oper);
            else if (dynamic_cast<Pow*>(oper) != nullptr) oper = dynamic_cast<Pow*>(oper);
            else if (dynamic_cast<Divide*>(oper) != nullptr) oper = dynamic_cast<Divide*>(oper);
            nodes[node_id]->val = oper->forward();
        } else if (node_id.rfind("variable", 0) == 0 && dynamic_cast<Variable*>(nodes[node_id])->is_placeholder) {
            nodes[node_id]->val = nodes[node_id]->inputs[0]->val;
        }
    }
}