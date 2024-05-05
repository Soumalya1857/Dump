###  Applicability
Use the Decorator pattern when you need to be able to assign extra behaviors to objects at runtime without breaking the code that uses these objects.
The Decorator lets you structure your business logic into layers, create a decorator for each layer and compose objects with various combinations of this logic at runtime.
The client code can treat all these objects in the same way, since they all follow a common interface.

### How to Implement

* Make sure your business domain can be represented as a primary component with multiple optional layers over it.
* Figure out what methods are common to both the primary component and the optional layers. Create a component interface and declare those methods there.
* Create a concrete component class and define the base behavior in it.
* Create a base decorator class. It should have a field for storing a reference to a wrapped object.
* Make sure all classes implement the component interface.

### Pros and Cons
```
#### Pros
 * You can extend an object’s behavior without making a new subclass.
 * You can add or remove responsibilities from an object at runtime.
 * You can combine several behaviors by wrapping an object into multiple decorators.
 * Single Responsibility Principle. You can divide a monolithic class that implements many possible variants of behavior into several smaller classes.
 
#### Cons
 *  It’s hard to remove a specific wrapper from the wrappers stack.
 *  It’s hard to implement a decorator in such a way that its behavior doesn’t depend on the order in the decorators stack.
 *  The initial configuration code of layers might look pretty ugly.

```

### Materials
* [Refactoring guru](https://refactoring.guru/design-patterns/decorator)
* [LLD shreyansh - youtube](https://www.youtube.com/watch?v=w6a9MXUwcfY&list=PL6W8uoQQ2c61X_9e6Net0WdYZidm7zooW&index=6)