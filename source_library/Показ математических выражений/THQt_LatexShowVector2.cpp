QString THQt_LatexShowVector (QStringList VHQt_Vector, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n"+TitleVector+":\n";
    VHQt_Result+="\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameVector+"} = ";

    VHQt_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VHQt_Vector.count();i++)
    {
        VHQt_Result+="\\text{"+(VHQt_Vector.at(i))+"}\\\\";
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexShowVector (QStringList VHQt_Vector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n";
    VHQt_Result+="\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameVector+"} = ";

    VHQt_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VHQt_Vector.count();i++)
    {
        VHQt_Result+="\\text{"+(VHQt_Vector.at(i))+"}\\\\";
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexShowVector (QStringList VHQt_Vector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n";
    VHQt_Result+="\\begin{equation}\n";
    VHQt_Result+="\\overline{x} = ";

    VHQt_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VHQt_Vector.count();i++)
    {
        VHQt_Result+="\\text{"+(VHQt_Vector.at(i))+"}\\\\";
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}