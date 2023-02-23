#!/bin/bash
#Si tuve errores durante la compilacion devuelvo 1, sino 0
characters=$(wc -m < "src/ci-cd-tools/compilation_error.log")
if [ $characters -gt 0 ]
then
	echo ""
	echo "Warnings encontrados: "
	cat "src/ci-cd-tools/compilation_error.log"
	exit 1
else
	echo ""
	echo "No se encontraron warnings durante compilacion"
	exit 0
fi
exit 0
