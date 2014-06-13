QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n"+TitleMatrix+":\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VMHL_Matrix[0].count();j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            if (j!=VMHL_Matrix[i].count()-1) H=" & "; else H="";
            VMHL_Result+="\\text{"+VMHL_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VMHL_Matrix[0].count();j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            if (j!=VMHL_Matrix[i].count()-1) H=" & "; else H="";
            VMHL_Result+="\\text{"+VMHL_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n";
    VMHL_Result+="\\begin{equation}\n";
    VMHL_Result+="\\overline{x} = ";

    QString C;
    for (int j=0;j<VMHL_Matrix[0].count();j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_Matrix[i].count();j++)
        {
            if (j!=VMHL_Matrix[i].count()-1) H=" & "; else H="";
            VMHL_Result+="\\text{"+VMHL_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}