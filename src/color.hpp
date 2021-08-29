#include <string_view>
namespace color {
  const std::string End         {"\033[0;0m"};
  namespace misc{
    const std::string Bold        {"\033[1m"};
    const std::string Dull        {"\033[2m"};
    const std::string Italic      {"\033[3m"};
    const std::string Underline   {"\033[4m"};
    const std::string Inverted    {"\033[7m"};
  }
  namespace bg{
    const std::string DarkBlack   {"\033[40m"};
    const std::string DarkRed     {"\033[41m"};
    const std::string DarkGreen   {"\033[42m"};
    const std::string DarkYellow  {"\033[43m"};
    const std::string DarkBlue    {"\033[44m"};
    const std::string DarkMagenta {"\033[45m"};
    const std::string DarkCyan    {"\033[46m"};
    const std::string DarkWhite   {"\033[47m"};
    const std::string LightBlack  {"\033[100m"};
    const std::string LightRed    {"\033[101m"};
    const std::string LightGreen  {"\033[102m"};
    const std::string LightYellow {"\033[103m"};
    const std::string LightBlue   {"\033[104m"};
    const std::string LightMagenta{"\033[105m"};
    const std::string LightCyan   {"\033[106m"};
    const std::string LightWhite  {"\033[107m"};
  }
  namespace fg{
    const std::string DarkBlack   {"\033[30m"};
    const std::string DarkRed     {"\033[31m"};
    const std::string DarkGreen   {"\033[32m"};
    const std::string DarkYellow  {"\033[33m"};
    const std::string DarkBlue    {"\033[34m"};
    const std::string DarkMagenta {"\033[35m"};
    const std::string DarkCyan    {"\033[36m"};
    const std::string DarkWhite   {"\033[37m"};
    const std::string LightBlack  {"\033[90m"};
    const std::string LightRed    {"\033[91m"};
    const std::string LightGreen  {"\033[92m"};
    const std::string LightYellow {"\033[93m"};
    const std::string LightBlue   {"\033[94m"};
    const std::string LightMagenta{"\033[95m"};
    const std::string LightCyan   {"\033[96m"};
    const std::string LightWhite  {"\033[97m"};
  }
}
