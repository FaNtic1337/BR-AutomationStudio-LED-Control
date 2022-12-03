# Creating project

Первым делом необходимо создать проект через AutomationStudio (у меня версия 4.10) Для этого перейдем во вкладку **File -> New Project** как на картинке или нажмем сочетание клавиш **Ctrl+Shift+N**.

<details align="center">
    <summary>Creating New Project</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/Create%20New%20Project.png" alt="Create New Project" title="Create New Project">

Создание нового проекта

</details>

Далее напишем название, выберем путь проекта и описание. Будьте внимательны, AutomationStudio не позволяет изменять файлы, если папка с проектами является корневой. Для изменения таких файлов потребуется запуск от имени администатора.

<details align="center">
    <summary>Name New Project</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/Name%20New%20Project.png" alt="Name New Project" title="Name New Project">

Название нового проекта

</details>

## Hardware configuration

Существует 3 способа задать конфигурацию аппаратного обеспечения.

- Ручная настройка аппаратного обеспечения;
- Определение онлайн подключенного аппаратного обеспечения;
- Использовать уже готовую конфигурацию аппаратного обеспечения.

Используем ручную настройку, чтобы самостоятельно задать все компоненты нашей конфигурации. Для этого выберем пункт **Define a new hardware configuration manually**. Также дадим название и добавим описание, как на картинке.

<details align="center">
    <summary>Configure New Project</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/Configure%20New%20Project.png" alt="Configure New Project" title="Configure New Project">

Конфигурация нового проекта

</details>

Откроется каталог предустановленного аппаратного обеспечения. Здесь небходимо выбрать промышленный лабораторный компьютер, который будет подключен к реальной B&R установке. В моем случае это PLK **4PP065.0571-P74**. Добавим его, как показано на картинке.

<details align="center">
    <summary>Adding PLK</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/Adding%20PLK.png" alt="Adding PLK" title="Adding PLK">

Добавление PLK 4PP065.0571-P74

</details>

После прогрузки проекта необходимо добавить мы увидим окно проекта AutomationStudio. Во вкладке **Physical View** перейти в **Toolbox - Hardware Catalog** и выбрать блоки соответсвующие вашей реальной установке.

Наша конфигурация будет состоять из следующих блоков:

- X20SL8000
- X20BC0083
- X20PS9400 (добавляется автоматически вместе с X20BC0083)
- X20SM1436
- X20SM1436
- X20MM4456
- X20DI9371
- X20DO9322

С помощью Drag and Drop подключаем модули последовательно друг к другу. Если у вас, как и у меня, возникла ошибка подключения блоков:

***Node number -1 is lower than the minimum node number 2 on network interface X20BB80.IF1.***			

Попробуйте подключить их в обратном порядке. По какой-то причине это сработало. В конечном итоге вы должны получить нечто похожее:

<details align="center">
    <summary>Adding Hardware</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/Adding%20Hardware.png" alt="Adding Hardware" title="Adding Hardware">

Добавление остального аппаратного обеспечение

</details>

Подключаем PLK 4PP065.0571-P74 порт IF4 к порту PLK1 блока X20SL8000, затем подключаем порт PLK1 блока X20SL8000 к порту PLK1 блока X20BC0083. Во всплывающих окнах функциональных моделей выбираем **Default**. В итоге мы должны получить такой же результат как и на картинке ниже.

<details align="center">
    <summary>Ready hardware</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/Ready%20Hardware.png" alt="Ready hardware" title="Ready hardware">

Готовое аппаратное обеспечение

</details>

## Connection configuration
 
 Если вы работаете на реальном оборудовании, вам необходимо знать IP-Address of PLK и маску подсети. Чтобы подключение произошло успешно, необходимо перейти в **Physical View -> ETH -> Configuration**. Во вкладке **Mode** выбрать **Enter IP address manually** и ввести IP-address и Subnet Mask. 

 <details align="center">
    <summary>ETH Configuration</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/ETH%20Configuration.png" alt="ETH configuration" title="ETH configuration">

Готовое аппаратное обеспечение

</details>

Если все настройки выставлены верно и оборудование подключено, через вкладку **Online -> Settings** нажать на кнопку **Browse**. PLK должен быть обнаружен. Иногда приходится вручную выставлять у PLK параметры. Для этого в найденом устройстве нажмите **Set IP Parameters** и повторите операции с вводом IP-address и Subnet Mask, после чего нажать **Add to Connections**. С новым отобразившимся подключением необходимо поставить галочку **Use in active config** и нажать **Connect**.

 <details align="center">
    <summary>Connection to PLK</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/Online%20Settings.png" alt="Connection to PLK" title="Connection to PLK">

Подключение к PLK

</details>

# Program structure

Необходимо подготовить все необходимые пакеты перед началом написания программного кода (язык C). Во вкладке **Logical View** находятся вся структура логики проекта. Сюда необходимо добавить программный пакет **ANSI C Program All In One** из **Toolbox - Object Catalog** просто перетащив его в Logical View. Получается что-то вроде этого.

 <details align="center">
    <summary>ANSI C Programm All In One</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/Program%20Structure.png" alt="Program Structure" title="Program Structure">

