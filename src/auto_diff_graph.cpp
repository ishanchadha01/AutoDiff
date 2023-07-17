#include "auto_diff_graph.hpp"
#include <iostream>


AutoDiffGraph::AutoDiffGraph(AutoDiffNode* aHead) {
    this->head = aHead;

    // Add nodes to list using DFS for topological sort
    _dfs(aHead);
};



void AutoDiffGraph::_dfs(AutoDiffNode* node) {
    if (dynamic_cast<Variable*>(node) == nullptr) {
        node->id = "variables/" + std::to_string(variable_count);
        this->variable_count++;
    } else {
        node->id = "operators/" + std::to_string(operator_count);
        this->operator_count++;
    }
    this->nodes[node->id] = node;
    for (AutoDiffNode* input : node->inputs)
        _dfs(input);
};
