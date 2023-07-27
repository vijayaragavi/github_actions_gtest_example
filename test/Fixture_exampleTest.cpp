
#include "gtest/gtest.h"
class C{};
class B
{
   C* ptr;
   public:
   //universal object creation
   B(C* addressofObject): ptr(addressofObject){
   }
};

class A
{
   B* ptr;
   public:
   //universal object creation
   A(B* addressofObject): ptr(addressofObject){
   }
   bool operation(){
     return true;
   }
};
class TestFixtureTestSuite:public testing::Test{
//anything we write in this class should be under protected
protected :
A* aPtr;
B *bPtr;
C* cPtr;
TestFixtureTestSuite(){
   //initialization
}
~TestFixtureTestSuite(){
   //Releasing the Resources
}
void Setup(){
   //Arrange
   this->aptr=new C();
   this->aptr=new B(cPtr);
   this->aptr=new A(bPtr);
}
void TearDown(){
   //delete resources
   delete cPtr;
   delete bPtr;
   delete aPtr;
}
};
 
TESTF(TestFixtureTestSuite, operationTrueTest)
{
   //Act and assert
   ASSERT_TRUE(aPtr->operation());

}
TESTF(TestFixtureTestSuite, operationFalseTest)
{
   //Act and assert
   ASSERT_FALSE(aPtr->operation());
}
