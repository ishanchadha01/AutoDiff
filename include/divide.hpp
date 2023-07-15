#include <numeric>

#include "operator.hpp"

class Divide : Operator {
	public:
		Divide();
		data_type forward();
		std::pair<data_type, data_type> backward(double d_out);
};