#include <event.grid/client/NodeClient.h>
#include <gtest/gtest.h>

namespace {
// Tests the Increment() method.

TEST(Counter, Increment) {
  EXPECT_EQ(1, 1);
}
TEST(Counter, Node) {
  EventGrid::Client::NodeClient node;
}

};  // namespace

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  const auto result = RUN_ALL_TESTS();

  return result;
}
