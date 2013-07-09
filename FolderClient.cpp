#include "FolderClient.h"
#include "LocalData.h"
#include <QDir>
#include <QDebug>

FolderClient::FolderClient(){
}

void FolderClient::createFolder(){

    sUserPath = CLIENT_FOLDER+"abc";//m_Login->getUserID();//
    QDir myFolder(sUserPath);
    QDir myStructLib(sUserPath+LIBRAIRIES_PATH);
    if(!myFolder.exists()){
        myStructLib.mkpath(".");
        myStructLib.mkdir(MODELS_PATH.section('/', -1));
        myStructLib.mkdir(MATERIALS_PATH.section('/', -1));

        myFolder.mkpath(PROJECT_PATH.section('/', -1)+BLUEPRINT_PATH);
        myFolder.mkpath(PROJECT_PATH.section('/', -1)+DESIGNER_PATH);
        myFolder.mkpath(PROJECT_PATH.section('/', -1)+RENDERING_PATH);
    }
    //Filling the paths
    sModelPath = myStructLib.absolutePath()+MODELS_PATH;
    sMaterialPath = myStructLib.absolutePath()+MATERIALS_PATH;
    sProjectPath = myFolder.absolutePath()+PROJECT_PATH;
    sBlueprintPath = sProjectPath+BLUEPRINT_PATH;
    sDesignerPath = sProjectPath+DESIGNER_PATH;
    sRenderingPath = sProjectPath+RENDERING_PATH;
}

QString FolderClient::getUserFolder(){
    return sUserPath;
}

QString FolderClient::getMaterialPath(){
    return sMaterialPath;
}

QString FolderClient::getModelPath(){
    return sModelPath;
}

QString FolderClient::getBlueprintPath(){
    return sBlueprintPath;
}

QString FolderClient::getDesignerPath(){
    return sDesignerPath;
}

QString FolderClient::getProjectPath(){
    return sProjectPath;
}

QString FolderClient::getRenderingPath(){
    return sRenderingPath;
}


bool FolderClient::saveWork(QString sfileName, QString stypeWork, const char *sData){
    bool theResult;
    if(stypeWork == PROJECT){
        //It is a project: Save its Id and Data in a XML file in the folder Project
        qDebug() << "Which folder?" << sProjectPath+'/'+sfileName+EXT;
        QFile sSavedFile(sProjectPath+'/'+sfileName+EXT);
        if(!sSavedFile.open(QIODevice::WriteOnly)){
            theResult = false;
            qDebug() << "can't write the file : " << sSavedFile.fileName();
        }else{
            sSavedFile.write(sData, qstrlen(sData));
            sSavedFile.close();
            theResult = true;
        }
    } else if(stypeWork == BLUEPRINT){
        //It is a blueprint: Save Data in a XML file in the folder Blueprint
        QFile sSavedFile(sBlueprintPath+'/'+sfileName+EXT);
        if(!sSavedFile.open(QIODevice::WriteOnly)){
            theResult = false;
            qDebug() << "can't write the file : " << sSavedFile.fileName();
        }else{
            sSavedFile.write(sData, qstrlen(sData));
            sSavedFile.close();
            theResult = true;
        }
    }else if(stypeWork == DESIGNER){
        //It is a designer: Save Data in a XML file in the folder Designer
        QFile sSavedFile(sDesignerPath+'/'+sfileName+EXT);
        if(!sSavedFile.open(QIODevice::WriteOnly)){
            theResult = false;
            qDebug() << "can't write the file : " << sSavedFile.fileName();
        }else{
            sSavedFile.write(sData, qstrlen(sData));
            sSavedFile.close();
            theResult = true;
        }
    }else if(stypeWork == RENDER){
        //It is a render: Save Data in a XML file in the folder Render
        QFile sSavedFile(sRenderingPath+'/'+sfileName+EXT);
        if(!sSavedFile.open(QIODevice::WriteOnly)){
            theResult = false;
            qDebug() << "can't write the file : " << sSavedFile.fileName();
        }else{
            sSavedFile.write(sData, qstrlen(sData));
            sSavedFile.close();
            theResult = true;
        }
    }
    return theResult;
}

QString FolderClient::fetchWork(QString sfileName, QString stypeWork){
    QString resultat;
    if(stypeWork == PROJECT){
        QFile sfileFetch(sProjectPath+'/'+sfileName+EXT);
        if(!sfileFetch.open(QIODevice::ReadOnly | QIODevice::Text )){
            qDebug() << "can't open the file : " << sfileFetch.fileName();
            resultat = "";
        }else{
            QTextStream myStream(&sfileFetch);
            resultat = myStream.readAll();
            sfileFetch.close();
        }
    }else if(stypeWork == BLUEPRINT){
        QFile sfileFetch(sBlueprintPath+'/'+sfileName+EXT);
        if(!sfileFetch.open(QIODevice::ReadOnly | QIODevice::Text )){
            qDebug() << "can't open the file : " << sfileFetch.fileName();
            resultat = "";
        }else{
            QTextStream myStream(&sfileFetch);
            resultat = myStream.readAll();
            sfileFetch.close();
        }
    }else if(stypeWork == DESIGNER){
        QFile sfileFetch(sDesignerPath+'/'+sfileName+EXT);
        if(!sfileFetch.open(QIODevice::ReadOnly | QIODevice::Text )){
            qDebug() << "can't open the file : " << sfileFetch.fileName();
            resultat = "";
        }else{
            QTextStream myStream(&sfileFetch);
            resultat = myStream.readAll();
            sfileFetch.close();
        }
    }else if(stypeWork == RENDER){
        QFile sfileFetch(sRenderingPath+'/'+sfileName+EXT);
        if(!sfileFetch.open(QIODevice::ReadOnly | QIODevice::Text )){
            qDebug() << "can't open the file : " << sfileFetch.fileName();
            resultat = "";
        }else{
            QTextStream myStream(&sfileFetch);
            resultat = myStream.readAll();
            sfileFetch.close();
        }
    }
    return resultat;
}
