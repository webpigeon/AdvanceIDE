#include <qapplication.h>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QTreeView>
#include <QToolBar>
#include <QDockWidget>
#include <QString>
#include <QSizePolicy>

/**
 * 
 * 
 */
int main(int argc, char *argv[]){
	QApplication app( argc, argv );

	QMainWindow *win = new QMainWindow();
	win->setWindowTitle("Advance IDE");
	win->resize( 650, 600 );  
	
	QToolBar *tool = new QToolBar;
	tool->setFloatable(false);
	win->addToolBar(tool);
	tool->addAction(QString("File"));
	tool->addAction(QString("Edit"));
	tool->addAction(QString("Search"));
	tool->addAction(QString("View"));
	
	QDockWidget *dock = new QDockWidget;
	dock->setFeatures(QDockWidget::NoDockWidgetFeatures);
	dock->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
	QTreeView *files = new QTreeView( dock );
	files->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
	win->addDockWidget( Qt::LeftDockWidgetArea, dock );
	

    QTextEdit *hello = new QTextEdit( "Hello world!");  
    win->setCentralWidget(hello);

	
    win->show();
    return app.exec();
}
