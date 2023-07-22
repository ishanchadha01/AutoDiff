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
		AutoDiffGraph(Variable& head);
        void forward_pass();

		std::unordered_map< std::string, AutoDiffNode* > nodes;
        std::vector<std::string> top_sort;
		// std::unordered_map< std::string, Operator* > operators;
		int variable_count = 0;
		int operator_count = 0;
        AutoDiffNode* head;

    private:
        void _dfs(AutoDiffNode* node);
};