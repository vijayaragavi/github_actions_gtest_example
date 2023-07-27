#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using testing::Types;

class ITempSensor{
    public:
    virtual ~ITempSensor(){};
    virtual int getOutSideTemp()=0;
};

class ModelATempSensor:public ITempSensor{
    public:
    int getOutSideTemp(){ return  23;}
};
class ModelBTempSensor:public ITempSensor{
    public:
    int getOutSideTemp(){ return  23;}
};
class ModelCTempSensor:public ITempSensor{
    public:
    int getOutSideTemp(){ return  23;}
};
class AutoTempRegulator{
    ITempSensor* tempSensorPtr;
    public:
    AutoTempRegulator(ITempSensor* address):tempSensorPtr{address} {}
    void  regulateTemp(){
         this->tempSensorPtr->getOutSideTemp();
    }  
};
class MockTempSensor: public ITempSensor(){
    public:
    MOCK_METHOD(int,getOutsideTemp,());
}
TEST(AutoTempRegulatorTestSuite,RegulateTempInteractionTesting)
{
   MockTempSensor stubObj;
   AutoTempRegulator codeUnderTest(&stubObj);
   codeUnderTest.regulateTemp();//interaction
}

int main()
{
   ::testing::InitGoogleMock();
  RUN_ALL_TESTS
}
