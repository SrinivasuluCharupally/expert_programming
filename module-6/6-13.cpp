Question: The probability of a car passing a certain intersection in a 20 minute windows is 0.9. What is the probability of a car passing the intersection in a 5 minute window? (Assuming a constant probability throughout)

Answer: This is one of the basic probability question asked in a software interview. Let’s start by creating an equation. Let x be the probability of a car passing the intersection in a 5 minute window.

Probability of a car passing in a 20 minute window = 1 – (probability of no car passing in a 20 minute window)
Probability of a car passing in a 20 minute window = 1 – (1 – probability of a car passing in a 5 minute window)^4
0.9 = 1 – (1 – x)^4
(1 – x)^4 = 0.1
1 – x = 10^(-0.25)
x = 1 – 10^(-0.25) = 0.4377