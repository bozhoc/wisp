#include "Highlighter.h"

Highlighter::Highlighter(QTextDocument *parent) : QSyntaxHighlighter(parent)
{
    Rule keyword_rule;
    keyword_rule.pattern = QRegularExpression(
        "\\b(abstract|alignas|alignof|and|as|asm|assert|async|await|"
        "auto|begin|break|case|catch|chan|char|class|const|"
        "constexpr|continue|crate|data|def|default|defer|del|"
        "delete|do|dynamic|elif|else|elseif|end|enum|except|"
        "export|extends|extern|false|final|finally|fn|for|foreach|"
        "friend|from|func|function|global|go|goto|if|implements|"
        "import|in|include|instanceof|interface|internal|is|"
        "lambda|let|match|mod|module|mut|mutable|namespace|"
        "native|new|nil|noexcept|not|null|object|operator|"
        "or|override|package|pass|private|protected|public|"
        "raise|readonly|ref|register|return|select|self|static|"
        "strictfp|struct|super|switch|synchronized|template|"
        "then|this|throw|throws|trait|transient|true|try|"
        "type|typedef|typeof|union|unsafe|unless|until|use|"
        "using|var|virtual|void|volatile|when|where|while|"
        "with|yield)\\b");

    keyword_rule.format.setForeground(QColor("#C4A1E8"));
    rules.append(keyword_rule);

    Rule datatype_rule;
    datatype_rule.pattern = QRegularExpression(
        "\\b(any|bool|boolean|byte|char|character|complex|decimal|"
        "double|float|int|int8|int16|int32|int64|integer|"
        "long|longint|number|object|real|short|string|str|"
        "text|uint|uint8|uint16|uint32|uint64|unsigned|"
        "void|never|unknown|undefined|null|nil|unit|"
        "BigInt|Symbol|"
        "Array|List|Set|Map|Dictionary|HashMap|HashSet|"
        "Queue|Stack|Tuple|Vector|Matrix|Collection|"
        "Iterable|Iterator|Generator|Optional|Option|Result|"
        "Promise|Future|Task|Stream|Channel|"
        "Date|Time|DateTime|Timestamp|Regex|RegExp|"
        "Error|Exception|File|Path|Buffer|ByteArray|"
        "Object|String|Boolean|Number|Function)\\b");

    datatype_rule.format.setForeground(QColor("#67C7D4"));
    rules.append(datatype_rule);

    Rule number_rule;
    number_rule.pattern = QRegularExpression("\\b[0-9]+(\\.[0-9]+)?\\b");
    number_rule.format.setForeground(QColor("#E6A56B"));
    rules.append(number_rule);

    Rule strings_rule;
    strings_rule.pattern = QRegularExpression("\"[^\"]*\"");
    strings_rule.format.setForeground(QColor("#A6D6A8"));
    rules.append(strings_rule);
}

void Highlighter::highlightBlock(const QString &text)
{
    for (const Rule &rule : rules)
    {
        QRegularExpressionMatchIterator iterator = rule.pattern.globalMatch(text);
        while (iterator.hasNext())
        {
            QRegularExpressionMatch match = iterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}