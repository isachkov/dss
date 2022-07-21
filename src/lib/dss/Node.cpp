#include "Node.hpp"

namespace dss {
void Node::run() {
  while (is_runnig_) {
    transport_.receive_commands(executor_);
  }
}
} // namespace dss