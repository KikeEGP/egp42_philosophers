_This project has been created as part of the 42 curriculum by enrgil-p._


<h1>Description</h1>

This project consist in the "Dinining philosophers problem". As a first approach to concurrence and multi-threaded process, purpose of this project is to understand how can use this type of execution, the risks of deadlock and data races, and how to avoid them.

<h3>Dining philosophers problem</h3>

  A given number of philosophers take a seat on a roundtable. They are expected to eat, sleep and think. All this actions have a given time to be done, and a given time to     die. If one philosphers needs more time to start to eat or eat again than the given die time, that philo dies.
  There is one fork per philosopher on table. However, each philosopher will take the two nearest forks to start to eat. So, if one philo cannot take two forks, must wait      thinking. After eating, a philosopher starts to sleep. After sleep time, philosopher awakes and try to take forks and eat.

<h3>Program</h3>

  Program creates a virtual roundtable of N philosophers, and prints a log of every state change of each on of them.

  **States**
    
    Take one fork
    
    Eat
    
    Sleep
    
    Think

    Die
  
  If time to die is less, equal or slightly bigger than sum of eat_time and sleep time, one philo will die. Also in case of execute program with just one philo, which is the   minimum number needed of them for a succesful execution.
  Program may stop if one philo dies, or if every philosopher has eat at least a given number of times -this is an optional argument. In other case, program should not stop,   so user should interrupt whenever consider it.
  


<h1>Instructions</h1>


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
  
  • "Programs, Processes, Threads and Multi-threading" -> <https>https://medium.com/@ckekula/computer-architecture-for-beginners-multi-threading-de99bdca6c49</https>
