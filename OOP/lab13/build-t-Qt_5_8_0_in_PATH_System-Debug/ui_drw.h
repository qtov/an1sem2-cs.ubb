/********************************************************************************
** Form generated from reading UI file 'drw.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DRW_H
#define UI_DRW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_drw
{
public:

    void setupUi(QWidget *drw)
    {
        if (drw->objectName().isEmpty())
            drw->setObjectName(QStringLiteral("drw"));
        drw->resize(400, 300);

        retranslateUi(drw);

        QMetaObject::connectSlotsByName(drw);
    } // setupUi

    void retranslateUi(QWidget *drw)
    {
        drw->setWindowTitle(QApplication::translate("drw", "drw", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class drw: public Ui_drw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DRW_H
