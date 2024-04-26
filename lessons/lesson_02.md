# Zweite Stunde

## praktische Beispiele

### 8 Bit Zähler

![Video of a curcuit containing a arduino and a breadboard. The 8 digital Ports 0 to 7 of the Arduino are each connected to a LED through a resistor. The eight LEDs are in a row on the breadboard. The other side of each of the LEDs is connected to the Ground Port of the Arduino. The eight LEDs display a eight Bit counter, counting from 00000000 to 11111111.](media/counting_LED.gif)  
Schaltkreis mit mehreren LED, die als binärer 8 Bit Zähler fungiert.  
Dazu gehört der Quellcode der Datei [counter.ino](src/counter/counter.ino)

### Blinkende LEDs durch Portregister

![Video of a curcuit containing a arduino and a breadboard. The 8 digital Ports 0 to 7 of the Arduino are each connected to a LED through a resistor. The eight LEDs are in a row on the breadboard. The other side of each of the LEDs is connected to the Ground Port of the Arduino. The LEDs turn alternate between on and off fastly and simultaneously.](media/flashing_LED.gif)  
Schaltkreis mit mehreren LED, dabei wird direkt das ganze Portregister PORTD auf 1 bezw. 0 gesetzt sodass eine gleichzeitig blinkende LED Leiste erzeugt wird.  
Dazu gehört der Quellcode der Datei [flashing.ino](src/flashing/flashing.ino)

### Verwirrendes Programm durch Clock Select

![Image of a curcuit containing a arduino and a breadboard. The 8 digital Ports 0 to 7 of the Arduino are each connected to a LED through a resistor. The eight LEDs are in a row on the breadboard. The other side of each of the LEDs is connected to the Ground Port of the Arduino. The two LEDs on the left are on, the rest is off.](media/complex_LED.png)  
Schaltkreis mit mehreren LED, dabei werden die Clock Select Bits CS00 und CS01, welche die Werte 0 bzw. 1 zurückliefern genutzt, um durch je einen Bitshift je eine LED einzuschalten.  
Dazu gehört der Quellcode der Datei [complex.ino](src/complex/complex.ino)  

### Einbindung Analoger Eingänge

![Video of a curcuit containing a arduino and a breadboard. The three digital Ports 3 to 5 of the Arduino are each connected to a LED through a resistor. The three LEDs are in a row on the breadboard and have the colors green, yellow and red. The other side of each of the LEDs is connected to the Ground Port of the Arduino. There is also a potentiometer on the breadboard, which is connected to the ground, analog input A0 and the 5V output of the arduino. In the video the potentiometer gets turned from low to middle to high and vice versa. During this, first the green LED is on, it then turns off and the yellow LED turns on and on the last third only the red LED is on.](media/analog_in_LED.gif)  
Schaltkreis mit drei LED (Grün, Gelb, Rot) und einem Potentiometer. Der Wert des Potentiometers wird über die Funktion analogRead() als das Ergebnis des Analog-Digital-Wandlers des ATMega, welches die am analogen PIN A0 anliegende Spannung in eine 10 bit Zahl umwandelt, ausgelesen. Anhand dieses wird entweder die grüne, gelbe oder rote LED zum Leuchten gebracht.  
Dazu gehört der Quellcode der Datei [analog_in.ino](src/analog_in/analog_in.ino)

### Analoge Eingänge digital Darstellen

![Video of a curcuit containing a arduino and a breadboard. The 8 digital Ports 0 to 7 of the Arduino are each connected to a LED. The eight LEDs are in a row on the breadboard and represent a binary 8 Bit counter. The other side of each of the LEDs is connected to the Ground Port of the Arduino through a resistor. There is also a potentiometer on the breadboard, which is connected to the ground, analog input A0 and the 5V output of the arduino. The potentiometer is being turned. For each turn of it clockwise, the binary counter increases. For each turn counter clockkwise it decreases.](media/map_pot_to_LED.gif)  
Potentiometer, dessen umgewandelter 10 Bit Wert mit der map Funktion auf eine 8 Bit Zahl abgebildet wird, um ihn dann durch einen binären 8 Bit LED Counter darzustellen.  
Die map-Funktion: ordnet den Wert eines Zahlenbereiches einem anderen Zahlenbereich zu. Aufruf: map(value, from_lowerbound, from_upperbound, to_lowerbound, to_upperbound)  
Dazu gehört der Quellcode der Datei [map_pot_to_led.ino](src/map_pot_to_led/map_pot_to_led.ino)

## Theorie

### Register

#### DDR (Data Definition Register)

Definiert die Konfigurationseinstellung der entsprechenden Pins (Eingabe oder Ausgabe)

#### PIN

Ein Register aus dem nur gelesen werden kann. Wird genutzt um eingehende Signale zu lesen.

#### Port Register

Ein Register in das auszugebende Signale geschrieben werden können. Ist der entsprechende Pin als Eingabe definiert, dann wird in diesem Register der Defaultwert des Pins festgelegt. Der Arduino besitzt 3 Port Register. Port D repräsentiert die Digitalen PIN 0 bis 7. Port B die Digitalen PIN 8 bis 13 und Port C die analogen PIN 0-5.

### RC/ LC Schwingkreis

TODO
