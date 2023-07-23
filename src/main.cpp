#include "auto_diff_graph.hpp"
#include <iostream>


int main() {
	// auto graph = AutoDiffGraph();
    Variable x = Variable(0.7);
    Variable y = Variable(1.5);
    Variable z = Variable(0.9);
    Variable out = z*(x+y);
    AutoDiffGraph g = AutoDiffGraph(out);
    // for (auto& node_id : g.top_sort) {
    //     std::cout << node_id << std::get<double>(g.nodes[node_id]->val) << std::endl;
    // }
    g.forward_pass();
    for (auto& node_id : g.top_sort) {
        std::cout << node_id << " " << std::get<double>(g.nodes[node_id]->val);
        if (g.nodes[node_id]->inputs.size() > 0) std::cout << " " << g.nodes[node_id]->inputs[0]->id;
        std::cout << std::endl;
    }
	return 0;
}