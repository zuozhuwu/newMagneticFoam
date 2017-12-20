
torque = 0;                   //reset torque

fluxLinkage_m = 0;

forAll(faceCentres, facei)
{
    scalar x = faceCentres[facei].x();
    scalar y = faceCentres[facei].y();
    scalar z = faceCentres[facei].z();

    if(z >= m_z0 && z <= m_z1 )
    {
        theta = std::atan(y/x);

        theta_m -= int(theta_m/subMotorAngle) * subMotorAngle;			
		
        theta -= theta_m;

        theta  = (theta < 0) ? (theta + subMotorAngle) : theta;

        nth = int(theta / m_theta_m);

        r = std::sqrt(x*x + y*y);			

        vector orientationi = vector(x, y, 0);

        if(r - m_distance_outter < delt_mesh_error_max &&
           m_distance_outter - r < delt_mesh_error_max)
        {
            if(theta - (startAngle_m + nth) * m_theta_m <= deltThetaMax &&
               theta - (startAngle_m + nth) * m_theta_m >= -1 * deltThetaMax)
            {
                fluxLinkage_m += fabs((B[facei] & orientationi) * (magSf[facei] ) );                      
            }
        }
    }
}

//Info<<"currency: "<< I<<nl;

//Info<<"fluxlinkage: "<<fluxLinkage_m<<nl;

torque = 1.5 * m_poles/2 * I * fluxLinkage_m;

for(int8_t i = 0; i < m_coil ; i++)
{
    scalar i_phase = 0;

    if(i == 8 || i == 0 || i == 1)
        i_phase = Iu;
    else if(i == 2 || i == 3 || i == 4)
        i_phase = Iv;
    else if(i == 5 || i == 6 || i == 7)
        i_phase = Iw;

    //torque += (0.5 * i_phase * i_phase * (inductance_now[i] - inductance_passed[i]) / (runTime.deltaTValue() * m_theta_c ));
}
