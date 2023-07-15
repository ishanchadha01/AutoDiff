

enum NodeType {
    VARIABLE = 0,
    OPERATOR = 1
};

class AutoDiffNode {
  public:
		AutoDiffNode();
        // AutoDiffNode(Operator& operator);
        // AutoDiffNode(Variable& variable);
        NodeType type;
		std::string id = "undefined/";
};