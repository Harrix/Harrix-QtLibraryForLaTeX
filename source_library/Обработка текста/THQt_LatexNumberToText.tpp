template <class T> QString THQt_LatexNumberToText (T VHQt_X)
{
    /*
    Функция выводит число VHQt_X в строку Latex, причем число выделено жирным.
    Входные параметры:
     VHQt_X - выводимое число.
    Возвращаемое значение:
     Строка, в которой записано число.
    */
    QString VHQt_Result;
    VHQt_Result=" \\textbf{"+QString::number(VHQt_X)+"} ";
    return VHQt_Result;
}