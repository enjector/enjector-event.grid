# Enjector Event Grid
Enjector Event Grid is a event based computing fabric. The Event Grid allows you to build complex distributed systems where the flow of the system is determined by events such as applications made a change to some state, a new sensor reading was published or user interacting with a web page.



A solution built using the Event Grid is made up on autonomous components that communicate with each other using asynchronous message passing.

Here are some principles:

* The Grid allows distributed components to run on any type of host (cloud, on-premise, mobile, embedded). Components can be many languages (C, C++, Java, Python). The key design is that components, which we call Event Grid Processes, should interact with each other asynchronously and the should aim to reduce the communication latency dynamically.

* The goal of the Event Grid's architecture is to ensure that software platform can achieve a greater magnitude in computing throughput than traditional architectures like "N-Tier" by taking advantage of growing number multi-core CPUs, GPUs and FPGAs within servers and specialised sensors on edge devices.

* Event Grid is not based on a centralised system. It contains purpose built autonomous components that work independently, but are coordinated to complete some piece of work.

* The way Event Grid Processes find each other is similar to how the mobile phone network works. Each business logic component is an autonomous service running on any machine, outside of the firewall or inside another firewall. When the service is activated it registers to the network and has a phone number. 

Grid Processes are responsible for its own resources in isolation from other services. When another business logic requests an action to be carried out it must specify the phone number and the request details. A response can be given immediately or leave a "voice mail" message to be responded later.

Several autonomous service could have the same phone number, so the mobile phone network would send the request to each service in turn (round robin). If a service then doesn't become available (ie. busy or not available), then the request is routed to the next available service with same phone number.

This mechanism is also used to scale up when a larger volume of incoming requests arrive.

* The Grid middleware also provides seamless interoperability between heterogeneous systems and languages to provide services.  It also provides authentication and role-based security model, which there are a list of permissions attached to the business endpoints to allow fine grain control over the business resource usage and prevent unauthorized business endpoints.

To summarise, the Grid middleware contains autonomous services that provides increase reliability and throughput.  If failure occurs the middleware will attempt to reroute requests (fix itself). 

The most critical aspect of the Grid middleware is the registration mechanism (for services registering with a "phone number" (called the Grid Process ID or PID)). This registration control mechanism is contained within the Grid Node service which all Grid Processes connect to. 

To ensure scalability all Grid Processes are always stateless and any session like information should reside in a centralised database.



## The Problem Statement
Many things need to be considered when choosing an architecture of a project/application that would provide the best performance, scalability and changeability. 

Firstly, consider n-tier architecture that contains at least 3 logical layers (presentation, business logic and data logic (database)).  Each layer interacts with only the layer directly below, and have specific responsibilities. 

Concentrating on the business logic, this layer is usually composed of multiple components that tightly coupled through programming code. It is then compiled and deployed as a monolithic package on each server. The business logic component then runs as a single process whose resources are allocated by the operating system. 

Here are some of the major limitations of running the business logic in a single process:

*	Problem: maximum threads per process
A single process (under .NET) can comfortably manage 25 concurrent threads. This is a major disadvantage since we wish to scale to 30k+ concurrent users. This limitations would cause bottlenecks when processing real-time requests.

*	Problem: no isolation of execution
If a component crashes it would stop the entire business logic layer process and any running threads. Ideally existing parts of the business logic should continue to run and the component that crashed should return a friendly message that they should try again.

*	Problem:  no isolation of memory, CPU and disk resources
Some components  may take more resources (such as memory and CPU) than other components. In a single process these resources would have to be shared amongst components. This would impact the performance of other components.

There's no way in monolithic business logic layer (as a single process) to offload processing to other servers or give a lower priority/QoS. Ideally there should be physical partitioning of the business logic components.

*	Problem: security
Some components of the business logic may communicate with external connections and exchange data. From a security perspective these components would need to be isolated from the main business logic to reduce the attack surface (what the hacker is attempting to break in via) to a minimum as possible.

*	Problem: no hot deployments
Making a changes in the business logic would require redeploying the entire application and would not cater for 24x7 operation. Ideally hot updates/patching should be achievable.
