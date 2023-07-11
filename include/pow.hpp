#include <numeric>
#include <cmath>

#include "operator.hpp"

class Pow : Operator {
	public:
		Pow();
		input forward();
		std::pair<input, input> backward(double d_out);
};