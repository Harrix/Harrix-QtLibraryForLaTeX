template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector в транспонированном виде с Latex кодами.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     TitleVector - заголовок выводимого вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n"+TitleVector+":\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameVector+"} = ";

    VMHL_Result+="\\left( ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;
        if (i!=VMHL_N-1) H="; ";
        VMHL_Result+=QString::number(VMHL_Vector[i])+H;
    }

    VMHL_Result+="\\right)^\\mathrm{T}.\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N, QString NameVector)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector в транспонированном виде с Latex кодами.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора;
     NameVector - обозначение вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result+="\n\n\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameVector+"} = ";

    VMHL_Result+="\\left( ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;
        if (i!=VMHL_N-1) H="; ";
        VMHL_Result+=QString::number(VMHL_Vector[i])+H;
    }

    VMHL_Result+="\\right)^\\mathrm{T}.\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторого вектора VMHL_Vector в транспонированном виде с Latex кодами.
    Входные параметры:
     VMHL_Vector - указатель на выводимый вектор;
     VMHL_N - количество элементов вектора.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым вектором.
    */
    QString VMHL_Result;

    VMHL_Result+="\n\n\\begin{equation}\n";
    VMHL_Result+="\\overline{x} = ";

    VMHL_Result+="\\left( ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;
        if (i!=VMHL_N-1) H="; ";
        VMHL_Result+=QString::number(VMHL_Vector[i])+H;
    }

    VMHL_Result+="\\right)^\\mathrm{T}.\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}