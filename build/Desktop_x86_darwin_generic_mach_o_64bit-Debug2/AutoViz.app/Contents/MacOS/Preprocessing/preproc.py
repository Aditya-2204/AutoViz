import pandas as pd
import numpy as np
import sys

filePath: str = sys.argv[1]


df=pd.read_csv(filePath)

df['Robot-VX']=np.zeros(len(df))
df['Robot-VY']=np.zeros(len(df))
df['Robot-Rot']=np.zeros(len(df))

df = df.reset_index(drop=True)  # Ensure clean index
row = 0

while row < len(df) - 1:
    current = df.iloc[row].drop(labels="timestamp").values
    next_ = df.iloc[row + 1].drop(labels="timestamp").values

    if (current == next_).all():
        # Sum timestamps
        df.at[row, "timestamp"] += df.at[row + 1, "timestamp"]
        # Drop the next row
        df.drop(index=row + 1, inplace=True)
        df.reset_index(drop=True, inplace=True)  # Reindex after drop
        # Do NOT increment row: recheck same row with new next row
    else:
        row += 1  # Only move forward if rows were not merged

df.to_csv(filePath, index=False)
