_This project has been created as part of the 42 curriculum by enrgil-p._


<h1>Description</h1>

This project consist in the "Dinining philosophers problem". As a first approach to concurrency and multi-threaded processes, purpose of this project is to understand how can be used this unit of execution, the risks of deadlock and data races, and how to avoid them.

<h3>Dining philosophers problem</h3>

  A given number of philosophers take a seat on a roundtable. They are expected to eat, sleep or think. All this actions have a given time to be done, and a given time to     die. If one philosphers needs more time to start to eat or eat again than the given die time, that philo dies.
  There is one fork per philosopher on table. However, each philosopher will take the two nearest forks to start to eat. So, if one philo cannot take two forks, must wait
  thinking. After eating, a philosopher starts to sleep. After sleep time, philosopher awakes, thinks, and immediatly try to take forks and eat.

<h3>Program</h3>

  Program creates a virtual roundtable of N philosophers. Every philo will be a thread. There always must be one philo created. N philo, last of them, will be next to first
  one. Through routine's execution of each thread, it will be printed a log of every state change. 

  <h5>States</h5>
    
    Take one fork
    
    Eat
    
    Sleep
    
    Think

    Die
  
  If time to die is less, equal or slightly bigger than sum of eat_time and sleep time, one philo will die. Also in case of execute program with just one philo, which is
  the minimum number needed of them for a succesful execution.
  Program may stop if one philo dies, or if every philosopher has eat at least a given number of times -this is an optional argument. In other case, program should not
  stop, so user should interrupt whenever consider it.
  


<h1>Instructions</h1>

  <h4>Compilation</h4>

  This project has a Makefile to compile. Possible options from it are:
    
    make ---> Regular compile

    nake fsanitize ---> Compile prepared to execute with fsanitize

    make clean ---> Remove objects created on compilation

    make fclean ---> Remove objects + exectuable

    make re ---> Executes make fclean and make

  <h4>Execution</h4> 
  
  Expected usage of program:  
  _./philo number_of_philosophers time_to_die time_to_eat time_to_sleep (**optional**: number_of_times_each_philosopher_must_eat)_

 Time arguments are in miliseconds, it is, a one thousandth of a second (1/1000 s). 

  <h6>Examples</h6>  
  
         ./philo 10 400 100 100
Creates 10 philos that needs 100 ms to eat and 100 ms to sleep. One will die at 400 ms after started execution or since last time started to eat -not expected in this case.
    
         ./philo 10 400 100 100 10
Same as above, but execution has been requested for 10 meals for each philo. When each of them has reached this amount of meals, program should stop.
        


<h1>Resources</h1>

  • "Dining philosophers problem". **Wikipedia®**, CC BY-SA. <https>https://en.wikipedia.org/wiki/Dining_philosophers_problem</https>
  
  • "Programs, Processes, Threads and Multi-threading". Chamuditha Kekulawala, Nov 15, 2024. <https>https://medium.com/@ckekula/computer-architecture-for-beginners-multi-threading-de99bdca6c49</https>
  
  • "Philosophers 42 Guide— 'The Dining Philosophers Problem'". Dean Ruina, Aug 21, 2023. <https>https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2</https>
  
  • "Introduction to Threads". Neso Academy, 24 may 2019. <https>https://youtu.be/LOfGJcVnvAk</https>
  
  • "Arquitectura de sistemas. Parte I.  Programación en C. Capítulo 11. Los hilos". Course from **© Universidad Carlos III de Madrid**, CC BY-NC-SA. <http>https://www.it.uc3m.es/pbasanta/asng/course_notes/threads_es.html</https> 


<h4>Use of AI</h4>
This project has been done with some help of ChatGPT, as advisor. Specifically to understand concepts like concurrency and it's relation or differ with parallelism. Also to get some examples of how create a thread, how works usleep() and help to debug data races. To do this last task, I wrote a prompt explaining my problem, the project and my student level. Then, I shared to the chatbot a part of the message printed by helgrind, and requested to ChatGPT to only ask me for more information about my program. I only allowed to give me an explanation when it has complete data to give me reasonable answer. This way, I not only learn more about how to avoid data races, but also how to read and understand helgrind.
