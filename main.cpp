#include "closemonitor.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CloseMonitor w;
    w.show();

    a.exec();
    return 0;
}
