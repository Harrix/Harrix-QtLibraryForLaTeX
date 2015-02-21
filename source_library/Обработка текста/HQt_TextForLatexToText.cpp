QString HQt_TextForLatexToText (QString String)
{
    /*
	Функция обрабатывает строку String из переделки функции HQt_StringForLaTeX в нормальную строку.
	Еще удаляются знаки $, которые обрамляют формулы.
    Входные параметры:
     String - обрабатываемая строка.
    Возвращаемое значение:
     Обработанная строка.
    */
    QString VHQt_Result;

    VHQt_Result=String.replace("\\_","_").replace("$","").replace("$\\sim$","~").replace("\\#","#");

    return VHQt_Result;
}