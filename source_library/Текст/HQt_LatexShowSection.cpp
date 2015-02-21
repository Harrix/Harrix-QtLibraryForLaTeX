QString HQt_LatexShowSection (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки в виде заголовка.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n\\section{"+String+"}\n\n";

    return VHQt_Result;
}