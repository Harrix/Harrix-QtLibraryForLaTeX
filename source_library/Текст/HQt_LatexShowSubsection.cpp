QString HQt_LatexShowSubsection (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде подзаголовка.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\subsection{"+String+"}\n\n";

    return VMHL_Result;
}