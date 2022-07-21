#pragma once

#include "../Types.hpp"

namespace dss::commands {
struct CommitTransaction {
  TransactionID id;
};
} // namespace dss::commands