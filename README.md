libtexprintf & utftex
=====================

The utftex program and underlying libtexprintf library provide tools to
pretty print math in monospace fonts, using a tex-like syntax. It 
produces UTF-8 encoded text. The program was inspired by 
[asciiTeX](http://asciitex.sourceforge.net/), and the improved 
[asciiTeX fork](https://github.com/larseggert/asciiTeX). However, 
utftex supports much more TeX syntax and contains extensive unicode 
tables to map latex commands to unicode symbols. Use 
libtexprintf/utftex to unlock the math capabilities of unicode in 
monospace text applications.

libtexprintf
------------
The core library to pretty print math in monospace font. Use it to 
enable your c or c++ code to print out formatted math. The calls are 
moddeled after the printf family to produce formatted output.   


utftex
------
The utftex program uses libtexprinf to implement a commandline utility 
to format math. For example:  

    > utftex '\frac{\alpha}{\beta+x}'  
gives
 
     α   
    ───  
    β+x  


The texprintf library provides a fairly full featured tex-like syntax
with arrays, brackets, many symbols, and even font style (note that 
texprintf outputs UTF-8 and as such cannot change the fonts. However,
unicode does provide several font-styles like mathematical caligraphic
style, or italic). For example:

    > utftex -F mathnormal '\frac{1}{a+x}' 
gives  

     1
    ───
    𝑎+𝑥

It also supports some diacritical combining marks, to do things like

    utftex '\vec x' 
to get
 
    x⃗.

A bit more elaborate example is this small table of Laplace transforms:

    > utftex '\begin{array}{|l|l|}  
    \hline  
    f(t) & \mathscr{L}[f(t)]=F(s) \\\hline  
    1 & \frac{1}{s} \\\hline  
    e^{at}f(t) & F(s-a) \\\hline  
    \delta\left(t\right) & 1 \\\hline  
    \delta\left(t-t_0\right) & e^{-st_0} \\\hline  
    \int_0^t f(x)g(t-x)dx & F(s)G(s)\hline  
    \end{array}'  

    ┌────────────────┬──────────────┐ 
    │f(t)            │ 𝓛[f(t)]=F(s) │  
    ├────────────────┼──────────────┤  
    │                │ 1            │  
    │1               │ ─            │  
    │                │ s            │  
    ├────────────────┼──────────────┤  
    │ at             │              │  
    │e  f(t)         │ F(s-a)       │  
    ├────────────────┼──────────────┤  
    │δ(t)            │ 1            │  
    ├────────────────┼──────────────┤  
    │                │  -st         │  
    │                │     0        │  
    │δ⎛t-t ⎞         │ e            │  
    │ ⎝   0⎠         │              │  
    ├────────────────┼──────────────┤  
    │ t              │              │  
    │⌠               │              │  
    │⎮  f(x)g(t-x)dx │ F(s)G(s)     │  
    │⌡               │              │  
    │ 0              │              │  
    └────────────────┴──────────────┘  


Note that if the table borders do not properly align you are not viewing 
the table in monospace fonts. 

utfstringinfo
-------------
Utility to analyze strings UTF-8 strings. The utfstringinfo  program 
reads  arguments or, if no arguments are provided, stdin and for every 
single character it finds it shows  the  UTF-8  character sequence, the 
unicode code-point and, if applicable, the utftex command that can be 
used to generate the symbol.  


Questions One Might Ask (QOMA)
------------------------------

* Why is my equation all misaligned?
	- Make sure you are using monospace fonts.
	
* I am using monospace fonts, why are my equations still poorly aligned?
	- Most fonts do not support all unicode characters. Your program 
	   may use some variable-width fallback fonts.
	   
* Why are some symbols are not displayed (properly)?
	- Most fonts do not support all unicode characters. Perhaps your 
	   font engine just gave up? This also often happens when using 
	   combining diacritical marks. Find the right set of font engine 
	   and fonts to use.
	   
* Can you recommend a good monospace symbol font?
	- Make your own out of your favorite (non-monospace) fonts! The 
	   great "monospacifier" will do that for you. Get it at 
	   https://github.com/cpitclaudel/monospacifier

* How do I specify the fallback fonts in <insert some program/system>?
	- This will depend on your system and/or program you are using. If 
	   your system uses fontconfig you may try that to set up an 
	   appropriate mono-space fallback font.

* How do I specify the fallback fonts in with fontconfig?
	- Let us assume you use some monospace font called "MONO" and we 
	   have some symbol monospace fallback font for it "SYMBOLMONO". 
	   Here are the steps:
	   1. Install all fonts (e.g. copy font files to 
	      ~/.local/share/fonts and run "fc-cache -f -v")
	   2. Then create a fontconfig file in 
	      ~/.config/fontconfig/fonts.conf
	      It could look something like (replace the font names with the 
	      approprate values):
	      
```
<?xml version="1.0"?>
<!DOCTYPE fontconfig SYSTEM "fonts.dtd">
<fontconfig>
 <alias>
   <family>monospace</family>
   <prefer>
     <family>MONO</family>
     <family>SYMBOLMONO</family>
   </prefer>
 </alias>
</fontconfig>	   
```	     


