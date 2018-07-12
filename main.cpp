#include <QCoreApplication>
#include <QTimer>

#include "generator.h"


int main (int argc, char *argv[])
{
    QCoreApplication a (argc, argv);

    (new CGenerator (1));
    return a.exec();
}
