
#include "MainWindow.h"

#include <QApplication>
#include <oclero/qlementine.hpp>

using namespace oclero;

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	auto* style = new qlementine::QlementineStyle(&app);
	style->setThemeJsonPath(":/light.json");
	QApplication::setStyle(style);
	QApplication::setWindowIcon(QIcon(QStringLiteral(":/icon.png")));

	MainWindow window;
	window.show();
	return app.exec();
}
