QString HQt_ForcedWordWrap(QString S)
{
    /*
    Функция расставляет принудительные переносы в стиле Latex.
    Входные параметры:
     S - разбиваемая строка.
    Возвращаемое значение:
     Срока с расставленными принудительно переносами.
    Примечание:
     Перевод слов производится по алгоритму П. Хpистова в модификации Дымченко и Ваpсанофьева.
    */
    QStringList List;

    List = HQt_CutToWordsWithWordWrap(S);

    QString VMHL_Result = List.join("\\-");

    VMHL_Result = VMHL_Result.replace("\\-\\\\-_", "\\_");

    return VMHL_Result;
}