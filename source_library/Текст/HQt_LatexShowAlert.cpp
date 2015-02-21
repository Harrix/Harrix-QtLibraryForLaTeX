QString HQt_LatexShowAlert (QString String)
{
    /*
    Функция возвращает строку с выводом некоторого предупреждения.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимым предупреждением.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n\\textcolor{red}{\\textbf{"+String+"}}\n\n";

    return VHQt_Result;
}