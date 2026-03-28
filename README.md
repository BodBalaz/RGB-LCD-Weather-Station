# RGB-LCD-Weather-Station

Ez a projekt egy **Arduino alapú meteorológiai állomás**, amely képes a környezeti hőmérséklet és páratartalom valós idejű monitorozására. A berendezés különlegessége, hogy az adatok számszerű kijelzése mellett egy RGB LED segítségével vizuális visszajelzést is ad a hőmérsékletről.

### Interaktív Tesztelés
A projekt teljes hardveres összeállítása és szoftveres működése megtekinthető és kipróbálható a **[Wokwi online szimulátorában](https://wokwi.com/projects/459456696843830273)**. A szimulációban a DHT22 szenzorra kattintva manuálisan állíthatod a hőmérsékletet, és figyelheted, ahogy az LCD és a LED azonnal reagál a változásra.

---

## Funkciók és Működés
A rendszer lelke egy DHT22-es precíziós szenzor, amely 2 másodpercenként frissíti az adatokat. 

Az RGB LED színe dinamikusan változik a hőmérséklet függvényében:
- ⚪ Fehér: 0°C alatt (Fagy)
- 🔵 Kék: 0°C – 18°C (Hideg)
- 🟢 Zöld: 18°C – 25°C (Ideális)
- 🟠 Narancs: 25°C – 30°C (Meleg)
- 🔴 Piros: 30°C felett (Hőség)

## Hardver felépítés
A projekt az alábbi fő komponensekből épül fel:
* **Arduino Uno R3:** A központi vezérlőegység.
* **DHT22 Szenzor:** Digitális hő- és páratartalom mérő.
* **I2C LCD 16x2:** Energiahatékony kijelző az adatok megjelenítéséhez.
* **Common Cathode RGB LED:** Háromszínű állapotjelző LED.

## Bekötési táblázat
<img src="https://github.com/user-attachments/assets/48fe1f2c-e810-491b-b9a9-73f681678eab" width="475" align="right">

| Komponens | Arduino Pin |
| :--- | :--- |
| **DHT22 Data** | 2 |
| **RGB Red** | 6 |
| **RGB Green** | 5 |
| **RGB Blue** | 3 |
| **LCD SDA** | A4 |
| **LCD SCL** | A5 |

## Telepítési útmutató
1. Telepítsd az Arduino IDE-ben a `DHT sensor library` és a `LiquidCrystal I2C` könyvtárakat.
2. Nyisd meg a `.ino` fájlt és töltsd fel az Arduinóra.
