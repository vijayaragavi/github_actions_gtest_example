#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using testing::Types;
//using ::testing::NiceMock
using ::testing::strictMock

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
   //NiceMock<MockTempSensor> mockObj; -> Nice GMOCK
    //StrictMock<MockTempSensor> mockObj; -> Strict GMOCK
    MockTempSensor mockObj; //-> Naggy GMOCK
    
   AutoTempRegulator codeUnderTest(&mockObj);
    //Set Expectation
    EXPECT_CALL(mockObj,getOutsideTemp()).Times(1);
   codeUnderTest.regulateTemp();//interaction
    
}

int main()
{
   ::testing::InitGoogleMock();
  RUN_ALL_TESTS
}
