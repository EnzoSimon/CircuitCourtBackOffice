/********************************************************************************
** Form generated from reading UI file 'dialogconnexion.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGCONNEXION_H
#define UI_DIALOGCONNEXION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogConnexion
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_9;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_11;
    QLabel *labelIncorrect;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QLabel *label;
    QLineEdit *lineEditLogin;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QLineEdit *lineEditMdp;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButtonAnnuler;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *pushButtonSeConnecter;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *DialogConnexion)
    {
        if (DialogConnexion->objectName().isEmpty())
            DialogConnexion->setObjectName(QStringLiteral("DialogConnexion"));
        DialogConnexion->resize(558, 328);
        QFont font;
        font.setFamily(QStringLiteral("Quicksand"));
        DialogConnexion->setFont(font);
        DialogConnexion->setStyleSheet(QLatin1String("*{\n"
"	font-family: Quicksand;\n"
"	font-size: 14px;\n"
"}\n"
"QLineEdit{\n"
"max-width: 250px;\n"
"}\n"
"QLabel{\n"
"min-width: 80px;\n"
"}\n"
"QPushButton{\n"
"	width: 150px;\n"
"	padding: 10px 0;\n"
"	border-radius: 19;\n"
"	font-size: 15px;\n"
"	font-weight: 700;\n"
"	background-color: #aac9f0;\n"
"	border: 2px solid #4689db;\n"
"	color: #242424;\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"	background-color: #8199b8;\n"
"	border: 2px solid #2b578c;\n"
"}\n"
"\n"
"QLineEdit {\n"
"	border-radius: 15;\n"
"	border: 2px solid #4689db;\n"
"	padding: 5px;\n"
"}"));
        verticalLayout = new QVBoxLayout(DialogConnexion);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_9);

        label_3 = new QLabel(DialogConnexion);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("font-size : 30px; \n"
"color : #4689db;\n"
"font-weight: 700;\n"
""));

        horizontalLayout_4->addWidget(label_3);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_11);

        labelIncorrect = new QLabel(DialogConnexion);
        labelIncorrect->setObjectName(QStringLiteral("labelIncorrect"));
        labelIncorrect->setStyleSheet(QStringLiteral("color: red; "));

        horizontalLayout_5->addWidget(labelIncorrect);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_10);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        label = new QLabel(DialogConnexion);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        lineEditLogin = new QLineEdit(DialogConnexion);
        lineEditLogin->setObjectName(QStringLiteral("lineEditLogin"));

        horizontalLayout_2->addWidget(lineEditLogin);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        label_2 = new QLabel(DialogConnexion);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEditMdp = new QLineEdit(DialogConnexion);
        lineEditMdp->setObjectName(QStringLiteral("lineEditMdp"));
        lineEditMdp->setToolTipDuration(-8);
        lineEditMdp->setEchoMode(QLineEdit::Password);

        horizontalLayout->addWidget(lineEditMdp);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        pushButtonAnnuler = new QPushButton(DialogConnexion);
        pushButtonAnnuler->setObjectName(QStringLiteral("pushButtonAnnuler"));

        horizontalLayout_3->addWidget(pushButtonAnnuler);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        pushButtonSeConnecter = new QPushButton(DialogConnexion);
        pushButtonSeConnecter->setObjectName(QStringLiteral("pushButtonSeConnecter"));

        horizontalLayout_3->addWidget(pushButtonSeConnecter);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(DialogConnexion);

        pushButtonSeConnecter->setDefault(true);


        QMetaObject::connectSlotsByName(DialogConnexion);
    } // setupUi

    void retranslateUi(QDialog *DialogConnexion)
    {
        DialogConnexion->setWindowTitle(QApplication::translate("DialogConnexion", "BackOffice Connexion", nullptr));
        label_3->setText(QApplication::translate("DialogConnexion", "Connectez vous", nullptr));
        labelIncorrect->setText(QApplication::translate("DialogConnexion", "-- Login ou Mot de passe incorrect --", nullptr));
        label->setText(QApplication::translate("DialogConnexion", "Login :", nullptr));
        lineEditLogin->setInputMask(QString());
        lineEditLogin->setText(QApplication::translate("DialogConnexion", "admin", nullptr));
        lineEditLogin->setPlaceholderText(QApplication::translate("DialogConnexion", "Entrer le login ...", nullptr));
        label_2->setText(QApplication::translate("DialogConnexion", "Mot de passe :", nullptr));
        lineEditMdp->setText(QApplication::translate("DialogConnexion", "admin", nullptr));
        lineEditMdp->setPlaceholderText(QApplication::translate("DialogConnexion", "Entrer le mot de passe ...", nullptr));
        pushButtonAnnuler->setText(QApplication::translate("DialogConnexion", "Annuler", nullptr));
        pushButtonSeConnecter->setText(QApplication::translate("DialogConnexion", "Se connecter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogConnexion: public Ui_DialogConnexion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGCONNEXION_H
