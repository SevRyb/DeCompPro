
#ifndef BITSWIDGET_H
#define BITSWIDGET_H


#include <QWidget>
#include <QPainter>
#include <oclero/qlementine/style/QlementineStyle.hpp>

#include "../utils/Utils.h"


using namespace oclero;

class BitsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BitsWidget(QWidget *parent = nullptr);
    QSize sizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;

signals:

private:
    void setup();

    int m_number;
    QString m_numberBinStr;
    int m_digits;


    QFont m_font;
    QSize m_sizeHint;


    int padding;
    int circlePadding;
    int circleSpacing;
    int m_circleDiameter;

};

#endif // BITSWIDGET_H
