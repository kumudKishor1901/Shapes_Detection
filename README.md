# Shapes_Detection


## Overview
This C++ program detects and classifies different shapes (triangles, squares, rectangles, and circles) in an image using contour analysis. It utilizes the OpenCV library for image processing tasks such as edge detection, contour extraction, and shape classification.

## Dependencies
- OpenCV 4.x
- C++ compiler supporting C++11 or later

## Installation and Setup
1. **Install OpenCV**: Ensure you have OpenCV 4.x installed on your system. You can follow the official [OpenCV installation guide](https://docs.opencv.org/master/d7/d9f/tutorial_linux_install.html) for installation instructions.

2. **Clone the Repository**: Clone this repository to your local machine using the following command:
    ```
    git clone <repository_url>
    ```

3. **Build the Project**: Use your preferred C++ compiler to build the project. Make sure to link against the OpenCV libraries. For example, you can use g++:
    ```
    g++ -o shape_detection shape_detection.cpp `pkg-config --cflags --libs opencv4`
    ```

## Usage
1. **Provide Input Image**: Replace the `path` variable in the code with the path to the input image you want to analyze.

2. **Run the Program**: Execute the compiled binary:
    ```
    ./shape_detection
    ```

3. **View Results**: The program will display the input image with detected shapes outlined by bounding boxes and labeled with their corresponding types.

## Customization
- **Thresholds**: You can adjust the parameters of the Canny edge detector (`Canny()`) for edge detection and the size of the structuring element (`getStructuringElement()`) for dilation to fine-tune the contour detection process.
- **Shape Classification**: Modify the conditions inside the loop to classify shapes differently or add support for additional shape types.

## Contributions
Contributions to this project are welcome. Feel free to fork the repository, make changes, and submit pull requests.

## Acknowledgments
- This project was inspired by the need for a simple object detection system using contour analysis.
- Thanks to the OpenCV community for providing powerful tools for image processing and computer vision.
