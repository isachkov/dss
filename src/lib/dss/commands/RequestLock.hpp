#pragma once

#include "../Types.hpp"
#include <string>
#include <vector>

namespace dss::commands {
struct RequestLock {
  LockID id;
  std::vector<std::string> keys;
};
} // namespace dss::commands