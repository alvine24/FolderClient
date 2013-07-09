/**
 * @file LocalData.h
 * @brief This header contains all constant data used in the aplication
 *
 */

#include <QString>
#include <QDir>

#ifndef LOCALDATA_H
#define LOCALDATA_H

//QString
const QString CLIENT_FOLDER     =   QDir::homePath()+"/Cairnsmith/";
const QString PROJECT           =   "Projects";
const QString BLUEPRINT         =   "Blueprint";
const QString DESIGNER          =   "Designer";
const QString RENDER            =   "Render";

const QString USER_MAIN_PATH    =   "/Cairnsmith";
const QString MATERIALS_PATH    =   "/Materials";
const QString MODELS_PATH       =   "/Models";
const QString PROJECT_PATH      =   "/Projects";
const QString BLUEPRINT_PATH    =   "/Blueprint";
const QString DESIGNER_PATH     =   "/Designer";
const QString RENDERING_PATH    =   "/Render";
const QString LIBRAIRIES_PATH   =   "/CSLibrairies";
const QString EXT               =   ".xml";

#endif // LOCALDATA_H
