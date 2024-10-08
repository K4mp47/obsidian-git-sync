Description
===========
Cheatsheet for LaTex, using Markdown for markup. I use this with [atom.io](https://atom.io/)
and :package:`markdown-preview-plus` to write math stuff. :package:`keyboard-localization`
is necessary when using an international layout (like [swiss] german).

Further Reference and source: ftp://ftp.ams.org/pub/tex/doc/amsmath/short-math-guide.pdf

Diagram in markdown: https://support.typora.io/Draw-Diagrams-With-Markdown/
Better to use: https://mermaid.js.org/intro/
Example expressions / functions
============================

Input             | Rendered        |
-----------------:|----------------:|
`$a = b + c − d$` | $a = b + c − d$ |
`$\sqrt{?\frac{\pi}{2}}$` | $\sqrt{\frac{\pi}{2}}$ |
`$y = a x_1^2 + b x_2 + c$` | $y = a x_1^2 + b x_2 + c$ |

# Title 1
## Title 2
### Title 3
#### Title 4
##### Title 5
######  Title 6

- pointed list
1. numbered list

Special characters / Symbols
============================
### Latin:
##### No dot:  
`\imath` $\rightarrow$ $\imath$,
`\jmath` $\rightarrow$ $\jmath$

##### Hat:  
`\hat{\imath}`  $\rightarrow$ $\hat{\imath}$,
`\hat{\jmath}`  $\rightarrow$ $\hat{\jmath}$

### Greek Letters:
##### Capital:
LaTex      |   | LaTex    |   |
----------:|:--|---------:|--:|
`\Gamma`   | Γ | `\Delta` | ∆ |
`\Lambda`  | Λ | `\Phi`   | Φ |
`\Pi`      | Π | `\Psi`   | Ψ |
`\Sigma`   | Σ | `\Theta` | Θ |
`\Upsilon` | Υ | `\Xi`    | Ξ |
`\Omega`   | Ω |          |   |

##### Lowercase:
LaTex      |   | LaTex     |   |
----------:|--:|----------:|--:|
`\alpha`   | α | `\nu`     | ν |
`\beta`    | β | `\kappa`  | κ |
`\gamma`   | γ | `\lambda` | λ |
`\delta`   | δ |  `\mu`    | µ |    
`\epsilon` | ϵ | `\zeta`   | ζ |
`\eta`     | η | `\theta`  | θ |
`\iota`    | ι | `\xi`     | ξ |
`\pi`      | π | `\rho`    | ρ |
`\sigma`   | σ | `\tau`    | τ |
`\upsilon` | υ | `\phi`    | φ |
`\chi`     | χ | `\psi`    | ψ |
`\omega`   | ω |           |   |

##### Other:
LaTex       |   | LaTex       |   |
-----------:|---|------------:|--:|
`\digamma`  | ϝ | `varepsilon`| ε       |
`\varkappa` | ϰ | `\varphi`   | ϕ       |
`\varpi`    | ϖ | `\varrho`   | ϱ       |
`\varsigma` | ς | `\vartheta` | ϑ       |
`\eth`      | ð | `\hbar`     | $\hbar$ |


### Other:
#### Other Symbols
LaTex         |   | LaTex            |   |
-------------:|---|-----------------:|--:|
`\partial`    | ∂ | `\infty`         | ∞ |
`\wedge`      | ∧ | `\vee`           | ∨ |
`\neg` `\not` | ¬ |                  |   |
`\bot`        | ⊥ | `\top`           | ⊤ |
`\nabla`      | ∇ | `\varnothing`    | ∅ |
`\angle`      | ∠ | `\measuredangle` | ∡ |
`\surd`       | √ | `\forall`        | ∀ |
`\exists`     | ∃ | `\nexists`       | ∄ |
`\pm`     | $\pm$ | 

#### Relational Symbols
LaTex             |   | LaTex              |          |
-----------------:|---|-------------------:|---------:|
`\hookrightarrow` | ↪      | `\Rightarrow`     | ⇒         |
`\rightarrow`     | →      | `\Leftrightarrow` | ⇔         |
`\nrightarrow`    | ↛      | `\mapsto`         | $\mapsto$ |
`\geq`            | ≥      | `\leq`            | ≤         |
`\equiv`          | ≡      | `\sim`            | ∼         |
`\gg`             | ≫      | `\ll`            | ≪          |
`\subset`          | ⊂     | `\subseteq`     | ⊆           |
`\in`             | ∈      | `\notin`         | ∉          |
`\mid`            | $\mid$ | `\propto`        | ∝          |
`\perp`            | ⊥     | ` \parallel`     | ∥          |
`\vartriangle`     | $\vartriangle$    | `\vdash`  | $\vdash$      |
`\bar`  | $\bar{X}$ | `\overline`  | $\overline{X}$      | 

#### Binary operators
LaTex        |   | LaTex  |   |
------------:|---|-------:|--:|
`\wedge`     | ∧ | `\vee` | ∨ |
`\neg``\not` | ¬ |        |   |

#### Cumulative operators
LaTex     |           | LaTex       |             |
---------:|-----------|------------:|------------:|
`\int`    | ∫         | `\iint`     | $\iint$     |
`\iiint`  | $\iiint$  | `\idotsint` | $\idotsint$ |
`\prod`   | $\prod$   | `\sum`      | $\sum$      |
`\bigcup` | $\bigcup$ | `\bigcap`   | $\bigcap$   |

#### Named operators
$\arccos$,
$\arcsin$,
$\arctan$,
$\arg$,
$\cos$,
$\cosh$,
$\cot$,
$\coth$,
$\deg$,
$\det$,
$\dim$,
$\exp$,
$\gcd$,
$\hom$,
$\inf$,
$\injlim$,
$\lg$,
$\lim$,
$\liminf$,
$\limsup$,
$\ln$,
$\log$,
$\max$,
$\min$,
$\Pr$,
$\projlim$,
$\sec$,
$\sin$,
$\sinh$,
$\sup$
