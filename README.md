# FUN4_6509
## Part 1: Setup Environment
- 1.หา workspace ของแขนกลพร้อมวิธีการตรวจสอบคําตอบ (1 คะแนน)
  - คำนวณสมการ inverse kinematic ของ หุ่นยนต์เพื่อตรวจสอบ task workspace
      - หา q1
<img src="img/q1_find.jpeg" alt="Alt Text for the Image" width="500" />
      - เนื่องจาก ปลายแขน เทียบกับ link 0 origin ของ end-effector จะมี offset แกน z ไป -0.02 ดังนั้นจึงต้องบวกมุมกลับเข้าไปถึงจะทำให้หุ่นหันหน้าตรงถูก
<img src="img/q1_extra.jpeg" alt="Alt Text for the Image" width="500" />

