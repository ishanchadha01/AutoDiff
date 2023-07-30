#pragma once

#include "auto_diff_node.hpp"



class Operator : public AutoDiffNode {
  public:
		Operator();

		virtual data_type forward() = 0;
		virtual std::vector<data_type> backward(data_type d_out) = 0;
    NodeType get_type();

		std::vector<data_type> input_vals;
    std::vector<data_type> gradients;
};