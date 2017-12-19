
if(I == 0)
{
    for(auto iI = 0; iI < m_coil; iI++)
    {
        inductance_now[iI] = 0;
    }
}
else
{

    if(runTime.value() != 0)   //not the first time
    {
       inductance_passed = inductance_now; 
    }

    forAll(faceCentres, facei)
    {   
	    scalar x = faceCentres[facei].x();
    	scalar y = faceCentres[facei].y();
	    scalar z = faceCentres[facei].z();


    	if(z >= m_z0 && z <= m_z1 )
	    {
    		theta = std::atan(y/x);	
    
		    theta += 0.5 * m_theta_c;       //rotating half m_theta_c, because the first coil is devided to two parts

	    	theta = (theta >= subMotorAngle) ? (theta - subMotorAngle) : theta;

    		r = std::sqrt(x*x + y*y);

    		nth = int(theta / m_theta_c);

            if(abs(r - (m_distance_outter - airGap) ) < delt_mesh_error_max)
            {
            
    			if(abs(theta - (startAngle_c + nth + 0.5) * m_theta_c) <= angleDeltSlotTopMax)      //+0.5 because of rotating
                {
                    vector orientationi = vector(0, 0, 0);

                    if(nth == 0 || nth == 3 || nth == 5 || nth == 7 )
                    {	
                        orientationi = vector(-1 * x / r, -1 * y / r, 0);                    
                    }
                    else if(nth == 1 || nth == 2 || nth == 4 || nth == 6 || nth == 8)
                    {
                        orientationi = vector(x / r, y / r, 0);
                    }

                    scalar I_phase = 0;

                    if(nth == 8 || nth == 0 || nth == 1)
                        I_phase = Iu;
                    else if(nth == 2 || nth == 3 || nth == 4)
                        I_phase = Iv;
                    else if(nth == 5 || nth == 6 || nth == 7)
                        I_phase = Iw;

                    inductance_now[nth] += (B[facei] & orientationi) * abs(Sf[facei] & orientationi) * m_coil / I_phase;      

                }
            
            }

        }

    }

}
