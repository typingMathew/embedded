# Erste Stunde

## erstes Erfolgserlebnis

![Image of a curcuit containing a arduino and a breadboard. A black cable connects the Ground Port of the Arduino through a resistor with a red LED. A red cable connects the 5 Volt Port of the Arduino with the other side of the LED](pngs/shining_LED.png)
Bild 1: Schaltkreis einer einfachen leuchtenden LED

![Image of a curcuit containing a arduino and a breadboard. It is similar to the last picture except the Red Cable now arises from the Digital Port 13 of the Arduino](pngs/blinking_LED.png)
Bild 2: Schaltkreis mit blinkender LED  
Dazu gehört der Quellcode der Datei [blinking.ino](src/blinking/blinking.ino)

![Image of a curcuit containing a arduino and a breadboard. The 8  digital Ports 0 to 7 of the Arduino are each connected to a LED through a resistor. The other side of the LEDs is connected to the Ground Port of the Arduino.](pngs/multiple_LED.png)
Bild 3: Schaltkreis mit mehreren LED die in einer Laola-Welle durchlaufen.  
Dazu gehört der Quellcode der Datei [laola.ino](src/laola/laola.ino)

## Controller - Microprozessor

Ersteres enthällt zusätzlich zum Prozessor noch Peripheriebausteine wie:  
analog-digital digital-analog Wandler, Timerbaustein

## Pull-Up/ -Down Widerstand

Pull-Up Widerstand zieht Spannung im Leerlauf auf die Eingangsspannung (High). Pull-Down widerum auf Ground(Low).

## Haupt - und Steuerstromkreis

von [wikipedia.org](https://de.wikipedia.org/wiki/Hauptstromkreis#:~:text=Steuerstromkreise%20beinhalten%20die%20notwendige%20Logik,Notausstromkreise%20meist%20zu%20den%20Steuerstromkreisen.)
> Der **Hauptstromkreis**, auch als Laststromkreis bezeichnet, wird mit dem Laststrom der Verbraucher beaufschlagt und stellt einen Teil einer elektrischen Schaltung dar. Er wird aus den Hauptgeräten und den Hauptleitungen gebildet. Dabei werden die Hauptgeräte vom Hauptstrom in einer bestimmten Reihenfolge durchflossen:
>
> 1. Elektrische Sicherung  
> 2. Hauptschalter  
> 3. Hauptschütz  
> 4. Motorschutzschalter  
> 5. Verbraucher  
>
> [...]
>
> Von den Hauptstromkreisen sind die **Steuerstromkreise** zu unterscheiden. Steuerstromkreise beinhalten die notwendige Logik zur Steuerung oder Verriegelung der Hauptstromkreise. Steuerstromkreise sind häufig Teil der Schaltungen rund um eine speicherprogrammierbare Steuerung. Ebenso zählen Notausstromkreise meist zu den Steuerstromkreisen.
