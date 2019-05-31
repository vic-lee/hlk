# hlk design document

This project aims to automate the planning and scheduling of a series of tasks, with hierarchical dependencies. The schedule is subject to the following constraints:

- Tasks and top-down dependencies
  - Anticipated time for each task
- Time available per day

From a technical point of view, this project explores:

1. Algorithmically, what is the most efficient way to scan through large dependency maps
2. How to integrate C++ and Python code

## Example and analysis

Let's say you want to build a new resume for software engineering positions. You may want to do the following series of tasks:

- Build tech resume (that highlights C++ and Python skills)
  - Projects
    - ML (python)
      - ...
    - OS Simulation
      - The kernel layer (C++, C, Asm)
        - Scheduling
        - Paging and memory management
        - Deadlock detection and prevention
        - File system
        - Interrupts
      - The shell layer (C++, C)
        - Shell executable
        - Shell-based configuration
        - Shell commands while the OS is running (e.g. `PS`)
      - The analytical layer (Python)
        - Interactive dashboard that displays statistics on localhost
        - ...

The program parses the hierarchical list, written in markdown-like syntax. 

In the angled brackets, we specify whether there exists dependencies on the same level (`<P>`, for `parallel`, indicates no dependency; `<S>`, for `sequential`, indicates sequential dependency). 

In the squared brackets, we specify the time needed. We start planning with the minimum level at which anticipated time is specified; lower-level tasks with no time attributes are ignored. Higher-level tasks' anticipated time is simply a recursive sum of the time needed by its child tasks.

Cross-level dependency is an interesting concept. It refers to the idea that a higher level task from a branch may depend on a lower level task from another branch. Such dependencies are common in real life; in fact, ideally we'd want to abandon the hierarchical construct and allow any node to be dependent on another. However, this is significantly more difficult to implement, and we're limiting ourselves to an hierarchical view for now. 

## Technical modules

### Document parsing

Technical problems to tackle:

- detect indentation
- parse for tags (time and P, S mode)
