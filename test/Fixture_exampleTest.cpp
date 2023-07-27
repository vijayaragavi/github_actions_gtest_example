#include "gtest/gtest.h"
class C();
class B(
C* ptr
public:
B(C* addressofObject: ptr(addressofObject)){
}
);
class A( 
B* ptr
public:
A(B* addressofObject: ptr(addressofObject)){
}
bool operator(){
  return true;
}
);
//Fixture test
TEST(TestFixtureTest,OperationTest)
{
  //Arrange
  C cObj;
  B bObj(&cObj);
  A obj(&bObj);
  //Act and Assert
  ASSERT_TRUE(obj.operation());  
}

TEST(TestFixtureTest,OperationFalseTest)
{
  //Arrange
  C cObj;
  B bObj(&cObj);
  A obj(&bObj);
  //Act and Assert
  ASSERT_FALSE(obj.operation());  
}
