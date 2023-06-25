#include <unordered_map>
#include <string>
#include <vector>
#include <variant>


using inputs_pair = std::pair< std::variant<double>, std::variant<double> >;

class Operator {
  public:
		Operator();
		std::string get_id();
		void set_id(std::string new_type);
		inputs_pair get_inputs();
		// void set_inputs(std::vector<double> new_inputs);

		double virtual forward() = 0;
		inputs_pair virtual backward(double d_out) = 0;

	private:
		std::string id;
		inputs_pair inputs; // Can add more types to variant as more operators created
};