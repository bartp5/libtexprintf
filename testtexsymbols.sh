#!/bin/bash
generated=`$utftex -T`
reference="\\_:_;\\{:{;\\}:};\\lbrac:[;\\rbrac:];\\sphat:^;\\sptilde:~;\\vert:|;\\mid:|;\\lvert:|;\\rvert:|;\\divides:|;\\cent:¢;\\pounds:£;\\yen:¥;\\neg:¬;\\circledR:®;\\pm:±;\\Micro:µ;\\times:×;\\eth:ð;\\div:÷;\\imath:ı;\\jmath:ȷ;\\Gamma:Γ;\\Delta:Δ;\\Theta:Θ;\\Lambda:Λ;\\Xi:Ξ;\\Pi:Π;\\Sigma:Σ;\\Upsilon:Υ;\\Phi:Φ;\\Psi:Ψ;\\Omega:Ω;\\alpha:α;\\beta:β;\\gamma:γ;\\delta:δ;\\varepsilon:ε;\\epsilon:ϵ;\\backepsilon:϶;\\zeta:ζ;\\eta:η;\\theta:θ;\\iota:ι;\\kappa:κ;\\lambda:λ;\\mu:μ;\\nu:ν;\\Nu:Ν;\\xi:ξ;\\pi:π;\\rho:ρ;\\varrho:ϱ;\\sigma:σ;\\varsigma:ς;\\tau:τ;\\upsilon:υ;\\varphi:𝜑;\\chi:χ;\\psi:ψ;\\omega:ω;\\varbeta:ϐ;\\vartheta:ϑ;\\phi:ϕ;\\varpi:ϖ;\\Qoppa:Ϙ;\\qoppa:ϙ;\\Stigma:Ϛ;\\stigma:ϛ;\\Digamma:Ϝ;\\digamma:ϝ;\\Koppa:Ϟ;\\koppa:ϟ;\\Sampi:Ϡ;\\sampi:ϡ;\\|:‖;\\dagger:†;\\ddagger:‡;\\ldots:…;\\prime:′;\\pprime:″;\\second:″;\\third:‴;\\ppprime:‴;\\backprime:‵;\\backpprime:‶;\\backppprime:‷;\\cat:⁀;\\fourth:⁗;\\pppprime:⁗;\\Euler:ℇ;\\hslash:ℏ;\\Im:ℑ;\\ell:ℓ;\\wp:℘;\\Re:ℜ;\\tcohm:Ω;\\mho:℧;\\Angstroem:Å;\\Finv:Ⅎ;\\aleph:ℵ;\\beth:ℶ;\\gimel:ℷ;\\daleth:ℸ;\\Yup:⅄;\\CapitalDifferentialD:ⅅ;\\DifferentialD:ⅆ;\\ExponetialE:ⅇ;\\ComplexI:ⅈ;\\ComplexJ:ⅉ;\\invamp:⅋;\\leftarrow:←;\\uparrow:↑;\\to:→;\\rightarrow:→;\\downarrow:↓;\\leftrightarrow:↔;\\updownarrow:↕;\\nwarrow:↖;\\nearrow:↗;\\searrow:↘;\\swarrow:↙;\\nleftarrow:↚;\\nrightarrow:↛;\\twoheadleftarrow:↞;\\twoheadrightarrow:↠;\\leftarrowtail:↢;\\rightarrowtail:↣;\\mapsfrom:↤;\\MapsUp:↥;\\mapsto:↦;\\MapsDown:↧;\\hookleftarrow:↩;\\hookrightarrow:↪;\\looparrowleft:↫;\\looparrowright:↬;\\leftrightsquigarrow:↭;\\nleftrightarrow:↮;\\lightning:↯;\\Lsh:↰;\\Rsh:↱;\\dlsh:↲;\\drsh:↳;\\curvearrowleft:↶;\\curvearrowright:↷;\\circlearrowleft:↺;\\circlearrowright:↻;\\leftharpoonup:↼;\\leftharpoondown:↽;\\upharpoonright:↾;\\upharpoonleft:↿;\\rightharpoonup:⇀;\\rightharpoondown:⇁;\\downharpoonright:⇂;\\downharpoonleft:⇃;\\rightleftarrows:⇄;\\updownarrows:⇅;\\leftrightarrows:⇆;\\leftleftarrows:⇇;\\upuparrows:⇈;\\rightrightarrows:⇉;\\downdownarrows:⇊;\\leftrightharpoons:⇋;\\rightleftharpoons:⇌;\\nLeftarrow:⇍;\\nLeftrightarrow:⇎;\\nRightarrow:⇏;\\Leftarrow:⇐;\\Uparrow:⇑;\\Rightarrow:⇒;\\Downarrow:⇓;\\Leftrightarrow:⇔;\\Updownarrow:⇕;\\Nwarrow:⇖;\\Nearrow:⇗;\\Searrow:⇘;\\Swarrow:⇙;\\Lleftarrow:⇚;\\Rrightarrow:⇛;\\leftsquigarrow:⇜;\\rightsquigarrow:⇝;\\dashleftarrow:⇠;\\dashrightarrow:⇢;\\LeftArrowBar:⇤;\\RightArrowBar:⇥;\\downuparrows:⇵;\\pfun:⇸;\\ffun:⇻;\\leftarrowtriangle:⇽;\\rightarrowtriangle:⇾;\\leftrightarrowtriangle:⇿;\\forall:∀;\\complement:∁;\\partialup:∂;\\exists:∃;\\nexists:∄;\\varnothing:∅;\\nabla:∇;\\in:∈;\\notin:∉;\\ni:∋;\\nni:∌;\\utfprod:∏;\\coprod:∐;\\utfsum:∑;\\mp:∓;\\dotplus:∔;\\slash:∕;\\smallsetminus:∖;\\ast:∗;\\circ:∘;\\bullet:∙;\\utfsqrt:√;\\utfsqrt[3]:∛;\\utfsqrt[4]:∜;\\propto:∝;\\infty:∞;\\rightangle:∟;\\angle:∠;\\measuredangle:∡;\\sphericalangle:∢;\\mid:∣;\\nmid:∤;\\parallel:∥;\\nparallel:∦;\\wedge:∧;\\vee:∨;\\cap:∩;\\cup:∪;\\utfint:∫;\\utfiint:∬;\\utfiiint:∭;\\utfoint:∮;\\utfoiint:∯;\\utfoiiint:∰;\\varointclockwise:∲;\\ointctrclockwise:∳;\\therefore:∴;\\because:∵;\\Proportion:∷;\\eqcolon:∹;\\sim:∼;\\backsim:∽;\\AC:∿;\\wr:≀;\\nsim:≁;\\eqsim:≂;\\simeq:≃;\\nsimeq:≄;\\cong:≅;\\ncong:≇;\\approx:≈;\\napprox:≉;\\approxeq:≊;\\asymp:≍;\\Bumpeq:≎;\\bumpeq:≏;\\doteq:≐;\\Doteq:≑;\\fallingdotseq:≒;\\risingdotseq:≓;\\coloneq:≔;\\eqcolon:≕;\\eqcirc:≖;\\circeq:≗;\\corresponds:≙;\\triangleq:≜;\\neq:≠;\\equiv:≡;\\nequiv:≢;\\leq:≤;\\geq:≥;\\leqq:≦;\\geqq:≧;\\lneqq:≨;\\gneqq:≩;\\ll:≪;\\gg:≫;\\between:≬;\\notasymp:≭;\\nless:≮;\\ngtr:≯;\\nleq:≰;\\ngeq:≱;\\lesssim:≲;\\gtrsim:≳;\\NotLessTilde:≴;\\NotGreaterTilde:≵;\\lessgtr:≶;\\gtrless:≷;\\NotGreaterLess:≹;\\prec:≺;\\succ:≻;\\preccurlyeq:≼;\\succcurlyeq:≽;\\precsim:≾;\\succsim:≿;\\nprec:⊀;\\nsucc:⊁;\\subset:⊂;\\supset:⊃;\\nsubset:⊄;\\nsupset:⊅;\\subseteq:⊆;\\supseteq:⊇;\\nsubseteq:⊈;\\nsupseteq:⊉;\\subsetneq:⊊;\\supsetneq:⊋;\\uplus:⊎;\\sqsubset:⊏;\\sqsupset:⊐;\\sqsubseteq:⊑;\\sqsupseteq:⊒;\\sqcap:⊓;\\sqcup:⊔;\\oplus:⊕;\\ominus:⊖;\\otimes:⊗;\\oslash:⊘;\\odot:⊙;\\circledcirc:⊚;\\circledast:⊛;\\circleddash:⊝;\\boxplus:⊞;\\boxminus:⊟;\\boxtimes:⊠;\\boxdot:⊡;\\vdash:⊢;\\dashv:⊣;\\top:⊤;\\bot:⊥;\\models:⊧;\\vDash:⊨;\\Vdash:⊩;\\Vvdash:⊪;\\VDash:⊫;\\nvdash:⊬;\\nvDash:⊭;\\nVdash:⊮;\\nVDash:⊯;\\vartriangleleft:⊲;\\vartriangleright:⊳;\\trianglelefteq:⊴;\\trianglerighteq:⊵;\\multimapdotbothA:⊶;\\multimapdotbothB:⊷;\\multimap:⊸;\\intercal:⊺;\\veebar:⊻;\\barwedge:⊼;\\bigwedge:⋀;\\bigvee:⋁;\\bigcap:⋂;\\bigcup:⋃;\\diamond:⋄;\\cdot:⋅;\\star:⋆;\\divideontimes:⋇;\\bowtie:⋈;\\ltimes:⋉;\\rtimes:⋊;\\leftthreetimes:⋋;\\rightthreetimes:⋌;\\backsimeq:⋍;\\curlyvee:⋎;\\curlywedge:⋏;\\Subset:⋐;\\Supset:⋑;\\Cap:⋒;\\Cup:⋓;\\pitchfork:⋔;\\hash:⋕;\\lessdot:⋖;\\gtrdot:⋗;\\lll:⋘;\\ggg:⋙;\\lesseqgtr:⋚;\\gtreqless:⋛;\\curlyeqprec:⋞;\\curlyeqsucc:⋟;\\npreceq:⋠;\\nsucceq:⋡;\\nsqsubseteq:⋢;\\nsqsupseteq:⋣;\\lnsim:⋦;\\gnsim:⋧;\\precnsim:⋨;\\succnsim:⋩;\\ntriangleleft:⋪;\\ntriangleright:⋫;\\ntrianglelefteq:⋬;\\ntrianglerighteq:⋭;\\vdots:⋮;\\cdots:⋯;\\iddots:⋰;\\ddots:⋱;\\barin:⋶;\\diameter:⌀;\\lceil:⌈;\\rceil:⌉;\\lfloor:⌊;\\rfloor:⌋;\\invneg:⌐;\\wasylozenge:⌑;\\ulcorner:⌜;\\urcorner:⌝;\\llcorner:⌞;\\lrcorner:⌟;\\frown:⌢;\\smile:⌣;\\APLinv:⌹;\\notslash:⌿;\\notbackslash:⍀;\\APLleftarrowbox:⍇;\\APLrightarrowbox:⍈;\\APLuparrowbox:⍐;\\APLdownarrowbox:⍗;\\APLcomment:⍝;\\APLinput:⍞;\\APLlog:⍟;\\overparen:⏜;\\underparen:⏝;\\overbrace:⏞;\\underbrace:⏟;\\bigtriangleup:△;\\blacktriangleup:▴;\\smalltriangleup:▵;\\RHD:▶;\\rhd:▷;\\blacktriangleright:▸;\\smalltriangleright:▹;\\bigtriangledown:▽;\\blacktriangledown:▾;\\smalltriangledown:▿;\\LHD:◀;\\lhd:◁;\\blacktriangleleft:◂;\\smalltriangleleft:◃;\\Diamondblack:◆;\\Diamond:◇;\\lozenge:◊;\\Box:□;\\Circle:○;\\CIRCLE:●;\\LEFTcircle:◐;\\RIGHTcircle:◑;\\LEFTCIRCLE:◖;\\RIGHTCIRCLE:◗;\\boxbar:◫;\\square:◻;\\blacksquare:◼;\\bigstar:★;\\Sun:☉;\\Square:☐;\\CheckedBox:☑;\\XBox:☒;\\steaming:☕;\\pointright:☞;\\skull:☠;\\radiation:☢;\\biohazard:☣;\\yinyang:☯;\\frownie:☹;\\smiley:☺;\\blacksmiley:☻;\\sun:☼;\\rightmoon:☽;\\leftmoon:☾;\\mercury:☿;\\female:♀;\\earth:♁;\\male:♂;\\jupiter:♃;\\saturn:♄;\\uranus:♅;\\neptune:♆;\\pluto:♇;\\aries:♈;\\taurus:♉;\\gemini:♊;\\cancer:♋;\\leo:♌;\\virgo:♍;\\libra:♎;\\scorpio:♏;\\sagittarius:♐;\\capricornus:♑;\\aquarius:♒;\\pisces:♓;\\spadesuit:♠;\\heartsuit:♡;\\diamondsuit:♢;\\clubsuit:♣;\\varspadesuit:♤;\\varheartsuit:♥;\\vardiamondsuit:♦;\\varclubsuit:♧;\\quarternote:♩;\\eighthnote:♪;\\twonotes:♫;\\sixteenthnote:♬;\\flat:♭;\\natural:♮;\\sharp:♯;\\recycle:♻;\\anchor:⚓;\\swords:⚔;\\warning:⚠;\\medcirc:⚪;\\medbullet:⚫;\\pencil:✎;\\checkmark:✓;\\ballotx:✗;\\maltese:✠;\\arrowbullet:➢;\\perp:⟂;\\Lbag:⟅;\\Rbag:⟆;\\Diamonddot:⟐;\\multimapinv:⟜;\\llbracket:⟦;\\rrbracket:⟧;\\langle:⟨;\\rangle:⟩;\\lang:⟪;\\rang:⟫;\\lgroup:⟮;\\rgroup:⟯;\\longleftarrow:⟵;\\longrightarrow:⟶;\\longleftrightarrow:⟷;\\Longleftarrow:⟸;\\Longrightarrow:⟹;\\Longleftrightarrow:⟺;\\longmapsfrom:⟻;\\longmapsto:⟼;\\Longmapsfrom:⟽;\\Longmapsto:⟾;\\psur:⤀;\\Mapsfrom:⤆;\\Mapsto:⤇;\\UpArrowBar:⤒;\\DownArrowBar:⤓;\\pinj:⤔;\\finj:⤕;\\bij:⤖;\\leadsto:⤳;\\leftrightharpoon:⥊;\\rightleftharpoon:⥋;\\leftrightharpoonup:⥎;\\rightupdownharpoon:⥏;\\leftrightharpoondown:⥐;\\leftupdownharpoon:⥑;\\LeftVectorBar:⥒;\\RightVectorBar:⥓;\\RightUpVectorBar:⥔;\\RightDownVectorBar:⥕;\\DownLeftVectorBar:⥖;\\DownRightVectorBar:⥗;\\LeftUpVectorBar:⥘;\\LeftDownVectorBar:⥙;\\LeftTeeVector:⥚;\\RightTeeVector:⥛;\\RightUpTeeVector:⥜;\\RightDownTeeVector:⥝;\\DownLeftTeeVector:⥞;\\DownRightTeeVector:⥟;\\LeftUpTeeVector:⥠;\\LeftDownTeeVector:⥡;\\leftleftharpoons:⥢;\\upupharpoons:⥣;\\rightrightharpoons:⥤;\\downdownharpoons:⥥;\\leftbarharpoon:⥪;\\barleftharpoon:⥫;\\rightbarharpoon:⥬;\\barrightharpoon:⥭;\\updownharpoons:⥮;\\downupharpoons:⥯;\\strictfi:⥼;\\strictif:⥽;\\VERT:⦀;\\spot:⦁;\\Lparen:⦅;\\Rparen:⦆;\\limg:⦇;\\rimg:⦈;\\lblot:⦉;\\rblot:⦊;\\circledbslash:⦸;\\circledless:⧀;\\circledgtr:⧁;\\boxslash:⧄;\\boxbslash:⧅;\\boxast:⧆;\\boxcircle:⧇;\\boxbox:⧈;\\LeftTriangleBar:⧏;\\RightTriangleBar:⧐;\\multimapboth:⧟;\\blacklozenge:⧫;\\setminus:⧵;\\zhide:⧹;\\bigodot:⨀;\\bigoplus:⨁;\\bigotimes:⨂;\\biguplus:⨄;\\bigsqcap:⨅;\\bigsqcup:⨆;\\varprod:⨉;\\utfiiiint:⨌;\\utffint:⨏;\\utfsqint:⨖;\\Join:⨝;\\zcmp:⨟;\\zpipe:⨠;\\zproject:⨡;\\fcmp:⨾;\\amalg:⨿;\\doublebarwedge:⩞;\\dsub:⩤;\\rsub:⩥;\\Coloneqq:⩴;\\Equal:⩵;\\Same:⩶;\\leqslant:⩽;\\geqslant:⩾;\\lessapprox:⪅;\\gtrapprox:⪆;\\lneq:⪇;\\gneq:⪈;\\lnapprox:⪉;\\gnapprox:⪊;\\lesseqqgtr:⪋;\\gtreqqless:⪌;\\eqslantless:⪕;\\eqslantgtr:⪖;\\NestedLessLess:⪡;\\NestedGreaterGreater:⪢;\\leftslice:⪦;\\rightslice:⪧;\\preceq:⪯;\\succeq:⪰;\\preceqq:⪳;\\succeqq:⪴;\\precapprox:⪷;\\succapprox:⪸;\\precnapprox:⪹;\\succnapprox:⪺;\\llcurly:⪻;\\ggcurly:⪼;\\subseteqq:⫅;\\supseteqq:⫆;\\subsetneqq:⫋;\\supsetneqq:⫌;\\Top:⫪;\\Bot:⫫;\\interleave:⫴;\\biginterleave:⫼;\\sslash:⫽;\\talloblong:⫾;\\blacksquare:⬛;\\square:⬜;\\partial:𝜕;\\emojify:️;\\cbrt:∛;\\mars:♂;\\xor:⊻;\\nand:⊼;\\nor:⊽;\\iff:⟺;\\implies:⟹;\\impliedby:⟸;\\euler:ℯ;\\ohm:Ω;\\hbar:ħ;\\del:∇;\\euro:€;\\exclamdown:¡;\\sterling:£;\\brokenbar:¦;\\S:§;\\copyright:©;\\ordfeminine:ª;\\highminus:¯;\\P:¶;\\cdotp:·;\\ordmasculine:º;\\questiondown:¿;\\AA:Å;\\AE:Æ;\\DH:Ð;\\O:Ø;\\TH:Þ;\\ss:ß;\\aa:å;\\ae:æ;\\dh:ð;\\o:ø;\\th:þ;\\DJ:Đ;\\dj:đ;\\L:Ł;\\NG:Ŋ;\\ng:ŋ;\\OE:Œ;\\oe:œ;\\hvlig:ƕ;\\nrleg:ƞ;\\doublepipe:ǂ;\\trna:ɐ;\\trnsa:ɒ;\\openo:ɔ;\\rtld:ɖ;\\schwa:ə;\\pgamma:ɣ;\\pbgam:ɤ;\\trnh:ɥ;\\btdl:ɬ;\\rtll:ɭ;\\trnm:ɯ;\\trnmlr:ɰ;\\ltlmr:ɱ;\\ltln:ɲ;\\rtln:ɳ;\\clomeg:ɷ;\\ltphi:ɸ;\\trnr:ɹ;\\trnrl:ɺ;\\rttrnr:ɻ;\\rl:ɼ;\\rtlr:ɽ;\\fhr:ɾ;\\rtls:ʂ;\\esh:ʃ;\\trnt:ʇ;\\rtlt:ʈ;\\pupsil:ʊ;\\pscrv:ʋ;\\invv:ʌ;\\invw:ʍ;\\trny:ʎ;\\rtlz:ʐ;\\yogh:ʒ;\\glst:ʔ;\\reglst:ʕ;\\inglst:ʖ;\\turnk:ʞ;\\dyogh:ʤ;\\tesh:ʧ;\\rasp:ʼ;\\verts:ˈ;\\verti:ˌ;\\lmrk:ː;\\hlmrk:ˑ;\\sbrhr:˒;\\sblhr:˓;\\rais:˔;\\low:˕;\\u:˘;\\tildelow:˜;\\Alpha:Α;\\Beta:Β;\\Epsilon:Ε;\\Zeta:Ζ;\\Eta:Η;\\Iota:Ι;\\Kappa:Κ;\\Rho:Ρ;\\Tau:Τ;\\Chi:Χ;\\varkappa:ϰ;\\varTheta:ϴ;\\enspace: ;\\thickspace: ;\\thinspace: ;\\hspace: ;\\endash:–;\\emdash:—;\\Vert:‖;\\lVert:‖;\\rVert:‖;\\lq:‘;\\rq:’;\\reapos:‛;\\ldq:“;\\rdq:”;\\dots:…;\\perthousand:‰;\\pertenthousand:‱;\\guilsinglleft:‹;\\guilsinglright:›;\\nolinebreak:⁠;\\pes:₧;\\numero:№;\\xrat:℞;\\trademark:™;\\bbsum:⅀;\\Game:⅁;\\dblarrowupdown:⇅;\\DownArrowUpArrow:⇵;\\emptyset:∅;\\surd:√;\\clwintegral:∱;\\Colon:∷;\\dotminus:∸;\\kernelcontraction:∻;\\lazysinv:∾;\\neqsim:≂;\\nsime:≄;\\approxnotequal:≆;\\tildetrpl:≋;\\allequal:≌;\\nBumpeq:≎;\\nbumpeq:≏;\\wedgeq:≙;\\starequal:≛;\\questeq:≟;\\ne:≠;\\le:≤;\\ge:≥;\\lvertneqq:≨;\\gvertneqq:≩;\\NotLessLess:≪;\\NotGreaterGreater:≫;\\notlessgreater:≸;\\notgreaterless:≹;\\nprecsim:≾;\\nsuccsim:≿;\\varsubsetneqq:⊊;\\varsupsetneq:⊋;\\cupdot:⊍;\\NotSquareSubset:⊏;\\NotSquareSuperset:⊐;\\indep:⫫;\\downvDash:⫪;\\upvDash:⫫;\\original:⊶;\\image:⊷;\\hermitconjmatrix:⊹;\\rightanglearc:⊾;\\verymuchless:⋘;\\adots:⋰;\\recorder:⌕;\\obar:⌽;\\dlcorn:⎣;\\lmoustache:⎰;\\visiblespace:␣;\\circledS:Ⓢ;\\dshfnc:┆;\\sqfnw:┙;\\diagup:╱;\\diagdown:╲;\\vrecto:▯;\\blacktriangle:▴;\\vartriangle:▵;\\triangledown:▿;\\bigcirc:○;\\cirfl:◐;\\cirfr:◑;\\cirfb:◒;\\rvbull:◘;\\sqfl:◧;\\sqfr:◨;\\sqfse:◪;\\venus:♀;\\Uuparrow:⤊;\\Ddownarrow:⤋;\\bkarow:⤍;\\dbkarow:⤏;\\drbkarrow:⤐;\\twoheadrightarrowtail:⤖;\\hksearow:⤥;\\hkswarow:⤦;\\tona:⤧;\\toea:⤨;\\tosa:⤩;\\towa:⤪;\\rdiagovfdiag:⤫;\\fdiagovrdiag:⤬;\\seovnearrow:⤭;\\neovsearrow:⤮;\\fdiagovnearrow:⤯;\\rdiagovsearrow:⤰;\\neovnwarrow:⤱;\\nwovnearrow:⤲;\\Rlarr:⥂;\\rLarr:⥄;\\rarrx:⥇;\\LeftRightVector:⥎;\\RightUpDownVector:⥏;\\DownLeftRightVector:⥐;\\LeftUpDownVector:⥑;\\UpEquilibrium:⥮;\\ReverseUpEquilibrium:⥯;\\RoundImplies:⥰;\\Vvert:⦀;\\Elroang:⦆;\\ddfnc:⦙;\\Angle:⦜;\\lpargt:⦠;\\obslash:⦸;\\Lap:⧊;\\defas:⧋;\\NotLeftTriangleBar:⧏;\\NotRightTriangleBar:⧐;\\dualmap:⧟;\\shuffle:⧢;\\RuleDelayed:⧴;\\bigcupdot:⨃;\\conjquant:⨇;\\disjquant:⨈;\\bigtimes:⨉;\\clockoint:⨏;\\sqrint:⨖;\\upint:⨛;\\lowint:⨜;\\plusdot:⨥;\\Times:⨯;\\btimes:⨲;\\And:⩓;\\Or:⩔;\\ElOr:⩖;\\perspcorrespond:⩞;\\ddotseq:⩷;\\nleqslant:⩽;\\ngeqslant:⩾;\\NotNestedLessLess:⪡;\\NotNestedGreaterGreater:⪢;\\partialmeetcontraction:⪣;\\bumpeqq:⪮;\\precneqq:⪵;\\succneqq:⪶;\\nsubseteqq:⫅;\\nsupseteqq:⫆;\\mlcp:⫛;\\forks:⫝̸;\\forksnot:⫝;\\dashV:⫣;\\Dashv:⫤;\\tdcol:⫶;\\openbracketleft:⟦;\\openbracketright:⟧;\\Zbar:Ƶ;\\upMu:Μ;\\upNu:Ν;\\upOmicron:Ο;\\upepsilon:ε;\\upomicron:ο;\\upvarbeta:ϐ;\\upoldKoppa:Ϙ;\\upoldkoppa:ϙ;\\upstigma:ϛ;\\upkoppa:ϟ;\\upsampi:ϡ;\\tieconcat:⁀;\\eulermascheroni:ℇ;\\planck:ℎ;\\turnediota:℩;\\Angstrom:Å;\\sansLturned:⅂;\\sansLmirrored:⅃;\\PropertyLine:⅊;\\upand:⅋;\\twoheaduparrow:↟;\\twoheaddownarrow:↡;\\mapsup:↥;\\mapsdown:↧;\\updownarrowbar:↨;\\downzigzagarrow:↯;\\Ldsh:↲;\\Rdsh:↳;\\linefeed:↴;\\carriagereturn:↵;\\nHuparrow:⇞;\\nHdownarrow:⇟;\\leftdasharrow:⇠;\\updasharrow:⇡;\\rightdasharrow:⇢;\\downdasharrow:⇣;\\rightarrowbar:⇥;\\leftwhitearrow:⇦;\\upwhitearrow:⇧;\\rightwhitearrow:⇨;\\downwhitearrow:⇩;\\whitearrowupfrombar:⇪;\\circleonrightarrow:⇴;\\rightthreearrows:⇶;\\nvleftarrow:⇷;\\nvrightarrow:⇸;\\nvleftrightarrow:⇹;\\nVleftarrow:⇺;\\nVrightarrow:⇻;\\nVleftrightarrow:⇼;\\increment:∆;\\smallin:∊;\\smallni:∍;\\QED:∎;\\vysmblkcircle:∙;\\fourthroot:∜;\\dotsminusdots:∺;\\arceq:≘;\\veeeq:≚;\\eqdef:≝;\\measeq:≞;\\Equiv:≣;\\nasymp:≭;\\nlesssim:≴;\\ngtrsim:≵;\\circledequal:⊜;\\prurel:⊰;\\scurel:⊱;\\varlrtriangle:⊿;\\equalparallel:⋕;\\eqless:⋜;\\eqgtr:⋝;\\npreccurlyeq:⋠;\\nsucccurlyeq:⋡;\\sqsubsetneq:⋤;\\sqsupsetneq:⋥;\\disin:⋲;\\varisins:⋳;\\isins:⋴;\\isindot:⋵;\\varisinobar:⋶;\\isinobar:⋷;\\isinvb:⋸;\\isinE:⋹;\\nisd:⋺;\\varnis:⋻;\\nis:⋼;\\varniobar:⋽;\\niobar:⋾;\\bagmember:⋿;\\house:⌂;\\vardoublebarwedge:⌆;\\invnot:⌐;\\sqlozenge:⌑;\\profline:⌒;\\profsurf:⌓;\\viewdata:⌗;\\turnednot:⌙;\\varhexagonlrbonds:⌬;\\conictaper:⌲;\\topbot:⌶;\\hexagon:⎔;\\underbracket:⎵;\\bbrktbrk:⎶;\\lvboxline:⎸;\\rvboxline:⎹;\\varcarriagereturn:⏎;\\trapezium:⏢;\\benzenr:⏣;\\strns:⏤;\\fltns:⏥;\\accurrent:⏦;\\elinters:⏧;\\blanksymbol:␢;\\blockuphalf:▀;\\blocklowhalf:▄;\\blockfull:█;\\blocklefthalf:▌;\\blockrighthalf:▐;\\blockqtrshaded:░;\\blockhalfshaded:▒;\\blockthreeqtrshaded:▓;\\squoval:▢;\\blackinwhitesquare:▣;\\squarehfill:▤;\\squarevfill:▥;\\squarehvfill:▦;\\squarenwsefill:▧;\\squareneswfill:▨;\\squarecrossfill:▩;\\smblksquare:▪;\\smwhtsquare:▫;\\hrectangleblack:▬;\\hrectangle:▭;\\vrectangleblack:▮;\\parallelogramblack:▰;\\parallelogram:▱;\\bigblacktriangleup:▲;\\blackpointerright:►;\\whitepointerright:▻;\\bigblacktriangledown:▼;\\blackpointerleft:◄;\\whitepointerleft:◅;\\mdlgblkdiamond:◆;\\mdlgwhtdiamond:◇;\\blackinwhitediamond:◈;\\fisheye:◉;\\dottedcircle:◌;\\circlevertfill:◍;\\bullseye:◎;\\mdlgblkcircle:●;\\circletophalfblack:◓;\\circleurquadblack:◔;\\blackcircleulquadwhite:◕;\\blacklefthalfcircle:◖;\\blackrighthalfcircle:◗;\\inversewhitecircle:◙;\\invwhiteupperhalfcircle:◚;\\invwhitelowerhalfcircle:◛;\\ularc:◜;\\urarc:◝;\\lrarc:◞;\\llarc:◟;\\topsemicircle:◠;\\botsemicircle:◡;\\lrblacktriangle:◢;\\llblacktriangle:◣;\\ulblacktriangle:◤;\\urblacktriangle:◥;\\smwhtcircle:◦;\\squareulblack:◩;\\trianglecdot:◬;\\triangleleftblack:◭;\\trianglerightblack:◮;\\lgwhtcircle:◯;\\squareulquad:◰;\\squarellquad:◱;\\squarelrquad:◲;\\squareurquad:◳;\\circleulquad:◴;\\circlellquad:◵;\\circlelrquad:◶;\\circleurquad:◷;\\ultriangle:◸;\\urtriangle:◹;\\lltriangle:◺;\\mdwhtsquare:◻;\\mdblksquare:◼;\\mdsmwhtsquare:◽;\\mdsmblksquare:◾;\\lrtriangle:◿;\\bigwhitestar:☆;\\astrosun:☉;\\danger:☡;\\acidfree:♾;\\dicei:⚀;\\diceii:⚁;\\diceiii:⚂;\\diceiv:⚃;\\dicev:⚄;\\dicevi:⚅;\\circledrightdot:⚆;\\circledtwodots:⚇;\\blackcircledrightdot:⚈;\\blackcircledtwodots:⚉;\\hermaphrodite:⚥;\\mdwhtcircle:⚪;\\mdblkcircle:⚫;\\mdsmwhtcircle:⚬;\\neuter:⚲;\\circledstar:✪;\\varstar:✶;\\dingasterisk:✽;\\draftingarrow:➛;\\threedangle:⟀;\\whiteinwhitetriangle:⟁;\\bsolhsub:⟈;\\suphsol:⟉;\\wedgedot:⟑;\\veedot:⟇;\\upin:⟒;\\bigbot:⟘;\\bigtop:⟙;\\UUparrow:⟰;\\DDownarrow:⟱;\\longrightsquigarrow:⟿;\\nvtwoheadrightarrow:⤀;\\nVtwoheadrightarrow:⤁;\\nvLeftarrow:⤂;\\nvRightarrow:⤃;\\nvLeftrightarrow:⤄;\\twoheadmapsto:⤅;\\downarrowbarred:⤈;\\uparrowbarred:⤉;\\leftbkarrow:⤌;\\leftdbkarrow:⤎;\\rightdotarrow:⤑;\\nvrightarrowtail:⤔;\\nVrightarrowtail:⤕;\\nvtwoheadrightarrowtail:⤗;\\nVtwoheadrightarrowtail:⤘;\\diamondleftarrow:⤝;\\rightarrowdiamond:⤞;\\diamondleftarrowbar:⤟;\\rightarrowplus:⥅;\\leftarrowplus:⥆;\\leftrightarrowcircle:⥈;\\twoheaduparrowcircle:⥉;\\leftrightharpoonupdown:⥊;\\leftrightharpoondownup:⥋;\\updownharpoonrightleft:⥌;\\updownharpoonleftright:⥍;\\leftharpoonsupdown:⥢;\\upharpoonsleftright:⥣;\\rightharpoonsupdown:⥤;\\downharpoonsleftright:⥥;\\leftrightharpoonsup:⥦;\\leftrightharpoonsdown:⥧;\\rightleftharpoonsup:⥨;\\rightleftharpoonsdown:⥩;\\leftharpoonupdash:⥪;\\dashleftharpoondown:⥫;\\rightharpoonupdash:⥬;\\dashrightharpoondown:⥭;\\measuredangleleft:⦛;\\rightanglemdot:⦝;\\angles:⦞;\\angdnr:⦟;\\sphericalangleup:⦡;\\turnangle:⦢;\\revangle:⦣;\\angleubar:⦤;\\revangleubar:⦥;\\wideangledown:⦦;\\wideangleup:⦧;\\measanglerutone:⦨;\\measanglelutonw:⦩;\\measanglerdtose:⦪;\\measangleldtosw:⦫;\\measangleurtone:⦬;\\measangleultonw:⦭;\\measangledrtose:⦮;\\measangledltosw:⦯;\\revemptyset:⦰;\\emptysetobar:⦱;\\emptysetocirc:⦲;\\emptysetoarr:⦳;\\emptysetoarrl:⦴;\\circledparallel:⦷;\\odotslashdot:⦼;\\circledwhitebullet:⦾;\\circledbullet:⦿;\\olessthan:⧀;\\ogreaterthan:⧁;\\lrtriangleeq:⧡;\\eparsl:⧣;\\smeparsl:⧤;\\eqvparsl:⧥;\\dsol:⧶;\\rsolbar:⧷;\\doubleplus:⧺;\\tripleplus:⧻;\\modtwosum:⨊;\\cirfnint:⨐;\\awint:⨑;\\rppolint:⨒;\\scpolint:⨓;\\npolint:⨔;\\pointint:⨕;\\ringplus:⨢;\\plushat:⨣;\\simplus:⨤;\\plussim:⨦;\\plussubtwo:⨧;\\plustrif:⨨;\\commaminus:⨩;\\opluslhrim:⨭;\\oplusrhrim:⨮;\\dottimes:⨰;\\timesbar:⨱;\\smashtimes:⨳;\\otimeslhrim:⨴;\\otimesrhrim:⨵;\\otimeshat:⨶;\\Otimes:⨷;\\odiv:⨸;\\triangleplus:⨹;\\triangleminus:⨺;\\triangletimes:⨻;\\capdot:⩀;\\uminus:⩁;\\capwedge:⩄;\\cupvee:⩅;\\twocups:⩊;\\twocaps:⩋;\\closedvarcup:⩌;\\closedvarcap:⩍;\\Sqcap:⩎;\\Sqcup:⩏;\\closedvarcupsmashprod:⩐;\\wedgeodot:⩑;\\veeodot:⩒;\\wedgeonwedge:⩕;\\bigslopedvee:⩗;\\bigslopedwedge:⩘;\\wedgemidvert:⩚;\\veemidvert:⩛;\\midbarwedge:⩜;\\midbarvee:⩝;\\wedgedoublebar:⩠;\\varveebar:⩡;\\doublebarvee:⩢;\\veedoublebar:⩣;\\eqdot:⩦;\\dotequiv:⩧;\\dotsim:⩪;\\simrdots:⩫;\\simminussim:⩬;\\congdot:⩭;\\asteq:⩮;\\hatapprox:⩯;\\approxeqq:⩰;\\eqqplus:⩱;\\pluseqq:⩲;\\eqqsim:⩳;\\Coloneq:⩴;\\eqeqeq:⩶;\\equivDD:⩸;\\ltcir:⩹;\\gtcir:⩺;\\ltquest:⩻;\\gtquest:⩼;\\lesdot:⩿;\\gesdot:⪀;\\lesdoto:⪁;\\gesdoto:⪂;\\lesdotor:⪃;\\gesdotol:⪄;\\lsime:⪍;\\gsime:⪎;\\lsimg:⪏;\\gsiml:⪐;\\lgE:⪑;\\glE:⪒;\\lesges:⪓;\\gesles:⪔;\\elsdot:⪗;\\egsdot:⪘;\\eqqless:⪙;\\eqqgtr:⪚;\\eqqslantless:⪛;\\eqqslantgtr:⪜;\\simless:⪝;\\simgtr:⪞;\\simlE:⪟;\\simgE:⪠;\\glj:⪤;\\gla:⪥;\\ltcc:⪦;\\gtcc:⪧;\\lescc:⪨;\\gescc:⪩;\\smt:⪪;\\lat:⪫;\\smte:⪬;\\late:⪭;\\precneq:⪱;\\succneq:⪲;\\Prec:⪻;\\Succ:⪼;\\subsetdot:⪽;\\supsetdot:⪾;\\subsetplus:⪿;\\supsetplus:⫀;\\submult:⫁;\\supmult:⫂;\\subedot:⫃;\\supedot:⫄;\\subsim:⫇;\\supsim:⫈;\\subsetapprox:⫉;\\supsetapprox:⫊;\\lsqhook:⫍;\\rsqhook:⫎;\\csub:⫏;\\csup:⫐;\\csube:⫑;\\csupe:⫒;\\subsup:⫓;\\supsub:⫔;\\subsub:⫕;\\supsup:⫖;\\suphsub:⫗;\\supdsub:⫘;\\forkv:⫙;\\lllnest:⫷;\\gggnest:⫸;\\leqqslant:⫹;\\geqqslant:⫺;\\squaretopblack:⬒;\\squarebotblack:⬓;\\squareurblack:⬔;\\squarellblack:⬕;\\diamondleftblack:⬖;\\diamondrightblack:⬗;\\diamondtopblack:⬘;\\diamondbotblack:⬙;\\dottedsquare:⬚;\\lgblksquare:⬛;\\lgwhtsquare:⬜;\\vysmblksquare:⬝;\\vysmwhtsquare:⬞;\\pentagonblack:⬟;\\pentagon:⬠;\\varhexagon:⬡;\\varhexagonblack:⬢;\\hexagonblack:⬣;\\lgblkcircle:⬤;\\mdblkdiamond:⬥;\\mdwhtdiamond:⬦;\\mdblklozenge:⬧;\\mdwhtlozenge:⬨;\\smblkdiamond:⬩;\\smblklozenge:⬪;\\smwhtlozenge:⬫;\\blkhorzoval:⬬;\\whthorzoval:⬭;\\blkvertoval:⬮;\\whtvertoval:⬯;\\circleonleftarrow:⬰;\\leftthreearrows:⬱;\\leftarrowonoplus:⬲;\\longleftsquigarrow:⬳;\\nvtwoheadleftarrow:⬴;\\nVtwoheadleftarrow:⬵;\\twoheadmapsfrom:⬶;\\twoheadleftdbkarrow:⬷;\\leftdotarrow:⬸;\\nvleftarrowtail:⬹;\\nVleftarrowtail:⬺;\\twoheadleftarrowtail:⬻;\\nvtwoheadleftarrowtail:⬼;\\nVtwoheadleftarrowtail:⬽;\\leftarrowx:⬾;\\leftcurvedarrow:⬿;\\equalleftarrow:⭀;\\bsimilarleftarrow:⭁;\\leftarrowbackapprox:⭂;\\rightarrowgtr:⭃;\\leftarrowless:⥷;\\rightarrowsupset:⭄;\\leftarrowsubset:⥺;\\LLeftarrow:⭅;\\RRightarrow:⭆;\\bsimilarrightarrow:⭇;\\rightarrowbackapprox:⭈;\\similarleftarrow:⭉;\\leftarrowapprox:⭊;\\leftarrowbsimilar:⭋;\\rightarrowbsimilar:⭌;\\medwhitestar:⭐;\\medblackstar:⭑;\\smwhitestar:⭒;\\rightpentagonblack:⭓;\\rightpentagon:⭔;\\postalmark:〒;\\triangleright:▷;\\triangleleft:◁;\\leftouterjoin:⟕;\\rightouterjoin:⟖;\\fullouterjoin:⟗;\\join:⨝;\\leftwavearrow:↜;\\rightwavearrow:↝;\\varbarwedge:⌅;\\smallblacktriangleright:▸;\\smallblacktriangleleft:◂;\\tricolon:⁝;\\grave ◌:◌̀;\\\` ◌:◌̀;\\acute ◌:◌́;\\' ◌:◌́;\\hat ◌:◌̂;\\^ ◌:◌̂;\\tilde ◌:◌̃;\\~ ◌:◌̃;\\breve ◌:◌̆;\\overline ◌:◌̅;\\bar ◌:◌̅;\\underline ◌:◌̲;\\underbar ◌:◌̲;\\dot ◌:◌̇;\\ddot ◌:◌̈;\\\" ◌:◌̈;\\mathring ◌:◌̊;\\ocirc ◌:◌̊;\\H ◌:◌̋;\\check ◌:◌̌;\\c ◌:◌̧;\\k ◌:◌̨;\\utilde ◌:◌̰;\\l ◌:◌̷;\\not ◌:◌̸;\\lvec ◌:◌⃐;\\leftharpoonaccent ◌:◌⃐;\\Lvec ◌:◌⃖;\\vec ◌:◌⃗;\\dddot ◌:◌⃛;\\ddddot ◌:◌⃜;\\overleftrightarrow ◌:◌⃡;\\ovhook ◌:◌̉;\\oturnedcomma ◌:◌̒;\\ocommatopright ◌:◌̕;\\droang ◌:◌̚;\\rightharpoonaccent ◌:◌⃑;\\widebridgeabove ◌:◌⃩;\\asteraccent ◌:◌⃰;\\candra ◌:◌̐;\\wideutilde ◌:◌̰;\\threeunderdot ◌:◌⃨;\\underleftarrow ◌:◌⃮;\\underrightarrow ◌:◌⃯;\\underleftrightarrow ◌:◌͍;\\underrightharpoondown ◌:◌⃬;\\underleftharpoondown ◌:◌⃭;\\palh ◌:◌̡;\\rh ◌:◌̢;\\sbbrg ◌:◌̪;\\sout ◌:◌̶;\\strike ◌:◌̶;\\annuity ◌:◌⃧;\\enclosecircle ◌:◌⃝;\\enclosesquare ◌:◌⃞;\\enclosediamond ◌:◌⃟;\\enclosetriangle ◌:◌⃤;\\vertoverlay ◌:◌⃒;"
if test "$generated" != "$reference"; then
    echo "FAIL: texsymbols"
    exit 1
fi
