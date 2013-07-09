#include <QApplication>
#include "FolderClient.h"
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FolderClient myFolder;
    myFolder.createFolder();

    //bool resultat = myFolder.saveWork("project_01", "Projects", "Test Projet Create");
    //bool resultat = myFolder.saveWork("blueprint_01", "Blueprint", "Test Blueprint Create");
    //bool resultat = myFolder.saveWork("designer_01", "Designer", "Test Designer Create");
    //bool resultat = myFolder.saveWork("render_01", "Render", "Test Render Create");
    //qDebug() << "Is the workk saved? :" << resultat;

    QString resultat = myFolder.fetchWork("project_01", "Projects");
    qDebug() << "The data is loaded :" << resultat;

    return app.exec();
}
