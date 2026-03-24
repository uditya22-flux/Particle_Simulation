#include<iostream>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std ;

class particle 
{ public : 
    double mass;
    double velocity ;
    int particle_id ;
    double x , y ;
    double vx , vy ;


    public :
    void storedata(double m , double v, int id)
       {

        mass = m ;
        velocity = v ;
        particle_id = id ;
          }

 double  kinetic_energy()
    { 
        
        return 0.5*mass*velocity*velocity ;

     }

 void show_details()
   
 {
         cout<<"\n" ;
         cout<<left<<setw(10)<<particle_id<<"\t";

        cout<<left<<setw(10)<<mass <<"\t"  ;

         cout<<left<<setw(10)<<velocity <<"\t" ;

       
        cout<<left<<setw(10)<<kinetic_energy() <<"\t";
}




};

bool compare(particle a , particle b)
{
    return a.kinetic_energy() > b.kinetic_energy() ;
}



int main ()
{

    srand(time(0)) ;
    int n=10,i=0,high =0 ;
    int count =0 ;
    double  TOTAL_ENERGY = 0 ,AVERAGE_ENERGY = 0;
    vector<particle> particles;

   

    //storing the details of particles


for(i=0 ;i<n ;i++)
    {
        particle p ;
       
        p.particle_id = i+1 ;
        p.mass = rand() % 10+1;
        p.velocity = rand()% 10 +1 ;

        p.x =rand()%10;
        p.y=rand()%10 ;
        p.vx=rand()%3-1;
        p.vy=rand()%3-1 ;

         particles.push_back(p) ;
       

        }



        //displaying the details of particles

    cout<<"---------------PARTICLE DETAILS------------------\n" ;


         cout<<left<<setw(10)<<"ID \t";   
        cout<<left<<setw(10)<<"MASS \t" ;
        
        cout<<left<<setw(10)<<"VELOCITY \t" ;

         cout<<left<<setw(10)<<"KINETIC ENERGY \t" ;


for(i=0;i<n;i++)
   
   {
     particles[i].kinetic_energy();
    particles[i].show_details() ;
   }
cout<<"\n";
   cout<<"---------------------------------------------------\n" ;



   //calculating total energy and average energy
  for(i=0;i<n;i++)
  {
   TOTAL_ENERGY+=particles[i].kinetic_energy() ;
  }

   cout<<"\n TOTAL ENERGY = "<<TOTAL_ENERGY<<"\n" ;

   AVERAGE_ENERGY = TOTAL_ENERGY/n ;

   cout<<showpoint<<setprecision(4)<<"\nAVERAGE ENERGY = "<<AVERAGE_ENERGY<<"\n" ;

   cout<<"\n" ;
   cout<<"---------------------------------------------------\n";
   cout<<"\n" ;

   
    for(i=0 ;i<n;i++)  
    {                      
if (particles[i].kinetic_energy() > 100)
{
cout<<"Particle "<<particles[i].particle_id<<"  ----  "<<particles[i].kinetic_energy()<<"\n" ;

count++ ;}

else 
  {
    continue ;
  }
    }
cout<<"\n" ;
cout<<"---------------------------------------------------\n";

cout<<"Total number of particles with kinetic energy > 100: "<<count<<"\n" ;

cout<<"---------------------------------------------------\n";


   sort (particles.begin() , particles.end() , compare ) ;

cout<<"\n" ;

   for(i=0;i<3;i++)
   {
    cout<<"Particle "<<i+1<<" Total energy : " << particles[i].kinetic_energy()<<"\n" ;
   }
   cout<<"\n" ;

cout<<"---------------------------------------------------\n";

                      



cout<<"---------------------------------------------------\n";

//  (2D simulation)


    //grid making 

    for(i=0;i<10;i++)
    {
        particle pos ;
      for(int j=0;j<10;j++)
      {

        if (i==pos.y && j==pos.x)
        cout<<"P" ;

        else 
        cout<<".";
       
      }

       cout<<"\n" ;
    }


    return 0 ;

}





