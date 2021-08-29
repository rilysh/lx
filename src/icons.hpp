#include <string_view>
#include <unordered_map>

std::unordered_map<std::string_view, std::string_view> kFullnameMap = {
  {".Trash",             "\uf1f8"}, // 
  {".atom",              "\ue764"}, // 
  {".bashprofile",       "\ue615"}, // 
  {".bashrc",            "\uf489"}, // 
  {".git",               "\uf1d3"}, // 
  {".gitattributes",     "\uf1d3"}, // 
  {".gitconfig",         "\uf1d3"}, // 
  {".github",            "\uf408"}, // 
  {".gitignore",         "\uf1d3"}, // 
  {".gitmodules",        "\uf1d3"}, // 
  {".rvm",               "\ue21e"}, // 
  {".vimrc",             "\ue62b"}, // 
  {".vscode",            "\ue70c"}, // 
  {".zshrc",             "\uf489"}, // 
  {"Cargo.lock",         "\ue7a8"}, // 
  {"bin",                "\ue5fc"}, // 
  {"config",             "\ue5fc"}, // 
  {"docker-compose.yml", "\uf308"}, // 
  {"Dockerfile",         "\uf308"}, // 
  {"ds_store",           "\uf179"}, // 
  {"gitignore_global",   "\uf1d3"}, // 
  {"gradle",             "\ue70e"}, // 
  {"gruntfile.coffee",   "\ue611"}, // 
  {"gruntfile.js",       "\ue611"}, // 
  {"gruntfile.ls",       "\ue611"}, // 
  {"gulpfile.coffee",    "\ue610"}, // 
  {"gulpfile.js",        "\ue610"}, // 
  {"gulpfile.ls",        "\ue610"}, // 
  {"hidden",             "\uf023"}, // 
  {"include",            "\ue5fc"}, // 
  {"lib",                "\uf121"}, // 
  {"localized",          "\uf179"}, // 
  {"Makefile",           "\ue779"}, // 
  {"node_modules",       "\ue718"}, // 
  {"npmignore",          "\ue71e"}, // 
  {"rubydoc",            "\ue73b"}, // 
  {"yarn.lock",          "\ue718"}, // 
  {"bin",                "\ue5fc"}, // 
  {".git",               "\uf1d3"}, // 
  {".idea",              "\ue7b5"}, // 
};



