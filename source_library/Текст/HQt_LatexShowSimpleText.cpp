QString HQt_LatexShowSimpleText (QString String)
{
    /*
    Функция возвращает строку с выводом некоторой строки с Latex кодами без всякого излишества.
    Входные параметры:
     String - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n"+String+"\n\n";

    return VHQt_Result;
}