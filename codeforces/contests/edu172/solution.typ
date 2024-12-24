#import "@local/template:1.0.0": *

#set math.mat(
    delim: "["
)
#set par(
  first-line-indent: 0em,
  justify: true,
)

#set page(
    numbering: "1",
    number-align: center,
    header: locate(loc => {
      box(stroke: (bottom: 0.7pt), inset: 0.3em)[#text(font: "Libertinus Serif")[Zhisu Wang #h(1fr)]]
    }),
)

#align(center, text(size: 1.5em, "Solution for Edu 172"))
(c) Given a $1$-indexed binary string. Let $s_i$ be the difference of $1$s and $0$s of indices $i...n$. Let $a_j$ be the start index of $j$th group, $m$ be the number of groups. Then the total score is 
$ sum_(i = 1)^m (i - 1)(s_a_i - s_a_(i + 1)) = sum_(i = 2)^(m) s_a_i $
So the solution would be constructing all $s_i$ and choose the next maximum $s_i$ until the sum is greater than or equal to $k$. Note that we can only add $n-1$ numbers of $s_i$ becasue $a_1$ will be ignored, however, since $a_i < a_(i + 1)$ , $s_1$ will always be ignored (either not choosen or becomes $a_1$), so we only need to keep track of $s_2, ..., s_(n)$.

