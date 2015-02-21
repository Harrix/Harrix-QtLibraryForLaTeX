QString THQt_LatexShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString TitleMatrix, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
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
    for (int j=0;j<VHQt_Matrix[0].count();j++) C+="c";
    VHQt_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;

        for (int j=0;j<VHQt_Matrix[i].count();j++)
        {
            if (j!=VHQt_Matrix[i].count()-1) H=" & "; else H="";
            VHQt_Result+="\\text{"+VHQt_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VHQt_N-1) H="\\\\"; else H="";
        VHQt_Result+=H;
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexShowMatrix (QStringList *VHQt_Matrix, int VHQt_N, QString NameMatrix)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице;
     NameMatrix - обозначение матрицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n";
    VHQt_Result+="\\begin{equation}\n";
    VHQt_Result+="\\overline{"+NameMatrix+"} = ";

    QString C;
    for (int j=0;j<VHQt_Matrix[0].count();j++) C+="c";
    VHQt_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;

        for (int j=0;j<VHQt_Matrix[i].count();j++)
        {
            if (j!=VHQt_Matrix[i].count()-1) H=" & "; else H="";
            VHQt_Result+="\\text{"+VHQt_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VHQt_N-1) H="\\\\"; else H="";
        VHQt_Result+=H;
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}
//---------------------------------------------------------------------------
QString THQt_LatexShowMatrix (QStringList *VHQt_Matrix, int VHQt_N)
{
    /*
    Функция возвращает строку с выводом некоторой матрицы VHQt_Matrix с Latex кодами.
    В качестве матрицы выступает массив QStringList, где количество QStringList - это количество строк.
    Каждый QStringList - это одна строка.
    Входные параметры:
     VHQt_Matrix - указатель на выводимую матрицу;
     VHQt_N - количество строк в матрице.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой матрицей.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n";
    VHQt_Result+="\\begin{equation}\n";
    VHQt_Result+="\\overline{x} = ";

    QString C;
    for (int j=0;j<VHQt_Matrix[0].count();j++) C+="c";
    VHQt_Result+="\\left( \\begin{array}{"+C+"} ";

    for (int i=0;i<VHQt_N;i++)
    {
        QString H;

        for (int j=0;j<VHQt_Matrix[i].count();j++)
        {
            if (j!=VHQt_Matrix[i].count()-1) H=" & "; else H="";
            VHQt_Result+="\\text{"+VHQt_Matrix[i].at(j)+"}"+H;
        }

        if (i!=VHQt_N-1) H="\\\\"; else H="";
        VHQt_Result+=H;
    }

    VHQt_Result+="\\end{array}\\right).\n";

    VHQt_Result+="\\end{equation}\n\n";

    return VHQt_Result;
}