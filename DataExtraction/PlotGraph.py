import os
import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import interp1d

# ------------------- Experiment 1 File Paths ------------------- #
EXPERIMENT_1_FILES_PATH = []

EXP1SAM1PATH = "Experiment 1/Sample 1"
EXP1SAM2PATH = "Experiment 1/Sample 2"
EXP1SAM3PATH = "Experiment 1/Sample 3"
EXP1SAM4PATH = "Experiment 1/Sample 4"

EXPERIMENT_1_FILES_PATH.append(EXP1SAM1PATH)
EXPERIMENT_1_FILES_PATH.append(EXP1SAM2PATH)
EXPERIMENT_1_FILES_PATH.append(EXP1SAM3PATH)
EXPERIMENT_1_FILES_PATH.append(EXP1SAM4PATH)

# ------------------- Experiment 2 File Paths ------------------- #
EXPERIMENT_2_FILES_PATH = []

EXP2SAM1PATH = "Experiment 2/Sample 1"
EXP2SAM2PATH = "Experiment 2/Sample 2 (Broke half way)"
EXP2SAM3PATH = "Experiment 2/Sample 3 (break at 8mm & 9mm)"
EXP2SAM4PATH = "Experiment 2/Sample 4"

EXPERIMENT_2_FILES_PATH.append(EXP2SAM1PATH)
EXPERIMENT_2_FILES_PATH.append(EXP2SAM2PATH)
EXPERIMENT_2_FILES_PATH.append(EXP2SAM3PATH)
EXPERIMENT_2_FILES_PATH.append(EXP2SAM4PATH)


def PlotExp2Graph(FILEPATH, plotTitle):
    Sample = {}  # Key will be displacement and value, the readings
    displacementS2 = []
    resistanceS2 = []
    remappedDisp = []

    for values in os.listdir(FILEPATH):
        if len(values) == 7:
            displacement_key = float(values[0])
        elif len(values) == 8:
            displacement_key = float(values[0:2])
        elif len(values) == 9:
            displacement_key = float(values[0:3])

        if int(displacement_key) == displacement_key:
            displacement_key = int(displacement_key)

        Sample.setdefault(displacement_key, [])

        with open(os.path.join(FILEPATH, values)) as file:
            file_contents = [float(line.strip()) for line in file.readlines() if line.strip()]
            Sample[displacement_key].extend(file_contents)

    # Sort the dictionary items by key in ascending order
    sorted_sample = dict(sorted(Sample.items()))

    for key, value in sorted_sample.items():
        length = len(value)
        div = key / length

        start_value = div
        end_value = key
        num_elements_forward = length // 2

        # Create the list using numpy's arange function for forward displacement
        temp1 = np.linspace(start_value, end_value, num_elements_forward).tolist()

        # Now for backward displacement
        start_value_backward = temp1[-1]
        end_value_backward = 0
        num_elements_backward = length - num_elements_forward

        # Create the list using numpy's arange function for backward displacement
        temp2 = np.linspace(start_value_backward, end_value_backward, num_elements_backward).tolist()

        # Concatenate forward and backward displacement values
        remappedDisp.extend(temp1 + temp2)

    # Ensure the length of remappedDisp matches the length of resistanceS2
    # remappedDisp = remappedDisp[:len(resistanceS2)]
    for key, value in sorted_sample.items():
        # print(key, value)
        displacementS2.append(key)
        resistanceS2.extend(value)

    print(len(resistanceS2), len(remappedDisp))

    # Adjust the length of remappedDisp to match the length of resistanceS2
    remappedDisp = remappedDisp[:len(resistanceS2)]
    print(len(remappedDisp))

    x_values = np.array(remappedDisp)
    y_values = np.array(resistanceS2)

    plt.plot(x_values, y_values, label='Smoothed Curve', color='red')

    # Set specific values for the x-axis ticks
    plt.xticks(displacementS2)
    plt.yticks(np.unique(resistanceS2))

    plt.title(plotTitle)
    plt.xlabel('Displacement')
    plt.ylabel('Resistance')
    plt.legend()
    plt.show()


