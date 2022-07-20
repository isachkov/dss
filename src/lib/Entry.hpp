#pragma once

#include <string>
#include <string_view>

namespace dss {
class Entry {
public:
  Entry(std::string, std::string);

  Entry(const Entry &) = delete;
  Entry(Entry &&) = delete;
  Entry &operator=(const Entry &) = delete;
  Entry &operator=(Entry &&) = delete;

  auto get_key() const noexcept -> std::string_view;
  auto get_value() const noexcept -> std::string_view;

private:
  std::string key_buffer_;
  std::string value_buffer_;
};
} // namespace dss