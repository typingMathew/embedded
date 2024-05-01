# Dritte Stunde

## Praxis

### Nutzen eines Timers zum präzisen Anschalten einer LED durch einen Interrupt

![Video of a curcuit containing a arduino and a breadboard. A black cable connects the Ground Port of the Arduino through a resistor with a red LED. A red cable connects the digital PIN 0 of the Arduino with the other side of the LED. The LED is blinking periodically.](media/interrupt_to_blink.gif)  
Der Arduino besitzt zwei 8 Bit und ein 16 Bit Timer. Bei einer CPU Frequenz von 16 Mhz lassen sich so mit 16 Bit nur maximal 4,096 ms zählen. Deswegen  wird immer nach einer Millisekunde des Timers ein Interrupt ausgelöst, der einen Zähler um eins erhöht und den Timer zurücksetzt. Innerhalb der loop-Funktion wird geprüft, ob der Zähler den Wert 500 erreicht hat. In diesem Fall wird die LED an-, bzw. ausgeschalten und der Zähler wieder zurückgesetzt.

## Theorie

### Interrupt - Unterbrechung

Wenn ein Interrupt ausgelöst wird, wird die aktuelle Verarbeitung unterbrochen, es wird zu einer anderen Stelle gesprungen, eine ISR (Interrupt Service Routine) ausgeführt und anschließend wieder zum normalen Programmfluss zurückgesprungen. Über einen solchen (zeitbasierten) Interrupt lässt sich beispielsweise ein Scheduler realisieren.

## Rolltor

Aufgabe:  
Zeichnung eines Ablaufdiagramms eines automatisierten Rolltores mit folgenden Bestandteilen:
Mikrocontroller, Motor, H-Brücke, 2 Taster (hoch, runter), 2 Endschalter (wann schranke ganz oben/ unten), 2*7 Segment für 10s counter. (Zusatz: Ampel,  Notaus)  
Lösung:
![A really complex activity diagramm](media/rolltor.png)  
[Quelltext](src/rolltor/rolltor.puml)
