
#include <Map>

typedef struct{
	QString mime;
	QString filename;
	QTextDocument fileData;
} Document;

class DocumentManager{
	public:
		void open(QString filename);
		bool isOpen(QString filename);
		void close(QString filename);

	signals:
		void fileOpened(QString filename);
		void fileClosed(QString filename);

	private:
		std::Map<QString, QFile> files;
}

