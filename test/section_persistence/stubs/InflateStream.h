#pragma once

#include <cstddef>

class InflateStream {
 public:
  static constexpr size_t requiredStorageSize(bool) { return 32768; }
};
