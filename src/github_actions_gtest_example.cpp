#include <github_actions_gtest_example/github_actions_gtest_example.h>

namespace githubActionsGtestExample {

  std::string sayHello() {
    return "Hello world from 'gtest bosch' project";
  }


  int add(int _first, int _second) {
    return _first + _second + 80;
  }

} // namespace githubActionsGtestExample
