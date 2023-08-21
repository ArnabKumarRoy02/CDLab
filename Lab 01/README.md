# Deterministic Finite Automata (DFA)

A finite automaton is a 5-tuple defined as:M = (Q, ∑, 𝜹, 𝑞0, F)
  
  Where,
  
  `𝑄` is the finite set of states
  `∑` is the finite alphabet
  `𝛿` is the transition function 
  `𝒒𝟎` ⊂ Q is the initial state 
  `F⊂Q` is the set of final states

  - In DFA, for each input symbol, one can determine the state to which the machine will move.
  - Hence, it is called Deterministic Automaton.
  - As it has a finite number of states, the machine is called Deterministic Finite Machine or Deterministic Finite Automaton.

`Language Acceptance`:
  A language accepted by a DFA, M = (Q, ∑,𝜹, 𝑞0, F) is the set of all strings on ∑ accepted by M i.e.
              𝑳(𝑴)={𝑾 ∈∑∗|δ(𝒒𝟎,𝑾)∈𝑭}
  A language is said to be rejected by a DFA, M = (Q, ∑,𝜹, 𝑞0, F) such that 
              𝑳(𝑴)={𝑾 ∈∑∗|δ(𝒒𝟎,𝑾)∉𝑭} 

Finite Automaton can be classified into two types −
 
 - Deterministic Finite Automaton (DFA)
 - Non-deterministic Finite Automaton (NDFA / NFA)

Deterministic Finite Automaton (DFA)
In DFA, for each input symbol, one can determine the state to which the machine will move. Hence, it is called Deterministic Automaton. As it has a finite number of states, the machine is called Deterministic Finite Machine or Deterministic Finite Automaton.

## To run the C file

```shell
gcc dfa.c -o dfa
./dfa
```
