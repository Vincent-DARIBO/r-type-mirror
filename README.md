# Welcome to RType project repository


## Here you will find all you need to know about:

- [Installation](#installation)
- [Project structure](#project-structure)
- [Gitflow](#gitflow)
- [Commit structure](#commit-structure)

### Installation
- [Clone the repository](https://github.com/EpitechPromo2025/B-CPP-500-LYN-5-2-rtype-tania.bezancon)
- On **Windows**
    - Install Visual studio 2021
    - Open the project and launch it
 - On **linux** run the following commands -> ``if [ ! -d "build" ]; then mkdir build; fi
rm -rf bomberman
cd build && cmake install .. && cmake --build . && cd .. && cp build/bomberman .``
### Project structure
*To complete*

### Gitflow
The Gitflow method can be defined in a few steps:
1. Each new feature should be implemented on a new branch -> ``git checkout develop ;git checkout -b feature_branch``
2. Once the feature is ready you create a **pull request** to merge **your branch on develop**
3. Once there are enough features on develop a new release can be done by using this command ``git checkout develop; git checkout -b release/0.1.0``

> :warning: This branch will be modified only for bug fixes, no more features will be added :warning:

4. Finally when the release is ready, the branch can be merged with develop and main

[More information on this page](https://www.atlassian.com/fr/git/tutorials/comparing-workflows/gitflow-workflow)

### Commit structure

Example → `fix: fix foo to enable bar`

The commit type can include the following:

- `feat` – a new feature is introduced with the changes
- `fix` – a bug fix has occurred
- `chore` – changes that do not relate to a fix or feature and don't modify src or test files (for example updating dependencies)
- `refactor` – refactored code that neither fixes a bug nor adds a feature
- `docs` – updates to documentation such as a the README or other markdown files
- `style` – changes that do not affect the meaning of the code, likely related to code formatting such as white-space, missing semi-colons, and so on.
- `test` – including new or correcting previous tests
- `perf` – performance improvements
- `ci` – continuous integration related
- `build` – changes that affect the build system or external dependencies
- `revert` – reverts a previous commit
