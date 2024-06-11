# Drone Battery Monitor
**Description**:
Developing an advanced battery percentage measurement system for the XFly drone platform to accurately determine remaining battery life and calculate flight time.

**Initial Approach**:
- Measured battery voltage and calibrated sensor readings to reflect actual voltage.
- Faced challenges due to battery voltage instability and sensor noise.
- Utilized a machine learning model with PWM values and voltage readings, but accuracy was limited.

**Current Approach**:
- Designing a module with analog low-pass filters to reduce voltage reading noise.
- Incorporating current measurements to complement voltage data.
- Analyzing voltage and current to calculate the battery's electromotive force (EMF).
- Providing a more reliable estimate of remaining battery capacity.

**Key Objectives**:
- Enhance accuracy of battery life measurement.
- Improve reliability of flight time predictions for the XFly drone platform.
- Develop a dual-parameter system considering both voltage and current for stable battery percentage readings.

This project aims to significantly improve the accuracy and reliability of battery measurement systems for drones, supporting better flight time management and overall performance.
