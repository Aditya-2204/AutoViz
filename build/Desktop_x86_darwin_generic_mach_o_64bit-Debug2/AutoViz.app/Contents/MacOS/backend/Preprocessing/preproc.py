import pandas as pd
import numpy as np
import sys
import subprocess
import os

try:
    projectName = sys.argv[1]
    width = sys.argv[2]
    height = sys.argv[3]
    df=pd.read_csv(f"../{projectName}.csv")
except Exception as e:
    print(f"Error: {e}")
    sys.exit(1)

def remove_duplicates(df) -> pd.DataFrame:
    """
    Remove duplicate rows based on all columns except 'T'.
    If duplicates are found, sum their 'T' values.
    """
    # Ensure 'T' is numeric for summation    
    df = df.reset_index(drop=True)
    row = 0

    while row < len(df) - 1:
        current_ = df.iloc[row]
        forward_ = df.iloc[row + 1]

        # Compare all columns except 'T'
        if (current_.drop(labels='timestamp') == forward_.drop(labels='timestamp')).all():
            # Sum the T values
            df.at[row, 'timestamp'] += df.at[row + 1, 'timestamp']
            # Drop the next row (it's a duplicate)
            df.drop(index=row + 1, inplace=True)
            df.reset_index(drop=True, inplace=True)
            # Don't increment row since the next row may still be a duplicate
        else:
            row += 1
    
    return df

clean_df = remove_duplicates(df)

def getModuleData(width: float, height: float, LB_angle, LF_angle, RB_angle, RF_angle, LB_velocity, LF_velocity, RB_velocity, RF_velocity) -> str:
    os.chdir("../Motion Modelling/build")
    result = subprocess.run(["./motionmodel", 
              f"{width} {height} {LB_angle} {LF_angle} {RB_angle} {RF_angle} "
              f"{LB_velocity} {LF_velocity} {RB_velocity} {RF_velocity}"
              ])
    return result.stdout

for i in range(len(clean_df)):
    LB_angle = clean_df.at(i, 'LB_angle') #Fix AtIndex Error
    LF_angle = clean_df.at(i, 'LF_angle')
    RB_angle = clean_df.at(i, 'RB_angle')
    RF_angle = clean_df.at(i, 'RF_angle')
    LB_velocity = clean_df.at(i, 'LB_velocity')
    LF_velocity = clean_df.at(i, 'LF_velocity')
    RB_velocity = clean_df.at(i, 'RB_velocity')
    RF_velocity = clean_df.at(i, 'RF_velocity')

    print(f"LB_angle: {LB_angle}, LF_angle: {LF_angle}, "
          f"RB_angle: {RB_angle}, RF_angle: {RF_angle}, "
          f"LB_velocity: {LB_velocity}, LF_velocity: {LF_velocity}, "
          f"RB_velocity: {RB_velocity}, RF_velocity: {RF_velocity}")

    module_data = getModuleData(width, height, LB_angle, LF_angle, RB_angle, RF_angle, LB_velocity, LF_velocity, RB_velocity, RF_velocity)
    
    print(module_data)