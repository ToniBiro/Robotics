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

This game is 2 player. One 8x8 displays will be used. There will be the standard cactus and the bird that will come towards the player and if they touch one life will be lost out of the 5 the player started with.
The "dino" will be controlled with a joystick and by targeting the other dino with the joystick you will attack. If the attack happens while he is in the air it is possible to trap the second player between two obstacles.
The game will end the moment one of the players remains with 0 lives and the player with the highest score wins.
(If a player avoids getting hit by 5 obstacles he will gain one new life.)

#### How can you gain points?
Both players scores increases as time passes. The speed of the dinos is independent of the speed by which the game increases. When you get hit by something your score drops by 10 points.

## Technical requirements
- will use 2 joysticks
- 1 8x8 matrix
- LCD - to show the two player scores and the highscore (the first 3 highscores will be stored in the EEPROM)
- 1 MAX7219 Driver
- buzzer - buzzes when a player dies
- a button to turn on and off the game

It will have two scores for each player, a single high score and the number of lives.
