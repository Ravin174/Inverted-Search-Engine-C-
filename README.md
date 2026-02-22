Overview:  A high-performance search engine core implemented in C that uses an Inverted Indexing mechanism. 
This system optimizes text retrieval by mapping unique words to their specific file locations and frequencies,
similar to how a search engine indexes the web. It is designed to handle large volumes of text data across multiple 
files with constant-time lookup capabilities.

Key Features

Optimized Indexing: 
Uses a Hash Table with 28 buckets to categorize words based on alphanumeric characters and special symbols for $O(1)$ average-case access.

Nested Linked-List Architecture: 
* Main Nodes: Store unique words found across all files.
* Sub Nodes: Track the specific file name and the frequency of the word within that file.
* Database Persistence: Supports saving the indexed data to a backup file and updating/restoring the database from an existing backup.
* Memory Management: Implements dynamic memory allocation for nodes, ensuring the system only uses the RAM necessary for the current dataset.
* Robust Input Validation: Includes a pre-processing stage to validate file existence and format before indexing.

Technical Specifications

Language: C
Data Structures: Hash Table, Doubly/Singly Linked Lists.
Algorithms: Hashing, String Tokenization, File Parsing.
Environment: Linux/Ubuntu.

How to Use

Compile the project: (Use GCC compailer )
Run with input files:   "gcc*.c"

Interactive Menu:
                  1: Create the database from provided files.
                  2: Display the current index.
                  3: Search for a specific word.
                  4: Update the database from a backup file.
                  5: Save the current index to a file.
