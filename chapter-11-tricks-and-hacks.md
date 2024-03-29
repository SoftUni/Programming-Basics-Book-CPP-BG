# Глава 11. Хитрости и хакове

В настоящата глава ще разгледаме някои хитрости, хакове и техники, които ще улеснят работата ни с езика **C++** в среда за разработка **Visual Studio**. По-специално ще се запознаем:

* Как правилно да **форматираме код**.
* С конвенции за **именуване на елементи от код**.
* С някои **бързи клавиши** (keyboard shortcuts).
* С някои **шаблони с код** (code snippets).
* С техники за **дебъгване на код**.

## Форматиране на кода

Правилното форматиране на нашия код ще го направи **по-четим и разбираем**, в случай че се наложи някой друг да работи с него. Това е важно, защото в практиката ще е необходимо да работим в екип с други хора и е от голямо значение дали пишем кода си така, че колегите ни да могат **бързо да се ориентират** в него.

Има определени правила за правилно форматиране на кода, които събрани в едно се наричат **конвенции**. Конвенциите са група от правила, общоприети от програмистите на даден език, и се ползват масово. Тези конвенции помагат за изграждането на норми в дадени езици - как е най-добре да се пише и какви са **добрите практики**. Приема се, че ако един програмист ги спазва, то кодът му е лесно четим и разбираем.

