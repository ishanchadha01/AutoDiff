#include <unordered_map>
#include <memory>
#include "add.hpp"
#include "auto_diff_node.hpp"


class AutoDiffGraph {
  public:
		AutoDiffGraph();

		void add_operator(Operator& oper);

		std::unordered_map< std::string, Variable* > variables;
		std::unordered_map< std::string, Operator* > operators;
		int variable_count = 0;
		int operator_count = 0;
		std::vector<std::vector<std::string>> adjacency_matrix;
};