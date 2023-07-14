# Automatic Differentiation

This is a C++ Library for Automatic Differentiation. 

## Installation
After cloning the repo:

```bash
mkdir build
cmake ..
make
./AutoDiff
```

## Usage

```C++
#include "AutoDiff/auto_diff_graph.hpp"

int main() {
	auto graph = AutoDiffGraph();
	auto add = Add();
    // TODO: Actually add parameters here
	std::cout << "Ran main" << std::endl;
	return 0;
}
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first
to discuss what you would like to change.