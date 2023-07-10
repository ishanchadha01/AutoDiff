#include <numeric>

#include "operator.hpp"

class Mult : Operator {
	public:
		Mult();
		double forward();
		std::pair<input, input> backward(double d_out);
};