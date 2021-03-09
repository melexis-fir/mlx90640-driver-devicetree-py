# MLX90640 driver for device tree on a SBC.

[![GitHub release (latest by date)](https://img.shields.io/github/v/release/melexis-fir/mlx90640-driver-devicetree-py?label=github-latest-release-tag)](https://github.com/melexis-fir/mlx90640-driver-devicetree-py/releases) ![Lines of code](https://img.shields.io/tokei/lines/github/melexis-fir/mlx90640-driver-devicetree-py)  

[![PyPI](https://img.shields.io/pypi/v/mlx90640-driver-devicetree)](https://pypi.org/project/mlx90640-driver-devicetree) ![PyPI - Python Version](https://img.shields.io/pypi/pyversions/mlx90640-driver-devicetree) ![PyPI - License](https://img.shields.io/pypi/l/mlx90640-driver-devicetree)  

![platform](https://img.shields.io/badge/platform-linux%20PC%20%7C%20rasberry%20pi%204%20%7C%20Jetson%20Nano%20%7C%20beagle%20bone-lightgrey)  

MLX90640 is a thermal camera (32x24 pixels) using Far InfraRed radiation from objects to measure the object temperature.  
https://www.melexis.com/mlx90640  
The python package "[mlx90640-driver](https://github.com/melexis-fir/mlx90640-driver-py)" driver interfaces the MLX90640 and aims to facilitate rapid prototyping.

This package provide the I2C low level routines.
It uses the I2C from the device tree of a single board computer(SBC).  

## Getting started

### Installation

```bash
pip install mlx90640-driver-devicetree
```

https://pypi.org/project/mlx90640-driver-devicetree  
https://pypistats.org/packages/mlx90640-driver-devicetree

__Note:__  
Make sure the user has access to `/dev/i2c-<x>`.  
And easy way to do this is by adding the user to the group `i2c`.

### Running the driver demo

* Connect the MLX90640 on the I2C bus of the SBC.  
* Open a terminal and run following command:  

```bash
mlx90640-devicetree-dump /dev/i2c-1
```

This program takes 1 optional argument.

```bash
mlx90640-devicetree-dump <communication-port>
```

Note: this dump command is not yet available!
