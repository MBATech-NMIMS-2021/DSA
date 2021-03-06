# Data Structures

---

![Data structures image](images/../../../../images/dsa.jpg)

---

-   A data structure is a particular way of organizing data in the computer so that it can be used effectively.

---

## Types of data structures

---

1. Linear data structure
2. Non linear data structures

---

## Linear data structure

---

-   Elements arranged in a sequence, one after the other.

Types of linear data structures

-   Arrays
-   Stacks
-   Queues
-   Linked lists

---

### Arrays

---

-   Elements arranged in continuos memory.
-   All elements are of the same type.

---

### Stacks

---

#### Applications

---

##### In compilers

---

-   Compilers use stacks to figure out the value of expressions like `2 + 4 / 5 * (7 - 9)`

---

##### In browsers

---

-   The back button saves all URL's we've visited in a stack.

---

![Stack of plates](../../../images/StackOfPlates.webp)

---

-   The last element that gets into the stack is removed first (**LIFO Principle**: Last in first out)

---

#### Terminologies

---

##### Push

---

-   To put the element inside the stack.

---

##### Pop

---

-   To remove an element from the stack. (Which is the last, recently inserted element)

---

##### Top

---

-   A variable to store the index value of the topmost element.

---

### Queues

---

![Queues image](../../../images/queue.png)

---

-   Works on the principle of first in first out (**FIFO**)
-   So the first element that gets inside also becomes the first element to leave the queue.

---

#### Terminologies

---

##### Enqueue

---

- To insert an element inside the queue

---

##### Dequeue

---

- To pop out an element from the queue.

---

##### Front

---

- Index to the front element of the queue.

---

##### Rear

---

- Index to the last element of the queue.

---

#### Applications

---

##### Call centers

---

- To hold people calling them in order, until a service representative is free.

---

![Call center image](../../../images/callCenter.png)

---

##### CPU task processing

---

- Serving request on a single shared resource like printer, CPU task scheduling.

---

![CPU silicon chip](../../../images/cpuChip.webp)

---

### Linked list

---

- Elements not stored in contiguous memory locations.
- Elements linked using pointers

---

![Linked list image](../../../images/Linkedlist.png)

---

Types of linked lists:

1. Singly linked list
2. Circular linked list
3. Doubly linked list

---

#### Advantages (over arrays)

---

1. Size of array is generally fixed. In order to store elements without knowing the total elements that'll come in the array, just store them in a linked list.
2. Insertion of elements in array is quite expensive. Because elements are stored in a contiguous block of memory, hence inserting a new element requires all the elements after that index to get shifted, which is becomes quite a big and inefficient job for insertion.

---

#### Disadvantages

---

- Random access not allowed: We need to access the elements sequentially. Accessing any element, randomly is not possible. Hence binary search is also not possible in this case.
- Extra memory space is required along with the element values in order to store the address to the next element.

---

**Note**: Singly linked list is same as the simple linked list we've leant above.

---

#### Circular linked list

---

![Circular linked list](../../../images/CircularLinkeList.png)

---

- Same as the singly linked list with an additional property that the first element's prev. element pointer now points to the last node except for NULL, and the last element's next element pointer now points to the first node.


---

#### Doubly linked list

---

![Doubly linked list image](../../../images/doublyLinkedList.png)

---

- First element

---

```mermaid
flowchart TB;
node(Node) --> prevElem(NULL)
node --> data(Data)
node --> nextEle(Next element)
```

---

- General elements

---

```mermaid
flowchart TB;
node(Node) --> prevEle(Previous element)
node --> data(Data)
node --> nextEle(Next element)
```

---

- Last element

---

```mermaid
flowchart TB;
node(Node) --> prevEle(Previous element)
node --> data(Data)
node --> nextEle(NULL)
```

---

- Visual representation of 3 element linked list

---

```mermaid
flowchart TB;

%% Node 1
node1(Node 1) --> prevEle1(NULL)
node1 --> data1(Data)
node1 --> nextEle1 --> node2

%% Node 2

node2(Node 2) --> prevEle2 --> node1
node2 --> data2(Data)
node2 --> nextEle2 --> node3

%% Node 3

node3(Node 3) --> prevEle3;
prevEle3 --> node2;
node3 --> nextEle3(NULL);
node3 --> data3(Data);
```

---

##### Advantages

---

