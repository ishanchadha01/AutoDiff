#pragma once

#include <unordered_map>
#include <memory>
#include "add.hpp"
#include "mult.hpp"
#include "pow.hpp"
#include "divide.hpp"
#include "variable.hpp"


class AutoDiffGraph {
  public:
		// AutoDiffGraph();
		AutoDiffGraph(AutoDiffNode& head);

		// void add_operator(Operator& oper);

		std::unordered_map< std::string, Variable* > variables;
		std::unordered_map< std::string, Operator* > operators;
		int variable_count = 0;
		int operator_count = 0;
		std::vector<std::vector<std::string>> adjacency_matrix;
        AutoDiffNode head;
};