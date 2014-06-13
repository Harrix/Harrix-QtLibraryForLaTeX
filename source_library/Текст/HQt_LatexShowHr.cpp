QString HQt_LatexShowHr ()
{
    /*
    Функция возвращает строку с выводом горизонтальной линии.
    Входные параметры:
     Отсутствуют.
    Возвращаемое значение:
     Строка с Latex кодами с тэгом горизонтальной линии.
    */
    QString VMHL_Result;

    VMHL_Result="\n\n\\hrulefill\n\n";

    return VMHL_Result;
}