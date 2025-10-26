#!/usr/bin/python3

import sys
# caution: path[0] is reserved for script path (or '' in REPL)

#------------------------------
# Setup for problem
#------------------------------
exam                 = "Lab 05"
problem              = "isHeap"
prob_files           = ['main.cpp', 'isHeap.h']
student_files        = ['isHeap.cpp']
allowed_include      = ['isHeap.h']
disallowed_functions = ['cout','cerr', 'new ',
                        'alloc(','malloc(', #'append', #'free', #'delete ' #,'['
                       ]

#------------------------------
# test cases
#------------------------------

tests    = [
    # 'eval_100_y',
    # 'eval_1000_y',
    # 'eval_10000_y',
    # 'eval_100000_y',
    'eval_1000000_y',
    # 'eval_100_n',
    'eval_1000_n',
    # 'eval_10000_n',
    'eval_100000_n',
    # 'eval_1000000_n',
    
    # 'test1',
    # 'test2',
    # 'test3',
    # 'test4',
    # 'test5',         # Zero length
    'test6',         # All same
    # 'longtestcase1', # Long yes
    # 'longtestcase2', # Long No
]

grades_file = "grade.csv"

#---------------------------
# Paths
#---------------------------
sys.path.insert( 1,    '../../../../utils' )
students_path        = '../../submissions/'
prob_path            = './harness/'
tests_path           = './tests'
students_path = "./students/"
prob_path = "./harness/"
tests_path = "./tests/"


import autograder
import pandas as pd
import numpy as np
import os
import copy
import matplotlib.pyplot as plt

pd.set_option('display.max_rows', 200)

#------------------------------
# student lists
#------------------------------

# students             = [ s for s in os.listdir(students_path) if os.path.isdir(students_path+'/'+s) ]

#---------------------------------
# Allocate auto-grader
#--------------------------------
base_grader = autograder.Autograder(
    exam                 = exam, 
    problem              = problem, 
    prob_path            = prob_path, 
    prob_files           = prob_files, 
    students_path        = students_path, 
    student_files        = student_files, 
    tests_path           = tests_path,
    tests                = tests,
    allowed_include      = allowed_include, 
    disallowed_functions = disallowed_functions,
    timeout              = 1,
    # students           = None,
)
base_grader.parallel = 1
# base_grader.allowed_recursion = False

def isheap_cmp( expected, output ):
    # return expected == output
    if output == None or (len(output) < 1):
        return (0,False)
        # return False
    results = {}
    for o in output:
        os = o.strip().split(':')
        if len(os) > 1:
            results[ os[0] ] = int(os[1])
    if (results['Result'] == 1 and expected[0] == 'YES\n') or (results['Result'] == 0 and expected[0] == 'NO\n'):
        return (results['Time'],True)
        # return True    
    return (results['Time'],False)
    # return False

def isheap_cmp_simple( expected, output ):
    t,r = isheap_cmp(expected,output)
    return r

base_grader.cmp_function = isheap_cmp

if len(sys.argv) < 2 : base_grader.display_usage(sys.argv[0])
if len(sys.argv) == 3: base_grader.set_student( grades_file, sys.argv[2] )

# ---------------------
# Actions of auto-grader
# --------------------
act  = sys.argv[1]
#----------------------------------------
# Policy check, compile, run, and results
#----------------------------------------
base_grader.action(act)
#-----------------------------------------------
# Assign grade
#-----------------------------------------------
if act in ['grade','all']:
    full =  base_grader.get_results()
    for test in tests:
        full[test+'-time'] = full[test].str.split(',').str[0].str[1:].astype(int)
        full[test] = full[test].str.split(',').str[1].str[1:-1]
        full[test] = np.where(full[test] == "True", True, False)
    full['total'] = full[tests].sum( axis = 1 )

    for test in tests:
        full[f'{test}-time'] = np.where(    full['total'] == len(tests), full[f'{test}-time'], 0)

    #----------------------------------
    # Compute total score 
    #----------------------------------

    num_t = len(tests)

    full['total'] = np.where( full['total'] >= num_t, 2, 0)
    full['total'] = np.where( ((full['total'] == 2) & (full['eval_1000000_y-time'] > 10000000)), 1, full['total'])

                             
    full.to_csv(grades_file, index=False)
    # full = full[['Roll No']+tests+[t+'-time' for t in tests]+['total']]
    # print(full.sort_values(f'eval_1000000_y-time'))
    full = full[['Roll No','Compile Success','Policy Error']+tests+['total']]
    base_grader.save_marks(full,'total')
    
#-----------------------------------------------
# create package before sending emails
#-----------------------------------------------
if act in ['package']:
    base_grader.grading_files = ['./grader.py','../../../../utils/autograder.py']
    base_grader.package_replace_sequence = auto_remove
    base_grader.create_packages()

