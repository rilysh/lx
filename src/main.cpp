#include <string>
#include <iostream>
#include <filesystem>
#include <string_view>
#include <string_view>
#include <string>
#include "color.hpp"
#include "argh.h"
#include "icons.h"
#include <string>

using namespace std::string_literals;
namespace fs = std::filesystem;


inline auto get_permissions(const fs::perms p) -> const std::string {
  return 
    ((p & fs::perms::owner_read) != fs::perms::none   ? "r"s : "-"s)
  + ((p & fs::perms::owner_write) != fs::perms::none  ? "w"s : "-"s)
  + ((p & fs::perms::owner_exec) != fs::perms::none   ? "x"s : "-"s)
  + ((p & fs::perms::group_read) != fs::perms::none   ? "r"s : "-"s)
  + ((p & fs::perms::group_write) != fs::perms::none  ? "w"s : "-"s)
  + ((p & fs::perms::group_exec) != fs::perms::none   ? "x"s : "-"s)
  + ((p & fs::perms::others_read) != fs::perms::none  ? "r"s : "-"s)
  + ((p & fs::perms::others_write) != fs::perms::none ? "w"s : "-"s)
  + ((p & fs::perms::others_exec) != fs::perms::none  ? "x"s : "-"s);
}

auto main(int argc, const char** argv) -> int {

  argh::parser cmdl(argc, argv);
  const bool bRealpath= cmdl[{ "-r", "--realpath" }];
  const bool bDotfiles = cmdl[{ "-A", "-a", "--all" }];
  const bool bLong = cmdl[{ "-l", "--long" }];
  std::string path;
  path = cmdl.pos_args()[1];
  if(path.empty())
    path=".";

  if(fs::exists(path)){
    const auto kFile = fs::path(path);
    const auto kStatus = fs::status(kFile);
    const auto kType = kStatus.type();
    if(kType==fs::file_type::symlink){
      auto target = fs::read_symlink(kFile);

      if(bLong) std::cout << color::fg::LightGreen << get_permissions(kStatus.permissions()) << color::End << "  ";
      if(fs::is_directory(target)){
        // "
        if(bRealpath) std::cout << color::fg::LightBlue << "\uf482" << " " << kFile.string() << color::End << std::endl;
        else         std::cout << color::fg::LightBlue << "\uf482" << " " << kFile.filename().string() << color::End << std::endl;
      }
      else {
        // "
        if(bRealpath) std::cout << color::fg::LightBlue << "\uf481" << " " << kFile.string() << color::End << std::endl;
        else         std::cout << color::fg::LightBlue << "\uf481" << " " << kFile.filename().string() << color::End << std::endl;
      }
    }
    else if(kType==fs::file_type::directory){
      for (const auto & entry : fs::directory_iterator(kFile)){
        const auto krFile = entry.path(); //TODO: set all to use this for code clarity
        const auto krStatus = fs::status(krFile);
        const auto krType = krStatus.type();
        if(entry.path().filename().string().at(0)=='.'){
          if(!bDotfiles) continue;
        }
        if(bLong) std::cout << color::fg::LightGreen << get_permissions(kStatus.permissions()) << color::End << "  ";
        if(krType==fs::file_type::symlink){
          auto target = fs::read_symlink(entry.path());
          if(fs::is_directory(target)){
            // "
            if(bRealpath) std::cout << color::fg::LightBlue << "\uf402" << " " << entry.path().string() << color::End << std::endl;
            else         std::cout << color::fg::LightBlue << "\uf402" << " " << entry.path().filename().string() << color::End << std::endl;
          }
          else {
            // "
            if(bRealpath) std::cout << color::fg::LightBlue << "\uf401" << " " << entry.path().string() << color::End << std::endl;
            else         std::cout << color::fg::LightBlue << "\uf401" << " " << entry.path().filename().string() << color::End << std::endl;
          }
        }
        else if(krType==fs::file_type::directory){
          std::string icon_s;
          auto fIcon = kFoldermap.find(entry.path().filename().string());
          if(fIcon!=kFoldermap.end()) icon_s = fIcon->second;
          else                         icon_s = "\uf115";
          if(bRealpath) std::cout << color::fg::DarkCyan << icon_s << " " << entry.path().string() << color::End << std::endl;
          else         std::cout << color::fg::DarkCyan << icon_s << " " << entry.path().filename().string() << color::End << std::endl;
        }


        else if(krType==fs::file_type::regular){
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
          if(bRealpath) std::cout << color::fg::LightCyan << icon_s << " " << entry.path().string() << color::End << std::endl;
          else         std::cout << color::fg::LightCyan << icon_s << " " << entry.path().filename().string() << color::End << std::endl;
        }
        else if(krType==fs::file_type::fifo){
          // "
          if(bRealpath) std::cout << color::fg::LightBlue << "\uf731" << " " << entry.path().string() << color::End << std::endl;
          else         std::cout << color::fg::LightBlue << "\uf731" << " " << entry.path().filename().string() << color::End << std::endl;
        }


        else if(krType==fs::file_type::socket){
          // "
          if(bRealpath) std::cout << color::fg::LightBlue << "\uf6a7" << " " << entry.path().string() << color::End << std::endl;
          else         std::cout << color::fg::LightBlue << "\uf6a7" << " " << entry.path().filename().string() << color::End << std::endl;
        }


        else if(krType==fs::file_type::block){
          // ﰩ"
          if(bRealpath) std::cout << color::fg::LightBlue << "\ufc29" << " " << entry.path().string() << color::End << std::endl;
          else         std::cout << color::fg::LightBlue << "\ufc29" << " " << entry.path().filename().string() << color::End << std::endl;
        }



        /* else if(fs::is_special(entry.path())){ */
        /*     // " */
        /*   if(realpath) std::cout << color::fg::LightBlue << "\uf2dc" << " " << entry.path().string() << color::End << std::endl; */
        /*   else         std::cout << color::fg::LightBlue << "\uf2dc" << " " << entry.path().filename().string() << color::End << std::endl; */
        /* } */

        else if(krType==fs::file_type::character){
          // "
          if(bRealpath) std::cout << color::fg::LightBlue << "\ue601" << " " << entry.path().string() << color::End << std::endl;
          else         std::cout << color::fg::LightBlue << "\ue601" << " " << entry.path().filename().string() << color::End << std::endl;
        }

      }
    } else if(kType==fs::file_type::regular) {
      std::string icon_s;
      if(kFile.has_extension()){
        auto fIcon = kFullnameMap.find(kFile.extension().string());
        if(fIcon!=kFullnameMap.end()){
          icon_s = fIcon->second;
        }else{
          auto eIcon = kExtmap.find(kFile.extension().string());
          if(eIcon!=kExtmap.end()) icon_s = eIcon->second;
          else                    icon_s = "\uf15b";
        }
      }
      else{
        icon_s = "\uf016";
      }

      if(bLong) std::cout << color::fg::LightGreen << get_permissions(kStatus.permissions()) << color::End << "  ";
      if(bRealpath) std::cout << color::fg::LightCyan << icon_s << " " << kFile.string() << color::End << std::endl;
      else         std::cout << color::fg::LightCyan << icon_s << " " << kFile.filename().string() << color::End << std::endl;
    }


    else if(kType==fs::file_type::fifo){
      // "
      //
      if(bLong) std::cout << color::fg::LightGreen << get_permissions(kStatus.permissions()) << color::End << "  ";
      if(bRealpath) std::cout << color::fg::LightBlue << "\uf731" << " " << kFile.string() << color::End << std::endl;
      else         std::cout << color::fg::LightBlue << "\uf731" << " " << kFile.filename().string() << color::End << std::endl;
    }


    else if(kType==fs::file_type::socket){
      // "
      if(bLong) std::cout << color::fg::LightGreen << get_permissions(kStatus.permissions()) << color::End << "  ";
      if(bRealpath) std::cout << color::fg::LightBlue << "\uf6a7" << " " << kFile.string() << color::End << std::endl;
      else         std::cout << color::fg::LightBlue << "\uf6a7" << " " << kFile.filename().string() << color::End << std::endl;
    }


    else if(kType==fs::file_type::block){
      // ﰩ"
      if(bLong) std::cout << color::fg::LightGreen << get_permissions(kStatus.permissions()) << color::End << "  ";
      if(bRealpath) std::cout << color::fg::LightBlue << "\ufc29" << " " << kFile.string() << color::End << std::endl;
      else         std::cout << color::fg::LightBlue << "\ufc29" << " " << kFile.filename().string() << color::End << std::endl;
    }



    /* else if(fs::is_special(file)){ */
    /*     // " */
    /*   if(realpath) std::cout << color::fg::LightBlue << "\uf2dc" << " " << file.string() << color::End << std::endl; */
    /*   else         std::cout << color::fg::LightBlue << "\uf2dc" << " " << file.filename().string() << color::End << std::endl; */
    /* } */

    else if(kType==fs::file_type::character){
      // "
      if(bLong) std::cout << color::fg::LightGreen << get_permissions(kStatus.permissions()) << color::End << "  ";
      if(bRealpath) std::cout << color::fg::LightBlue << "\ue601" << " " << kFile.string() << color::End << std::endl;
      else         std::cout << color::fg::LightBlue << "\ue601" << " " << kFile.filename().string() << color::End << std::endl;
    }
  } else{
    std::cerr << argv[0] << ": "<< path <<": No such file or directory" << std::endl;
  }
  return 0;
}


