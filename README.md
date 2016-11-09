# REST notes API

This is a simple RESTful, JSON API to power a note-taking application. The API is implemented in C++ and uses the ngrest framework. The API supports POST, GET by id, GET by query and GET all operations.

## Setup and config

The API uses the ngrest framework which can be downloaded from https://github.com/loentar/ngrest. There are detailed instructions to help install the framework on Windows, Linux and Mac OS X.

After the installation of ngrest, create the notes project as below
```
ngrest create -d hpp notes
```
The -d hpp option enables combining the .h and .cpp files into a single file.

Start the project after it is created
```
cd notes
ngrest
```
ngrest wrapper will build the notes project and will start the server on default port (9098)

Service's sources are located in ```<servicename>/src/<ServiceName>.h/cpp/hpp``` files (For the *notes* service it will be ```notes/src/notes.hpp```).
When a project is generated in ngrest, an echo operation is added into each service as a fast example. 
Replace the existing *notes.hpp* file with the *notes.hpp* in this repository.

After replacing the .hpp file, go back to the original *notes* directory and build the project again with the ```ngrest``` command.

After server is started you can try the service operations: open the link located below the ```To test your services try ngrest service tester:``` message in your browser and test the service operations by entering the required inputs.

## Testing with curl

To test using curl, below are the syntax examples for each of the supported operations:

**POST**

```curl -i -H "Content-Type: application/json" -X POST -d '{"body" : "Example note"}' http://localhost:9098/notes/add```

**GET by id**

```curl -i -H "Content-Type: application/json" -X GET http://localhost:9098/notes/4```

where ```4``` is the id

**GET by query**

```curl -i -H "Content-Type: application/json" -X GET http://localhost:9098/notes/getQuery?query=rest```

where ```rest``` is the query string

**GET all**

```curl -i -H "Content-Type: application/json" -X GET http://localhost:9098/notes/getAll```





