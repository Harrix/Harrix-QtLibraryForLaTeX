QString HQt_LatexShowHr ()
{
    /*
    Функция возвращает строку с выводом горизонтальной линии.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Строка с Latex кодами с тэгом горизонтальной линии.
    */
    QString VHQt_Result;

    VHQt_Result="\n\n\\hrulefill\n\n";

    return VHQt_Result;
}