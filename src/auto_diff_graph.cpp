#include "auto_diff_graph.hpp"
#include <iostream>


AutoDiffNode::AutoDiffNode() {
	
}

AutoDiffGraph::AutoDiffGraph() {

}

std::unordered_map<std::string, AutoDiffNode> AutoDiffGraph::get_nodes() {
	return this->nodes;
}

void AutoDiffGraph::set_nodes(std::unordered_map<std::string, AutoDiffNode> new_nodes) {
	this->nodes = new_nodes;
}

std::unordered_map< std::string, std::shared_ptr<Operator> > AutoDiffGraph::get_operators() {
	return this->operators;
}

void AutoDiffGraph::set_operators(std::unordered_map< std::string, std::shared_ptr<Operator> > new_operators) {
	this->operators = new_operators;
}

std::string AutoDiffNode::get_id() {
	return this->id;
}

void AutoDiffNode::set_id(std::string new_id) {
	this->id = new_id;
}