#include <string_view>
namespace color {
  const std::string_view End           {"\033[0;0m"};
  namespace misc{
    const std::string_view Bold        {"\033[1m"};
    const std::string_view Dull        {"\033[2m"};
    const std::string_view Italic      {"\033[3m"};
    const std::string_view Underline   {"\033[4m"};
    const std::string_view Inverted    {"\033[7m"};
  }
  namespace bg{
    const std::string_view DarkBlack   {"\033[40m"};
    const std::string_view DarkRed     {"\033[41m"};
    const std::string_view DarkGreen   {"\033[42m"};
    const std::string_view DarkYellow  {"\033[43m"};
    const std::string_view DarkBlue    {"\033[44m"};
    const std::string_view DarkMagenta {"\033[45m"};
    const std::string_view DarkCyan    {"\033[46m"};
    const std::string_view DarkWhite   {"\033[47m"};
    const std::string_view LightBlack  {"\033[100m"};
    const std::string_view LightRed    {"\033[101m"};
    const std::string_view LightGreen  {"\033[102m"};
    const std::string_view LightYellow {"\033[103m"};
    const std::string_view LightBlue   {"\033[104m"};
    const std::string_view LightMagenta{"\033[105m"};
    const std::string_view LightCyan   {"\033[106m"};
    const std::string_view LightWhite  {"\033[107m"};
  }
  namespace fg{
    const std::string_view DarkBlack   {"\033[30m"};
    const std::string_view DarkRed     {"\033[31m"};
    const std::string_view DarkGreen   {"\033[32m"};
    const std::string_view DarkYellow  {"\033[33m"};
    const std::string_view DarkBlue    {"\033[34m"};
    const std::string_view DarkMagenta {"\033[35m"};
    const std::string_view DarkCyan    {"\033[36m"};
    const std::string_view DarkWhite   {"\033[37m"};
    const std::string_view LightBlack  {"\033[90m"};
    const std::string_view LightRed    {"\033[91m"};
    const std::string_view LightGreen  {"\033[92m"};
    const std::string_view LightYellow {"\033[93m"};
    const std::string_view LightBlue   {"\033[94m"};
    const std::string_view LightMagenta{"\033[95m"};
    const std::string_view LightCyan   {"\033[96m"};
    const std::string_view LightWhite  {"\033[97m"};
  }
}
