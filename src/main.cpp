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
  bool realpath= cmdl[{ "-r", "--realpath" }];
  std::string path;
  path = cmdl.pos_args()[1];
  if(path.empty())
    path=".";

  if(fs::exists(path)){
    auto file = fs::path(path);
    if(fs::is_symlink(file)){
      auto target = fs::read_symlink(file);
      if(fs::is_directory(target)){
        // "
        if(realpath) std::cout << color::fg::LightBlue << "\uf482" << " " << file.string() << color::End << std::endl;
        else         std::cout << color::fg::LightBlue << "\uf482" << " " << file.filename().string() << color::End << std::endl;
      }
      else {
        // "
        if(realpath) std::cout << color::fg::LightBlue << "\uf481" << " " << file.string() << color::End << std::endl;
        else         std::cout << color::fg::LightBlue << "\uf481" << " " << file.filename().string() << color::End << std::endl;
      }
    }
    else if(fs::is_directory(file)){
      for (const auto & entry : fs::directory_iterator(file)){
        if(fs::is_symlink(entry.path())){
          auto target = fs::read_symlink(entry.path());
          if(fs::is_directory(target)){
            // "
            if(realpath) std::cout << color::fg::LightBlue << "\uf402" << " " << entry.path().string() << color::End << std::endl;
            else         std::cout << color::fg::LightBlue << "\uf402" << " " << entry.path().filename().string() << color::End << std::endl;
          }
          else {
            // "
            if(realpath) std::cout << color::fg::LightBlue << "\uf401" << " " << entry.path().string() << color::End << std::endl;
            else         std::cout << color::fg::LightBlue << "\uf401" << " " << entry.path().filename().string() << color::End << std::endl;
          }
        }
        else if(fs::is_directory(entry.path())){
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
        else if(fs::is_fifo(entry.path())){
          // "
          if(realpath) std::cout << color::fg::LightBlue << "\uf731" << " " << entry.path().string() << color::End << std::endl;
          else         std::cout << color::fg::LightBlue << "\uf731" << " " << entry.path().filename().string() << color::End << std::endl;
        }


        else if(fs::is_socket(entry.path())){
          // "
          if(realpath) std::cout << color::fg::LightBlue << "\uf6a7" << " " << entry.path().string() << color::End << std::endl;
          else         std::cout << color::fg::LightBlue << "\uf6a7" << " " << entry.path().filename().string() << color::End << std::endl;
        }


        else if(fs::is_block_file(entry.path())){
          // ﰩ"
          if(realpath) std::cout << color::fg::LightBlue << "\ufc29" << " " << entry.path().string() << color::End << std::endl;
          else         std::cout << color::fg::LightBlue << "\ufc29" << " " << entry.path().filename().string() << color::End << std::endl;
        }



        /* else if(fs::is_special(entry.path())){ */
        /*     // " */
        /*   if(realpath) std::cout << color::fg::LightBlue << "\uf2dc" << " " << entry.path().string() << color::End << std::endl; */
        /*   else         std::cout << color::fg::LightBlue << "\uf2dc" << " " << entry.path().filename().string() << color::End << std::endl; */
        /* } */

        else if(fs::is_character_file(entry.path())){
          // "
          if(realpath) std::cout << color::fg::LightBlue << "\ue601" << " " << entry.path().string() << color::End << std::endl;
          else         std::cout << color::fg::LightBlue << "\ue601" << " " << entry.path().filename().string() << color::End << std::endl;
        }

      }
    } else if(fs::is_regular_file(path)) {
      std::string icon_s;
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


    else if(fs::is_fifo(file)){
      // "
      if(realpath) std::cout << color::fg::LightBlue << "\uf731" << " " << file.string() << color::End << std::endl;
      else         std::cout << color::fg::LightBlue << "\uf731" << " " << file.filename().string() << color::End << std::endl;
    }


    else if(fs::is_socket(file)){
      // "
      if(realpath) std::cout << color::fg::LightBlue << "\uf6a7" << " " << file.string() << color::End << std::endl;
      else         std::cout << color::fg::LightBlue << "\uf6a7" << " " << file.filename().string() << color::End << std::endl;
    }


    else if(fs::is_block_file(file)){
      // ﰩ"
      if(realpath) std::cout << color::fg::LightBlue << "\ufc29" << " " << file.string() << color::End << std::endl;
      else         std::cout << color::fg::LightBlue << "\ufc29" << " " << file.filename().string() << color::End << std::endl;
    }



    /* else if(fs::is_special(file)){ */
    /*     // " */
    /*   if(realpath) std::cout << color::fg::LightBlue << "\uf2dc" << " " << file.string() << color::End << std::endl; */
    /*   else         std::cout << color::fg::LightBlue << "\uf2dc" << " " << file.filename().string() << color::End << std::endl; */
    /* } */

    else if(fs::is_character_file(file)){
      // "
      if(realpath) std::cout << color::fg::LightBlue << "\ue601" << " " << file.string() << color::End << std::endl;
      else         std::cout << color::fg::LightBlue << "\ue601" << " " << file.filename().string() << color::End << std::endl;
    }
  } else{
    std::cerr << argv[0] << ": No such file or directory" << std::endl;
  }
  return 0;
}



