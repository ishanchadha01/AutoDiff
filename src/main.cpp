#include "auto_diff_graph.hpp"
#include <iostream>


int main() {
	// auto graph = AutoDiffGraph();
    AutoDiffNode* x = new Variable(0.5);
    AutoDiffNode* y = new Variable(1.5);
    AutoDiffNode* z = *x + y;
    AutoDiffGraph g = AutoDiffGraph(z);
	std::cout << "Ran main" << std::endl;
	return 0;
}