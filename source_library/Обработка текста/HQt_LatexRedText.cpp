QString HQt_LatexRedText (QString String)
{
    /*
    Функция возвращает строку с выводом красного текста.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с красным текстом.
    */
    QString VHQt_Result;

    VHQt_Result="\\textcolor{red}{\\textbf{"+String+"}}";

    return VHQt_Result;
}