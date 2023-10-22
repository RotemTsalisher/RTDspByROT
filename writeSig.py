import numpy as np

x = np.random.uniform(-1, 1,4) + 1.j * np.random.uniform(-1, 1,4)
path = "sigs.txt"

with open(path , "w") as txt_file:
    txt_file.write("x = " + str(x))
    
