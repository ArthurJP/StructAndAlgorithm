cmake_minimum_required(VERSION 3.7)
project(StructAndAlgorithm)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES List_SequentialStorage.c List_Linked.c List_Static.c List_Circle.c List_DoublyLink.c Stack_DoubleShare.c Stack_Linked.c Calculator_StackImpl.c Queue_SequentialStorage.c Queue_Linked.c String_SequentialStorage.c String_KMP.c Tree_structure.c Tree_Binary.c ThreadBinaryTree.c test.c Graph_Vertex.c Graph_AdjacencyList.c Graph_VertexTraverse.c Graph_AdjacencyListTraverse.c Search_HashTable.c Search_Static.c Search_BinaryTree.c Sort.c)
add_executable(StructAndAlgorithm ${SOURCE_FILES})