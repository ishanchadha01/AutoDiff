#include "auto_diff_graph.hpp"
#include <iostream>


int main() {
    Variable x = Variable(0.9);
    Variable y = Variable(0.4);
    Variable z = Variable(1.3);
    Variable out = (x*y+z)*z + x;
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

    // Variable v = Variable(0.3);
    // Variable w = Variable(0.5);
    // Variable x = Variable(0.7);
    // Variable y = Variable(1.5);
    // Variable z = Variable(2.0);
    // Variable out = (y.power(x+y*z)*w)/v;
    // AutoDiffGraph g = AutoDiffGraph(out);
    // g.forward_pass();
    // std::cout << "Values: " << std::endl;
    // for (auto& node_id : g.top_sort) {
    //     std::cout << node_id << " " << std::get<double>(g.nodes[node_id]->val) << std::endl;
    // }
    // g.backward_pass();
    // std::cout << "Gradients: " << std::endl;
    // for (auto& node_id : g.top_sort) {
    //     std::cout << node_id << " " << std::get<double>(g.nodes[node_id]->gradient) << std::endl;
    // }
	return 0;
}