## shm_lib
[Русский](https://github.com/sdkiyo/shm_lib/blob/main/README.ru.md) | [Documentation](https://github.com/sdkiyo/shm_lib/blob/main/docs/technical_documentation.md)
## Description
A small wrapper library, written in C for simple work with shared memory.
___
### installation
0. clone the repository:
~~~java
git clone https://github.com/waflya-xleb/shm_lib.git
~~~
### compilation
1. go to the build directory:
~~~shell
cd имя-репозитория/build
~~~
2. start compiling:
~~~shell
cmake -G "Ninja" .. && ninja
~~~
To show debug messages when compiling, use cmake flag `'--log-level=DEBUG'`
~~~shell
cmake --log-level=DEBUG -G "Ninja" .. && ninja
~~~
### adding to project
after compilation, the `build` directory will contain a file named `lib_SharedMemoryLibrary.so`, it needs to be moved to the directory where the executable file of your program will be located. The header file `shm_api.h` from the library will need to be added to the project itself.
___
## License
This project uses the [GNU AGPLv3](https://choosealicense.com/licenses/agpl-3.0/#) license.
#### $\textcolor{#238636}{\textsf{Permissions:}}$
##### 1. Commercial use
> **Commercial use permission: The licensed material and derivatives may be used for commercial purposes.**
##### 2. Distribution
> **Distribution permission: The licensed material may be distributed.**
##### 3. Modification
> **Modification permission: The licensed material may be modified.**
##### 4. Patent use
> **Patent use permission: This license provides an express grant of parent rights from contributors.**
##### 5. Private use
> **Private use permission: The licensed material may be used and modified in private.**
#### $\textcolor{#0099D6}{\textsf{Conditions:}}$
##### 1. Disclose source
> **Disclose source condition: Source code must be made available when the licensed material is distributed.**
##### 2. License and copyright notice
> **License and copyright notice condition: A copy of the license and copyright notice must be included with the licensed material.**
##### 3. Network use is distribution
> **Network use is distributin condition: Users who interact with the licensed material via network are given the right to receive a copy of the source code.**
##### 4. Same license
> **Same license condition: Modifications must be released under the same license when distributing the licensed material. In some cases a similar or related license may be used.**
##### 5. State changes
> **State changes condition: Changes make to the licensed material must be documented.**
#### $\textcolor{#c6403D}{\textsf{Limitations:}}$
##### 1. Liability
> **Liability limitation: This license includes a limitation of liability.**
##### 2. Warranty
> **Warranty limitation: This license explicitly states that it does NOT provide any warranty.**
___
###### Permissions of this strongest copyleft license are conditioned on making available complete source code of licensed works and modifications, which include larger works using a licensed work, under the same license. Copyright and license notices must be preserved. Contributors provide an express grant of patent rights. When a modified version is used to provide a service over a network, the complete source code of the modified version must be made available.
___
## Contacts
To contact the author of the project, write to the email: just.eugene.j@gmail.com
___
###### © 8.29.2025 the end of the document, really the end.
