# Problem 109 - イレイナ画结界

**ACMOJ Problem ID**: 1426

## Table of Contents

- [Problem 109 - イレイナ画结界](#problem-109-イレイナ画结界)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

This problem tests algorithmic problem-solving skills.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **1426. イレイナ画结界** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/109/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

伊蕾娜是一位魔女，因为向往着幼时读过的旅行故事，她踏上了漫长的旅途，与形形色色的国家与人们邂逅。

这一次，她来到了一个常年遭到野兽袭击的国家，为了感谢国王的款待，她决定帮这个国家创造一个可以抵御野兽入侵的结界。

伊蕾娜已经围绕国家布下了结界的 $n$ 个节点，可以认为这些节点是均匀分布在一个圆上的。现在伊蕾娜需要给这 $n$ 个结界节点之间连接 $n - 1$ 条魔法线，使得这 $n$ 个节点是连通的。

根据结界的要求，这 $n - 1$ 条魔法线必须不能相交，并且节点间不同的连线方法会得到不同效果的结界。伊蕾娜知道防御结界的要求是对于一些特定的节点，不能用魔法线将它们直接相连（也就是它们之间只能间接相连）。

伊蕾娜愿意将防御结界的要求教给你，但是作为交换她想知道有多少种不同的防御结界，你能告诉她吗？

两种结界被认为是不同的当且仅当存在两个节点在其中一个结界中被魔法线直接相连而在另一个中没有。

由于答案可能很大，只需要输出答案对 $10^9 + 7$ 取模的结果。

### Input Format

第一行一个整数 $n$ 表示结界的节点个数。

接下来 $n$ 行，每行 $n$ 个数。如果第 $i$ 行第 $j$ 列的数 $a_{i, j} = 0$，那么节点 $i$ 和节点 $j$ 就不能被魔法线直接相连，否则 $a_{i, j} = 1$。

保证 $a_{i, j} = a_{j, i}$，并且 $a_{i, i} = 0$。

### Output Format

输出所有可能的防御结界个数对 $10^9 + 7$ 取模的结果。

### Samples

#### 样例 1

**Input:**
```
3
0 0 1
0 0 1
1 1 0
```

**Output:**
```
1
```

#### 样例 2

**Input:**
```
4
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0
```

**Output:**
```
12
```

### Data Constraints

对于 $20\\%$ 的数据，$1\leq n \leq 10$

对于 $50\\%$ 的数据，$1\leq n \leq 50$

对于 $100\\%$ 的数据，$1\leq n \leq 500$

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 1000 ms
- **Memory Limit (per test case)**: 256 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/109/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
