#include "Entry.hpp"
#include <iostream>

namespace dss {
Entry::Entry(std::string key_buffer, std::string value_buffer)
    : key_buffer_(std::move(key_buffer)),
      value_buffer_(std::move(value_buffer)) {}

auto Entry::key() const noexcept -> std::string_view { return key_buffer_; }

auto Entry::value() const noexcept -> std::string_view { return value_buffer_; }

void Entry::key(std::string buffer) noexcept {
  key_buffer_ = std::move(buffer);
}
void Entry::value(std::string buffer) const noexcept {
  value_buffer_ = std::move(buffer);
}

} // namespace dss