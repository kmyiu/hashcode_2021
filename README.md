# HashCode 2021

Thanks to all my teammates spending the whole midnight.

## Summary and Reflection

At first glance we think the problem statement is much longer than the practice problem, writing a simulation code on all cars from t=0s to the end may be unfeasible during the contest time. (But this is essential to solve D) Therefore we decide to build a random guess solution and see any improvements can be made.

We do not go deep into the dataset and we adopt a general strategy to all cases.
The only thing we do is :

- give 1s for every direction
- remove all unused paths (completed at ~1h15m)

Then

- for every direction count the number of cars
- make a score on every direction and give a longer interval based on the score
- random shuffle to get epsilon more score

In the last hour we do nothing and see the ranking falling to the ground :)

## Scores

A – An example
2,002 points

B – By the ocean
4,566,672 points

C – Checkmate
1,300,867 points

D – Daily commute
1,587,681 points

E – Etoile
706,461 points

F – Forever jammed
1,418,790 points

**Total score
9,582,473 points (Rank #187/9004)**

For top teams they can score ~10,xxx,xx and get >2,000,000 in D.

- #25 10,146,534

- #50 9,702,211

- #100 9,612,014

- #200 9,580,571

- #500 9,543,152