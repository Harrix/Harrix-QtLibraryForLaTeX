QString HQt_LatexShowSubsection (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде подзаголовка.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n\\subsection{"+String+"}\n\n";

    return VHQt_Result;
}