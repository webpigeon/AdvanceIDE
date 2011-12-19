#include <QApplication>
#include <QMainWindow>
#include <QTabWidget>
#include <QTextEdit>
#include <QToolBar>

#include "MainWindow.h"
#include "CodeEditor.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	
	MainWindow *window = new MainWindow();
	window->show();
	
	return app.exec();
}
