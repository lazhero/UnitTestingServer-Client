#include"GraphAlgo/FloydWAlgo.h"
#include"DoubleList/DoubleList.hpp"
#include<string>
#include<iostream>
#include<gtest/gtest.h>
#include"GraphProves.h"
#include"Graph/DirectedGraph.hpp"

int ArrayLen=100;
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
TEST(Graph,AddRelations){
    DoubleList<DoubleList<int>>* List=GraphTools::getRelationMatriz(ArrayLen);
    DGraph<int>* Graph= GraphTools::getGraph(List);
    EXPECT_EQ(GraphTools::compare(List,Graph),true);

}
TEST(Graph,WarshallAlgo){
    DoubleList<DoubleList<int>>* List=GraphTools::getRelationMatriz(ArrayLen);
    DGraph<int>* Graph= GraphTools::getGraph(List);
    EXPECT_EQ(GraphTools::assertEmptyWay(*Graph,minIndex,ArrayLen),true);


}


