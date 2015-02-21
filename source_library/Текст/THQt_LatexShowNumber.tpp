template <class T> QString THQt_LatexShowNumber (T VHQt_X, QString TitleX, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с Latex кодами.
    Входные параметры:
     VHQt_X - выводимое число;
     TitleX - заголовок выводимого числа;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n"+TitleX+":\n";
    VHQt_Result+="\\begin{equation}\n";
    VHQt_Result+=NameX+" = " + QString::number(VHQt_X) + ".\n";
    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowNumber (T VHQt_X, QString NameX)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с Latex кодами.
    Входные параметры:
     VHQt_X - выводимое число;
     NameX - обозначение числа.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+=NameX+" = " + QString::number(VHQt_X) + ".\n";
    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowNumber (T VHQt_X)
{
    /*
    Функция возвращает строку с выводом некоторого числа VHQt_X с Latex кодами.
    Входные параметры:
     VHQt_X - выводимое число.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым числом.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="x = " + QString::number(VHQt_X) + ".\n";
    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}