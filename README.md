Sparse motion-planning for autonomous vehicle street traversibility.

## Installing / Getting started

A quick introduction of the minimal setup of the environment.

```shell
# clone the project into your local repository
# "Open folder in container" on VS code using Remote Containers extendion

```

This should build and run the Dockerfile on your system. This is essential for working with the latest packages and dependencies required for our project

## Developing

### Setting up Dev

To begin developing, open the terminal inside the container and run the following:

```shell
cd ~/workspaces/cs225FinalProject2022/code/catkin_ws
source /opt/ros/melodic/setup.bash # sets up ros framework
source devel/setup.bash  # sets up project within ros framework
```
This sets up your project in the context of ROS (robot operating system)

### Building

If code is changed within the workspace, to realize the changes, you will have to make the project by doing the following:

```shell
cd ~/workspaces/cs225FinalProject2022/code/catkin_ws
catkin_make # equivalent to "make"
source devel/setup.bash # sets up project within ros framework
```
This will make the catkin project. 

