Sparse motion-planning for autonomous vehicle street traversibility.

## Installing / Getting started

A quick introduction of the minimal setup of the environment.

```shell
# clone the project into your local repository
# "Open folder in container" on VS code using Remote Containers extendion

```

This should build and run the Dockerfile on your system. This is essential for working with the latest packages and dependencies required for our project

## Developing

### Setting up Dev and Building

To begin developing, open the terminal inside the container and run the following:

```shell
cd ~/workspaces/cs225FinalProject2022/code/MotionPlanning
mkdir build
cd build
cmake ..
```

All the source files will be present here

### Building

If code is changed within the workspace, to realize the changes, you will have to make the project by doing the following:

```shell
cd ~/workspaces/cs225FinalProject2022/code/MotionPlanning/build
make "/workspaces/cs225FinalProject2022/data/000113/lidar_roof/1616536043201.bin" "/workspaces/cs225FinalProject2022/data/000113.json" "/workspaces/cs225FinalProject2022/data/000113/lidar_roof/ 1616536043201.bin"
```
This will make the project. The data can be found here (large files):
annotations: https://drive.google.com/drive/folders/14cI2vleBokHEtSLjZAgzmjL1cFOkoYwD
lidar data: https://drive.google.com/drive/folders/1gUCYhCFIEuRePMIRzzRQGTY1L0XmbsUq

## Presentation video and report
The link to the video:
The link to the final report: https://github.com/stuti-agrawal/cs225FinalProject2022/blob/main/report.md
