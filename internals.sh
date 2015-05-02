
sordirec="$(dirname "${0}")"
bsordirec="$(cd "${sordirec}" && pwd)"
echo > Tlmake

if [ -f "${HOME}/.chorplus/compile-cpp.txt" ]; then
	echo "spvr_cpp_compile =" `cat "${HOME}/.chorplus/compile-cpp.txt"` >> Tlmake
else
	echo "C++ Compiler Not Specified" > /dev/stderr
	exit 2
fi

cfgtl="cfgtl"
rm -rf "${cfgtl}"

echo "spvr_linked_files = ${cfgtl}/linked" >> Tlmake
echo "spvr_object_files = ${cfgtl}/object" >> Tlmake
echo "spvr_srcdir = ${bsordirec}" >> Tlmake

cat "${sordirec}/Makefile.bulk" >> Tlmake

make -f Tlmake "${cfgtl}/linked/chorplus-cnf001" || exit


