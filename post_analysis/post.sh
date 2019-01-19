#!/bin/bash
$control_static_file ="./staticduck.jpg"
$radiated_static_file ="../radiated_staticduck.jpg"
# Convert files to compare into hex, and write lines which are different
# into ./static_diff.log
diff <(xxd $control_static_file) <(xxd $radiated_static_file) > static_diff.log
