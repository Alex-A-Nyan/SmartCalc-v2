<h1>SmartCalc. V2.0<img src="Technical/TheFlash.png" width="150" height="197" 
		alt="TheFlashIcon" align="right" 
		vspace="0" hspace="10"></h1>

!!! ПРОГРАММА НАХОДИТСЯ НА СТАДИИ РАЗРАБОТКИ !!!

<h2>Описание программы</h2>

<p>Программа разработана на языке С++ стандарта C17 с использованием компилятора clang++. Использованы дополнительные библиотеки и модули QT.</p>

<p>Программа обладает следующим функционалом:</p>
<ul>
	<li>Вычисление произвольных скобочных арифметических выражений в инфиксной нотации;</li>
	<li>Вычисление произвольных скобочных арифметических выражений в инфиксной нотации с подстановкой значения переменной <em>x</em> в виде числа;
	<li>Вывод значения выражения как с задаваемой точностью, так и со значением по умолчанию (до 7 знаков после запятой);</li>
	<li>Вывод значения выражения в экспоненциальной (научной) записи;</li>
	<li>Построение графика функции, заданной с помощью выражения в инфиксной нотации с переменной <em>x</em> (с координатными осями, отметкой используемого масштаба и сеткой с адаптивным шагом)</li>
</ul>

На вход программы могут подаваться как целые числа, так и вещественные числа, записанные через точку и/или запятую. Возможны операции c величинами Inf, -Inf и NaN.<br>
Вычисление производится после полного ввода вычисляемого выражения и нажатия на символ&nbsp; <code>&quot;=&quot;</code>.<br>
В исходном выражении допустимо использование неявного умножения в выражении (рекомендуется придерживаться правил составления упрощенных выражений), а также экспоненциальная (научная) запись.<br>
Область определения и область значения функций ограничиваются числами от -1000000 до 1000000.<br>
Максимально допустимая длина выражения 255 символов.</p>


<p>Поддерживаются следующие операции и математичеcкие функции:</p>

<table align="center" border="1" cellpadding="1" cellspacing="1" style="width:500px">
	<tbody>
		<tr>
			<td style="text-align:center">Скобки</td>
			<td style="text-align:center">(a + b)</td>
		</tr>
		<tr>
			<td style="text-align:center">Сложение</td>
			<td style="text-align:center">a + b</td>
		</tr>
		<tr>
			<td style="text-align:center">Вычитание</td>
			<td style="text-align:center">a - b</td>
		</tr>
		<tr>
			<td style="text-align:center">Умножение</td>
			<td style="text-align:center">a * b</td>
		</tr>
		<tr>
			<td style="text-align:center">Деление</td>
			<td style="text-align:center">a / b</td>
		</tr>
		<tr>
			<td style="text-align:center">Остаток от деления</td>
			<td style="text-align:center">a mod b / a % b</td>
		</tr>
		<tr>
			<td style="text-align:center">Возведение в степень</td>
			<td style="text-align:center">a ^ b</td>
		</tr>
		<tr>
			<td style="text-align:center">Квадратный корень</td>
			<td style="text-align:center">sqrt(a)</td>
		</tr>
		<tr>
			<td style="text-align:center">Унарный плюс</td>
			<td style="text-align:center">+a</td>
		</tr>
		<tr>
			<td style="text-align:center">Унарный минус</td>
			<td style="text-align:center">-a</td>
		</tr>
		<tr>
			<td style="text-align:center">Округление вниз</td>
			<td style="text-align:center">floor(a)</td>
		</tr>
		<tr>
			<td style="text-align:center">Округление вверх</td>
			<td style="text-align:center">ceil(a)</td>
		</tr>
		<tr>
			<td style="text-align:center">Косинус</td>
			<td style="text-align:center">cos(a)</td>
		</tr>
		<tr>
			<td style="text-align:center">Синус</td>
			<td style="text-align:center">sin(a)</td>
		</tr>
		<tr>
			<td style="text-align:center">Тангенс</td>
			<td style="text-align:center">tan(a) / tg(a)</td>
		</tr>
		<tr>
			<td style="text-align:center">Арккосинус</td>
			<td style="text-align:center">acos(a) / arccos(a)</td>
		</tr>
		<tr>
			<td style="text-align:center">Арксинус</td>
			<td style="text-align:center">asin(a) / arcsin(a)</td>
		</tr>
		<tr>
			<td style="text-align:center">Арктангенс</td>
			<td style="text-align:center">atan(a) / arctg(a) / arctan(a)</td>
		</tr>
		<tr>
			<td style="text-align:center">Натуральный логарифм</td>
			<td style="text-align:center">ln(a) / logE(a) / loge(a)</td>
		</tr>
		<tr>
			<td style="text-align:center">Десятичный логарифм</td>
			<td style="text-align:center">lg(a) / log(a) / log10(a)</td>
		</tr>
	</tbody>
</table>

<h2>Установка программы</h2>

<p>Для запуска программы необходимо выполнить команду</p>

</ul>
	<li>make run</li>
</ul>

<p>Путь установки программы: ~/build_calc/</p>

====================================================================================

<p>Copyright 2024 valeryje</p>

<p>This file contains Original Code created by valeryje aka Alexander Alexanyan or Alex-A-Nyan.</p>

<p>The Original Code and all software developed in the process of
participation on learning by experimental programming educational method.<br>
The whole methodology was developed and distributed by
autonomous non-profit organization «School 21» (ANO «School 21»).</p>

<p>Redistribution and use of this file, its parts, or entire project
are permitted by confirmation of its original creator.</p>


====================================================================================
