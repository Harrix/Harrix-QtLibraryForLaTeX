template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString TitleX, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами.
    Входные параметры:
     VMHL_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n"+TitleX+":\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+=NameX+" = " + QString::number(VMHL_X) + ".\n";
    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами.
    Входные параметры:
     VMHL_X - выводимое число;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VMHL_Result;

    VMHL_Result+="\n\n\\begin{equation}\n";
    VMHL_Result+=NameX+" = " + QString::number(VMHL_X) + ".\n";
    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowNumber (T VMHL_X)
{
    /*
    Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами.
    Входные параметры:
     VMHL_X - выводимое число.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VMHL_Result;

    VMHL_Result+="\n\n\\begin{equation}\n";
    VMHL_Result+="x = " + QString::number(VMHL_X) + ".\n";
    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}