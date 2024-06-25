
//проверить являются ли числа А и В друзьями???
// напиример 220 и 284 друзья, а 34 и 45 не друзья

// Гриб Дарья 6 группа

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
