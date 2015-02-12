#include "closemonitor.h"
#include "ui_closemonitor.h"
#include <QPainter>
#include <QRectF>
#include <QFont>
#include <QTimer>
#include <QDebug>
#include <QApplication>
#include <QCloseEvent>
#include <windows.h>

CloseMonitor::CloseMonitor(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CloseMonitor)
{
    ui->setupUi(this);
    setWindowTitle ("关闭显示器");
    resize(250,190);
    //全屏并且透明
    setWindowFlags (Qt::FramelessWindowHint);
    setAttribute (Qt::WA_TranslucentBackground);
    QTimer *timer=new QTimer(this);
    connect (timer,SIGNAL(timeout()),this,SLOT(update()));
    timer->start(1000);
}

CloseMonitor::~CloseMonitor()
{
    delete ui;
}

//关闭显示器，黑屏
void CloseMonitor::blackScreen()
{
    SendMessage(HWND_BROADCAST,WM_SYSCOMMAND,SC_MONITORPOWER,2);
}


void CloseMonitor::closeEvent(QCloseEvent *event)
{
    event->accept();
}

void CloseMonitor::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //左边距65，上边距20，大小100*100
    QRectF rect(0,0,250,140);
    QFont font("宋体",64,QFont::Bold,true);
    painter.setFont (font);
    if(num==3){
        painter.setPen (Qt::red);
    }else if(num==2){
        painter.setPen (Qt::green);
    }else if(num==1){
        painter.setPen (Qt::blue);
    }
    painter.drawText (rect,Qt::AlignCenter,QString::number (num));
    num=num-1;
    if(num==-1){
        this->close ();
//        QApplication::exit (0);
//        QApplication::quit ();
        blackScreen ();
    }
}
