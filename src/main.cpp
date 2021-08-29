#include <cstdio>
#include <string>
#include <iostream>
#include <filesystem>
#include <string_view>
#include "color.hpp"
#include "argh.h"
#include "icons.hpp"

namespace fs = std::filesystem;

auto main(int argc, const char** argv) -> int {

  argh::parser cmdl(argc, argv);
  bool realpath=false;
  if (cmdl[{ "-r", "--realpath" }])
    realpath = true;
  std::string path;
  path = cmdl.pos_args()[1];
  if(path.empty())
    path=".";

  if(fs::exists(path)){
    if(fs::is_directory(path)){
    for (const auto & entry : fs::directory_iterator(path))
      if(fs::is_directory(entry.path())){
        std::string icon_s;
        auto fIcon = kFullnameMap.find(entry.path().filename().string());
        if(fIcon!=kFullnameMap.end()) icon_s = fIcon->second;
        else                         icon_s = "\uf115";
        if(realpath) std::cout << color::fg::DarkCyan << icon_s << " " << entry.path().string() << color::End << std::endl;
        else         std::cout << color::fg::DarkCyan << icon_s << " " << entry.path().filename().string() << color::End << std::endl;
      }


      else if(fs::is_regular_file(entry.path())){
        std::string icon_s;
        if(entry.path().has_extension()){
          auto fIcon = kFullnameMap.find(entry.path().extension().string());
          if(fIcon!=kFullnameMap.end()){
            icon_s = fIcon->second;
          }else{
            auto eIcon = kExtmap.find(entry.path().extension().string());
            if(eIcon!=kExtmap.end()) icon_s = eIcon->second;
            else                    icon_s = "\uf15b";
          }
        }
        else{
          icon_s = "\uf016";
        }
        if(realpath) std::cout << color::fg::LightCyan << icon_s << " " << entry.path().string() << color::End << std::endl;
        else         std::cout << color::fg::LightCyan << icon_s << " " << entry.path().filename().string() << color::End << std::endl;
      }
    } else {

        std::string icon_s;
        auto file = fs::path(path);
        if(file.has_extension()){
          auto fIcon = kFullnameMap.find(file.extension().string());
          if(fIcon!=kFullnameMap.end()){
            icon_s = fIcon->second;
          }else{
            auto eIcon = kExtmap.find(file.extension().string());
            if(eIcon!=kExtmap.end()) icon_s = eIcon->second;
            else                    icon_s = "\uf15b";
          }
        }
        else{
          icon_s = "\uf016";
        }
        if(realpath) std::cout << color::fg::LightCyan << icon_s << " " << file.string() << color::End << std::endl;
        else         std::cout << color::fg::LightCyan << icon_s << " " << file.filename().string() << color::End << std::endl;
      }
  } else{
    std::cerr << argv[0] << ": No such file or directory" << std::endl;
  }
  return 0;
}



