# Enjector Event.Grid
Enjector Event.Grid is an event based computing fabric framework. The Event.Grid allows you to rapidly build complex distributed systems where the flow of the system is determined by events such as applications made a change to some state, a new sensor reading was published or user interacting with a web page.

An Event.Grid system is made up of services that are written in C, C++, .NET C#, Java and Python. All communication is done using asynchronous message passing.

## Install
```console
$ git clone https://github.com/enjector/enjector-event.grid.git
$ cd enjector-event.grid
$ mkdir build 
$ cd build
$ cmake -A x64 ../
$ cmake -A x64 --build ../

Python package
$ pip install ./event.grid-client.python

```
## Platforms
 * Linux (Ubuntu)
 * Windows

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


