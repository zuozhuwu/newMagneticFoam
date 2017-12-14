#define pi 3.1415926

scalar m_num = 8;      //number of  sub motors

scalar m_magnetic = 8;   //number of magnetics in a sub motor 

scalar m_coil = 9;      //number of coil in a sub motor

scalar m_L = 58.5e-3;     //the lenght of magnetic

scalar m_W = 16.5e-3;     //the width of magnetic

scalar m_H = 5e-3;        //the height of magnetic

scalar m_distance_outter = 181e-3;   //the distance from magnetic to origin(0 0 0)

scalar m_distance_inner = 151e-3;   //the stator back iron inner radius 

scalar m_z0 = 0;        //magnetic z axis position

scalar m_z1 = m_L;

scalar Mri = 860000;       //Mr of magnetic

scalar Muri = 1000;       //Mur for ferriteDefine

scalar thickIron = 6.2e-3;    //the thickness of outer iron

scalar airGap = 1e-3;

scalar thickTT = 1e-3;        //the thickness of tooth tip

scalar deptSlot = 23e-3;         //slot depth

scalar slotOpening = 5e-3;       //slot opening

scalar slotBottomWidth = 6.87e-3;  //slot bottom width

scalar startAngle_m = 0.5;    //the angle of axis of first magnet devided by m_theta_m (delta theta between two magnetics)

scalar startAngle_c = 0;    //the angle of axis of first coil devided by m_theta_c (delta theta between two coils)
