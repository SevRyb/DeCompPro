
#include "BitsWidget.h"
#include <QFontDatabase>

BitsWidget::BitsWidget(QWidget *parent)
    : QWidget{parent}
{
    setup();
}

QSize BitsWidget::sizeHint() const
{
    return m_sizeHint;
}

void BitsWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setFont(m_font);
    //painter.setBrush(Qt::yellow);
    painter.setPen(Qt::black);

    int circleX = padding;
    for (int i = 0; i < m_digits; ++i)
    {


        const QString bitStr = m_numberBinStr.mid(i, 1);
        if (bitStr.at(0) == '1')
            painter.setBrush(Qt::yellow);
        else
            painter.setBrush(Qt::white);

        QString digitIndexStr = QString::number(m_digits - i - 1);
        painter.drawEllipse(circleX, padding, m_circleDiameter, m_circleDiameter);

        QRect textRect(circleX, m_circleDiameter + padding, m_circleDiameter, height() - (m_circleDiameter + padding));
        painter.drawText(textRect, Qt::AlignCenter, digitIndexStr);

        textRect = QRect(circleX, padding, m_circleDiameter, m_circleDiameter);
        painter.drawText(textRect, Qt::AlignCenter, bitStr);

        circleX += m_circleDiameter + circlePadding;
        if ((i + 1) % 4 == 0)
            circleX += circleSpacing;
    }

    QPen pen;
    pen.setColor(Qt::red);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(0, 0, size().width(), size().height());
}

void BitsWidget::setup()
{
    const QStyle *style = this->style();
    const qlementine::QlementineStyle *qlementineStyle = qobject_cast<const qlementine::QlementineStyle*>(style);
    m_font = qlementineStyle->theme().fontMonospace;
    const QFontMetrics fontMetrics(m_font);



    m_number = 10;
    m_digits = 16;
    padding = 10;
    m_circleDiameter = 15;
    circlePadding = 1;
    circleSpacing = 5;
    QSize size;
    size.rwidth() = m_digits * m_circleDiameter + (m_digits - 1) * circlePadding + (m_digits / 4 - 1) * circleSpacing + 2 * padding;
    size.rheight() = m_circleDiameter + 2 * padding + fontMetrics.height();
    m_sizeHint = size;
    setFixedSize(size);

    m_numberBinStr = Utils::toBinStr(m_number, m_digits);
    //m_numberBinStr = "1111111111111111";
}

