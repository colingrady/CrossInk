add_executable(MemoryPoolPolicyTest MemoryPoolPolicyTest.cpp)
target_include_directories(MemoryPoolPolicyTest PRIVATE stubs ${REPO_ROOT}/lib/Memory ${REPO_ROOT}/lib/MemoryBudget)
target_compile_definitions(MemoryPoolPolicyTest PRIVATE ARDUINO_ARCH_ESP32=1 CROSSINK_MEMORY_TEST=1)
target_link_libraries(MemoryPoolPolicyTest PRIVATE crosspoint_test_common GTest::gtest_main)
gtest_discover_tests(MemoryPoolPolicyTest PROPERTIES ENVIRONMENT "UBSAN_OPTIONS=halt_on_error=1")

find_package(ZLIB REQUIRED)
add_executable(InflateStreamStorageTest InflateStreamStorageTest.cpp
  ${REPO_ROOT}/lib/miniz/src/InflateStream.cpp ${REPO_ROOT}/lib/miniz/src/miniz_impl.c
  ${REPO_ROOT}/lib/Memory/BuildScratch.cpp)
target_include_directories(InflateStreamStorageTest PRIVATE stubs ${REPO_ROOT}/lib/Memory ${REPO_ROOT}/lib/MemoryBudget ${REPO_ROOT}/lib/miniz/src)
target_compile_definitions(InflateStreamStorageTest PRIVATE ARDUINO_ARCH_ESP32=1 CROSSINK_MEMORY_TEST=1)
target_link_libraries(InflateStreamStorageTest PRIVATE crosspoint_test_common GTest::gtest_main ZLIB::ZLIB)
gtest_discover_tests(InflateStreamStorageTest PROPERTIES ENVIRONMENT "UBSAN_OPTIONS=halt_on_error=1")

add_executable(SdFontBitmapStorageTest SdFontBitmapStorageTest.cpp
  ${REPO_ROOT}/lib/EpdFont/SdCardFont.cpp ${REPO_ROOT}/lib/EpdFont/EpdFont.cpp ${REPO_ROOT}/lib/Utf8/Utf8.cpp)
target_include_directories(SdFontBitmapStorageTest PRIVATE stubs ${REPO_ROOT}/lib/Memory ${REPO_ROOT}/lib/MemoryBudget ${REPO_ROOT}/lib/EpdFont ${REPO_ROOT}/lib/Utf8)
target_compile_definitions(SdFontBitmapStorageTest PRIVATE ARDUINO_ARCH_ESP32=1 CROSSINK_MEMORY_TEST=1)
target_link_libraries(SdFontBitmapStorageTest PRIVATE crosspoint_test_common GTest::gtest_main)
gtest_discover_tests(SdFontBitmapStorageTest PROPERTIES ENVIRONMENT "UBSAN_OPTIONS=halt_on_error=1")
