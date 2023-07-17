#pragma once

#include "auto_diff_node.hpp"



class Operator : public AutoDiffNode {
  public:
		Operator();

		data_type virtual forward() = 0;
		std::pair<data_type, data_type> virtual backward(double d_out) = 0;
        NodeType get_type();

        // OperatorType type = ADD;
        data_type output_forward;
		std::pair<data_type, data_type> input_vals;
};