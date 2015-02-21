template <class T> QString THQt_LatexShowVector (T *VHQt_Vector, int VHQt_N, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
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

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+=QString::number(VHQt_Vector[i])+"\\\\";
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowVector (T *VHQt_Vector, int VHQt_N, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameVector+"} = ";

    VHQt_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+=QString::number(VHQt_Vector[i])+"\\\\";
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowVector (T *VHQt_Vector, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VHQt_Vector с Latex кодами.
    Входные параметры:
     VHQt_Vector - указатель на выводимый вектор;
     VHQt_N - количество элементов вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="\\overline{x} = ";

    VHQt_Result+="\\left( \\begin{array}{c} ";

    for (int i=0;i<VHQt_N;i++)
    {
        VHQt_Result+=QString::number(VHQt_Vector[i])+"\\\\";
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}