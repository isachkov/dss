#pragma once

#include "../Types.hpp"
#include <string>

namespace dss::commands {
struct PrepareTransaction {
  TransactionID id;
  std::string transaction;
};
} // namespace dss::commands