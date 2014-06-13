template <class T> QString THQt_LatexNumberToText (T VMHL_X)
{
    /*
    Функция выводит число VMHL_X в строку Latex, причем число выделено жирным.
    Входные параметры:
     VMHL_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VMHL_Result;
    VMHL_Result=" \\textbf{"+QString::number(VMHL_X)+"} ";
    return VMHL_Result;
}