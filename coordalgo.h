/**
  *@file coordalgo.h
  */

#ifndef COORDALGO_H
#define COORDALGO_H
#include<QPoint>
#include "Graph.h"
/**
 * @brief get a list of point in the circle
 * @param radius of the circle
 * @param number of point in the circle
 * @param x coord of the circle center
 * @param y coord of the circle center
 * @return
 */
DoubleList<QPoint>* getCirlePoints(int radius,int subdivision,int x_Center,int y_Center);
#endif // COORDALGO_H
