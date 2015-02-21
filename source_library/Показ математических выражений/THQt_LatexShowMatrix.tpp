template <class T> QString THQt_LatexShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с Latex кодами.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     VHQt_M - количество столбцов в матрице;
     TitleMatrix - заголовок выводимой матрицы;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n"+TitleMatrix+":\n";
    VHQt_Result+="\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VHQt_M;j++) C+="c";
    VHQt_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;

        for (int j=0;j<VHQt_M;j++)
        {
            if (j!=VHQt_M-1) H=" & "; else H="";
            VHQt_Result+=QString::number(VHQt_Matrix[i][j])+H;
        }

        if (i!=VHQt_N-1) H="\\\\"; else H="";
        VHQt_Result+=H;
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с Latex кодами.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     VHQt_M - количество столбцов в матрице;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VHQt_M;j++) C+="c";
    VHQt_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;

        for (int j=0;j<VHQt_M;j++)
        {
            if (j!=VHQt_M-1) H=" & "; else H="";
            VHQt_Result+=QString::number(VHQt_Matrix[i][j])+H;
        }

        if (i!=VHQt_N-1) H="\\\\"; else H="";
        VHQt_Result+=H;
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
template <class T> QString THQt_LatexShowMatrix (T *VHQt_Matrix, int VHQt_N, int VHQt_M)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с Latex кодами.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     VHQt_M - количество столбцов в матрице.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result+="\n\n\\begin{equation}\n";
    VHQt_Result+="\\overline{x} = ";

    QString C;
    for (int j=0;j<VHQt_M;j++) C+="c";
    VHQt_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;

        for (int j=0;j<VHQt_M;j++)
        {
            if (j!=VHQt_M-1) H=" & "; else H="";
            VHQt_Result+=QString::number(VHQt_Matrix[i][j])+H;
        }

        if (i!=VHQt_N-1) H="\\\\"; else H="";
        VHQt_Result+=H;
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}