- A DLL (Doubly Linked List) can be traversed in both the ways.
- Deletion is quite efficient if the pointer to the element that needs to get deleted is given.
- Insertion is also quite efficiently done.

---

##### Disadvantages

---

- Require more memory than linked list because every element now stores the address of next, as well as previous element.

---

## Non-linear data structure

---

- Trees
- Graphs

---

### Trees

---

![Real tree ????](../../../images/realTree.jpg)

---

- Data is arranged in a hierarchial structure, tree like structure.

---

#### Terminologies

---

##### Root

---

- To topmost node from where the tree starts to expand.

---

```mermaid
flowchart TB
rt(Root) --> ele1(Node 1)
rt --> ele2(Node 2)
rt --> ele3(Node 3)
```

---

##### Edge

---

- Link between 2 nodes is called an edge.

---

```mermaid
flowchart TB
rt(Root) --> |Edge1|ele1(Node 1)
rt --> |Edge2|ele2(Node 2)
rt --> |Edge3|ele3(Node 3)
```

---

##### Child Node

---

- Node that has a parent node

---

```mermaid
flowchart TB
rt(Root, Parent node) --> |Edge1|ele1(Child node 1)
rt --> |Edge2|ele2(Child node 2)
rt --> |Edge3|ele3(Child node 3)
```

---

##### Parent Node

---

- Node that has an edge to child node.

---

##### Leaf node

---

- Node that does not have a child node.

---

```mermaid
flowchart TB
rt(Root, Parent node) --> |Edge1|ele1(Child node 1)
rt --> |Edge2|ele2(Child node 2)
rt --> |Edge3|ele3[Leaf node 1]

ele1 --> a[Leaf node 2]
ele2 --> b[Leaf node 3]
```

---

##### Height of node

---

- Number of edges on longest path from that node to leaf node.
- Height is always measured from bottom.

---

```mermaid
flowchart TB
rt(Root, Parent node) --> |Edge1|ele1(Target node)
rt --> |Edge2|ele2(Child node 2)
rt --> |Edge3|ele3[Leaf node 1]
ele1 --> c(Child node)
ele1 --> e(branch1 ele1)
e --> f(ele2)
f --> g(ele 3)
c --> d(Leaf node)
ele2 --> b[Leaf node 3]
```

---

- Height of `target node` is 3 because 3 edges come till `ele 3` while only 2 edges till `Leaf node`

---

![Real height](../../../images/realHeight.webp)

---

##### Depth of node

---

![Real depth](../../../images/realDepth.jpg)

---

- Edges from root to node.
- Depth is always counted from the top.

---

```mermaid
flowchart TB
rt(Root, Parent node) --> |Edge1|ele1(Target node)
rt --> |Edge2|ele2(Child node 2)
rt --> |Edge3|ele3[Leaf node 1]
ele1 --> c(Child node)
ele1 --> e(branch1 ele1)
e --> f(ele2)
f --> g(ele 3)
c --> d(Leaf node)
ele2 --> b[Leaf node 3]
```

---

- Depth of `ele2` is 3.

---

#### Binary trees

---

- A binary tree is a tree data structure in which each node has **AT THE MOST** two children, which are referred to as the left child and the right child.

---

```mermaid
flowchart TB
rt(Root) --> ele1(Element 1)
rt --> ele2(Element 2)

ele1 --> ele11(Element 1's 1)
ele1 --> ele12(Element 1's 2)

ele2 --> ele21(Element 2's 1)
```

---

##### Types of binary trees

---

###### Full binary tree

---

- Every node should have 0 or 2 children.

---

###### Complete binary tree

---

- A complete binary tree is a binary tree in which all the levels are completely filled except possibly the lowest one, which is filled from the left.

---

###### Complete BT Vs Full BT

---

- In a complete binary tree, 

---

1. All the leaf elements must lean towards the left.
2. The last leaf element might not have a right sibling i.e. a complete binary tree doesn't have to be a full binary tree.

---

###### Perfect binary tree

---

- A Binary tree is a Perfect Binary Tree in which all the internal nodes have two children and all leaf nodes are at the same level.

---

```mermaid
flowchart TB
rt(Root) --> ele1(Element 1)
rt --> ele2(Element 2)

ele1 --> ele11(Element 1 1)
ele1 --> ele12(Element 1 2)

ele2 --> ele21(Element 2 1)
ele2 --> ele22(ELement 2 1)
```

---

###### Degenerate tree

---

- A tree where every internal node has 1 children.