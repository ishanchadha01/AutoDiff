
#include <string>

class Operator {
  public:
		Operator();

		std::string get_type();
		void set_type(std::string new_type);

	private:
		std::string type;
};