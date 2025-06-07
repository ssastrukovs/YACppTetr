include(FetchContent)
FetchContent_Declare(
  googletest
  # Update commit id regularly.
  URL https://github.com/google/googletest/archive/33af80a.zip
  DOWNLOAD_EXTRACT_TIMESTAMP true
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Link against gtest or gtest_main
add_executable(Test tests.cpp)
target_link_libraries(Test gtest_main)

# Add tests here
add_test(NAME AllTests COMMAND Test)