Езикът C++ е направен от **Бьорн Строуструп** (Bjarne Stroustrup - https://en.wikipedia.org/wiki/Bjarne_Stroustrup). Трябва да знаете, че дори да не се спазват конвенциите, кодът ще работи (стига да е написан правилно), но просто няма да бъде лесно разбираем. Това, разбира се, не е фатално на основно ниво, но колкото по-бързо свикнете да пишете качествен код, толкова по-добре.

За езика **C++ съществуват множество код конвенции**, като например една често използвана е на Bjarne Stroustrup, която е публикувана в статията "Bjarne Stroustrup's C++ Style and Technique FAQ" в [https://www.stroustrup.com/bs_faq2.html](https://www.stroustrup.com/bs_faq2.html).

Използваните конвенции в текущата книга са описани на следващите редове. За форматиране на кода се препоръчва **къдравите скоби `{}`** да са по следния начин:
* Отварящата скоба **`{`** да е на същия ред и точно след конструкцията, към която се отнася.
* Затварящата скоба **`}`** да е самостоятелно на отделен ред, както е в примера по-долу.

```cpp
if (someCondition) {
    cout << "Inside the if statement" << endl;
}
```

Вижда се, че командата **`cout`** в примера е **4 празни полета навътре (една табулация)**, което също се препоръчва от **Microsoft** като добра практика. Без значение колко таба навътре започва определена конструкция с къдрави скоби (т.е. без значение колко влагания на различни оператори имаме), **къдравите скоби `{}`** трябва да са в **началото на конструкцията**, както е в примера по-долу:

```cpp
if (someCondition) {
   if (anotherCondition) {
       cout << "Inside the if statement" << endl;
   }
}
```

Ето това е пример за **лошо форматиран код** спрямо общоприетите конвенции за писане на код на езика C++:
   
```cpp
if(someCondition)
{
cout << "Inside the if statement" << endl;}
```

Първото, което се забелязва са **къдравите скоби `{}`**. Първата (отваряща) скоба трябва да е **точно след `if` условието**, a втората (затваряща) скоба - **под командата `cout << (…)`, на отделен празен ред**. В допълнение, командата вътре в **`if`** конструкцията трябва да бъде **4 празни полета навътре (един таб)**. Веднага след ключовата дума **`if`** и преди условието на проверката се оставя **интервал**.

Същото правило важи и за **`for` цикли, както и за всякакви други конструкции, включващи къдрави скоби `{}`**. Ето още няколко примера:

Правилно:

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

Грешно:

```cpp
for(int i=0;i<5;i++){
cout << i << endl;
}
```

За наше удобство има **бързи клавиши във Visual Studio**, за които ще обясним по-късно в настоящата глава, но засега ни интересуват 2 конкретни комбинации. Едната комбинация е за форматиране на **кода в целия документ**, а другата комбинация - за форматиране на **част от кода**. Ако искаме да форматираме **целия код**, то трябва да натиснем [**CTRL + K + D**]. В случай, че искаме да форматираме само **част от кода**, то ние трябва да **маркираме с мишката частта**, която искаме да форматираме, и да натиснем [**CTRL + K + F**].

Нека използваме **грешния пример** от преди малко:

```cpp
for(int i=0;i<5;i++){
cout << i << endl;
}
```

Ако натиснем [**CTRL + K + D**], което е нашата комбинация за форматиране на **целия документ**, ще получим код, форматиран според **общоприетите конвенции за C++**, който ще изглежда по следния начин:

```cpp
for (int i = 0; i < 5; i++) {
    cout << i << endl;
}
```

Тази комбинация може да ни помогне, ако попаднем на лошо форматиран код.

## Именуване на елементите на кода

В тази секция ще се фокусираме върху **общоприетите конвенции за именуване на проекти, файлове и променливи** в C++ света.

### Именуване на проекти и файлове

**За именуване на проекти и файлове** се препоръчва описателно име, което подсказва **каква е ролята** на въпросния файл / проект и в същото време се препоръчва **`PascalCase` конвенцията**. Tова е **конвенция за именуване** на елементи, при която всяка дума, включително първата, започва с **главна буква**, например **`ExpressionCalculator`**.

Пример: в този курс се започва с лекция **First steps in coding** и следователно едно примерно именуване на проекта (Solution) за тази лекция може да бъде **`FirstStepsInCoding`**. Същата конвенция важи и за файловете в даден проект. Ако вземем за пример първата задача от лекцията **First steps in coding**, тя се казва **Hello World** и следователно нашият файл в проекта ще се казва **`HelloWorld`**.

### Именуване на променливи

В програмирането променливите пазят някакви данни и за да е по-разбираем кодът, името на една променлива трябва **да подсказва нейното предназначение**. Ето и още няколко препоръки за имената на променливите:

* Името трябва да е **кратко и описателно** и да обяснява за какво служи дадената променлива.
* Името трябва да се състои само от буквите **a-z**, **A-Z**, **цифрите 0-9**, както и **символа '\_'**.
* В C++ е прието променливите да **започват** винаги **с малка буква** и да **съдържат малки букви**, като **всяка следваща дума** в тях **започва с главна буква** (това именуване е още познато като **`camelCase`** конвенция).
* Трябва да се внимава за главни и малки букви, тъй като C++ прави разлика между тях. Например **`age`** и **`Age`** са различни променливи.
* Имената на променливите **не могат да съвпадат със служебна дума** (keyword) от езика C++, например **`int`** е невалидно име на променлива.

<table><tr><td><img src="/assets/alert-icon.png" style="max-width:50px" /></td>
<td>Въпреки че използването на променливи от изцяло главни букви в имената е разрешено, в C++ това не се препоръчва и се счита за лош стил на именуване.
Добрата практика е променливи с изцяло главни букви да се ползват само за имена на <strong>Macros</strong> (https://docs.microsoft.com/en-us/cpp/preprocessor/macros-c-cpp?view=vs-2017)</td>
</tr></table>

Ето няколко примера за **добре именувани** променливи:

* **`firstName`**
* **`age`**
* **`startIndex`**
* **`lastNegativeNumberIndex`**

Ето няколко примера за **лошо именувани променливи**, макар и имената да са коректни от гледна точка на компилатора на C++:

* **`_firstName`** (започва с '\_')
* **`last_name`** (съдържа '\_')
* **`AGE`** (изписана е с главни букви)
* **`Start_Index`** (започва с главна буква и съдържа '\_')
* **`lastNegativeNumber_Index`** (съдържа '\_')

Първоначално всички тези правила може да ви се струват безсмислени и ненужни, но с течение на времето и натрупването на опит ще видите нуждата от норми за писане на качествен код, за да може да се работи по-лесно и по-бързо в екип. Ще разберете, че е изключително досадна работата с код, който е написан без да се спазват никакви правила за качествен код.

## Бързи клавиши във Visual Studio

В предната секция споменахме за две от комбинациите, които се отнасят за форматиране на код. Едната комбинация [**CTRL + K + D**] беше за **форматиране на целия код в даден файл**, а втората [**CTRL + K + F**] ни служеше в случай, че искаме да **форматираме само дадена част от кода**. Тези комбинации се наричат **бързи клавиши** и сега ще дадем по-подробна информация за тях.

Бързи клавиши са **комбинации**, които ни предоставят възможността да извършваме някои действия **по-лесно и по-бързо**, като всяка среда за разработка на софтуер си има своите бързи клавиши, въпреки че повечето се повтарят. Сега ще разгледаме някои от **бързите клавиши** във **Visual Studio**.

|        Комбинация       |                                    Действие                                |
| ----------------------- | -------------------------------------------------------------------------- |
|  [**CTRL + F**]         | Комбинацията **отваря търсачка**, с която можем да **търсим в нашия код**. |
|  [**CTRL + K + C**]     | **Закоментира** част от кода.                                              |
|  [**CTRL + K + U**]     | **Разкоментира код**, който е вече закоментиран.                           |
|  [**CTRL + Z**]         | **Връща една промяна назад** (т.нар. Undo).                                |
|  [**CTRL + Y**]         | Комбинацията има противоположно действие на [**CTRL + Z**] (т.нар. Redo).  |
|  [**CTRL + K + D**]     | **Форматира кода** според конвенциите по подразбиране.                     |
|  [**CTRL + Backspace**] | **Изтрива** думата вляво от курсора.                                       |
|  [**CTRL + Del**]       | **Изтрива** думата вдясно от курсора.                                      |
|  [**CTRL + Shift + S**] | **Запазва** всички файлове в проекта.                                      |
|  [**CTRL + S**]         | **Запазва** текущия файл.                                                  |

Повече за **бързите клавиши във Visual Studio** може да намерите тук: [https://docs.microsoft.com/en-us/visualstudio/ide/default-keyboard-shortcuts-in-visual-studio](https://docs.microsoft.com/en-us/visualstudio/ide/default-keyboard-shortcuts-in-visual-studio).

## Шаблони с код (code snippets)

Във Visual Studio съществуват т.нар. **шаблони с код** (code snippets), при изписването на които се изписва по шаблон някакъв блок с код. Например при изписването на кратък код **`for`** и натискане на **[Tab]** се генерира следният код, в тялото на нашата програма, на мястото на краткия код:

```cpp
for (size_t i = 0; i < length; i++) {

}
```

Това се нарича "разгъване на шаблон за кратък код". На фигурата по-долу е показано действието на шаблона **`for`**:

![](/assets/chapter-11-images/01.Code-snippet-01.png)

### Шаблони за код

Можем да **създаваме собствени шаблони** или да свалим такива от интернет и да ги добавим (**Add**) или вмъкнем (**Import**). Това се прави от [**Tools**] -> [**Code Snippets Manager**], както е показано на картинката:

![](/assets/chapter-11-images/01.Code-snippet-02.png) 

В отворилия се прозорец трябва да изберем [**Language**] -> [**Visual C++**], а от секцията [**Locations**] -> [**Visual C++**]. Там се намират всички съществуващи шаблони за езика **C++**:

![](/assets/chapter-11-images/01.Code-snippet-03.png) 

От бутоните [**Add**] и [**Import**] можем да добавим нови шаблони. Бутона [**Remove**] служи за изтриване.

## Техники за дебъгване на кода

Дебъгването играе важна роля в процеса на създаване на софтуер, която ни позволява **постъпково да проследим изпълнението** на нашата програма. С помощта на тази техника можем да **следим стойностите на локалните променливи**, тъй като те се променят по време на изпълнение на програмата, и да **отстраним** евентуални **грешки** (бъгове). Процесът на дебъгване включва:

* **Забелязване** на проблемите (бъговете).
* **Намиране** на кода, който причинява проблемите.
* **Коригиране** на кода, причиняващ проблемите, така че програмата да работи правилно.
* **Тестване**, за да се убедим, че програмата работи правилно след нанесените корекции.

Visual Studio ни предоставя **вграден дебъгер** (debugger), чрез който можем да поставяме **точки на прекъсване** (или breakpoints), на избрани от нас места. При среща на **стопер** (breakpoint), програмата **спира изпълнението** си и позволява **постъпково изпълнение** на останалите редове. Дебъгването ни дава възможност да **вникнем в детайлите на програмата** и да видим къде точно възникват грешките и каква е причината за това.

За да демонстрираме работа с дебъгера ще използваме следната програма:

```cpp
int main() {
    for (int i = 0; i < 100; i++) {
        cout << i << endl;
    }
}
```

Ще сложим **стопер** (breakpoint) на функцията **`cout`**. За целта трябва да преместим курсора на реда, който печата на конзолата, и да натиснем [**F9**]. Появява се **стопер**, където програмата ще **спре** изпълнението си:

![](/assets/chapter-11-images/02.Debugger-01.png) 

За да стартираме **програмата в режим на дебъгване**, избираме [**Debug**] -> [**Start Debugging**] или натискаме [**F5**]:

![](/assets/chapter-11-images/02.Debugger-02.png) 

След стартиране на програмата виждаме, че тя **спира изпълнението си** на ред 6, където сложихме стопера (breakpoint). Стрелката вляво показва текущия ред. За да преминем на **следващ ред** използваме клавиш [**F10**]. **Забелязваме, че кодът на текущия ред все още не е изпълнен**. **Изпълнява се, когато преминем на следващия ред**:

![Debugger](/assets/chapter-11-images/02.Debugger-03.png) 

От прозореца [**Locals**] можем да наблюдаваме **промените по локалните променливи**. За да отворим прозореца, избираме [**Debug**] -> [**Windows**] -> [**Locals**]:

![Debugger](/assets/chapter-11-images/02.Debugger-04.png) 

## Справочник с хитрости

В тази секция ще припомним накратко **хитрости и техники** от програмирането с езика C++, разглеждани вече в тази книга, които ще са много полезни при явяването на изпит по програмиране за начинаещи:

### Отпечатване на текст на конзолата

```cpp
string text = "some text";
cout << text << endl;
// Tова ще отпечата на конзолата "some text"
```
Може да тествате примера онлайн: https://repl.it/@vncpetrov/PrintText.

### Вкарване на променливи в стринг (string)

**Placeholder** представлява израз, който ще бъде заменен с конкретна стойност при отпечатване. Функцията **`printf(…)`**  поддържа печатане на текст по шаблон, като първият аргумент, който трябва да подадем, е форматиращият низ, следван от броя аргументи, равен на броя на плейсхолдърите. Функцията се намира в библиотеката **stdio.h** и е необходимо да я реферираме в началото на програмата:

```cpp
string text = "some text";
int number = 5;

printf("%s %d %s\n",
    text.c_str(), number, text.c_str());
// Tова ще отпечата "some text 5 some text"
```
Може да тествате примера онлайн: https://repl.it/@vncpetrov/VarInString.

В този пример забелязваме, че можем да подаваме **не само текстови променливи**. С **`%`** се указва типа на следващата прменлива: **`%d`** се използва са числов тип **`int`**, **`%s`** - за стринг и т.н.

### Форматиране с 2 цифри след десетичния знак

```cpp
double number = 5.432432;
cout << fixed << setprecision(2) << number;
// Това ще отпечата на конзолата "5.43"
```
Може да тествате примера онлайн: https://repl.it/@vncpetrov/RoundingSetprecision.

Закръгляме резултата до **2 цифри след десетичния знак използвайки `fixed << setprecision(2)`**, като не забравяме да реферираме библиотеката **`<iomanip>`**.

Ако искаме да закръглим до **2 цифри след десетичния знак** и третата цифра е по-малкa от 5, както в примера по-горе, то закръглянето е надолу, но ако третата цифра е 5 или по-голяма - закръглянето е нагоре, както е в примера по-долу:

```cpp
double number = 5.439;
cout << fixed << setprecision(2) << number << endl;
// Tова ще отпечата на конзолата "5.44"
```
Може да тествате примера онлайн: https://repl.it/@vncpetrov/RoudinginSetprecision2.

### Закръгляне на числа

При нужда от закръгляне можем да използваме един от следните функции, които се намират в библиотеката **math.h**:

 * **`round(…)`** - закръглянето се извършва по основното математическо правило - ако десетичната част е по-малка 5, числото се закръгля надолу и обратно: ако е по-голяма от 5 - нагоре. Важно е да отбележим, че тази функция закръгля до цяло число:

     ```cpp
    double firstNumber = 5.431;
    cout << round(firstNumber) << endl;
    // Това ще отпечата на конзолата "5"

    double secondNumber = 5.539;
    cout << round(secondNumber) << endl;
    // Това ще отпечата на конзолата "6"
    ```
Може да тествате примера онлайн: https://repl.it/@vncpetrov/RoundingWithRound.
 
 * **`floor(…)`** -  в случай, че искаме закръглянето да е винаги **надолу**. Тази функция също закръгля до цяло число. Например, ако имаме числото 5.99 и използваме **`floor(5.99)`**, ще получим числото **5**:
 
    ```cpp
    double numberToFloor = 5.99;
    cout << floor(numberToFloor) << endl;
    // Tова ще отпечата на конзолата 5
    ```
Може да тествате примера онлайн: https://repl.it/@vncpetrov/RoundFloor.

 * **`ceil(…)`** - в случай, че искаме закръглянето да е винаги **нагоре**. Тази функция също закръгля до цяло число. Например, ако имаме числото 5.11 и използваме **`ceil(5.11)`**, ще получим числото **6**:

    ```cpp
    double numberToCeiling = 5.11;
    cout << ceil(numberToFloor) << endl;
    // Tова ще отпечата на конзолата 6
    ```
Може да тествате примера онлайн: https://repl.it/@vncpetrov/RoundCeil.

 * **`trunc(…)`** - в случай, че искаме да **премахнем дробната част**. Например, ако имаме числото 2.63 и използваме **`trunc(2.63)`**, ще получим **2**:

    ```cpp
    double numberToTrunc = 2.63;
    cout << trunc(numberToTrunc) << endl;
    // Tова ще отпечата на конзолата 2
    ```
Може да тествате примера онлайн: https://repl.it/@vncpetrov/RoundTrunc.

### Закръгляне чрез placeholder

    ```cpp
    double num = 5.439524;
    printf("%.3f\n", num);
    // Това ще отпечата на конзолата "5.440"
    ```
Може да тествате примера онлайн: https://repl.it/@vncpetrov/RoundingWithPlaceholder.

В случая след числото добавяме **`.3f`**, което ще ограничи числото до 3 цифри след десетичния знак. Поведението ще е като на функцията **`setprecision(…)`**. Трябва да имаме предвид, че числото преди буквата **`f`** означава до колко цифри след десетичния знак да е закръглено числото (т.е. може да е примерно **`2f`** или **`5f`**). Не забравяйте и **точката преди числото** - тя е задължителна.

### Как се пише условна конструкция?

Условната **`if` конструкция** се състои от следните елементи:

* Ключова дума **`if`**.
* **Булев израз** (условие).
* **Тяло** на условната конструкция.
* Незадължително: **`else` клауза**.

```cpp
if (условие) {
    // тяло
}
else (условие) {
    // тяло
}
```

За улеснение може да използваме code snippet за **`if` конструкция**:
 * **`if` + [Tab]**

### Как се пише for цикъл?

За **`for` цикъл** ни трябват няколко неща:

* **Инициализационен блок**, в който се декларира променливата-брояч (**`int i`**) и се задава нейна начална стойност.
* **Условие** за повторение (**`i <= 10`**).
* **Обновяване** на брояча (**`i++`**).
* **Тяло** на цикъла.

```cpp
for (int i = 0; i < 5; i++) {
    // тяло
}
```

За улеснение може да използваме code snippet за **`for` цикъл**:
 * **`for` + [Tab]**
 * **`forr` + [Tab]**
 
## Какво научихме от тази глава?

В **настоящата** глава се запознахме как **правилно** да **форматираме** и именуваме елементите на нашия **код**, някои **бързи клавиши** (shortcuts) за работа във Visual Studio, **шаблони с код** (code snippets) и разгледахме как се **дебъгва код**.
