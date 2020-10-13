/**
  *@file mainwindow.h
  * @version 1.0
  * @date 25/09/2020
  * @author Luis Andrey Zuniga
  * @title mainwindow
  */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPainter>
#include<QPaintEvent>
//#include<Graph.h>
#include"coordalgo.h"
#include<QLineEdit>
class QLocalSocket;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow class needed constructor
     * @param parent QtWidget
     */
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent* event);


private slots:
    /**
     * @brief what to do when the Add Edge push button is clicked
     */
    void on_AddEdge_clicked();
    /**
     * @brief what to do when the get route button is clicket
     */

    void on_getRoute_clicked();
    /**
     * @brief what to do when the add node button is clicket
     */
    void on_AddNode_clicked();
    /**
     * @brief what to do when the JoinButton is clicked
     */

    void on_JoinButton_clicked();

private:
    /**
     * @brief the graph widget
     */
    Graph * graph;
    Ui::MainWindow *ui;
    /**
     * @brief the scoket to send/recieve info
     */
    QLocalSocket* socket;
    /**
     * @brief get a QString of a QLineText given
     * @param pointer to QLineEdit
     * @return  a QString from the QLineEdit
     */
    QString getLineEditText(QLineEdit* lineEdit);
    /**
     * @brief addNode to the graphic graph
     */
    void addNode();
    /**
     * @brief addRelationShip between two nodes
     */
    void addRelationShip();
    /**
     * @brief shows a Notification with the give QString
     * @param QString message
     */
    void showM(QString message);

};
#endif // MAINWINDOW_H
