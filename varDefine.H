#define pi 3.1415926

scalar m_poles = 64;    //number of poles

scalar m_num = 8;      //number of  sub motors

uint8_t m_magnetic = 8;   //number of magnetics in a sub motor 

uint8_t m_coil = 9;      //number of coil in a sub motor

scalar m_L = 58.5e-3;     //the lenght of magnetic

scalar m_W = 16.5e-3;     //the width of magnetic

scalar m_H = 5e-3;        //the height of magnetic

scalar m_distance_outter = 181e-3;   //the distance from magnetic to origin(0 0 0)

scalar m_distance_inner = 151e-3;   //the stator back iron inner radius 

scalar m_turns = 32;

scalar m_z0 = 0;        //magnetic z axis position

scalar m_z1 = m_L;

scalar Mri = 1060000;       //Mr of magnetic

scalar Muri = 1000;       //Mur for ferriteDefine

scalar thickIron = 6.2e-3;    //the thickness of outer iron

scalar airGap = 1e-3;

scalar thickTT = 1e-3;        //the thickness of tooth tip

scalar deptSlot = 25e-3;         //slot depth

scalar slotOpening = 5e-3;       //slot opening

scalar slotBottomWidth = 6.87e-3;  //slot bottom width

scalar startAngle_m = 0.5;    //the angle of axis of first magnet devided by m_theta_m (delta theta between two magnetics)

scalar startAngle_c = 0;    //the angle of axis of first coil devided by m_theta_c (delta theta between two coils)


/////////////////////////////////////////////////////
	
scalar subMotorAngle =  2 * pi/m_num;

scalar m_theta_m = subMotorAngle/m_magnetic;    //delta theta between two magnetics

const surfaceVectorField& faceCentres = mesh.Cf();

const surfaceVectorField& Sf = mesh.Sf();

scalar theta = 0.0;

scalar r = 0.0;

int nth = 1;     //the nth magnetic

scalar deltThetaMax = m_W / m_distance_outter / 2;	

scalar theta_m = 0;       //rotating angle 

scalar theta_e = 0;  

scalar omiga = 0;       //the rotating speed, rpm

scalar fluxLinkage_m = 0;   //the Permanent magnets flux linkage

scalar I = 0.0;

scalar Iu = 0.0;

scalar Iv = 0.0;

scalar Iw = 0.0;

scalar coeff_I2Mr = m_turns * Muri / deptSlot;

scalar m_theta_c = subMotorAngle/m_coil;        //delta theta between two coils

scalar distanceSlotBottom = m_distance_outter - airGap - thickTT - deptSlot;

scalar angleDeltSlotTopMax = (m_theta_c - slotOpening / (m_distance_outter - airGap) )/2.0;

scalar angleDeltSlotBottomMax = (slotBottomWidth / distanceSlotBottom) / 2.0;

auto inductance_now= new scalar[m_coil];

auto inductance_passed= new scalar[m_coil];    //

scalar torque = 0;          //the output torque

scalar voltage = 0;       //the sum of the three phases voltage

scalar resistance = 0.26;   //the phase resistance per sub-motor

scalar delt_mesh_error_max = 1e-4;      //set the mesh error max, used for calc inductance

scalar hysteresis_torque = 5;         //N.m, the torque induced by friction between stator and rator 
