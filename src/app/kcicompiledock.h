/*
 *  Copyright 2013 Kreogist Dev Team
 *
 *  This file is part of Kreogist-Cuties.
 *
 *    Kreogist-Cuties is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *    Kreogist-Cuties is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Kreogist-Cuties.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KCICOMPILEDOCK_H
#define KCICOMPILEDOCK_H

#include <QTreeView>
#include <QPalette>
#include <QWidget>
#include <QSplitter>
#include <QList>
#include <QVector>
#include <QPropertyAnimation>
#include <QDockWidget>
#include <QModelIndex>
#include <QDebug>
#include <QTimeLine>

#include "kciplaintextbrowser.h"
#include "compileoutputreceiver.h"
#include "connectionhandler.h"

class kcicompiledock : public QDockWidget
{
    Q_OBJECT
public:
    explicit kcicompiledock(QWidget *parent = 0);

    //Compile File Path
    void setCompileFilePath(QString FilePath);
    QString CompileFilePath();

    void setReceiver(const compileOutputReceiver* currReceiver);

private:
    QWidget *objCombine;
    QSplitter *splCombine;
    QTreeView *trevwCompileInfo;
    kciPlainTextBrowser *compileOutput;
    QModelIndex lastSelIndex;
    QTimeLine *animeShowTimeLine, *animeHideTimeLine;
    const QVector<ErrInfo> *erifList;
    connectionHandler receiverConnectionHandles;

signals:
    void requireOpenErrFile(QString filePath);
    void requireGotoLine(int nLineNum, int nColNum);
    void requireSetFocus();
    
public slots:
    //Show & Hide Error Animation.
    void animeShowError();
    void animeHideError();

private slots:
    void changeDockCompileWidth(int dockCompileWidth);
    void selectAnError(QModelIndex ItemIndex);
    void jumpToError(QModelIndex ItemID);
};

#endif // KCICOMPILEDOCK_H