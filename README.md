# Enjector Event.Grid
Enjector Event.Grid is an event based computing fabric framework. The Event.Grid allows you to rapidly build complex distributed systems where the flow of the system is determined by events such as applications made a change to some state, a new sensor reading was published or user interacting with a web page.

An Event.Grid system is made up of services that are written in C, C++, .NET C#, Java and Python. All communication is done using asynchronous message passing.

# Support
* Join us on [Discord](https://discord.me/enjector-intermix) 

## Install
Windows Build
* Requires Visual Studio 2019 and CMake 3.18.x

```console
$ git clone https://github.com/enjector/enjector-event.grid.git
$ cd enjector-event.grid
$ mkdir build 
$ cd build
$ cmake -A x64 .
$ cmake -A x64 --build .
```

Install Python package
* Requires Python 3.8.x
```console
$ python event.grid-client.python/setup.py install
```

Ubuntu (NOT WORKING YET)
```console
sudo apt install -y python3-dev default-jdk

sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.8 1
curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
python get-pip.py
pip install pybind11
```

## Platforms
 * Linux (Ubuntu) x64
 * Windows x64

## Usage samples

#### C++ Basic Subscriber
```c++
#include <Event.Grid/Node.h>

int main() 
{
}

```
---
#### C# Basic Publisher
```c#
```
---
#### Python Basic Publisher
```python
import eventgrid as evg
```


