# Reverse Engineered Actuator
This project is a scientific collaboration with a professor at the University of Wollongong in Dubai in their resarch of development of 3D printed Flexible Strain Sensors.

Measuring and collecting resistance values of these 3D printed flexible sensors when exposed to incremental linear displacemets along the body using a linear actuator. Using this collected data to plot graphs relating displacement to reistance of the sensors through a set of two separate experiments to find the correlation between them.

**Experiment 1:**
 - Sensor will undergo incremental displacement of 0.5mm up to a total displacement of 10mm, from there it will come back to original position at -0.5mm increments.
 - 3 seconds pause after completing each increment.
 - Resistance data is only recorded while moving and not during the pause periods.

**Experiment 2:**
 - Sensors will go through mulitple rounds continously, each round will a target displacement.
 - At each round, the sensor will be displaced to a total displacement of the target displacement with no increments and then return to starting position.
 - Target displacements start at 0.5mm; after each round, this increases by 0.5mm until a maximum of 10mm.
 - All rest periods after reaching target displacement and in between rounds are standardized too 3 seconds 

Collected data of resistance values with varying displacements are located in "DataExtraction"

Below is the apparatus used for these experiments, constituting of a linear actuator with the black sensors mounted on top, Arduino Mega, and a laptop. A voltage divider circuit was used with a 10k ohms resistor to calculate the the resistance across the sensor.

![Apparatus](https://github.com/user-attachments/assets/6485c219-62ca-471d-ad3d-3ec3c3a08a4f)
