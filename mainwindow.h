#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <iostream>
#include <QtGui>
#include <QGraphicsScene>
#include <QThread>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void thick_changed();
    void draw();
    

    // class draw_line
    // {
    // public:
    //     draw_line (QGraphicsScene *_scene ,qint16 _x1, qint16 _y1, qint16 _x2, qint16 _y2, QPen& _pen):
    //     scene{_scene},x1{_x1},y1{_y1},x2{_x2},y2{_y2}, pen{_pen}
    //     {
    //     }
    //     void operator()()
    //     {
    //         QGraphicsLineItem *line;
    //         line = scene -> addLine(x1, y1, x2, y2, pen);
    //     }
    // private:
    //     qint16 x1;
    //     qint16 y1;
    //     qint16 x2;
    //     qint16 y2;
    //     QGraphicsScene *scene;
    //     QPen pen;
    // };

private:
    Ui::MainWindow *ui;

    qint16 thickness{1};
    qint16 delay{400};
    qint16 num_ticks{11};


    QGraphicsScene *scene;
    
};
#endif // MAINWINDOW_H
