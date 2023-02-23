#!/bin/bash
# Compilo exportando logs de errores a archivo
make -C src/ci-cd-tools/ -j8 all 2> src/ci-cd-tools/compilation_error.log
#Comparo la salida de make para ver si fue exitosa
exitStatus=$?
if [ $exitStatus -eq 0 ]
then
	# Si compilo bien imprimo warnings en consola y salgo sin fallas
	echo ""
	echo "Compilacion exitosa, warnings encontrados: "
	cat src/ci-cd-tools/compilation_error.log
	exit 0
fi
#Si compilo con errores los imprimo en consola y salgo con error
echo ""
echo "Error durante la compilacion: "
cat src/ci-cd-tools/compilation_error.log
exit 1
