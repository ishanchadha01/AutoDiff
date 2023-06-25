

class AutoDiffNode {
  public:
		AutoDiffNode();

		std::string get_id();
		void set_id(std::string new_id);

	private:
		std::string id = "undefined/";
};