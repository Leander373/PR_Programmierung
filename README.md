# Strukturen in C - 10 Punkte (+ 5 Punkte Präsentation)

In dieser Aufgabe solle Sie sich mit der Verwendung von _Strukturen_ (oder _Structs_) vertraut machen.

## Teilaufgabe a) - Elastischer Stoß

In dieser Teilaufgabe soll ein elastischer Stoß von zwei Reitern, angenähert als Punktteilchen, berechnet werden. Der nötige Quellcode befindet sich unter `stoss.c`. Wie Sie dem Code entnehmen können, werden die einzelnen Teilchen durch das Struct `reiter` mit den Feldern `masse` und `geschwindigkeit` beschrieben, wobei zwei Teilchen dann durch das Struct `zustand` zusammengefasst werden können.

Lesen Sie die Argumente über die Kommandozeile in der Reihenfolge `<m1> <v1> <m2> <v2>` ein und initialisieren Sie zwei Teilchen mit den entsprechenden Parametern, welche Sie anschließend zu einem Zustand zusammenfassen. Die Funktion `stosse_reiter` soll nun zu einem gegebenen Zustand `vorher` den Zustand `nachher`, nach dem Stoß, berechnen und zurückgeben. Fragen Sie hierbei ab, ob es überhaupt zu einem Stoß kommen kann und berechnen Sie dann ggf. die Geschwindigkeiten nach dem Stoß durch

```math
\begin{aligned}
v_1' &= \frac{m_1 v_1 + m_2 v_2 + m_2 (v_2 - v_1)}{m_1 + m_2} \\
v_2' &= \frac{m_1 v_1 + m_2 v_2 + m_1 (v_1 - v_2)}{m_1 + m_2}
\end{aligned}
```

Überprüfen Sie Ihre Implementierung anhand verschiedener beispielhafter Anfangsszenarien.

## Teilaufgabe b) - Raketengleichung

Betrachten Sie hierbei eine Rakete die sich sehr weit entfernt von jeglichen Planeten, Sternen oder anderen Himmelkörpern in einem homogenen Universum befindet. Das bedeutet, Sie können die Wirkung der Gravitation in dieser Aufgabe vernachlässigen. Die Rakete soll durch das Struct `rakete` beschrieben werden. Eine `rakete` hat also die Eigenschaften:

- `leer_masse`: Die Masse der Rakete ohne Treibstoff $`m_R`$
- `geschwindigkeit`: Die Geschwindigkeit der Rakete $`v_R`$ (soll hier bei 0 starten)
- `treibstoff_masse`: Die Masse des Treibstoffs, den die Rakete mit sich führt $`m_T`$
- `treibstoff_geschwindigkeit`: Die Geschwindigkeit, mit der der Treibstoff von der Rakete ausgestoßen wird $`v_T`$
- `treibstoff_massenverlustrate`: Gibt an, wie groß die Menge an Treibstoff ist, die pro Zeitintervall ausgestoßen wird $`\Delta m_T/\Delta t`$ (erst für _Teilaufgabe c_ relevant).

Die Parameter der Rakete sollen über Kommandozeilen-Argumente, in der Reihenfolge `<leer_masse> <treibstoff_masse> <treibstoff_geschwindigkeit> <treibstoff_massenverlustrate>`, übergeben werden.

Sie sollen numerisch berechnen, wie hoch die Endgeschwindigkeit der Rakete ist, wenn der komplette Treibstoff ausgestoßen ist. Implementieren Sie dazu die Funktion `masseschritt`.

Wie der Funktionsprototyp von `masseschritt` bereits zeigt, soll das Struct `rakete` mit Hilfe eines _Pointers_ übergeben werden. Das ist in diesem Fall sinnvoll, da somit z.B. die neu berechnete Geschwindigkeit auch in der aufrufenden Funktion (hier die `main`-Funktion) zur Verfügung steht. Außerdem muss der Funktion `masseschritt` die Größe des _Massenschritts_ übergeben werden können, also wie viel Masse an Treibstoff in einem Berechnungsschritt ausgestoßen wird. Je kleiner diese Zahl gewählt wird, desto genauer und länger wird die Berechnung. Es muss also ein Kompromiss eingegangen werden. Die Geschwindigkeit der Rakete ändert sich bei einem _Massenschritt_ um:

```math
\text{d}v_R = v_T \frac{\text{d}m_T}{m_R+m_T}
```

Vergessen Sie nicht, die Masse in jedem Schritt zu aktualisieren.

## Teilaufgabe c)

Berechnen sie nun, nach welcher Zeit und Strecke die Endgeschwindigkeit der Rakete erreicht wird. Erweitern Sie dazu das Struct `rakete` um `strecke` und `zeit`. Implementieren Sie außerdem die Funktion `zeitschritt`. Diese funktioniert ähnlich wie `masseschritt`, nur, dass jetzt über Zeitschritte iteriert wird. Um die Massenänderung innerhalb des Zeitschritts zu berechnen verwenden Sie den Parameter `treibstoff_massenverlustrate`, der für die Rakete am Anfang initialisiert wird. Die `main`-Funktion muss natürlich ebenfalls erweitert werden, sodass die Berechnung durchgeführt und das Ergebnis ausgegeben wird.

## Teilaufgabe d)

Bereiten Sie eine 15- bis 20-minütige Präsentation vor, in der Sie die Verwendung von Strukturen (`structs`) in C beschreiben und die Problemstellung sowie die Ergebnisse dieser Aufgabe vorstellen. 

### Die Präsentation ist als `.pdf`-Datei bis 23\. Mai 2025 via `git` abzugeben, der Code kann nach der Präsentation noch überarbeitet werden und muss bis 30\. Mai 2025 über `git` abgegeben werden.