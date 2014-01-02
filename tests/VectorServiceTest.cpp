#include <gtest/gtest.h>

#include <vector>
using std::vector;

#include "../src/VectorService.h"

TEST(VectorServiceTest, SwapElementsWithTwoDifferentElements)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    VectorService<int>::swapElements(integer_vector, 0, 1);
    EXPECT_EQ(2, integer_vector.at(0));
    EXPECT_EQ(1, integer_vector.at(1));
}

TEST(VectorServiceTest, SwapElementsWithElementsWithSameIndex)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    integer_vector.push_back(3);
    VectorService<int>::swapElements(integer_vector, 1, 1);
    EXPECT_EQ(1, integer_vector.at(0));
    EXPECT_EQ(2, integer_vector.at(1));
    EXPECT_EQ(3, integer_vector.at(2));
}

TEST(VectorServiceTest, SwapElementsWithElementsWithIndexLessZero)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    integer_vector.push_back(3);
    VectorService<int>::swapElements(integer_vector, -1, 1);
    EXPECT_EQ(1, integer_vector.at(0));
    EXPECT_EQ(2, integer_vector.at(1));
    EXPECT_EQ(3, integer_vector.at(2));
}

TEST(VectorServiceTest, SwapElementsWithElementsWithIndexMoreThanVectorSize)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    integer_vector.push_back(3);
    VectorService<int>::swapElements(integer_vector, 4, 1);
    EXPECT_EQ(1, integer_vector.at(0));
    EXPECT_EQ(2, integer_vector.at(1));
    EXPECT_EQ(3, integer_vector.at(2));
}

TEST(VectorServiceTest, SwapElementsWithNextElementCase1)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    integer_vector.push_back(3);
    VectorService<int>::swapWithNextElement(integer_vector, 0);
    EXPECT_EQ(2, integer_vector.at(0));
    EXPECT_EQ(1, integer_vector.at(1));
    EXPECT_EQ(3, integer_vector.at(2));
}

TEST(VectorServiceTest, SwapElementsWithNextElementCase2)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    integer_vector.push_back(3);
    VectorService<int>::swapWithNextElement(integer_vector, 1);
    EXPECT_EQ(1, integer_vector.at(0));
    EXPECT_EQ(3, integer_vector.at(1));
    EXPECT_EQ(2, integer_vector.at(2));
}

TEST(VectorServiceTest, SwapElementsWithNextElementWithIndexLessZero)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    integer_vector.push_back(3);
    VectorService<int>::swapWithNextElement(integer_vector, -5);
    EXPECT_EQ(1, integer_vector.at(0));
    EXPECT_EQ(2, integer_vector.at(1));
    EXPECT_EQ(3, integer_vector.at(2));
}

TEST(VectorServiceTest, SwapElementsWithNextElementWithIndexMoreVectorSize)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    integer_vector.push_back(3);
    VectorService<int>::swapWithNextElement(integer_vector, 5);
    EXPECT_EQ(1, integer_vector.at(0));
    EXPECT_EQ(2, integer_vector.at(1));
    EXPECT_EQ(3, integer_vector.at(2));
}

TEST(VectorServiceTest, MoreThanNextElementTrue)
{
    vector<int> integer_vector;
    integer_vector.push_back(3);
    integer_vector.push_back(2);
    integer_vector.push_back(1);
    EXPECT_EQ(true, VectorService<int>::moreThanNextElement(integer_vector, 0));
}

TEST(VectorServiceTest, MoreThanNextElementFalseWithRightIndex)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    integer_vector.push_back(3);
    EXPECT_EQ(false, 
              VectorService<int>::moreThanNextElement(integer_vector, 0));
}

TEST(VectorServiceTest, MoreThanNextElementFalseWithWrongIndexCase1)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    integer_vector.push_back(3);
    EXPECT_EQ(false, 
              VectorService<int>::moreThanNextElement(integer_vector, -4));
}

TEST(VectorServiceTest, MoreThanNextElementFalseWithIndexOfLastElement)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    integer_vector.push_back(3);
    EXPECT_EQ(false, 
              VectorService<int>::moreThanNextElement(integer_vector, 2));
}

TEST(VectorServiceTest, MoreThanNextElementFalseWithWrongIndexCase2)
{
    vector<int> integer_vector;
    integer_vector.push_back(1);
    integer_vector.push_back(2);
    integer_vector.push_back(3);
    EXPECT_EQ(false, 
              VectorService<int>::moreThanNextElement(integer_vector, 10));
}