std::unordered_map<std::string_view, std::string_view> kExtmap = {

  { ".ai",             "\ue7b4"}, // 
  { ".android",        "\ue70e"}, // 
  { ".apk",            "\ue70e"}, // 
  { ".apple",          "\uf179"}, // 
  { ".avi",            "\uf03d"}, // 
  { ".avro",           "\ue60b"}, // 
  { ".awk",            "\uf489"}, // 
  { ".bash",           "\uf489"}, // 
  { ".bash_history",   "\uf489"}, // 
  { ".bash_profile",   "\uf489"}, // 
  { ".bashrc",         "\uf489"}, // 
  { ".bat",            "\uf17a"}, // 
  { ".bmp",            "\uf1c5"}, // 
  { ".bz",             "\uf410"}, // 
  { ".bz2",            "\uf410"}, // 
  { ".c",              "\ue61e"}, // 
  { ".c++",            "\ue61d"}, // 
  { ".cab",            "\ue70f"}, // 
  { ".cc",             "\ue61d"}, // 
  { ".cfg",            "\ue615"}, // 
  { ".class",          "\ue256"}, // 
  { ".clj",            "\ue768"}, // 
  { ".cljs",           "\ue76a"}, // 
  { ".cls",            "\uf034"}, // 
  { ".cmd",            "\ue70f"}, // 
  { ".coffee",         "\uf0f4"}, // 
  { ".conf",           "\ue615"}, // 
  { ".cp",             "\ue61d"}, // 
  { ".cpp",            "\ue61d"}, // 
  { ".cs",             "\uf81a"}, // 
  { ".csh",            "\uf489"}, // 
  { ".cshtml",         "\uf1fa"}, // 
  { ".csproj",         "\uf81a"}, // 
  { ".css",            "\ue749"}, // 
  { ".csv",            "\uf1c3"}, // 
  { ".csx",            "\uf81a"}, // 
  { ".cxx",            "\ue61d"}, // 
  { ".d",              "\ue7af"}, // 
  { ".dart",           "\ue798"}, // 
  { ".db",             "\uf1c0"}, // 
  { ".deb",            "\ue77d"}, // 
  { ".diff",           "\uf440"}, // 
  { ".djvu",           "\uf02d"}, // 
  { ".dll",            "\ue70f"}, // 
  { ".doc",            "\uf1c2"}, // 
  { ".docx",           "\uf1c2"}, // 
  { ".ds_store",       "\uf179"}, // 
  { ".DS_store",       "\uf179"}, // 
  { ".dump",           "\uf1c0"}, // 
  { ".ebook",          "\ue28b"}, // 
  { ".editorconfig",   "\ue615"}, // 
  { ".ejs",            "\ue618"}, // 
  { ".elm",            "\ue62c"}, // 
  { ".env",            "\uf462"}, // 
  { ".eot",            "\uf031"}, // 
  { ".epub",           "\ue28a"}, // 
  { ".erb",            "\ue73b"}, // 
  { ".erl",            "\ue7b1"}, // 
  { ".ex",             "\ue62d"}, // 
  { ".exe",            "\uf17a"}, // 
  { ".exs",            "\ue62d"}, // 
  { ".fish",           "\uf489"}, // 
  { ".flac",           "\uf001"}, // 
  { ".flv",            "\uf03d"}, // 
  { ".font",           "\uf031"}, // 
  { ".fs",             "\ue7a7"}, // 
  { ".fsi",            "\ue7a7"}, // 
  { ".fsx",            "\ue7a7"}, // 
  { ".gdoc",           "\uf1c2"}, // 
  { ".gem",            "\ue21e"}, // 
  { ".gemfile",        "\ue21e"}, // 
  { ".gemspec",        "\ue21e"}, // 
  { ".gform",          "\uf298"}, // 
  { ".gif",            "\uf1c5"}, // 
  { ".git",            "\uf1d3"}, // 
  { ".gitattributes",  "\uf1d3"}, // 
  { ".gitignore",      "\uf1d3"}, // 
  { ".gitmodules",     "\uf1d3"}, // 
  { ".go",             "\ue626"}, // 
  { ".gradle",         "\ue70e"}, // 
  { ".groovy",         "\ue775"}, // 
  { ".gsheet",         "\uf1c3"}, // 
  { ".gslides",        "\uf1c4"}, // 
  { ".guardfile",      "\ue21e"}, // 
  { ".gz",             "\uf410"}, // 
  { ".h",              "\uf0fd"}, // 
  { ".hbs",            "\ue60f"}, // 
  { ".hpp",            "\uf0fd"}, // 
  { ".hs",             "\ue777"}, // 
  { ".htm",            "\uf13b"}, // 
  { ".html",           "\uf13b"}, // 
  { ".hxx",            "\uf0fd"}, // 
  { ".ico",            "\uf1c5"}, // 
  { ".image",          "\uf1c5"}, // 
  { ".iml",            "\ue7b5"}, // 
  { ".ini",            "\uf17a"}, // 
  { ".ipynb",          "\ue606"}, // 
  { ".iso",            "\ue271"}, // 
  { ".jad",            "\ue256"}, // 
  { ".jar",            "\ue204"}, // 
  { ".java",           "\ue204"}, // 
  { ".jfi",            "\uf1c5"}, // 
  { ".jfif",           "\uf1c5"}, // 
  { ".jif",            "\uf1c5"}, // 
  { ".jpe",            "\uf1c5"}, // 
  { ".jpeg",           "\uf1c5"}, // 
  { ".jpg",            "\uf1c5"}, // 
  { ".js",             "\ue74e"}, // 
  { ".json",           "\ue60b"}, // 
  { ".jsx",            "\ue7ba"}, // 
  { ".ksh",            "\uf489"}, // 
  { ".latex",          "\uf034"}, // 
  { ".less",           "\ue758"}, // 
  { ".lhs",            "\ue777"}, // 
  { ".license",        "\uf718"}, // 
  { ".localized",      "\uf179"}, // 
  { ".lock",           "\uf023"}, // 
  { ".log",            "\uf18d"}, // 
  { ".lua",            "\ue620"}, // 
  { ".lz",             "\uf410"}, // 
  { ".lzh",            "\uf410"}, // 
  { ".lzma",           "\uf410"}, // 
  { ".lzo",            "\uf410"}, // 
  { ".m",              "\ue61e"}, // 
  { ".mm",             "\ue61d"}, // 
  { ".m4a",            "\uf001"}, // 
  { ".markdown",       "\uf48a"}, // 
  { ".md",             "\uf48a"}, // 
  { ".mjs",            "\ue74e"}, // 
  { ".mkd",            "\uf48a"}, // 
  { ".mkv",            "\uf03d"}, // 
  { ".mobi",           "\ue28b"}, // 
  { ".mov",            "\uf03d"}, // 
  { ".mp3",            "\uf001"}, // 
  { ".mp4",            "\uf03d"}, // 
  { ".msi",            "\ue70f"}, // 
  { ".mustache",       "\ue60f"}, // 
  { ".nix",            "\uf313"}, // 
  { ".node",           "\uf898"}, // 
  { ".npmignore",      "\ue71e"}, // 
  { ".odp",            "\uf1c4"}, // 
  { ".ods",            "\uf1c3"}, // 
  { ".odt",            "\uf1c2"}, // 
  { ".ogg",            "\uf001"}, // 
  { ".ogv",            "\uf03d"}, // 
  { ".otf",            "\uf031"}, // 
  { ".patch",          "\uf440"}, // 
  { ".pdf",            "\uf1c1"}, // 
  { ".php",            "\ue73d"}, // 
  { ".pl",             "\ue769"}, // 
  { ".png",            "\uf1c5"}, // 
  { ".ppt",            "\uf1c4"}, // 
  { ".pptx",           "\uf1c4"}, // 
  { ".procfile",       "\ue21e"}, // 
  { ".properties",     "\ue60b"}, // 
  { ".ps1",            "\uf489"}, // 
  { ".psd",            "\ue7b8"}, // 
  { ".pxm",            "\uf1c5"}, // 
  { ".py",             "\ue606"}, // 
  { ".pyc",            "\ue606"}, // 
  { ".r",              "\uf25d"}, // 
  { ".rakefile",       "\ue21e"}, // 
  { ".rar",            "\uf410"}, // 
  { ".razor",          "\uf1fa"}, // 
  { ".rb",             "\ue21e"}, // 
  { ".rdata",          "\uf25d"}, // 
  { ".rdb",            "\ue76d"}, // 
  { ".rdoc",           "\uf48a"}, // 
  { ".rds",            "\uf25d"}, // 
  { ".readme",         "\uf48a"}, // 
  { ".rlib",           "\ue7a8"}, // 
  { ".rmd",            "\uf48a"}, // 
  { ".rpm",            "\ue7bb"}, // 
  { ".rs",             "\ue7a8"}, // 
  { ".rspec",          "\ue21e"}, // 
  { ".rspec_parallel", "\ue21e"}, // 
  { ".rspec_status",   "\ue21e"}, // 
  { ".rss",            "\uf09e"}, // 
  { ".rtf",            "\uf718"}, // 
  { ".ru",             "\ue21e"}, // 
  { ".rubydoc",        "\ue73b"}, // 
  { ".sass",           "\ue603"}, // 
  { ".scala",          "\ue737"}, // 
  { ".scss",           "\ue749"}, // 
  { ".sh",             "\uf489"}, // 
  { ".shell",          "\uf489"}, // 
  { ".slim",           "\ue73b"}, // 
  { ".sln",            "\ue70c"}, // 
  { ".so",             "\uf17c"}, // 
  { ".sql",            "\uf1c0"}, // 
  { ".sqlite3",        "\ue7c4"}, // 
  { ".sty",            "\uf034"}, // 
  { ".styl",           "\ue600"}, // 
  { ".stylus",         "\ue600"}, // 
  { ".svg",            "\uf1c5"}, // 
  { ".swift",          "\ue755"}, // 
  { ".tar",            "\uf410"}, // 
  { ".taz",            "\uf410"}, // 
  { ".tbz",            "\uf410"}, // 
  { ".tbz2",           "\uf410"}, // 
  { ".tex",            "\uf034"}, // 
  { ".tiff",           "\uf1c5"}, // 
  { ".toml",           "\ue615"}, // 
  { ".ts",             "\ue628"}, // 
  { ".tsv",            "\uf1c3"}, // 
  { ".tsx",            "\ue7ba"}, // 
  { ".ttf",            "\uf031"}, // 
  { ".twig",           "\ue61c"}, // 
  { ".txt",            "\uf15c"}, // 
  { ".tz",             "\uf410"}, // 
  { ".tzo",            "\uf410"}, // 
  { ".video",          "\uf03d"}, // 
  { ".vim",            "\ue62b"}, // 
  { ".vue",            "\ufd42"}, // ﵂
  { ".war",            "\ue256"}, // 
  { ".wav",            "\uf001"}, // 
  { ".webm",           "\uf03d"}, // 
  { ".webp",           "\uf1c5"}, // 
  { ".windows",        "\uf17a"}, // 
  { ".woff",           "\uf031"}, // 
  { ".woff2",          "\uf031"}, // 
  { ".xhtml",          "\uf13b"}, // 
  { ".xls",            "\uf1c3"}, // 
  { ".xlsx",           "\uf1c3"}, // 
  { ".xml",            "\ufabf"}, // 謹
  { ".xul",            "\ufabf"}, // 謹
  { ".xz",             "\uf410"}, // 
  { ".yaml",           "\uf481"}, // 
  { ".yml",            "\uf481"}, // 
  { ".zip",            "\uf410"}, // 
  { ".zsh",            "\uf489"}, // 
  { ".zsh-theme",      "\uf489"}, // 
  { ".zshrc",          "\uf489"}, // 

};

