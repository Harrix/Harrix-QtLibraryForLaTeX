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
    QString VMHL_Result;

    VMHL_Result=String.replace("\\_","_").replace("$","").replace("$\\sim$","~").replace("\\#","#");

    return VMHL_Result;
}