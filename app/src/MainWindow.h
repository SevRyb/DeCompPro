
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <oclero/qlementine/widgets/FramelessWindow.hpp>
#include <oclero/qlementine/widgets/StatusBadgeWidget.hpp>
#include <oclero/qlementine/widgets/NavigationBar.hpp>
#include <oclero/qlementine/widgets/LineEdit.hpp>
#include <QVBoxLayout>
#include <QStackedLayout>
#include <QGridLayout>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QGroupBox>
#include <QSpinBox>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>

#include "widgets/BitsWidget.h"


using namespace oclero;

class MainWindow : public qlementine::FramelessWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    

private:

    QWidget *m_rootWidget;
    QVBoxLayout *m_rootLay;


    QPushButton *m_btn;

    BitsWidget *m_bitsWidget;


};

#endif // MAINWINDOW_H
