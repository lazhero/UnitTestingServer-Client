#include<DoubleList/DoubleList.hpp>
#include<string>
#include<iostream>
#include<gtest/gtest.h>
int ArrayLen=1000;
int lowestPosition=0;
void initializeAnIntegerList(DoubleList<int> &List,int len){
    for(int i=0;i<len;i++){
        List.add(i);
    }
}
void initializaAnIntegerArray(int Array[],int len){
    for(int i=0;i<len;i++){
        Array[i]=i;
    }
}
TEST(List,DoubleList_IO){
    int IntegerArray[ArrayLen];
    DoubleList<int> IntegerList;
    initializaAnIntegerArray(IntegerArray,ArrayLen);
    initializeAnIntegerList(IntegerList,ArrayLen);
    for(int i=0;i<ArrayLen;i++){
        EXPECT_EQ(IntegerArray[i],*IntegerList.get(i));
    }
    std::cout<<"Mateme Satamas"<<std::endl;

}
TEST(List,DoubleListDelete){
    int IntegerArray[ArrayLen];
    DoubleList<int> IntegerList;
    initializaAnIntegerArray(IntegerArray,ArrayLen);
    initializeAnIntegerList(IntegerList,ArrayLen);
    for(int i=0;i<ArrayLen;i++){
        EXPECT_EQ(IntegerArray[i],*IntegerList.get(lowestPosition));
        IntegerList.erase(lowestPosition);
    }
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

