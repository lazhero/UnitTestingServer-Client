#include"GraphProves.h"
#include"GraphAlgo/FloydWAlgo.h"
DoubleList<DoubleList<int>>* GraphTools::getRelationMatriz(int Nodes_Number){
    DoubleList<DoubleList<int>>* ReturningList=new DoubleList<DoubleList<int>>;
    DoubleList<int>* vector;
    for(int i=0;i<Nodes_Number;i++){
        vector=new DoubleList<int>;
        for(int j=0;j<Nodes_Number;j++){
            if(i!=j){
                vector->add(*new int(rand()));
            }
            else vector->add(*new int(DGraph<int>::maxValue));

          }
        ReturningList->add(*vector);

      }
    return ReturningList;
}
DGraph<int>* GraphTools::getGraph(DoubleList<DoubleList<int>>* List ){
    DGraph<int>* Graph=new DGraph<int>;
    initGraph(Graph,List->getLen());
    for(int i=0;i<List->getLen();i++){
        for(int j=0;j<List->getLen();j++){
            Graph->fixRelationShip(i,j,*List->get(i)->get(j));
        }
    }
    return Graph;
}

bool GraphTools::compare(DoubleList<DoubleList<int> > *Matrix, DGraph<int>* Graph)
{
    for(int i=0;i<Matrix->getLen();i++){
        for(int j=0; j<Matrix->getLen();j++){
            if(!(*Matrix->get(i)->get(j)==*Graph->getRelations(i)->get(j)))return false;

        }
    }
    return true;
}
void GraphTools::initGraph(DGraph<int>* graph,int len){
    for(int i =0;i<len;i++){
        graph->AddNode(i);
    }
}
void GraphTools::clearRoad(DGraph<int>* graph,int position){
    for(int i=0;i<graph->getRelations()->getLen();i++){
        for(int j=0;j<graph->getRelations()->getLen();j++){
            if(i==position || j==position){
                graph->fixRelationShip(i,j,DGraph<int>::maxValue);
            }
        }
    }
}

bool GraphTools::assertEmptyWay(DGraph<int>, int pos,int len)
{
    DoubleList<DoubleList<int>>* List=GraphTools::getRelationMatriz(len);
    DGraph<int>* Graph= GraphTools::getGraph(List);
    GraphTools::clearRoad(Graph,minIndex);
    FloydWResponse* floydR;
    floydR=Floyd(*new DoubleList<DoubleList<double>>(*Graph->getRelations()));
    DoubleList<double>* OutPrices=floydR->getPrices()->get(pos);
    for(int i=0;i<OutPrices->getLen();i++){
        if(*OutPrices->get(i)<DGraph<int>::maxValue && i!=pos)return false;
    }
    return true;
}
