#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setText(QString::number(thickness));
    ui->lineEdit_2->setText(QString::number(delay));
    ui->lineEdit_3->setText(QString::number(num_ticks));

    

    scene = new QGraphicsScene{this};
    ui->graphicsView->setScene(scene);
    
    QPen blackpen{Qt::black};
    blackpen.setWidth(thickness);
    QGraphicsLineItem *line;
    line = this->scene->addLine(0, 0, 0, -550, blackpen);
    line = this->scene->addLine(0, 0, 550, 0, blackpen);


    connect(ui->lineEdit, &QLineEdit::editingFinished, this, &MainWindow::thick_changed);

    // QPen blackpen{Qt::black};
    // QBrush redbrush{Qt::red};
    

    
    

    // connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::handle_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::thick_changed()
{
    draw();
}

void MainWindow::draw()
{   
    scene->clear();
    ui->graphicsView->items().clear();

    QPen blackpen{Qt::black};
    blackpen.setWidth(thickness);
    QGraphicsLineItem *line;
    line = this->scene->addLine(0, 0, 0, -550, blackpen);
    line = this->scene->addLine(0, 0, 550, 0, blackpen);
    
    // failed to implement using functors
    // draw_line a{scene,0,0,100,100, blackpen};

    qint16 l{static_cast<short int>((500)/num_ticks)};

    qint16 x1{0};
    qint16 y1{-500};
    qint16 x2{l};
    qint16 y2{0};

    
    
    for (size_t i{0}; i<num_ticks; i++)
    {
        QTimer::singleShot(delay * (i+1), this, [x1, y1, x2, y2, this, blackpen](){
            QGraphicsLineItem *line;
            line = this->scene -> addLine(x1, y1, x2, y2, blackpen);
        });
        y1 += l;
        x2 += l;
    }

}
