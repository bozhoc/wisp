#pragma once
#include <QSyntaxHighlighter>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

class Highlighter : public QSyntaxHighlighter
{
public:
    Highlighter(QTextDocument *parent);

private:
    struct Rule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QList<Rule> rules;

protected:
    void highlightBlock(const QString &text) override;
};