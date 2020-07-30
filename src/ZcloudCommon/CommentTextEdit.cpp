#include "CommentTextEdit.h"

CommentTextEdit::CommentTextEdit(QWidget *parent)
	: QTextEdit(parent)
{
}

CommentTextEdit::~CommentTextEdit()
{
}

void CommentTextEdit::inputMethodEvent(QInputMethodEvent *e)
{
	if (e->preeditString().isEmpty())
	{
		this->setPlaceholderText(QString::fromLocal8Bit("请描述您遇到的问题或建议"));
	}
	else
	{
		this->setPlaceholderText(QString::null);
	}

	QTextEdit::inputMethodEvent(e);
}

