#include "auto_diff_graph.hpp"
#include <iostream>


int main() {
    Variable x = Variable(0.9);
    Variable y = Variable(0.4);
    Variable z = Variable(1.3);
    Variable out = z*(x+y);
    AutoDiffGraph g = AutoDiffGraph(out);
    g.forward_pass();
    std::cout << "Values: " << std::endl;
    for (auto& node_id : g.top_sort) {
        std::cout << node_id << " " << std::get<double>(g.nodes[node_id]->val) << std::endl;
    }
    g.backward_pass();
    std::cout << "Gradients: " << std::endl;
    for (auto& node_id : g.top_sort) {
        std::cout << node_id << " " << std::get<double>(g.nodes[node_id]->gradient) << std::endl;
    }
	  return 0;
}