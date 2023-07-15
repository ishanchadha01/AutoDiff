#include <unordered_map>
#include <string>
#include <vector>
#include <variant>
#include <Eigen/Dense>
#include <iostream>

using data_type = std::variant<double, Eigen::MatrixXd>;
template<class... Ts> struct overload : Ts... { using Ts::operator()...; };
template<class... Ts> overload(Ts...) -> overload<Ts...>;


enum OperatorType {
    ADD = 0,
    MULT = 1,
    DIVIDE = 2,
    POW = 3
};


class Operator {
  public:
		Operator();

		data_type virtual forward() = 0;
		std::pair<data_type, data_type> virtual backward(double d_out) = 0;

        OperatorType type = ADD;
        data_type output_forward;
		std::string id;
		std::pair<data_type, data_type> inputs;
};