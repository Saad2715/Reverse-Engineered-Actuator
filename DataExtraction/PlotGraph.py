import os
import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d

# ------------------- Experiment 1 File Paths ------------------- #
EXPERIMENT_1_FILES_PATH = []

EXP1SAM1PATH = "C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer's Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 1\\Sample 1"
EXP1SAM2PATH = "C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer's Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 1\\Sample 2"
EXP1SAM3PATH = "C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer's Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 1\\Sample 3"
EXP1SAM4PATH = "C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer's Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 1\\Sample 4"

EXPERIMENT_1_FILES_PATH.append(EXP1SAM1PATH)
EXPERIMENT_1_FILES_PATH.append(EXP1SAM2PATH)
EXPERIMENT_1_FILES_PATH.append(EXP1SAM3PATH)
EXPERIMENT_1_FILES_PATH.append(EXP1SAM4PATH)

# ------------------- Experiment 2 File Paths ------------------- #
EXPERIMENT_2_FILES_PATH = []

EXP2SAM1PATH = "C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer's Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 1"
EXP2SAM2PATH = "C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer's Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 2 (Broke half way)"
EXP2SAM3PATH = "C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer's Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 3 (break at 8mm & 9mm)"
EXP2SAM4PATH = "C:\\Users\\msaad\\Documents\\Saad\\Research Projects\\Dr. Umer's Project\\Reverse-Engineered-Actuator\\DataExtraction\\Experiment 2\\Sample 4"

EXPERIMENT_2_FILES_PATH.append(EXP2SAM1PATH)
EXPERIMENT_2_FILES_PATH.append(EXP2SAM2PATH)
EXPERIMENT_2_FILES_PATH.append(EXP2SAM3PATH)
EXPERIMENT_2_FILES_PATH.append(EXP2SAM4PATH)


def PlotExp1Graph(FILEPATH, plotTitle):

    Sample = {}  # Key will be displacement and value, the readings

    for values in os.listdir(FILEPATH):
        # RES_PATH = os.path.join(FILEPATH, values)

        if len(values) == 7:
            displacement_key = float(values[0])
        elif len(values) == 8:
            displacement_key = float(values[0:2])
        elif len(values) == 9:
            displacement_key = float(values[0:3])

        # Handle the case where the file names do not include ".0"
        if int(displacement_key) == displacement_key:
            displacement_key = int(displacement_key)

        Sample.setdefault(displacement_key, [])

        with open(os.path.join(FILEPATH, values)) as file:
            # file_contents = [float(line.strip()) for line in file.readlines()]
            file_contents = [float(line.strip()) for line in file.readlines() if line.strip()]

            Sample[displacement_key].extend(file_contents)

    # Sort the dictionary items by key in ascending order
    sorted_sample = dict(sorted(Sample.items()))

    # Extract x and y values from the sorted dictionary
    x_values = np.array(list(sorted_sample.keys()))
    y_values = np.array(list(sorted_sample.values()))

    # Flatten the y_values to a 1D array
    y_values_flat = np.array([item for sublist in y_values for item in sublist])

    # Repeat each x value according to the length of its corresponding y values
    x_values_mapped = np.repeat(x_values, [len(sublist) for sublist in y_values])

    # Perform linear interpolation to make both arrays of the same length
    f_interp = interp1d(x_values_mapped, y_values_flat, kind='linear', fill_value='extrapolate')

    # Generate more x values for a smoother curve
    x_interp = np.linspace(min(x_values_mapped), max(x_values_mapped), 1000)

    # Calculate corresponding y values using the interpolation function
    y_interp = f_interp(x_interp)

    # Plot the original points as a continuous line
    plt.plot(x_values_mapped, y_values_flat, 'o-', label='Original Data')

    # Plot the smooth curve
    plt.plot(x_interp, y_interp, label='Smoothed Curve', color='red')

    # Set specific values for the x-axis ticks
    plt.xticks(np.unique(x_values))
    plt.yticks(np.unique(y_values))

    plt.title(plotTitle)
    plt.xlabel('Displacement')
    plt.ylabel('Resistance')
    plt.legend()
    plt.show()


PlotExp1Graph(EXP1SAM1PATH, f'Experiment 1 Sample 1')
