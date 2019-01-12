#!/usr/bin/env bash

## associative array for job status
declare -A JOBS

# format of logged data for all test programs is currently:
# (we can change this if we come up with anything else to track)
# OUTPUT| PROGRAM_NAME | TIMING | EXIT_CODE
# eg. "mm" | 1.17 |

## generic wrapper that logs execution data to ./results/{$1}
## $1 is the program path
## $2 is the normally correct output
## $3 is the file which to store the execution data
test_prog() {
    local prog=$1
    local correct_output=$2
    local log_file=$3

    time -p $prog |\
        (
            read output real_time user_time sys_time;
            # echo (vars) >> $log_file
        )

    # TODO how to read both time output and standard out of timed command into var?
    read -r <<< ()
    # time $1


    # { } >> $log_file
}

## waits on and checks exit status of each job
## preserves exit status in ${JOBS}
## returns 1 if any job failed
# execute_jobs() {
#     local cmd
#     local status=0

#     # iterate over all keys (pids) in JOBS
#     for pid in ${!JOBS[@]}; do
#         cmd=${JOBS[${pid}]}

#         wait ${pid}
#         # $? is the most recent foreground pipeline exit status
#         JOBS[${pid}]=$?

#         # update return status if a job has failed
#         if [[ ${JOBS[${pid}]} -ne 0 ]]; then
#             status=${JOBS[${pid}]}
#             echo -e "[${pid}] Exited with status: ${status}\n${cmd}"
#         fi
#     done
#     return ${status}
# }

test_prog '../bin/matrix_multiplier' ''
