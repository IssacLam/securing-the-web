# Current Status

Report Submitted.

-----

# Grep no body Functions
2>&1 | grep "WARNING"

-----

# Relink the dynamic library for executing s2n sample code

install_name_tool -change libs2n.dylib @executable_path/../lib/libs2n.dylib s2nc

install_name_tool -change libs2n.dylib @executable_path/../lib/libs2n.dylib s2nd

-----
