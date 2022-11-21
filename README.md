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
make [arg]
```
This will make the project. Replace [arg] with any compilation type of your liking.
