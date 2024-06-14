# VIGENERE CIPHER

## HOW IT WORKS

A Vigenère cipher works by generating a table from a key to be used to encode or decode text. This works by writing down the Alphabet, then writing the key ignoring repeat characters, you then remove the letters from the Alphabet that match the key, and finally you fill in the rest of the row with the remaining Alphabet.

### Example

key = SECRET
1. **Write the Alphabet**
    - A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
2. **Rewrite the key removing repeat characters**
    - S E C R T
3. **Write the key and then the rest of the Alphabet**
    - S E C R T A B D F G H I J K L M N O P Q U V W X Y Z

The next step is to create the table. To do this write the string created in the last step in the first row. Then in the next step remove the first character and place it at the end of the string and write down this new 26-character string. On the sides of the table write down the Alphabet regularly, this step will help when encoding and decoding.

### Example

One row added.

|   | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| A | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z |

Two rows added.

|   | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| A | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z |
| B | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S |

Three rows added.

|   | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| A | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z |
| B | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S |
| C | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E |

Keep moving the character to the end of the string and rewriting until you have twenty-six rows or in other words when the last character is in the front.

### Completed Table for key = SECRET

|   | A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z |
| - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - | - |
| A | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z |
| B | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S |
| C | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E |
| D | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C |
| E | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R |
| F | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T |
| G | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A |
| H | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B |
| I | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D |
| J | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F |
| K | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G |
| L | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H |
| M | J | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I |
| N | K | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J |
| O | L | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K |
| P | M | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L |
| Q | N | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M |
| R | O | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N |
| S | P | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O |
| T | Q | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P |
| U | U | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q |
| V | V | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U |
| W | W | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V |
| X | X | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W |
| Y | Y | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X |
| Z | Z | S | E | C | R | T | A | B | D | F | G | H | I | J | K | L | M | N | O | P | Q | U | V | W | X | Y |

To use the table you take your plaintext and align it with your key repeating the key when necessary. Using the table you use the first character of your plaintext to align with the Alphabet on the top or bottom; then using the first character of the key you align with the Alphabet on the side. Using the table like a cartesian plane with the plaintext serving as x, and the key serving as y you find the character that they match to.

### Example

- HIDDEN MESSAGE : plaintext
- SECRTS ECRTSEC : key
- ZJAUXA NBGIPHB : encoded text

## PROGRAM OPTIONS

### REGULAR

encoding / decoding regularly

### BY WORD

byWordEncoding / byWordDecoding
