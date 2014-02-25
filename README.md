HarrixQtLibraryForLaTeX
=======================

Версия 1.23

Библиотека для отображения различных данных в LaTeX файлах.

[https://github.com/Harrix/HarrixQtLibraryForLaTeX](https://github.com/Harrix/HarrixQtLibraryForLaTeX)

Библиотека распространяется по лицензии [Apache License, Version 2.0](https://github.com/Harrix/HarrixQtLibraryForLaTeX/blob/master/LICENSE.txt).

Установка
---------

Подробно о установке с подробным примером можно прочитать тут [http://blog.harrix.org/?p=1164](http://blog.harrix.org/?p=1164).

Функции для получения LaTeX кода 
--------------------------------

- Возвращает начало для полноценного Latex файла.

        QString HQt_LatexBegin();
		
- Возвращает начало для полноценного Latex файла с использованием графиков через пакет pgfplots.

        QString HQt_LatexBeginWithPgfplots();

- Возвращает начало для полноценного Latex файла в виде статьи.

        QString HQt_LatexBeginArticle();

- Возвращает начало для полноценного Latex файла в виде статьи с использованием графиков через пакет pgfplots.

        QString HQt_LatexBeginArticleWithPgfplots();

- Возвращает концовку для полноценного Latex файла.

        QString HQt_LatexEnd();
		
- Функция переводит текст в текст, который можно добавить в Latex код.

        QString HQt_TextToTextForLatex (QString Text)

- Функция возвращает строку с выводом некоторой строки с Latex кодами.

        QString HQt_LatexShowText (QString TitleX);

- Функция возвращает строку с выводом некоторой строки с Latex кодами без всякого излишевства.

        QString HQt_LatexShowSimpleText (QString String);

- Функция возвращает строку с выводом горизонтальной линии.

        QString HQt_LatexShowHr ();

- Функция возвращает строку с выводом некоторой строки в виде заголовка.

        QString HQt_LatexShowSection (QString String);

- Функция возвращает строку с выводом некоторой строки в виде подзаголовка.

        QString HQt_LatexShowSubsection (QString String);

- Функция возвращает строку с выводом некоторого предупреждения.

        QString HQt_LatexShowAlert (QString String);

- Функция возвращает строку с выводом некоторого числа VMHL_X с Latex кодами.

        template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString TitleX, QString NameX);
        template <class T> QString THQt_LatexShowNumber (T VMHL_X, QString NameX);
        template <class T> QString THQt_LatexShowNumber (T VMHL_X);
		
- Функция выводит число VMHL_X в строку Latex, причем число выделено жирным.

        template <class T> QString THQt_LatexNumberToText (T VMHL_X);		
		
- Функция возвращает строку с выводом некоторого вектора VMHL_Vector с Latex кодами.

        template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
        template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N, QString NameVector);
        template <class T> QString THQt_LatexShowVector (T *VMHL_Vector, int VMHL_N);
		QString THQt_LatexShowVector (QStringList VMHL_Vector, QString TitleVector, QString NameVector);
		QString THQt_LatexShowVector (QStringList VMHL_Vector, QString NameVector);
		QString THQt_LatexShowVector (QStringList VMHL_Vector);

- Функция возвращает строку с выводом некоторого вектора VMHL_Vector в транспонированном виде с Latex кодами.

        template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N, QString TitleVector, QString NameVector);
        template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N, QString NameVector);
        template <class T> QString THQt_LatexShowVectorT (T *VMHL_Vector, int VMHL_N);
		
- Функция возвращает строку с выводом некоторой матрицы VMHL_Matrix с Latex кодами.

        template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString TitleMatrix, QString NameMatrix);
        template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M, QString NameMatrix);
        template <class T> QString THQt_LatexShowMatrix (T *VMHL_Matrix, int VMHL_N, int VMHL_M);
		QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString TitleMatrix, QString NameMatrix);
		QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N, QString NameMatrix);
		QString THQt_LatexShowMatrix (QStringList *VMHL_Matrix, int VMHL_N);
		
- Функция возвращает строку с выводом начала рисунка, состоящего из нескольких рисунков или графиков.

        QString HQt_LatexBeginCompositionFigure ();

- Функция возвращает строку с выводом окончания рисунка, состоящего из нескольких рисунков или графиков.

        QString HQt_LatexEndCompositionFigure (QString TitleFigure, QString Label);
        QString HQt_LatexEndCompositionFigure (QString TitleFigure);
        QString HQt_LatexEndCompositionFigure ();

- Функция возвращает строку с Latex кодом при добавлении дополнительного рисунка или графика в рисунок, состоящего из нескольких рисунков.

        QString HQt_LatexBeginFigureInCompositionFigure ();

		

Скриншоты применения функций
----------------------------

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForLaTeX/master/images/example.png "Пример использования функций")

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForLaTeX/master/images/example2.png "Пример использования функций")

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForLaTeX/master/images/example3.png "Пример использования функций")

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForLaTeX/master/images/example4.png "Пример использования функций")

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForLaTeX/master/images/example5.png "Пример использования функций")

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForLaTeX/master/images/example6.png "Пример использования функций")

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForLaTeX/master/images/example7.png "Пример использования функций")

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForLaTeX/master/images/example8.png "Пример использования функций")

![alt text](https://raw.github.com/Harrix/HarrixQtLibraryForLaTeX/master/images/example9.png "Пример использования функций")

Использованные технологии
-------------------------

- [Qt](http://qt-project.org/), [LaTeX](http://ru.wikipedia.org/wiki/LaTeX), [MiKTeX](http://miktex.org/), [TeXstudio](http://texstudio.sourceforge.net/), [PSCyr]([http://blog.harrix.org/?p=444](http://blog.harrix.org/?p=444)), [pgfplots](http://pgfplots.sourceforge.net/).
- [HarrixQtLibrary](https://github.com/Harrix/HarrixQtLibrary), [HarrixLaTeXDocumentTemplate](https://github.com/Harrix/HarrixLaTeXDocumentTemplate), [HarrixMathLibrary](https://github.com/Harrix/HarrixMathLibrary), [mtrand](http://www.bedaux.net/mtrand/).

Сведения для редактирования файлов
----------------------------------

Для полноценной работы редактированию LaTeX документа вам потребуются программа для компиляции \*.tex документов в \*.pdf. Автор использует для этого связку [MiKTex](http://www.miktex.org/) и [TeXstudio](http://texstudio.sourceforge.net/). 

В варианте, который использует автор, в \*.tex файлах справок для отображения русских букв используется модуль pscyr. Об его установке можно прочитать (и скачать) в статье [http://blog.harrix.org/?p=444](http://blog.harrix.org/?p=444).

Подробное описание установки и настройки связки MiKTeX + TeXstudio + pscyr можно прочитать в статье [http://blog.harrix.org/?p=849](http://blog.harrix.org/?p=849).

История проекта
---------------

Подробный список изменений в файле [CHANGELOG.md](https://github.com/Harrix/HarrixQtLibraryForLaTeX/blob/master/CHANGELOG.md).

Контакты
--------

Автор: Сергиенко Антон Борисович.

С автором можно связаться по адресу [sergienkoanton@mail.ru](mailto:sergienkoanton@mail.ru) или  [http://vk.com/harrix](http://vk.com/harrix).

Сайт автора, где публикуются последние новости: [http://blog.harrix.org](http://blog.harrix.org), а проекты располагаются по адресу: [http://harrix.org](http://harrix.org).