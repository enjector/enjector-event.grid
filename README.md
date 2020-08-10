# Enjector Event.Grid

[![CI](https://github.com/enjector/enjector-event.grid/workflows/Ubuntu%20Build/badge.svg)](https://github.com/enjector/enjector-event.grid/actions)

Enjector Event.Grid is an event based computing fabric framework. The Event.Grid allows you to rapidly build complex distributed systems where the flow of the system is determined by events such as applications made a change to some state, a new sensor reading was published or user interacting with a web page.

An Event.Grid system is made up of services that are written in C, C++, .NET C#, Java and Python. All communication is done using asynchronous message passing.

# Support
* Join us on [Discord](https://discord.me/enjector-intermix) 

## Install
##### Windows Build
* Requires Visual Studio 2019 and CMake 3.18.x

```console
$ git clone https://github.com/enjector/enjector-event.grid.git
$ cd enjector-event.grid
$ cmake -A x64 .
$ cmake -A x64 --build .
```

##### Ubuntu
```console
$ sudo apt install -y python3-dev default-jdk

$ git clone https://github.com/enjector/enjector-event.grid.git
$ cd enjector-event.grid
$ cmake .
$ make -j
```

##### Python package
* Requires Python 3.8.x
```console
$ python event.grid-client.python/setup.py install
$ python event.grid-client.python/tests/check_if_installed.py
```

##### Docker image
```console
Build
$ docker build -t enjector/event.grid:latest .

Publish
$ docker push enjector/event.grid

Run
$ docker run -p 127.0.0.1:8080:8080/tcp enjector/event.grid

Shell To
$ docker exec -it <container name/id> /bin/bash

Clean (Windows)
$ powershell
$ > docker ps -q | % { docker stop $_ }
$ > docker images -a -q | % { docker image rm $_ -f }
$ > docker system prune --all -f
$ > exit
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


