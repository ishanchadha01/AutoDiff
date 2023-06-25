#include "auto_diff_graph.hpp"
#include <iostream>

AutoDiffNode::AutoDiffNode() {

}

AutoDiffGraph::AutoDiffGraph() {

}

Operator::Operator() {

}

std::unordered_map<std::string, AutoDiffNode> AutoDiffGraph::get_nodes() {
	return this->nodes;
}

void AutoDiffGraph::set_nodes(std::unordered_map<std::string, AutoDiffNode> new_nodes) {
	this->nodes = new_nodes;
}

std::unordered_map<std::string, Operator> AutoDiffGraph::get_operators() {
	return this->operators;
}

void AutoDiffGraph::set_operators(std::unordered_map<std::string, Operator> new_operators) {
	this->operators = new_operators;
}

std::string Operator::get_type() {
	return this->type;
}

void Operator::set_type(std::string new_type) {
	this->type = new_type;
}

std::string AutoDiffNode::get_id() {
	return this->id;
}

void AutoDiffNode::set_id(std::string new_id) {
	this->id = new_id;
}

int main() {
	auto graph = AutoDiffGraph();
	std::cout << "Ran main" << std::endl;
	return 0;
}