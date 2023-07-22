#pragma once

#include <numeric>
#include <cmath>
#include "operator.hpp"

class Pow : public Operator {
	public:
		Pow(AutoDiffNode* node1, AutoDiffNode* node2);
		virtual data_type forward();
		virtual std::pair<data_type, data_type> backward(double d_out);
};