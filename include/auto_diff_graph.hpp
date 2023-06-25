#include <unordered_map>
#include "operator.hpp"
#include "auto_diff_node.hpp"

class AutoDiffGraph {
  public:
		AutoDiffGraph();

      std::unordered_map<std::string, AutoDiffNode> get_nodes();
			void set_nodes(std::unordered_map<std::string, AutoDiffNode> new_nodes);

			std::unordered_map<std::string, Operator> get_operators();
			void set_operators(std::unordered_map<std::string, Operator> new_operators);

	private:
		std::unordered_map<std::string, AutoDiffNode> nodes;
		std::unordered_map<std::string, Operator> operators;
};