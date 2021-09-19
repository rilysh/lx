#include <iomanip>
#include <iostream>
#include <filesystem>
#include <string>
#include <cmath>
#include "color.hpp"
#include "argh.h"
#include "icons.h"

using namespace std::string_literals;
namespace fs = std::filesystem;

#define KeyColor color::fg::DarkCyan
#define DiskColor color::fg::LightWhite

struct HumanReadable {
  std::uintmax_t size{};
  private: friend
           inline std::ostream& operator<<(std::ostream& os, HumanReadable hr) {
             int i{};
             double mantissa = hr.size;
             for (; mantissa >= 1024.; mantissa /= 1024., ++i) { }
             mantissa = std::ceil(mantissa * 10.) / 10.;
             os << std::setprecision(3) << mantissa << ' ' << "BKMGTPE"[i];
             return i == 0 ? os : os;
           }
};


struct Permission{
  fs::perms p{};
  private: friend
           inline std::ostream& operator<<(std::ostream& os, Permission pp) {
             os << color::fg::DarkGreen  << ((pp.p & fs::perms::owner_read)  != fs::perms::none ? "r" : "-") 
               << color::fg::DarkYellow << ((pp.p & fs::perms::owner_write)  != fs::perms::none ? "w" : "-")
               << color::fg::DarkRed    << ((pp.p & fs::perms::owner_exec)   != fs::perms::none ? "x" : "-")
               << color::fg::DarkGreen  << ((pp.p & fs::perms::group_read)   != fs::perms::none ? "r" : "-")
               << color::fg::DarkYellow << ((pp.p & fs::perms::group_write)  != fs::perms::none ? "w" : "-")
               << color::fg::DarkRed    << ((pp.p & fs::perms::group_exec)   != fs::perms::none ? "x" : "-")
               << color::fg::DarkGreen  << ((pp.p & fs::perms::others_read)  != fs::perms::none ? "r" : "-")
               << color::fg::DarkYellow << ((pp.p & fs::perms::others_write) != fs::perms::none ? "w" : "-")
               << color::fg::DarkRed    << ((pp.p & fs::perms::others_exec)  != fs::perms::none ? "x" : "-") << color::End;
             return os;
           }
};


/* using enum fs::file_type; */ // for c++20

