# Space Shooter
I started making this project to learn C++ OOP concepts for college in a fun way.

[Game Demo](https://youtu.be/G7nRT5rS9sg)

[Pixel art](https://grafxkid.itch.io/mini-pixel-pack-3)

### Tools used:
 - C++
 - raylib

### Major concepts utilized:
 - OOP
 - design patterns:
   - State
   - Object pool
   - Observer 

### Reflection
I leveraged the Observer pattern to achieve decoupling. I was aware of its limitation that the subject doesn't resume its 
own work until all the observers have returned from their notification methods. It wasn't an issue as it paired nicely
with the Object pool pattern, so creating new objects wouldn't slow anything down as they were already there after the game 
started.

I was thinking about implementing spatial partitioning, but it turned out it would be overkill. I run a profiler
with hundreds of entities, and my naive way of checking collisions(every player bullet against every enemy, etc.)
wasn't causing any bottlenecks.

### Room for improvement
 - I probably overused static in one or two places.
 - I believe I would benefit from more planning before writing the actual code.
 - I am not sure how you should structure cpp project, so I hope my current structure is not a mess.

<details>
  <summary>additional sources of help</summary>
  <ul>
    <li>Observer pattern https://gameprogrammingpatterns.com/observer.html</li>
    <li>State pattern https://gameprogrammingpatterns.com/state.html</li>
    <li>Object pool pattern https://gameprogrammingpatterns.com/object-pool.html</li>
    <li>Cpp templates https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file</li>
    <li>Cpp random number https://stackoverflow.com/questions/19665818/generate-random-numbers-using-c11-random-library</li>
    <li>Enum within a class https://stackoverflow.com/questions/2503807/declaring-an-enum-within-a-class</li>
  </ul>
</details>