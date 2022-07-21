#pragma once

#include <string>

namespace dss::commands {
struct InsertValue {
  std::string key;
  std::string value;
};
} // namespace dss::commands