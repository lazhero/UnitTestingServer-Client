#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<QLocalSocket>
#include<QTextStream>
#include<QMessageBox>
#define separator '#'
DoubleList<int> *LastInfo=nullptr;
int a=0;
int b=0;
int radius;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    graph=new Graph(ui->GraphCointainer);
    socket=new QLocalSocket(this);
    radius=20;
    graph->setRadius(radius);
    //a=parent->geometry().height()/2;
    //b=parent->geometry().width()/2;
    a=200;
    b=200;

}

MainWindow::~MainWindow()
{
    delete ui;


}

void MainWindow::paintEvent(QPaintEvent *event)
{

}



void MainWindow::on_AddEdge_clicked()
{
    QString Start=getLineEditText(ui->EdgeStartInput);
    QString End=getLineEditText(ui->EdgeStopInput);
    QString value=getLineEditText(ui->EdgeValueInput);
    int from=Start.toInt();
    int to=End.toInt();
    int price=value.toInt();
    QTextStream T(socket);
    T<<1<<separator<<from<<separator<<to<<separator<<price<<separator;
   socket->flush();
   if(LastInfo!=nullptr)free(nullptr);
   LastInfo=new DoubleList<int>;
   LastInfo->add(from);
   LastInfo->add(to);
   LastInfo->add(price);


}

void MainWindow::on_getRoute_clicked()
{
    QString Start=getLineEditText(ui->FloydStartInput);
    QString End=getLineEditText(ui->FloydStopInput);
    int from=Start.toUInt();
    int to=End.toInt();
    QTextStream T(socket);
    T<<"2"<<separator<<from<<separator<<to<<separator;
    socket->flush();

}

void MainWindow::on_AddNode_clicked()

{
    QTextStream T(socket);
    T<<"0#";
    socket->flush();
  }
QString MainWindow::getLineEditText(QLineEdit* lineEdit){
    return lineEdit->text() ;
}

void MainWindow::on_JoinButton_clicked()
{
    QString name=ui->serverName->text();
    socket->connectToServer(name);
    ui->JoinButton->setDisabled(true);
    connect(socket,&QLocalSocket::readyRead,[&]{
         QString string=socket->readAll();
         std::string value=string.toStdString();
         std::cout<<"El valor recibido es "<<value<<std::endl;
         if(value.length()>2){
             showM(string);
             return ;
         }
         int condition=string.toInt();
         switch (condition) {
            case 0:
             addNode();
             break;
         case 1:
             addRelationShip();
             break;
         default:
             showM(string);
             break;
         }


     });
}
void MainWindow::addNode(){    std::cout<<"Llegue a la respuesta de la vida"<<std::endl;

    int x;
    int y ;
     x = rand()%700+20;
     y = rand()%220+40;
    DoubleList<int> pos;
     graph->addNode(x,y);
    graph->update();

   // graph->addNode(a,b);
    //int graphNumber=graph->getNodesNumber();
   // DoubleList<QPoint> *points=getCirlePoints(radius*graphNumber,graphNumber,a,b);
   // graph->setPoints(points);
     //graph->update();
}

void MainWindow::addRelationShip()
{
    int source=*LastInfo->get(0);
    int to=*LastInfo->get(1);
    int value=*LastInfo->get(2);
    graph->addEdge(source,to,value);
    graph->update();
    //free(LastInfo);
    //LastInfo=nullptr;
    return;
}

void MainWindow::showM(QString message)
{
    QMessageBox::information(this,"",message);
}
