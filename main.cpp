//A text advanture about a person in a space ship
//
//Ending 1 Car starts
//Ending 2 explosion
//Ending 3 borked
#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;

string input;
int main()
{

  cout << "Well your here, on the side of the road in your car. It ran out of gas. Your car is not starting again and you have no cell service.\n";
  string input = "";
  short area      = 0; //0: inside car, 1: front of car, 2: behind car
  short itemlevel = -1; // 0: screw driver, 1: hammer, 2: crowbar, 3: gas can.
  short progress = 0; // 0: nothing, 1: glove box open, 2: trunk open, 3: hood open, 4: car refueled, 5: car started (ending 1), 6: engine explosion (ending 2), 7: wheel turns to dust (ending 3)
  for  ( ; progress < 5; )
  {
      input = "";
      cout << "type help for help\n";
      cout << ">"; 
      getline(cin, input);

      if ( input == "help")
      {
        cout << "help: shows this menu\n"; // logic done, tested
        cout << "look: describes the area around you.\n";
        cout << "goto: move about our car. (hood, cabin, trunk)\n"; // logic done, tested
        cout << "grab: pick somthing up\n"; //logic done, tested
        cout << "use: use somthing\n"; //logic done, tested
        cout << "pocket: what do you have on you.\n"; //logic done, tested
      }
      else if (input == "pocket dev") // hidden debug option
      {
        cout << "Item Level: " << itemlevel << "; Progress Level: " << progress << "; Area Code: " << area << ";\n";
      }
      // --------------------------------|| look command logic ||--
      else if (input == "look")
      {
        if (area==0) //cabin
        {
          cout << "Your sitting at the driver seat of your car. The foors have rusted out and show the asphalt below.\n";
          if (itemlevel==-1)
          {
            cout << "there is a screw driver stuck in the ignition of the car\n";
          }
          cout << "next to you, where the passanger seat would norammarly be (if you had not intergrated it into your couch at home!) is a glovebox with a keyhole.\n";
          if (progress > 0)
          {
            cout << "The glovebox is open\n";
            if (itemlevel < 3)
            {
              cout << "peering into the glovebox, you see a small rusted out hole leading the the engine bay, there is a large \"gas can\" of fuel on the other side of the whole.\n";
            }
            if (itemlevel < 1)
            {
              cout << "Laying inside of the glovebox, there is a hammer.\n";
            }
          }
          cout << "The steering wheel is basicly load baring at this point, this car has so many holes in it, that it actually imrpoves the gas milage from the reduced whight and drag. Also, smells like cigarettes and gas in here.\n";
        }
        else if (area==1) //hood
        {
          cout << "Your infront of your car, it has one pop up headlight and one regular headlight taped to the top.\n";
          if (progress >= 3)
          {
            cout << "The hood is now missing, again, you have a few spares at home you can use though. You can see clearly now into the engine bay.\n";
            if (itemlevel < 3)
            {
              cout << "On the firewall to the driver's cabin is a large rusted out hole housing \"gas can\". You must of forgoten it there somehow. It's lucky that it has not caused any trouble after driving for so long. \n";
            }
            
          }
          else
          {
            cout << "This hood has allways stood in the way of greatness, the latch is broken preventing the hood from opening. Though, a good prying would take care of that.\n";
          }
          cout << "The person you bought the engine from told you never to wack it with anything unless you wanted to die! The front license plate reads \"nuts\" \n";
        }
        else // trunk
        {
          cout << "This the the rear of the car, there are no tail lights as those fell off a few nights ago while tailgating somone.\n";
          if (progress >= 2)
          {
            cout << "The trunk is wide open, inside is decades full of garbage...\n";
            if (itemlevel < 2)
              cout << "...and a crowbar\n";
          }
          else
          {
            cout << "The trunk is closed, and would need a good wack to open\n";
          }
          cout << "The rear license plate reads \"deez\"\n";
        }
      }
      // --------------------------------|| pocket command logic ||
      else if (input == "pocket")
      {
        cout << "You have: \n";
        if (itemlevel >=0)
          cout << "flathead screwdriver\n";
        if (itemlevel >=1)
          cout << "A small hammer\n";
        if (itemlevel >=2)
          cout << "A red crowbar\n";
        if (itemlevel >=3)
          cout << "A \"gas can\" full of gasoline\n";
        if (itemlevel < 0)
          cout << "Nothing\n";
      }
      // --------------------------------|| use command logic ||---
      else if (input == "use hammer" && itemlevel == 1 && area == 2)
      {
        if (progress < 2 )
        {
          cout << "You take your trusty hammer and murmur the words \"It's hammering time\", your pure intimidation causes the trunk to open out of fear, works everytime.\n";
          progress++;
        }
      }
      else if ( input == "use hammer" && itemlevel >= 1 && area == 1 )
      {
        cout << "You use your hammer on the hood of your car, at first nothing happened. Then Everything was consumed my an explosion.\n";
        progress=6;
      }
      else if (input == "use screwdriver" && itemlevel >= 0 && area == 0)
      {
        if (progress == 0)
        {
          progress++;
          cout << "You wedge your red neck car keys between the glove box door and pry it open. \n";
        }
        else if (progress == 4)
        {
          progress++;
          cout << "you drive your glovebox opening tool into the car's ignition switch and turn. It starts up and you throw yourshit box in drive. A trail of oil romtanicly chases as you drive into the sunset.\n";
        }
        else
        {
          cout << "Screw that!\n";
        }
      }
      else if (input == "use crowbar" && itemlevel >= 2 && area == 1)
      {
        if (progress == 2)
        {
          cout << "You pry open the hood of your car, the hood flys open and is blown away by the wind. \n";
          progress++;
        }
        else
        {
          cout << "Maybe I would would if there was an alien invasion. Otherwise I can't really use that here! \n";
        }
      }
      else if (input == "use crowbar" && itemlevel >= 2 && area == 0)
      {
        cout << "You pry off your steering wheel; which, you should of not done. As it was the main load baring steering wheel.\n The whole car falls apart around you, I guess it's time to walk.\n";
        progress=7;
      }
      else if (input == "use gas can" && itemlevel >= 3)
      {
        if (progress==3)
        {
          cout << "You refuel your car, now there is only one last thing to do...\n";
          progress++;
        }
        else
        {
          cout << "You know how to start a car, right?\n";
        }
      }
      // --------------------------------|| goto command logic ||--
      else if (input == "goto cabin") 
      {
        if (area!=0)
        {
          cout << "You enter the cabin of the car.\n";
          area= 0;
        }
        else
        {
          cout << "But your already there!\n";
        }
      }
      else if(input == "goto hood")
      {
        if (area!=1)
        {
          cout << "You goto the front of your car\n";
          area=1;
        }
        else
        {
          cout << "But your already there!\n";
        }
      }
      else if(input == "goto trunk")
      {
        if (area!=2)
        {
          cout << "You goto the trunk of your car\n";
          area=2;
        }
        else
        {
          cout << "But your already there!\n";
        }
      }
//--------------------------------------|| grab logic || ----
      // Item locations: screwdriver: cabin, hammer: glove box, crowbar: trunk, gas can: engine bay (but can be seen from glove box via rusted out hole, but can grab it due to hole being too small)
      else if (input == "grab screwdriver" && progress == 0 && area == 0 && itemlevel == -1 )
      {
        cout << "You grab your car key/screw driver\n";
        itemlevel++;
      }
      else if (input == "grab hammer" && progress == 1 && area == 0 && itemlevel == 0 )
      {
        cout << "You grab the trunk key/hammer\n";
        itemlevel++;
      }
      else if( input == "grab crowbar" && progress == 2 && area == 2 && itemlevel == 1 )
      {
        cout << "You grab your crowbar\n";
        itemlevel++;
      }
      else if( input == "grab gas can" && progress == 3 && area == 1 && itemlevel == 2 ) 
      {
        cout << "You grab a milk jug full of gasolene\n";
        itemlevel++;
      }
      else if( input == "grab gas can" && progress <= 1 && area == 0 && itemlevel <= 2)
      {
        cout << "You can grab the milk jug full of gasolene, but it does not fit through the rusted out hole.\n";
      }
//--------------------------------------|| invalid input ||--      
      else
      {
        cout << "I don't understand!\n";
      }
  }

  return 0;
}
