/**
  *@file Graph.h
  * @version 1.0
  * @date 25/09/2020
  * @author Luis Andrey Zuniga
  * @title Graph
  */
#ifndef THENODE_H
#define THENODE_H

#include <QWidget>
#include<QPainter>
#include "DoubleList/DoubleList.hpp"
#include<string>
#include<math.h>
#define Defaul_Radius 20
#define FontType "times"
#include<QtDesigner/QDesignerCustomWidgetInterface>
class Graph : public QWidget//,public QDesignerCustomWidgetInterface
{
    Q_OBJECT
   // Q_INTERFACES(QDesignerCustomWidgetInterface)
public:
    explicit Graph(QWidget *parent = nullptr);
    /**
     * @brief addNode at a (x,y) position
     * @param x position
     * @param y position
     */
    void addNode(int x,int y);
    /**
     * @brief setRadius
     * @param int rad
     */
    void setRadius(int rad);
    /**
     * @brief add a conection between two nodes
     * @param int first node
     * @param int second node
     * @param int value of the relationShip
     */
    void addEdge(int a,int b,int value);
    /**
     * @brief setSize of the graph chart
     * @param int width
     * @param int height
     */
    void setSize(int x,int y);
    /**
     * @brief set a List of points of the graph
     * @param pointer to DoubleList<QPoint>
     */
    void setPoints(DoubleList<QPoint>* points);
    /**
     * @brief get the number of nodes
     * @return int nodes number
     */
    int getNodesNumber();
protected:
    void paintEvent(QPaintEvent* event);
private:
    /**
     * @brief DoubleList<QPoint> pointer
     */
    DoubleList<QPoint>* Points;
    /**
     * @brief radius of the node
     */
    int *radius;
    /**
     * @brief Pointer DoubleList<int> that saves the relationShips
     */
    DoubleList<int>* Edges;
    /**
     * @brief ointer DoubleList<QPoint> the position of the text
     */
    DoubleList<QPoint> *stringPoint;
    /**
     * @brief deprecated, was supposed to save the text int the nodes
     */
    DoubleList<int>* stringValues;
    /**
     * @brief the len of the widget
     */
    int *Xlen=new int(800);
    /**
     * @brief the heigh of the widget
     */
    int *Ylen=new int(800);
};

#endif // THENODE_H
