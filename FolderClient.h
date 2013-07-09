/**
 * @file FolderClient.h
 * @brief The FolderClient class will contain all required
 * definitions and basic utilities functions for the
 * client folder and its structure
 *
 * @author Alvine AGBO
 * @date 07/09/2013
 * @version 1.0
 */

#ifndef FOLDERCLIENT_H
#define FOLDERCLIENT_H

#include <QString>
#include <QByteArray>
#include <QTextStream>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QEventLoop>
#include "../../../../Desktop/Cairnsmith13/CairnSmith/CairnSmith/Server/ClientLib/sheer_cloud.h"
#include <QDir>
#include <QHash>
#include <QList>
#include "FileHash.h"
#include <QtTest/QtTest>
#include <QtTest/QTest>
//#include "cslogin.h"

class FolderClient : public QObject {
    Q_OBJECT

public:
    /**
     * @brief FolderClient
     * Constructor that set the client folder
     */
    FolderClient();

    /**
     * @brief saveWork
     * @param idWork
     * @param sProject
     * @param sData
     * @return
     */
    bool saveWork(QString sfileName, QString stypeWork, const char *sData);

    /**
     * @brief fetchWork
     * @param sfileName
     * @param stypeWork
     * @return
     */
    QString fetchWork(QString sfileName, QString stypeWork);

    /**
     * @brief createFolder
     * This will be used to create the structure of the
     * folder where will be stored all the Libraries
     * used by the user
     */
    void createFolder();

    /**
     * @brief getUserFolder
     * This getter help to retrieve the path of the user's
     * folder.
     * @return a Qstring of user's path.
     */
    QString getUserFolder();

    /**
     * @brief getModelPath
     * This function helps to get the path of the Models
     * folder under CSLibrairies
     * @return a QString that is the path
     */
    QString getModelPath();

    /**
     * @brief getMaterialPath
     * This function helps to get the path of the Materials
     * folder under CSLibrairies
     * @return a QString that is the path
     */
    QString getMaterialPath();

    /**
     * @brief setLogin
     * This function helps to set the userId
     * @param login is the userId that has been filled
     */
    void setLogin(QString *login){//(CSLogin *login){//
        m_Login = login;
    }

    /**
     * @brief getProjectPath
     * This function helps to get the path of the projects'
     * folder.
     * @return a QString that is the path
     */
    QString getProjectPath();

    /**
     * @brief getBlueprintPath
     * This function helps to get the path of the blueprints'
     * folder.
     * @return a QString that is the path
     */
    QString getBlueprintPath();

    /**
     * @brief getDesignerPath
     * This function helps to get the path of the designers'
     * folder.
     * @return a QString that is the path
     */
    QString getDesignerPath();

    /**
     * @brief getRenderingPath
     * This function helps to get the path of the renderings'
     * folder.
     * @return a QString that is the path
     */
    QString getRenderingPath();

private:
    QString sUserPath;
    QString sModelPath;
    QString sMaterialPath;
    QString sProjectPath;
    QString sBlueprintPath;
    QString sDesignerPath;
    QString sRenderingPath;
    QString *m_Login;//CSLogin *m_Login; //
};

#endif // FOLDERCLIENT_H
