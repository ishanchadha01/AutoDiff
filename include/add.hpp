#pragma once

#include <numeric>
#include "operator.hpp"

class Add : public Operator {
	public:
		Add(AutoDiffNode* node1, AutoDiffNode* node2);
		virtual data_type forward();
		virtual std::vector<data_type> backward(data_type d_out);
};