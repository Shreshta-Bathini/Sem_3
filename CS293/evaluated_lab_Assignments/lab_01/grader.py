#!/usr/bin/python3

import sys
# caution: path[0] is reserved for script path (or '' in REPL)

#------------------------------
# Setup for problem
#------------------------------
exam                 = "Lab 01"
problem              = "avg-binary"
prob_files           = ['main.cpp','common.h','avg-binary.h']
student_files        = ['avg-binary.cpp']
allowed_include      = ['common.h']
disallowed_functions = ['cout','cerr', #'new ',
                        'append','alloc(','malloc(','free','delete ' #,'['
                       ]


#------------------------------
# test cases
#------------------------------

tests    = [
    'test1',
    'test2',
    'test4',
    'test5',
    'test6',
    'test7',
    'test-extra1',
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

students             = [ s for s in os.listdir(students_path) if os.path.isdir(students_path+'/'+s) ]


#---------------------------------
# Allocate auto-grader
#--------------------------------
base_grader = autograder.Autograder(
    exam                 = exam, 
    problem              = problem, 
    prob_path            = prob_path, 
    prob_files           = prob_files, 
    students             = students,
    students_path        = students_path, 
    student_files        = student_files, 
    tests_path           = tests_path,
    tests                = tests,
    allowed_include      = allowed_include, 
    disallowed_functions = disallowed_functions,
    timeout              = 40,
)
# base_grader.parallel = 1

if len(sys.argv) < 2: base_grader.display_usage(sys.argv[0])

if len(sys.argv) == 3:
    rollno  = sys.argv[2]
    base_grader.set_student( grades_file, rollno )

# ---------------------
# Actions of auto-grader
# --------------------
act  = sys.argv[1]
if act in ['compile','policy','run','results','grade','package','email','all']:
    #----------------------------------------
    # Policy check, compile, run, and results
    #----------------------------------------
    base_grader.action(act)
    #-----------------------------------------------
    # Assign grade
    #-----------------------------------------------
    if act in ['grade','all']:
        full =  base_grader.get_results()
        #----------------------------------
        # Compute total score 
        #----------------------------------
        full['total'] = full[tests].sum( axis = 1 )
        full['total' ] = np.where( ( (full['total'] > 3)  ), 2, 0)
        full.to_csv( grades_file, index=False )
        #----------------------------------
        # Score distribution
        #----------------------------------
        counts = full['total'].value_counts().reindex( list(range(0, 9)), fill_value = 0 )
        #---------------------------------
        # Printing
        #---------------------------------
        print(full[['Roll No','total']])
        print(counts)
        print(full['total'].mean())

    #-----------------------------------------------
    # create package before sending emails
    #-----------------------------------------------
    if act in ['package']:
        base_grader.grading_files = ['./grader.py','../../../../utils/autograder.py']
        base_grader.package_replace_sequence = auto_remove
        base_grader.create_packages()

