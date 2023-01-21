# Rotary Dial Interface

This is a small sketch for Arduino to read input from old phones ☎️ that had rotary dials.

![Schematic](https://user-images.githubusercontent.com/22567537/213864575-405e497d-ad13-4203-b16d-31d468af6b14.png)

## Installation

1. Connect the ground wire (usually green) to GND
2. Connect the brown wire to DIGITAL 2 on the board
3. Connect the white wire to DIGITAL 3 on the board
4. Upload the sketch to your Arduino board (Tested on Arduino Uno)

## Operation

Open Serial Monitor to see which digit is being put in  
When the dial is engaged a built in LED will light up  
You can additionally connect and LED to digital pin 12 - it will light up everytime the digit is incremented  

## Roadmap

- [ ] Analog write in increments of 9 as an optional output
- [ ] Adapt the project for Raspberry Pi

### Troubleshooting

One common problem with old mechanisms is that their contact surfaces wear with time.
For example if the digit counter terminal sometimes reads abnormal values, usually a couple digits above what should have been one might try to slightly bend them closer together for a tighter fit.
This problem happened during development and stalled it for a couple of days of rewiring and rewriting code.

### Known issues

* If user dials less than 1 the output will read 0
* If user doesn't disengage the dial completely and keeps rotating the dial it can read upward to any digit

## License

[MIT](https://choosealicense.com/licenses/mit/)
