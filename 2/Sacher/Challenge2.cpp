#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
struct Mission
{
    std::string type = "";
    int playerCount = 0;
    std::string name = "";
    int version = 0;
    bool isValid = false;
    std::string fullName = "";
    bool operator<(const Mission& r) 
    {
        return  playerCount < r.playerCount;
      /*  if(std::string(type) == std::string(r.type))
            
        else
            return std::string(type) < std::string(r.type);*/
    }
};

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

Mission parseMission(std::string name)
{
    std::vector<std::string> allowedTypes{"COTVT","CO","TVT","LOL"}; //order matters
    Mission parsedMission;
    parsedMission.fullName = name;
    for(std::string type:allowedTypes)
    {
        if(name.find(type) == 0)
        {
            parsedMission.type = type;
            name.erase(0,type.length());
            std::cout << name << "\n";
            break;
        }
    }
    if(parsedMission.type == "")
    {
       
        std::cout << " does not have a valid type!";
        return parsedMission;
    }
    
    int firstUnderscoreIndex = name.find("_");
    // 0< playercount < 1000
    if(firstUnderscoreIndex == 0)
    {
         
        std::cout << " playercount is too short!";
        return parsedMission;
    }
    std::string playerCountString = name.substr(0,firstUnderscoreIndex);
     std::cout << playerCountString << "\n";
    if(is_number(playerCountString))
    {
        parsedMission.playerCount = atoi(playerCountString.c_str());
        name.erase(0,playerCountString.length() + 1); //remove first _
        std::cout << name << "\n";
    }
    else
    {
        std::cout  << " playercount is not a proper number!";
        return parsedMission;
    }
    
    //
    int pboIndex = name.find(".pbo");
    if(pboIndex < 1 || pboIndex + std::string(".pbo").length() != name.length())
    {
         std::cout << " .pbo is not at the correct location!";
         return parsedMission;
    }
    name.erase(pboIndex,4);
    int versionNumberIndex = -1;
    for(int i = name.length() -1 ; i >= 0;i--)
    {
        if(!isdigit(name[i]))
        {
            versionNumberIndex = i;
            if(!(name[i] == 'v' || name[i] == 'V'))
            {
                  std::cout << " versionnumber V is not placed correctly!";
                  return parsedMission; 
            }
            break;
        }
    }
    if(versionNumberIndex == -1 || versionNumberIndex + 1 == name.length() || versionNumberIndex == 0)
    {    
         std::cout << " versionnumber is malformed!";
         return parsedMission; 
    }
    std::string versionNumberString = name.substr(versionNumberIndex +1,name.length() - versionNumberIndex -1);
    std::cout << versionNumberString << std::endl;
    if(is_number(versionNumberString))
    {
        parsedMission.version = atoi(versionNumberString.c_str());
        name.erase(versionNumberIndex,versionNumberString.length() + 1); //remove Vxx
        std::cout << name << "\n";
    }
    else
    {
        std::cout << " versionNumber is not a number!";
        return parsedMission;
    }
    
    if(name.length() == 0)
    {
        std::cout << " no missionName!";
        return parsedMission;
    }
    if(name[name.length() -1] != '_')
    {
         std::cout << " missionName missing _!";
         return parsedMission;
    }
    name.erase(name.length() -1,1);
    std::cout << name << "\n";
    parsedMission.name = name;
    parsedMission.isValid = true;
    
    return parsedMission;
}

std::vector<std::string> removeOldMissions(std::vector<std::string> missions) 
{
   
       std::map<std::string,Mission> parsedMissions;
        for(std::string mission : missions)
        {
            if(mission.length() == 0) continue;
            Mission mis = parseMission(mission);
            if(mis.isValid)
            {
                 auto searchName = parsedMissions.find(mis.type + std::to_string(mis.playerCount)+ mis.name);
                 if (searchName != parsedMissions.end()) 
                 {
                     if(searchName->second.version < mis.version)
                     {
                         searchName->second = mis;
                     }
                 }
                else
                {
                    parsedMissions.insert(std::make_pair(mis.type + std::to_string(mis.playerCount)+ mis.name, mis ));
                }

            }

        }
        std::vector<Mission> validMissions;
        for(std::map<std::string,Mission>::iterator it = parsedMissions.begin(); it!=parsedMissions.end(); ++it)
        {
           validMissions.push_back(it->second);
        }
        std::sort(validMissions.begin(),validMissions.end());
        std::vector<string> names;
        for(auto x : validMissions)
        {
            names.push_back(x.fullName);
        }
        return names;
   
}

