#include <QtWidgets/QApplication>
#include "UI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    repo Repo("Taskuri.txt");
    service srv(Repo);
    GUI ui(srv);

    ui.show();
    
    return a.exec();
}
