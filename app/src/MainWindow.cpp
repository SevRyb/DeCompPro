
#include "MainWindow.h"

#include <QDebug>
#include <QTextCodec>
#include <QByteArray>

using namespace oclero;

MainWindow::MainWindow(QWidget *parent)
    : qlementine::FramelessWindow(parent)

{
    setWindowTitle("DeCompPro");
    resize(800, 450);
    setMinimumHeight(450);

    m_rootLay = new QVBoxLayout;
    m_rootLay->setMargin(0);
    m_rootWidget = new QWidget(this);
    m_rootWidget->setLayout(m_rootLay);

    setContentWidget(m_rootWidget);


    m_btn = new QPushButton("0", this);
    m_btn->setCheckable(true);
    //m_btn->setFixedWidth(20);
    //m_btn->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    m_btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QPushButton *btn = new QPushButton("1", this);
    btn->setCheckable(true);
    //m_btn->setFixedWidth(20);
    //m_btn->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
    btn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);




    m_rootLay->addWidget(m_btn, 0, Qt::AlignTop);
    m_rootLay->addWidget(btn, 0, Qt::AlignTop);


    for (int var = 0; var < 2; ++var)
    {
        auto* checkBox = new QCheckBox(this);
        checkBox->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        m_rootLay->addWidget(checkBox, 0, Qt::AlignTop);
    }

    auto* textEdit = new qlementine::LineEdit(this);
    textEdit->setAlignment(Qt::AlignRight);
    textEdit->setUseMonoSpaceFont(true);
    QFont font = textEdit->font();
    font.setBold(true);
    textEdit->setFont(font);
    textEdit->setMaxLength(16+16/4);
    //textEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    textEdit->setFixedWidth(140);
    textEdit->setFixedWidth(140);
    m_rootLay->addWidget(textEdit, 0, Qt::AlignTop);


    m_bitsWidget = new BitsWidget(this);
    m_rootLay->addWidget(m_bitsWidget, 0, Qt::AlignTop);


    {
        auto* radio = new QRadioButton(this);
        radio->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        radio->setChecked(true);
        radio->setAttribute(Qt::WidgetAttribute::WA_TransparentForMouseEvents);
        m_rootLay->addWidget(radio, 0, Qt::AlignTop);
    }

    for (int var = 0; var < 3; ++var)
    {
        auto* radio = new QRadioButton(this);
        radio->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        m_rootLay->addWidget(radio, 0, Qt::AlignTop);
    }

    //radio1->setEnabled(false);






    m_rootLay->addStretch(1);

    //connect(m_navBar, &qlementine::NavigationBar::currentIndexChanged, this, &MainWindow::onPageChanged);

}

MainWindow::~MainWindow() {}

void MainWindow::closeEvent(QCloseEvent *event)
{
    qlementine::FramelessWindow::closeEvent(event);
}



