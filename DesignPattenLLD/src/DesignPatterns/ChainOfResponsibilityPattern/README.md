## Variation of the problem
  * ATM design
  * Logger design
  * Design vending machine (asked in amazon frequently)

## Concept in a NutShell

   ```
        This of an linkedList where you nee to specify who will be 
        the next in line. Extend a common class or an common interface
        and chain all the child classes one by one like this
        
        > new InfoLogger(new ErrorLogger(new DebugLogger(null)));
   ```

```mermaid
---
title: Animal example
---
classDiagram
    note "From Duck till Zebra"
    Animal <|-- Duck
    note for Duck "can fly\ncan swim\ncan dive\ncan help in debugging"
    Animal <|-- Fish
    Animal <|-- Zebra
    Animal : +int age
    Animal : +String gender
    Animal: +isMammal()
    Animal: +mate()
    class Duck{
        +String beakColor
        +swim()
        +quack()
    }
    class Fish{
        -int sizeInFeet
        -canEat()
    }
    class Zebra{
        +bool is_wild
        +run()
    }

```