def PlotExp2Interp(FILEPATH, plotTitle):
    Sample = {}  # Key will be displacement and value, the readings
    displacementS2 = []
    resistanceS2 = []
    remappedDisp = []

    for values in os.listdir(FILEPATH):
        # (Assuming your file name parsing logic remains the same)
        if len(values) == 7:
            displacement_key = float(values[0])
        elif len(values) == 8:
            displacement_key = float(values[0:2])
        elif len(values) == 9:
            displacement_key = float(values[0:3])

        if int(displacement_key) == displacement_key:
            displacement_key = int(displacement_key)

        Sample.setdefault(displacement_key, [])

        with open(os.path.join(FILEPATH, values)) as file:
            file_contents = [float(line.strip()) for line in file.readlines() if line.strip()]
            Sample[displacement_key].extend(file_contents)

    # Sort the dictionary items by key in ascending order
    sorted_sample = dict(sorted(Sample.items()))

    for key, value in sorted_sample.items():
        length = len(value)
        div = key / length

        start_value = div
        end_value = key
        num_elements_forward = length // 2

        temp1 = np.linspace(start_value, end_value, num_elements_forward)
        remappedDisp.extend(temp1)

        start_value_backward = remappedDisp[-1]
        end_value_backward = 0
        num_elements_backward = length - num_elements_forward

        temp2 = np.linspace(start_value_backward, end_value_backward, num_elements_backward)
        remappedDisp.extend(temp2)

    for key, value in sorted_sample.items():
        displacementS2.append(key)
        resistanceS2.extend(value)

    # Use linear interpolation to create a smooth curve
    f_interp = interp1d(remappedDisp, resistanceS2, kind='linear', fill_value='extrapolate')

    # Generate more x values for a smoother curve
    x_interp = np.linspace(min(remappedDisp), max(remappedDisp), 1000)

    # Calculate corresponding y values using the interpolation function
    y_interp = f_interp(x_interp)

    plt.plot(x_interp, y_interp, label='Smoothed Curve', color='red')
    plt.scatter(remappedDisp, resistanceS2, label='Data Points', color='blue')

    plt.title(plotTitle)
    plt.xlabel('Displacement')
    plt.ylabel('Resistance')
    plt.legend()
    plt.show()


def PlotExp1Interp(FILEPATH, plotTitle):

    Sample = {}  # Key will be displacement and value, the readings
    displacementS1 = []
    resistanceS1 = []
    # remappedDisp = []

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

    for key, value in sorted_sample.items():
        # print(key, value)
        displacementS1.append(key)
        resistanceS1.extend(value)

    div = 10/1240
    # print(div)

    # Specify the starting number, end value, and the increment
    start_value = div
    end_value = 10
    num_elements = len(resistanceS1)

    # Create the list using numpy's arange function
    remappedDisp = np.linspace(start_value, end_value, num_elements).tolist()

    print(len(remappedDisp))

    # Use linear interpolation to create a smooth curve
    f_interp = interp1d(remappedDisp, resistanceS1, kind='linear', fill_value='extrapolate')

    # Generate more x values for a smoother curve
    x_interp = np.linspace(min(remappedDisp), max(remappedDisp), 1000)

    # Calculate corresponding y values using the interpolation function
    y_interp = f_interp(x_interp)

    plt.plot(x_interp, y_interp, label='Smoothed Curve', color='red')
    plt.scatter(remappedDisp, resistanceS1, label='Data Points', color='blue')

    plt.title(plotTitle)
    plt.xlabel('Displacement')
    plt.ylabel('Resistance')
    plt.legend()
    plt.show()


def PlotExp1Graph(FILEPATH, plotTitle):

    Sample = {}  # Key will be displacement and value, the readings
    displacementS1 = []
    resistanceS1 = []
    remappedDisp = []

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

    for key, value in sorted_sample.items():
        # print(key, value)
        displacementS1.append(key)
        resistanceS1.extend(value)

    div = 10/1240
    # print(div)

    # Specify the starting number, end value, and the increment
    start_value = div
    end_value = 10
    num_elements = len(resistanceS1)

    # Create the list using numpy's arange function
    remappedDisp = np.linspace(start_value, end_value, num_elements).tolist()

    print(len(remappedDisp))

    # Extract x and y values from the sorted dictionary
    x_values = np.array(remappedDisp)
    y_values = np.array(resistanceS1)

    plt.plot(x_values, y_values, label='Smoothed Curve', color='red')

    # Set specific values for the x-axis ticks
    plt.xticks(displacementS1)
    plt.yticks(np.unique(y_values))

    plt.title(plotTitle)
    plt.xlabel('Displacement')
    plt.ylabel('Resistance')
    plt.legend()
    plt.show()


# Plotting Experiment 1 Samples
counter = 1
for plots in EXPERIMENT_1_FILES_PATH:
    PlotExp1Graph(plots, f'Experiment 1 Sample {counter}')
    PlotExp1Interp(plots, f'Experiment 1 Sample {counter}')
    counter = counter + 1


# Plotting Experiment 2 Samples
counter = 1
for plots in EXPERIMENT_2_FILES_PATH:
    PlotExp2Graph(plots, f'Experiment 2 Sample {counter}')
    PlotExp2Interp(plots, f'Experiment 2 Sample {counter}')
    counter = counter + 1
