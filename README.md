# Z-from-p
C code to convert Z-value (significance) to p-value 

Saves the need for looking up a standard normal Z-table, which is likely only to go up to Z = 3.49, or a two-sided probability p > 0.000483 (calculated from this code).

E.g. Enter Z-value [sigma]: 6.5

One-sided probability, p = 4.01e-11

Two-sided probability, p = 8.03e-11

Python version at https://github.com/steviecurran/Z-value, but this is only accurate to p > 1e-5 [Z < 4.1σ]
