#include "auto_diff_graph.hpp"
#include <unordered_set>
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
};


void AutoDiffGraph::backward_pass() {
    std::unordered_set<AutoDiffNode*> visited_inputs;
    std::vector<std::string>::iterator reverse_it;
    std::string out_node_id = this->top_sort[this->top_sort.size()-1];
    nodes[out_node_id]->gradient = 1.0; // gradient of output is 1
    for (reverse_it = this->top_sort.end()-2; reverse_it >= this->top_sort.begin(); reverse_it--) {
        std::string node_id = *reverse_it;
        if (node_id.rfind("operator", 0) == 0) {
            Operator* oper = dynamic_cast<Operator*>(nodes[node_id]);
            if (dynamic_cast<Add*>(oper) != nullptr) oper = dynamic_cast<Add*>(oper);
            else if (dynamic_cast<Mult*>(oper) != nullptr) oper = dynamic_cast<Mult*>(oper);
            else if (dynamic_cast<Pow*>(oper) != nullptr) oper = dynamic_cast<Pow*>(oper);
            else if (dynamic_cast<Divide*>(oper) != nullptr) oper = dynamic_cast<Divide*>(oper);
            oper->gradients = oper->backward(oper->gradient);
            for (int idx = 0; idx < oper->gradients.size(); idx++) {
                // input gradient equals corresponding gradient output from operator
                if (visited_inputs.find(oper->inputs[idx]) != visited_inputs.end()) {
                    oper->inputs[idx]->gradient = oper->gradients[idx];
                    visited_inputs.insert(oper->inputs[idx]);
                } else {
                    data_type input1 = oper->inputs[idx]->gradient;
                    data_type input2 = oper->gradients[idx];
                    std::visit(
                        overload{
                            [&oper, idx](double& a, double& b) {
                                oper->inputs[idx]->gradient = a+b;
                            },
                            [&oper, idx](Eigen::MatrixXd& a, Eigen::MatrixXd& b) {
                                oper->inputs[idx]->gradient = a+b;
                            },
                            [&oper, idx](Eigen::MatrixXd& a, double& b) {
                                std::cout << "Error, Mult types don't match!" << std::endl;
                            },
                            [&oper, idx](double& a, Eigen::MatrixXd& b) {
                                std::cout << "Error, Mult types don't match!" << std::endl;
                            }
                        },
                        input1, input2
                    );
                    // oper->inputs[idx]->gradient += oper->gradients[idx];
                }
            }
        } else if (node_id.rfind("variable", 0) == 0 && dynamic_cast<Variable*>(nodes[node_id])->is_placeholder) {
            nodes[node_id]->inputs[0]->gradient = nodes[node_id]->gradient;
        }
    }
}