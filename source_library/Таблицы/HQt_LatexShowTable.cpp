QString HQt_LatexShowTable (QStringList Col1, QStringList Col2, QString NameCol1, QString NameCol2, double WidthCol1, QString Title)
{
    /*
    Функция возвращает строку с выводом таблицы с двумя столбцами.
    Входные параметры:
     Col1 - список строк первого столбца;
     Col2 - список строк второго столбца;
     NameCol1- заголовок первого столбца;
     NameCol2- заголовок второго столбца;
     WidthCol1 - ширина первого столбца в процентах, например 50%;
     Title - заголовок таблицы.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой таблицы.
    */
    QString VMHL_Result;

    VMHL_Result+="\\begin{center}\n";
    VMHL_Result+="{\n\\renewcommand{\\arraystretch}{1.5}\n";

    double width1 = 0.93*(WidthCol1/100.);
    double width2 = 0.93*(1.-WidthCol1/100.);

    VMHL_Result+="\\footnotesize\\begin{longtable}[H]{|m{"+QString::number(width1)+"\\linewidth}|m{"+QString::number(width2)+"\\linewidth}|}\n";
    VMHL_Result+="\\caption{"+Title+"}\n";

    VMHL_Result+="\\tabularnewline\\hline\n";
    VMHL_Result+="\\centering \\textbf{"+NameCol1+"} & \\centering \\textbf{"+NameCol2+"} \\centering \\tabularnewline \\hline \\endhead\n";
    VMHL_Result+="\\multicolumn{2}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    VMHL_Result+="\\endlastfoot\n";

    for (int i=0;i<Col1.count();i++)
    {
        VMHL_Result+="\\footnotesize "+Col1.at(i)+" & \\footnotesize "+Col2.at(i)+" \\tabularnewline \\hline\n";
    }

    VMHL_Result+="\\end{longtable}\n";
    VMHL_Result+="}\n";
    VMHL_Result+="\\end{center}\n\n";

    return VMHL_Result;
}
//---------------------------------------------------------------------------
QString HQt_LatexShowTable (QStringList Col1, QStringList Col2, QStringList Col3, QString NameCol1, QString NameCol2, QString NameCol3, double WidthCol1, double WidthCol2, QString Title)
{
    /*
    Функция возвращает строку с выводом таблицы с тремя столбцами.
    Входные параметры:
     Col1 - список строк первого столбца;
     Col2 - список строк второго столбца;
     Col3 - список строк второго столбца;
     NameCol1- заголовок первого столбца;
     NameCol2- заголовок второго столбца;
     NameCol3- заголовок второго столбца;
     WidthCol1 - ширина первого столбца в процентах, например 50%;
     WidthCol2 - ширина первого столбца в процентах, например 50%;
     Title - заголовок таблицы;
    Возвращаемое значение:
     Строка с Latex кодами с выводимой таблицы.
    */
    QString VMHL_Result;

    VMHL_Result+="\\begin{center}\n";
    VMHL_Result+="{\n\\renewcommand{\\arraystretch}{1.5}\n";

    double width1 = 0.93*(WidthCol1/100.);
    double width2 = 0.93*(WidthCol2/100.);
    double width3 = 0.93*(1.-WidthCol1/100.-WidthCol2/100.);

    VMHL_Result+="\\footnotesize\\begin{longtable}[H]{|m{"+QString::number(width1)+"\\linewidth}|m{"+QString::number(width2)+"\\linewidth}|m{"+QString::number(width3)+"\\linewidth}|}\n";
    VMHL_Result+="\\caption{"+Title+"}\n";

    VMHL_Result+="\\tabularnewline\\hline\n";
    VMHL_Result+="\\centering \\textbf{"+NameCol1+"} & \\centering \\textbf{"+NameCol2+"} & \\centering \\textbf{"+NameCol3+"} \\centering \\tabularnewline \\hline \\endhead\n";
    VMHL_Result+="\\multicolumn{3}{|r|}{{Продолжение на следующей странице...}} \\\\ \\hline \\endfoot\n";
    VMHL_Result+="\\endlastfoot\n";

    for (int i=0;i<Col1.count();i++)
    {
        VMHL_Result+="\\footnotesize "+Col1.at(i)+" & \\footnotesize "+Col2.at(i)+" & \\footnotesize "+Col3.at(i)+" \\tabularnewline \\hline\n";
    }

    VMHL_Result+="\\end{longtable}\n";
    VMHL_Result+="}\n";
    VMHL_Result+="\\end{center}\n\n";

    return VMHL_Result;
}