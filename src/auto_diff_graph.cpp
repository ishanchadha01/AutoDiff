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
    this->top_sort.push_back(node->id);
    for (AutoDiffNode* input : node->inputs)
        _dfs(input);
};
