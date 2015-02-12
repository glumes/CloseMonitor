#ifndef CLOSEMONITOR_H
#define CLOSEMONITOR_H

#include <QWidget>
#include <windows.h>
#include <QCloseEvent>
namespace Ui {
class CloseMonitor;
}

class CloseMonitor : public QWidget
{
    Q_OBJECT

public:
    explicit CloseMonitor(QWidget *parent = 0);
    ~CloseMonitor();

    void blackScreen();
    void closeEvent (QCloseEvent * event);

private:
    Ui::CloseMonitor *ui;
    int num=3;

//声明重绘事件处理函数
protected:
    void paintEvent (QPaintEvent *event);
};

#endif // CLOSEMONITOR_H
