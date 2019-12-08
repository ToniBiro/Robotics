# The Dino Game
## Description
It is a game similar to the dinosaur game that Google chrome offers it's users when there is no internet.

### (For those who don't know)
![t-rex game](https://github.com/ToniBiro/Robotics/blob/master/Matrix%20game/trex.png?raw=true)
This the hidden Google chrome T-rex game. By pressing the up and down arrow you make the dino jump or bend. You do this in order to avoid hitting the obstacles that you are running toward, in order not to die, cactuses and birds. As time passes your speed increases making it harder to avoid getting hit.
![t-rex game](https://github.com/ToniBiro/Robotics/blob/master/Matrix%20game/deadtrex.png?raw=true)

### My Dino Game

My game will look somewhat similar to this:
![t-rex game](https://github.com/ToniBiro/Robotics/blob/master/Matrix%20game/mytrex.png?raw=true)

It will have the option of a single-player and 2 players. Two 8x8 displays will be used to make the display longer. There will be the standard cactus and the bird that will come towards the player and if they touch one life will be lost out of the 3 the player started with.
The "dino" will be controlled with a joystick and by pressing the joystick he will attack. If the attack happens while he is in the air it is possible to hit the second player if this one is also at that height.
The game will end the moment one of the players remains with 0 lives and the player with the highest score wins.

#### How can you gain points?
Both players scores increases as time passes and the rate at which the score increases is directly proportional to the speed of the dino. When you get hit by something your score drops.

## Technical requirements
- will use 2 joysticks
- 2 8x8 matrices
- LCD - to show the two player scores and the highscore (the highscore will be stored in the EEPROM
- 2 MAX7219 Drivers
- buzzer - buzzes when a player dies
- possibly a button to turn on and off the game

It will have two scores for each player, a single high score and the number of lives.

