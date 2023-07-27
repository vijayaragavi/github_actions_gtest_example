#include <gtest/gtest.h>
using testing::Types;
class ITempSensor{
public:
virtual int getOutsideTemp()=0;
};
class ModelATempSensor::public ITempSensor(){
  public:
  int getOutsideTemp(){
    return 23;
  }
};
class ModelBTempSensor::public ITempSensor(){
 public:
  int getOutsideTemp(){
    return 23;
  }
};
class AutoTemplateRegulator{
    ITempSensor* tempSensorPtr;
    public:
      AutoTempRegulator(ITempSensor* address):tempSensorPtr{address}{}
void regulateTemp(){
   this->tempSensorPtr->getOutSideTemp();
}
};
//Test Suite
template <typename T>
ITempSensor* createObject();
template <>
ITempSensor* createObject<ModelATempSensor>() { return new ModelATempSensor(); }
template <>
ITempSensor* createObject<ModelBTempSensor>() { return new ModelBTempSensor(); }
//Fixture
template <typename T>
class TempSensorFixture:public testing::Test{
protected
//arrange
ITempSensor* objUnderTest;
TempSensorFixture() :objUnderTest{ createObject<T>() } {}
}
typedef Types<ModelATempSensor,ModelBTempSensor> Implementations;

TYPED_TEST_SUITE(TempSensorFixture, Implementations);

TYPED_TEST(TempSensorFixture, Implementations) {
	ASSERT_EQ(objUnderTest->getOutsideTemp(),23);
}
