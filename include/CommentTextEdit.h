#pragma once

#ifdef ZCLOUDCOMMON_LIB
# define ZCLOUDCOMMONTEXREDIT_EXPORT Q_DECL_EXPORT
#else
# define ZCLOUDCOMMONTEXREDIT_EXPORT Q_DECL_IMPORT
#endif

#include <QTextEdit>
#include <QObject>
#include <QInputMethodEvent>

class ZCLOUDCOMMONTEXREDIT_EXPORT CommentTextEdit : public QTextEdit
{
	Q_OBJECT

public:
	CommentTextEdit(QWidget *parent = nullptr);
	~CommentTextEdit();

protected:
	virtual void inputMethodEvent(QInputMethodEvent *e);
};
