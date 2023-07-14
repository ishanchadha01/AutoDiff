#include "auto_diff_graph.hpp"
#include <iostream>


int main() {
	auto graph = AutoDiffGraph();
	auto add = Add();
	std::cout << "Ran main" << std::endl;
	return 0;
}