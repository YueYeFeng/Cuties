/*
 *  Copyright 2013 Kreogist Dev Team
 *
 *      Wang Luming <wlm199558@126.com>
 *      Miyanaga Saki <tomguts@126.com>
 *      Zhang Jiayi <bf109g2@126.com>
 *
 *  This file is part of Kreogist-Cute-IDE.
 *
 *    Kreogist-Cute-IDE is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *    Kreogist-Cute-IDE is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Kreogist-Cute-IDE.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KCICONTROLCENTER_H
#define KCICONTROLCENTER_H

#include <QWidget>
#include <QToolButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPalette>
#include <QFrame>
#include <QLabel>
#include <QIcon>
#include <QSize>
#include <QFont>
#include <QRect>
#include <QSignalMapper>
#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QHBoxLayout>
#include <QStackedWidget>

#include "kcisearchlinetext.h"
#include "kciccgerneral.h"
#include "kcilistbutton.h"

class kciControlCenterBanner : public QWidget
{
    Q_OBJECT
public:
    explicit kciControlCenterBanner(QWidget *parent = 0);

private:
    QHBoxLayout *TitleLayout;
    QLabel *lblBannerTitle;
    kciSearchLineText *CCSearch;
};

class kciControlCenter : public QWidget
{
    Q_OBJECT
public:
    explicit kciControlCenter(QWidget *parent = 0);
    
signals:
    
public slots:

private slots:
    void lstClick(int Index);

private:
    QStackedWidget *ccMainTabs;
    QVBoxLayout *WholeTitleBarSplit;
    QHBoxLayout *ContentLayout;
    QStackedWidget *CCMainContents;
    kciControlCenterBanner *ccBanner;

    enum kciCCLists
    {
        cclstGerneral,
        cclstEditor,
        cclstCompiler,
        cclstDebugger,
        cclstFileAssociation,
        cclist_count
    };

    QSequentialAnimationGroup *WholeAnimeGroup;
    kciListButton *lsbLeftButtons[cclist_count];
    QSignalMapper *lstMapper;
    int lstSelect;
    void createLeftList();
    
};

#endif // KCICONTROLCENTER_H
