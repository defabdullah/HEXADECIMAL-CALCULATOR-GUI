# HEXADECIMAL-CALCULATOR-GUI
CMPE 230 System Programming Homework

User interface of the project consist a main vertical layout. This layout is formed by a label
and a grid layout. Our label class is derived from QLabel class and used for display current result as
aligned to right of the screen. Also its initial value is 0. The grid layout takes up most of the screen.
It consists 20(5x4) button which is derived from QPushButton class. Buttons in first row are +,-,Clr
and = buttons. Other buttons are numbers in hexadecimal base (e.g. 2,5,C...). There used qt's slot
and signal structure to execute the function of buttons. Number buttons and other buttons are
connected to signal and slots according to their proper usage.

**Clr Button** : Clears all necessary strings and boolean values in the program.

**Plus Sign** : This button is used for addition operation between last two strings after
converting them to hexadecimal value. Updates necessary boolean values and sign variable.

**Minus Sign** : This button is used for addition operation between last two strings after
converting them to hexadecimal value. Updates necessary boolean values and sign variable.

**Equal Button** : Makes operation between last two strings according to sign variable. Then
updates values and display current value in screen. It also set current value as empty string so push
this button more than one time is meaningles.

**Number buttons** : These buttons concatenate appropriate number current string. Then
display current result.

Except main file there are used 3 class in the project and 1 helper cpp file.

**1-MainWidget** : It is main widget which is showed in program and inherited from QWidget.
In the construction of the object buttons,screen and signal-slot structure for all buttons are created.

**2-MyScreen** : It is used for display result and inherited from QLabel. It has functions to set
and clear text.

**3-MyButton** : It is used for buttons and inherited from QPushButton. It has slots and
constant text for distinct buttons.

**4-ConvertFunctions:** It has three functions that is used to convert hexadecimal number to
decimal number. These functions are as follows:

&nbsp;&nbsp;&nbsp;&nbsp; **a-convert_integer:** It takes hexadecimal string as a parameter, converts it to integer
  decimal value and returns it.
  
&nbsp;&nbsp;&nbsp;&nbsp; **b-convert_string:** It takes integer decimal number as a parameter and converts it to
  hexadecimal string and returns it.
  
&nbsp;&nbsp;&nbsp;&nbsp; **c-power:** It takes two arguments, makes a power calculation and returns the value.
  First argument is base and second argument is exponent.

</t>


## Contributors:
  Batuhan İlhan

  Abdullah Susuz
