#include "CodeEditor.h"

class LineNumberArea : public QWidget
{
	public:
		LineNumberArea(CodeEditor* editor) : QWidget(editor){
			codeEditor = editor;
		}

		QSize sizeHint() const{
			return QSize(codeEditor->lineNumberAreaWidth(), 0);
		}
		
	protected:
		void paintEvent(QPaintEvent *event){
			codeEditor->lineNumberAreaPaintEvent(event);
		}
	
	private:
		CodeEditor *codeEditor;
};
