# Toy data storage system

## Structure

DSS is composed of a bunch of the nodes, which actually store the data
and perform operations entered by the user.

Each node internally process the messages (commands) and send new ones:

```
[                Node                  ]
[transport] <-> [executor] <-> [storage]
```

Exchange bus provide the medium for message exchange between nodes:

```
[               App               ]
[exchange bus] -> [nodes]O[threads]
```

And each node is served by it's own thread.

