#pragma once

#include <string>
#include <string_view>

namespace dss {
class Entry {
public:
  Entry(std::string, std::string);

  Entry(const Entry &) = default;
  Entry(Entry &&) = default;
  Entry &operator=(const Entry &) = default;
  Entry &operator=(Entry &&) = default;

  auto key() const noexcept -> std::string_view;
  auto value() const noexcept -> std::string_view;

  void key(std::string) noexcept;
  void value(std::string) const noexcept;

private:
  std::string key_buffer_;
  mutable std::string value_buffer_;
};
} // namespace dss