auto main(int argc, const char** argv) -> int {

  argh::parser cmdl(argc, argv);
  const bool bRealpath= cmdl[{ "-r", "--realpath" }];
  const bool bDotfiles = cmdl[{ "-A", "-a", "--all" }];
  const bool bLong = cmdl[{ "-l", "--long" }];
  std::string path;
  /* if(cmdl.pos_args().size()<=1) path="."; */
  /* else                          path = cmdl.pos_args()[1]; */

  const bool many_path = !(cmdl.pos_args().size()<=1);
  for(size_t i=many_path;i<cmdl.pos_args().size();i++){
    path=(many_path)?cmdl.pos_args().at(i):".";
    if(fs::exists(path)){
      const auto kFile = fs::path(path);
      const auto kStatus = fs::status(kFile);
      const auto kType = kStatus.type();
      if(kType==fs::file_type::symlink){
        auto target = fs::read_symlink(kFile);

        if(bLong) {
          std::cout << KeyColor << "l"  << Permission{kStatus.permissions()} << "  ";
        }
        if(fs::is_directory(target)){
          // "
          if(bLong) std::cout << "000 B" << "\t";
          if(bRealpath) std::cout << color::fg::LightBlue << "\uf482" << " " << kFile.string() << color::End << std::endl;
          else         std::cout << color::fg::LightBlue << "\uf482" << " " << kFile.filename().string() << color::End << std::endl;
        }
        else {
          // "
          if(bLong) std::cout << HumanReadable{fs::file_size(kFile)} << "\t";
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
          if(krType==fs::file_type::symlink){
            auto target = fs::read_symlink(entry.path());
            if(bLong){
              std::cout << KeyColor << "l" << Permission{krStatus.permissions()} << "  ";
            }
            if(fs::is_directory(target)){
              // "
              if(bLong) std::cout << DiskColor << "000 B" << color::End << "\t";
              if(bRealpath) std::cout << color::fg::LightBlue << "\uf402" << " " << entry.path().string() << color::End << std::endl;
              else         std::cout << color::fg::LightBlue << "\uf402" << " " << entry.path().filename().string() << color::End << std::endl;
            }
            else {
              // "
              if(bLong) std::cout << DiskColor << HumanReadable{entry.file_size()} << color::End << "\t";
              if(bRealpath) std::cout << color::fg::LightBlue << "\uf401" << " " << entry.path().string() << color::End << std::endl;
              else         std::cout << color::fg::LightBlue << "\uf401" << " " << entry.path().filename().string() << color::End << std::endl;
            }
          }
          else if(krType==fs::file_type::directory){
            if(bLong){
              std::cout << KeyColor << "d" << Permission{kStatus.permissions()} << "  " << DiskColor << "000 B" << color::End << "\t";
            }
            std::string icon_s;
            auto fIcon = kFoldermap.find(entry.path().filename().string());
            if(fIcon!=kFoldermap.end()) icon_s = fIcon->second;
            else                         icon_s = "\uf115";
            if(bRealpath) std::cout << color::fg::DarkCyan << icon_s << " " << entry.path().string() << color::End << std::endl;
            else         std::cout << color::fg::DarkCyan << icon_s << " " << entry.path().filename().string() << color::End << std::endl;
          }


          else if(krType==fs::file_type::regular){
            if(bLong){
              std::cout << KeyColor << "." << Permission{kStatus.permissions()} << "  " << DiskColor << HumanReadable{entry.file_size()} << color::End << "\t";
            }
            std::string icon_s;
            if(entry.path().has_extension()){
              auto fIcon = kFullnameMap.find(entry.path().filename().string());
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
            if(bLong){
              std::cout << KeyColor << "p" << Permission{kStatus.permissions()} << "  " << DiskColor << HumanReadable{entry.file_size()} << color::End << "\t";
            }
            if(bRealpath) std::cout << color::fg::LightBlue << "\uf731" << " " << entry.path().string() << color::End << std::endl;
            else         std::cout << color::fg::LightBlue << "\uf731" << " " << entry.path().filename().string() << color::End << std::endl;
          }


          else if(krType==fs::file_type::socket){
            // "
            if(bLong){
              std::cout << KeyColor << "s" << Permission{kStatus.permissions()} << "  " << DiskColor << HumanReadable{entry.file_size()} << color::End << "\t";
            }
            if(bRealpath) std::cout << color::fg::LightBlue << "\uf6a7" << " " << entry.path().string() << color::End << std::endl;
            else         std::cout << color::fg::LightBlue << "\uf6a7" << " " << entry.path().filename().string() << color::End << std::endl;
          }


          else if(krType==fs::file_type::block){
            // ﰩ"
            if(bLong){
              std::cout << KeyColor << "b" << Permission{kStatus.permissions()} << "  " << DiskColor << HumanReadable{entry.file_size()} << color::End << "\t";
            }
            if(bRealpath) std::cout << color::fg::LightBlue << "\ufc29" << " " << entry.path().string() << color::End << std::endl;
            else         std::cout << color::fg::LightBlue << "\ufc29" << " " << entry.path().filename().string() << color::End << std::endl;
          }


          else if(krType==fs::file_type::character){
            // "
            if(bLong){
              std::cout << KeyColor << "c" << Permission{kStatus.permissions()} << "  " << DiskColor << HumanReadable{entry.file_size()} << color::End << "\t";
            }
            if(bRealpath) std::cout << color::fg::LightBlue << "\ue601" << " " << entry.path().string() << color::End << std::endl;
            else         std::cout << color::fg::LightBlue << "\ue601" << " " << entry.path().filename().string() << color::End << std::endl;
          }

        }
      } else if(kType==fs::file_type::regular) {
        std::string icon_s;
        if(kFile.has_extension()){
          auto fIcon = kFullnameMap.find(kFile.filename().string());
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

        if(bLong){
          std::cout << KeyColor << "." << Permission{kStatus.permissions()} << "  " << DiskColor << HumanReadable{fs::file_size(kFile)} << color::End << "\t";
        }
        if(bRealpath) std::cout << color::fg::LightCyan << icon_s << " " << kFile.string() << color::End << std::endl;
        else         std::cout << color::fg::LightCyan << icon_s << " " << kFile.filename().string() << color::End << std::endl;
      }


      else if(kType==fs::file_type::fifo){
        // "
        if(bLong){
          std::cout << KeyColor << "p" << Permission{kStatus.permissions()} << "  " << DiskColor << HumanReadable{fs::file_size(kFile)} << color::End << "\t";
        }
        if(bRealpath) std::cout << color::fg::LightBlue << "\uf731" << " " << kFile.string() << color::End << std::endl;
        else         std::cout << color::fg::LightBlue << "\uf731" << " " << kFile.filename().string() << color::End << std::endl;
      }


      else if(kType==fs::file_type::socket){
        // "
        if(bLong){
          std::cout << KeyColor << "s" << Permission{kStatus.permissions()} << "  " << DiskColor << HumanReadable{fs::file_size(kFile)} << color::End << "\t";
        }
        if(bRealpath) std::cout << color::fg::LightBlue << "\uf6a7" << " " << kFile.string() << color::End << std::endl;
        else         std::cout << color::fg::LightBlue << "\uf6a7" << " " << kFile.filename().string() << color::End << std::endl;
      }


      else if(kType==fs::file_type::block){
        // ﰩ"
        if(bLong){
          std::cout << KeyColor << "b" << Permission{kStatus.permissions()} << "  " << DiskColor << HumanReadable{fs::file_size(kFile)} << color::End << "\t";
        }
        if(bRealpath) std::cout << color::fg::LightBlue << "\ufc29" << " " << kFile.string() << color::End << std::endl;
        else         std::cout << color::fg::LightBlue << "\ufc29" << " " << kFile.filename().string() << color::End << std::endl;
      }


      else if(kType==fs::file_type::character){
        // "
        if(bLong){
          std::cout << KeyColor << "c" << Permission{kStatus.permissions()} << "  " << DiskColor << HumanReadable{fs::file_size(kFile)} << color::End << "\t";
        }
        if(bRealpath) std::cout << color::fg::LightBlue << "\ue601" << " " << kFile.string() << color::End << std::endl;
        else         std::cout << color::fg::LightBlue << "\ue601" << " " << kFile.filename().string() << color::End << std::endl;
      }


      if(cmdl.pos_args().size()!=i+1){
        std::cout << std::endl;
      }
    } else{
      std::cerr << argv[0] << ": "<< path <<": No such file or directory" << std::endl;
    }
  }
  return 0;
}


