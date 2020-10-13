#include "coordalgo.h"
#include "bits/stdc++.h"
//#include "DoubleList/DoubleList.hpp"

DoubleList<QPoint>* getCirlePoints(int radius,int subdivision,int x_Center,int y_Center){
    DoubleList<QPoint> *points=new DoubleList<QPoint>;
    double pi=2*acos(0.0);
    int angle=0;
    int x_Pos;
    int y_Pos;
    for(int i=0;i<subdivision;i++){
        angle=(2*pi/subdivision)*i;
        x_Pos=radius*cos(angle)+x_Center;
        y_Pos=radius*sin(angle)+y_Center;
        points->add(*new QPoint(x_Pos,y_Pos));
    }
    std::cout<<"El len de los puntos es "<<points->getLen()<<std::endl;
    return points;
}
