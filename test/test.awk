#!/usr/bin/awk -f
# awk script to run tests
# test format:
# A text file where a start of a block is indicates with a line: 
# <input>
# The rest is considered input untill the keyword <ref> is encountered
# <ref> arg1 | arg2 | ...
# a reference block describes what should come out. A reference block 
# ends with either a second reference block or the <end> keyword
# For each argument for the reference block (arg1, arg2, ...) utftex is 
# called with the input and the specified argument. Note that if a 
# reference block has more than one argument, it means you expect the 
# output to be independent of the argument

function test()
{
	
	n=split(arglist,args,"|");
	if (n==0) {
		args[1]=" "
	}	
	ac=0;
	for (arg in args)
	{
		ac=ac+1;
		tc=tc+1;
		system("cat tmp | "exe" "args[arg]" > out"); 
		r=system("cmp -s ref out")
		if (!(r==0)){
		  fail=fail+1;
		  print "FAIL: "name" ref" ref ", arg"ac" = " args[arg]
		  if (debug>0)
		  {
		    file="debug_"name"_ref"ref"_arg"ac
		    print "      test results written to file: " file
		    system("echo \"# args:\" > "file)
		    system("echo \"# input:\" >> "file)
		    system("cat tmp >> "file)
		    system("echo \"# reference:\" >> "file)
		    system("cat ref >> "file)
		    system("echo \"# output:\" >> "file)
		    system("cat out >> "file)
		  }
		}
		else {
		  print "PASS: "name" ref" ref ", arg"ac" = " args[arg]
		}
	}
}

# variables
# eq:      boolean, are we in an equation input block?
# ref:     boolean, are we in a reference block?
# name:    string, name of the test
# arglist: string, list of '|' separated arguments to test a reference against
# fail:    integer, counter for failed tests
# tc:      integer, test counter (all tests)
# exe:     string, with name and path of the utftex executable, defaults to "utftex"
# debug:   if >0, each failed tests generates an output file with test and test results 
BEGIN {eq=0;ref=0;name="none";arglist="";fail=0;tc=0;if(!exe){exe="utftex"};if(!debug){debug=0}}
{
  if ($1=="<end>") {
    test()
	system("rm ref")
	system("rm tmp")
    ref=0;
  }
  if ($1=="<ref>") {
    if (ref>0) {
		test()
		system("rm ref")    
    }
    eq=0;
    ref=ref+1;
    $1="";
    arglist=$0;
  } else if (ref>0) {
	system("echo '"$0"' >> ref")
  }
  if (eq) {
	system("echo '"$0"' >> tmp")
  }
  if ($1=="<input>") {
    eq=1;
    name=$2;
  }
}
END{system("rm out");print tc,fail}
