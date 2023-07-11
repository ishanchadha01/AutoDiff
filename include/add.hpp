#include <numeric>

#include "operator.hpp"

class Add : Operator {
	public:
		Add();
		double forward();
		std::pair<input, input> backward(double d_out);
};