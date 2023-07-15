#include <numeric>
#include <cmath>

#include "operator.hpp"

class Pow : Operator {
	public:
		Pow();
		data_type forward();
		std::pair<data_type, data_type> backward(double d_out);
};