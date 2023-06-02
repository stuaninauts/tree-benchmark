# tree-benchmark

This repository refers to a project for the course INF01203 - Data Structures at [INF](https://www.inf.ufrgs.br/site/en) in [UFRGS](http://www.ufrgs.br/ufrgs/inicial).

## Brief Documentation

- **data_analysis/** - contains the notebook for data analysis
- **results/** - contains the output of the `batch-run.sh` script
- **CMakeLists.txt** - file for CMake to compile and build the project
- **abp.*** - contains the methods for the Binary Search Tree (BST)
- **avl.*** - contains the methods for the AVL Tree
- **batch-run.sh** - bash script to create ordered and unordered databases
- **desordered-database.py** - python script to create unordered databases
- **ordered-database.py** - python script to create ordered databases
- **main.cpp** - performs the operations

## About

The main goal of this project was to compare two data structures covered during the course: the Binary Search Tree (BST) and the AVL Tree. Our benchmark was based on insertions and searches using both ordered and unordered databases. Python was used for creating the databases and for data analysis, while C was used to create and manipulate the structures.

## Conclusion

Upon completion of this work, we concluded that the BST was more efficient for insertion and search operations with a small dataset, while the AVL Tree showed better results with larger datasets, particularly with ordered databases.

For a more detailed and comprehensive explanation of this project, please refer to this [document](https://docs.google.com/document/d/1STO7e1hHVLVLtDGfnXgcLTsWxNb8A1QZb-wRzvXhbn4/edit?usp=sharing).





