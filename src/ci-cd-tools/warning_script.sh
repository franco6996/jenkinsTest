#!/bin/bash
#Si tuve errores durante la compilacion devuelvo 1, sino 0
characters=$(wc -m < compilation_error.log)
if [ $characters -gt 0 ]
then
	exit 1
else
	exit 0
fi
exit 0
