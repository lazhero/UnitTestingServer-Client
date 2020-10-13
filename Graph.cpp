#include "Graph.h"
#include<iostream>

Graph::Graph(QWidget *parent) : QWidget(parent)
{
    Points=new DoubleList<QPoint>;
    radius=new int(Defaul_Radius);
    Edges=new DoubleList<int>;
    stringPoint=new DoubleList<QPoint>;
    stringValues=new DoubleList<int>;
    resize(*Xlen,*Ylen);
}
void Graph::paintEvent(QPaintEvent *event){
    QPoint temp;
    int size;
    QPainter painter(this);
    QFont font(FontType,*radius);
    QPen pen(Qt::white,*radius/10);
    painter.setPen(pen);
    painter.setBrush(Qt::red);
    painter.setFont(font);
    size=*radius/2;
    for(int i=0;i<Edges->getLen()-1;i++){
        painter.drawLine(*Points->get(*Edges->get(i)),*Points->get(*Edges->get(i+1)));
    }

    for(int i=0;i<Points->getLen();i++){
        painter.drawEllipse(*Points->get(i),*radius,*radius);
        temp=*new QPoint(Points->get(i)->x()-size,Points->get(i)->y()+size);
        painter.drawText(temp,QString::number(i));
    }
    font=*new QFont("times",*radius/2);
    painter.setFont(font);
    for(int i=0;i<stringPoint->getLen();i++){
        QString string=QString::number(*stringValues->get(i));
        painter.drawText(*stringPoint->get(i),string);
    }


}
void Graph::addNode(int x,int y){
    QPoint* point=new QPoint(x,y);
   Points->add(*point);

}
void Graph::addEdge(int a, int b, int value){
    Edges->add(*new int(a));
    Edges->add(*new int(b));
    QPoint point1=*Points->get(a);
    QPoint point2=*Points->get(b);
    int xDif=point1.x()-point2.x();
    int yDif=point1.y()-point2.y();
    int m=(yDif)/(xDif);//slope
    int start;// x lower coord
    int x;//x coord
    int y;//y coord
    int bs=point1.y()-m*point1.x();// interseccion y axis
    if(xDif<0){
        xDif=-xDif;
        start=point1.x();
    }
    else start=point2.x();
    x=(xDif/2)+start;
    y=m*x+bs;
    stringPoint->add(*new QPoint(x,y));
   stringValues->add(*new int(value));



}
void Graph::setRadius(int rad){
    *radius=*new int(rad);
}
void Graph::setSize(int x, int y){
    if(x>0)*Xlen=*new int(x);
    if(y>0)*Ylen=*new int(y);
    resize(*Xlen,*Ylen);
}

void Graph::setPoints(DoubleList<QPoint> *points)
{
    free(Points);
    Points=points;
}

int Graph::getNodesNumber()
{
    return Points->getLen();
}
