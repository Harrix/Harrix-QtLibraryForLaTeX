QString HQt_LatexGreenText (QString String)
{
    /*
    Функция возвращает строку с выводом зеленого текста.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с зеленым текстом.
    */
    QString VHQt_Result;

    VHQt_Result="\\textcolor{darkgreen}{\\textbf{"+String+"}}";

    return VHQt_Result;
}