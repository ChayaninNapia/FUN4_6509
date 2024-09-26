# FUN4_6509
## Part 1: Setup Environment
### 1.หา workspace ของแขนกลพร้อมวิธีการตรวจสอบคําตอบ (1 คะแนน)
- คำนวณสมการ inverse kinematic ของ หุ่นยนต์เพื่อตรวจสอบ task workspace
  - หา q1
<img src="img/q1_find.jpeg" alt="Alt Text for the Image" width="500" />
      - เนื่องจาก ปลายแขน เทียบกับ link 0 origin ของ end-effector จะมี offset แกน z ไป -0.02 ดังนั้นจึงต้องบวกมุมกลับเข้าไปถึงจะทำให้หุ่นหันหน้าตรงถูก
<img src="img/q1_extra.jpeg" alt="Alt Text for the Image" width="500" />
      - หา q2
<img src="img/q2_find.jpeg" alt="Alt Text for the Image" width="700" />
      - หา q3
<img src="img/q3_find.jpeg" alt="Alt Text for the Image" width="600" />
      - มุมที่หา เป็นมุมที่เทียบกับแกน X แต่ ต้องทำให้เป็นเทียบกับแกน Z เพื่อให้ตรงกับ joint ของ urdf
<img src="img/q3_extra.jpeg" alt="Alt Text for the Image" width="600" />
    - ค่า X <= l3 + l5, Y <= l3 + l5, Z <= l1 + l3 +l5
      <img src="img/boundary.jpeg" alt="Alt Text for the Image" width="500" />
      
#### ตรวจคำตอบด้วย robotictoolbox


```python
# Add your Python code here
import roboticstoolbox as rtb
from math import pi
import numpy as np
from spatialmath import SE3

l1 = 0.2    # 200 mm
l2 = 0.06   # 60 mm
l3 = 0.25   # 250 mm
l4 = 0.1    # 100 mm
l5 = 0.28   # 280 mm

robot = rtb.DHRobot(
    [
        rtb.RevoluteMDH(d=l1, alpha=0, offset=0), 
        rtb.RevoluteMDH(alpha=-pi/2, offset=-pi/2),  
        rtb.RevoluteMDH(a=l3, d=-0.02, offset=pi/2), 
        rtb.RevoluteMDH(alpha=pi/2, d=l5, offset=0) 
    ],
    name="robot"    
)
q_initial = [0.970, 0.595, 1.411, 0]
T_0e = robot.fkine(q_initial)

'''for display'''
# robot.plot(q_initial)
# print("Forward Kinematics (T_0e):")
# print(T_0e)
# print(robot)

def ikine_find(desired_pose,s):
    solution = robot.ikine_LM(desired_pose)

    if solution.success:
        q_ik = solution.q
        print("Inverse Kinematics converge Solution:")
        print(q_ik)
        T_verification = robot.fkine(q_ik)
        print("Verification :")
        print(T_verification)
        robot.plot(q_ik)
    else:
        print(s)
        print("Inverse Kinematics did not converge to a solution.")
        print()
        
#case 1 X <= l3 + l5
ikine_find(SE3(l3+l5+1.0, -0.02, 0.73),'case 1: X <= l3 + l5')
#case 2 Y <= l3 + l5
ikine_find(SE3(0.0, l3+l5+1.0, 0.73),'case 2: Y <= l3 + l5')
#case 3 Z <= l1 + l3 + l5
ikine_find(SE3(0.0, -0.02, l1 + l3 + l5 + 1),'case 3: Z <= l1 + l3 + l5')
#case 4  0.0009  <= x^2 + z^2 <= 0.2809 
ikine_find(SE3(l3+l5+1.0, -0.02, 0.73),'case 4:  0.0009  <= x^2 + z^2 <= 0.2809')
#case 4 reachable
ikine_find(SE3(0.0, -0.02, 0.73),'case 4:')

```
```sh
case 1: X <= l3 + l5
Inverse Kinematics did not converge to a solution.

case 2: Y <= l3 + l5
Inverse Kinematics did not converge to a solution.

case 3: Z <= l1 + l3 + l5
Inverse Kinematics did not converge to a solution.

case 4:  0.0009  <= x^2 + z^2 <= 0.2809
Inverse Kinematics did not converge to a solution.

Inverse Kinematics converge Solution:
[-0.13695534  0.01058346 -0.01058348  0.13695546]
Verification :
   1        -1.201e-07 -1.896e-08 -0.0001095  
   1.201e-07  1         2.613e-09 -0.02017   
   1.896e-08 -2.613e-09  1         0.73      
   0         0         0         1       
```

### plot workpace with rviz marker
 <img src="img/workspace_plot1.png" alt="Alt Text for the Image" width="500" />
      
