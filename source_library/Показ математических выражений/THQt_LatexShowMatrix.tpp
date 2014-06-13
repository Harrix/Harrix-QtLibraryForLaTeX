template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     VMHL_M - количество столбцов в матрице;
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
    for (int j=0;j<VMHL_M;j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_M;j++)
        {
            if (j!=VMHL_M-1) H=" & "; else H="";
            VMHL_Result+=QString::number(VMHL_Matrix[i][j])+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     VMHL_M - количество столбцов в матрице;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result+="\n\n\\begin{equation}\n";
    VMHL_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VMHL_M;j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_M;j++)
        {
            if (j!=VMHL_M-1) H=" & "; else H="";
            VMHL_Result+=QString::number(VMHL_Matrix[i][j])+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.
    Входные параметры:
     VMHL_Matrix - указатель на выводимую матрицу;
     VMHL_N - количество строк в матрице;
     VMHL_M - количество столбцов в матрице.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VMHL_Result;

    VMHL_Result+="\n\n\\begin{equation}\n";
    VMHL_Result+="\\overline{x} = ";

    QString C;
    for (int j=0;j<VMHL_M;j++) C+="c";
    VMHL_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VMHL_N;i++)
    {
        QString H;

        for (int j=0;j<VMHL_M;j++)
        {
            if (j!=VMHL_M-1) H=" & "; else H="";
            VMHL_Result+=QString::number(VMHL_Matrix[i][j])+H;
        }

        if (i!=VMHL_N-1) H="\\\\"; else H="";
        VMHL_Result+=H;
    }

    VMHL_Result+="\\end{array}\\right).\n";

    VMHL_Result+="\\end{equation}\n\n";

    return VMHL_Result;
}