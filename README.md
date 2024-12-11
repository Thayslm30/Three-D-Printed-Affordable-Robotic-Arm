# T.A.R.A. - Three-D Printed Affordable Robotic Arm

This repository includes the code, 3D printing files, and documentation to build the industrial robot arm named **T.A.R.A.**. This project aims to make robotics accessible by providing a low-cost and customizable solution for education, research, and small-scale industry applications.

<img width="317" alt="Figure 12" src="https://github.com/user-attachments/assets/1d63093c-5e74-4239-9de0-4f86ffb40c9e">

---

## What's Included

This repository contains:

1. **3D Printing Files**: STL files for all robot parts.
2. **Electronics and Circuit Diagrams**: Wiring guides.
3. **Software**:
   - Arduino code to control de robot
   - Arduino code for troubleshooting
   - Jupyter Notebobks with the Python code to run simulations of the robot
4. **Documentation**:
   - Bill of materials (BOM) https://docs.google.com/document/d/1PwCRcLvzc4oVpurYSVTbRW2TU2EedRhl2yPV-Ze2hmc/edit?usp=sharing

---

## Getting Started

### Prerequisites

To replicate this project, you’ll need the following:
- **3D Printer**: Compatible with PLA or ABS filament.
- **Electronics**: 
  - Microcontroller (Arduino)
  - Servo motors (MG996R, SG90SR, etc.)
  - Power supply and wires
- **Software**:
  - Python 3.8+ https://www.python.org
  - Arduino IDE (for firmware upload) https://www.arduino.cc/en/software
  - Autodesk Fusion 360 (or any software that allows you to view and modify the 3D printing .stl files) https://www.autodesk.com/products/fusion-360/overview?term=1-YEAR&tab=subscription
  - Jupyter Notebook https://docs.jupyter.org/en/latest/
  - Pinocchio Library https://stack-of-tasks.github.io/pinocchio/
  - Meshcat Library https://pypi.org/project/meshcat/
  - Conda for environment management https://anaconda.org/anaconda/conda

### Steps to Build

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/Thayslm30/Three-D-Printed-Affordable-Robotic-Arm.git
2.  **3D Print the parts**:
     - All the parts can be printed with a 20% infill, except for the base, which has to be 50% to be able to handle the weight of all the robot.
     - All the parts can be printed without supports and without adhesions.
       
3.  **Build the circuit**:
![Figure 11](https://github.com/user-attachments/assets/9e1a0557-dbdc-4448-9370-accc07058d7d)
  
4.  **Assemble the robot**  
   - Starting from top motor at the gripper, the convention is hand servo, wrist servo, elbow servo, shoulder servo, and base servo inside the base.
   - The micro servo goes in the hand joint.
   - The standard servos are for the wrist, elbow, and base joints.
   - The High torque servo is for the shoulder joint.
   - The joints and links have spaces to pass the cables through
   - Use the complete 3D model available in the 3D printing file, to use as a reference of how the parts should fit together. Attach the halves of the links using the screws mentioned in the BOM.
   - The boards can be organized inside the base of the robot.
     
5.  **Running the code**
    - Before running the code for the first time, make sure that all the servos are physically disconnected from the links and are allowed to move freely, for them to be able to move to the zero postion for calibration.
         


### Demos
https://drive.google.com/drive/u/1/folders/1L06COeyFpNktWuyYnfT8AG40fpObh4bi