Добавление программного пакета

</details>

В блоке **Variables.var** инициализируем переменные светоиндикаторова **led1**, **led2**, **led3**, **led4** и счетчик времени **time_cnt**. Так как у светоиндикаторов есть только 2 положения: включен и выключен, для этих переменных поставим тип данных **BOOL**, счетчик же будет обычный **INT**. Для выбора типа данных можно воспользоваться контекстным меню или написать вручную. Также желательно задать начальные значения переменным, пускай все светодиоды выключены, а временной счетчик изначально равен 0. Резульат должен быть как на картинке.

 <details align="center">
    <summary>Variables Initialization</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/Variables%20Initialization.png" alt="Variables Initialization" title="Variables Initialization">

Инициализация переменных

</details>

### X20DO9322 I/O Mapping 

Важным шагом является инициализация входов и выходов для установки, если вы работаете с реальным оборудованием. За выход отвечает блок X20DO9322 (DO - Digital Output). В разделе **Physical View -> X20DO9322 -> I/O Mapping** В моем случае светодиоды подключены к выходам **DigitalOutput01 - DigitalOutput04**, но у вас может быть по другому. В столбце **Process Variable** выбрать из контекстного меню наши инициализированные переменные **led1 - led4**. Должно получиться что-то такое.

 <details align="center">
    <summary>I/O Mapping</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/IO%20Mapping.png" alt="I/O Mapping" title="I/O Mapping">

Согласования реальных светодиодов с переменными

</details>

На данном этапе все настройки произведены и можно приступать к написанию кода программы. Надеюсь процесс настройки вас не сильно утомил, теперь начнется самое интересное.

# Writing code

AutomationStudio сама себе представляет программу, которая выполняет программный пакет с заданной переодичностью, по стандарту 100ms. Это можно изменить во вкладке **Configuration View -> Cpu.sw**. Здесь видно, что наш Program расположен в блоке **Cyclic#4**. Это означает, что цикличную часть кода программа будет выполнять именно столько времени, держите это время в голове, когда будете писать свой код.

 <details align="center">
    <summary>Program Cyclic</summary>

<img src="https://github.com/FaNtic1337/B-R-AutomationStudio-LED-Control/blob/main/tutorial%20images/Program%20Cyclic.png" alt="Program Cyclic" title="Program Cyclic">

Частота выполнения программы

</details>

Теперь перейдем в наш **main.c** внутри Logical View. Программный пакет All In One по сути совмещает в себе три отельных части программы: **Init**, **Cyclic**, **Exit**.

**Init** выполняется только один раз. Обычно здесь объявляются переменные, присваиваются начальные значения и прочие подготовительные этапы.

**Cyclic** - основное тело программы. Это как раз та часть когда, которая выполняется циклично по времени (в нашем случае) 100ms.

**Exit** является тем блоком программы, который выполняется по достижению цели, досрочного выхода или завершения работы ПЛК. Обычно сюда записывают сохранения логов или реализуется безопасный выход из программы.

Для демонстрации работы программы поставим следующую цель:

***Заставить светодиоды led1 - led4 мигать с частотой 10 Гц, 5 Гц, 2 Гц, 1 Гц соответсвенно***.

Декомпозируем задачу.

Вспомним, что такое единица измерения Герц. *Один герц  - это величина обратная одной секунде*. Мы имеем дело с миллисекундами, поэтому при переводе нужно это учитывать. И тогда получим следующее соотношения:

<div align="center">

| Hz |  ms  |
|:--:|:----:|
| 10 | 100  |
| 5  | 200  |
| 2  | 500  |
| 1  | 1000 |

</div>

Процесс мигания это сами по себе включения и выключения светодиода. Чем быстрее переключаемся, тем чаще мигает светодиод. Светодиоды жестко привязаны к состояниям состояниям переменных led1 - led4. *Следовательно меняя состояние переменых происходит мигание*.

Вспомним, что один цикл AutomationStudio прогоняет соответсвенно Cyclic#4, то есть 100мс. С помощью счетчика time_cnt будем отслеживать сколько времени прошло. Например, если time_cnt равен 2, то с момента запуска прошло 200мс, следовательно это тот момент времени, когда мы должны переключить состояние нашего led2. 

Для того, чтобы счетчик считал наше время, будем инкрементировать его в конце нашего cyclic блока.

Вот такое решение для мигания 4 светодиодами на разных частотах:

 <details>
    <summary>Sample of solution</summary>

```C
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	time_cnt = 0;
}

void _CYCLIC ProgramCyclic(void)
{
	// 10Hz - 100ms
	led1 = !led1;
	
	// 5Hz - 200ms
	if (time_cnt % 2)
	{
		led2 = !led2;
	}
		
	// 2Hz - 500ms
	if (time_cnt % 2)
	{
		led3 = !led3;
	}
	
	// 1Hz - 1000ms
	if (time_cnt % 2)
	{
		led4 = !led4;
	}
	
	time_cnt++;
}

void _EXIT ProgramExit(void)
{

}
```

</details>

Поддержите этот проект, если вы хотите более объяснение с подробным решением ошибок и отладкой данной программы.