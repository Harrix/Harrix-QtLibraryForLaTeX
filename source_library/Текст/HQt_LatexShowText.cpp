QString HQt_LatexShowText (QString TitleX)
{
    /*
    Функция возвращает строку с выводом некоторой строки с Latex кодами.
    Входные параметры:
     TitleX - непосредственно выводимая строка.
    Возвращаемое значение:
     Строка с Latex кодами с выводимой строкой (в виде абзаца).
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\textbf{"+TitleX+".}\n\n";

    return VMHL_Result;
}