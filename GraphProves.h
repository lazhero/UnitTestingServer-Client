#pragma once
#include"Graph/DirectedGraph.hpp"
class GraphTools{
public:
     static DoubleList<DoubleList<int>>* getRelationMatriz(int Nodes_Number);
     static DGraph<int>* getGraph(DoubleList<DoubleList<int>>* List );
     static bool compare(DoubleList<DoubleList<int>>* Matrix,DGraph<int>* Graph);
      static void clearRoad(DGraph<int>* graph,int position);
      static bool assertEmptyWay(DGraph<int>,int pos,int len);

private:
     static void initGraph(DGraph<int>* graph,int len);

};



