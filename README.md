# Number Base Converter

This is a simple console program written in **C++**.  
It converts numbers between different number systems.

The program supports **bases from 2 to 16** and works with:
- positive numbers
- negative numbers
- large values
- repeated conversions without re-entering the number

---

## Features

- Convert numbers between any bases from **2 to 16**
- Supports digits and letters (`A–F`)
- Works with **negative numbers**
- Converts through the **decimal system internally**
- Input validation (wrong symbols, wrong bases)
- Option to **reuse the old number** without typing it again
- Correct handling of `0`

---

## How it works

1. User enters a number  
2. User selects the base of the entered number  
3. Program checks if the number is valid  
4. The number is converted to **base 10**  
5. From base 10 it is converted to the target base  
6. User can:
   - convert the same number again  
   - or enter a new number  

---

## Example

**Input**
```
Number: -1011
Base: 2
Convert to: 16
```

**Output**
```
-B
```

---

## Limitations

- Console application only
- Uses `windows.h` for clearing the screen
- Bases higher than 16 are not supported

---

## Technologies

- Language: **C++**
- Standard: C++11
- Platform: Windows console

---

## Notes

This project was created for learning purposes.  
The code is written step by step and is easy to read and understand.
