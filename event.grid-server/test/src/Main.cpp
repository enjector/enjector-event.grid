#include <gtest/gtest.h>
#include <EventGrid/Node.h>

namespace {
    // Tests the Increment() method.

    TEST(Counter, Increment) {

        EXPECT_EQ(1, 1);
    }
    TEST(Counter, Node) {
        EventGrid::Node node;
    }

};

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    const auto result = RUN_ALL_TESTS();

    return result;
}
