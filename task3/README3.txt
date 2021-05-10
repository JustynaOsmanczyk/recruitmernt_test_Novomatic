Content of the task: 
"Remove items in constant time (the complexity of the solution O(1)) from an unsorted random access container (std::vector or std ::array). 
The order of items in the final container does not matter."

My comment about my solution:
The content of the task is written in a fairly general form, which allows for various interpretations of the problem.
Removing elements from a container in constant time with the complexity of O(1) is possible in the case when It is an element from the beginning or the end of the container.
If instead of an element at the beginning or end of the container, we remove any element, it will be necessary to move all elements of the container, 
which means that the solution is not independent of the number of elements and its computational complexity is O(n).
The solution I propose is to create an unordered map that check what is the index of a given element.
In the case of the delete command, a search is carried out at what index a given value is, then we move the last element to this place and replace the indexes.
The applied map type has the computational complexity of searching and replacing equal to O(1), which allows us to maintain the computational complexity at the level of O(1).
However, the solution I propose has its limitations.
All elements of the container must be the implemented template specializations of std: hash, which will not work for some data types.
An additional disadvantage is that the elements of the container cannot be repeated.